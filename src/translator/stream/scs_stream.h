#pragma once

#include <string>
#include <sstream>
#include <iostream>

#include <functional>
#include <unordered_set>

#include "sc_string_stream.h"

class SCsStream : protected ScStringStream
{
public:
  SCsStream()
  {
  }

  template <typename... Args>
  SCsStream(Args const &... args)
  {
    std::vector<std::string> vector{args...};

    for (auto const & item : vector)
      *this << item;
  }

  SCsStream & operator<< (std::string const & string) override
  {
    m_instance << string;
    return *this;
  }

  SCsStream & Row(std::function<void(SCsStream &)> const & row)
  {
    row(*this);
    return *this;
  }

  SCsStream & Row(std::function<SCsStream()> const & row)
  {
    *this << row();
    return *this;
  }

  SCsStream & Offset(std::function<void(SCsStream &)> const & formatted)
  {
    formatted(*this << DefineEndline() <<  DefineOffset());
    return *this;
  }

  SCsStream & Offset(std::function<SCsStream()> const & formatted)
  {
    *this << DefineEndline() << DefineOffset() << formatted();
    return *this;
  }

  SCsStream & Formatted(std::function<void(SCsStream &)> const & formatted)
  {
    PreFormat([this, &formatted]() {
      formatted(*this << DefineSemicolons() << DefineEndline() << DefineOffset());
    });
    return *this;
  }

  SCsStream & Formatted(std::function<SCsStream()> const & formatted)
  {
    PreFormat([this, &formatted]() {
      *this << DefineSemicolons() << DefineEndline() << DefineOffset() << formatted();
    });
    return *this;
  }

  SCsStream & Tabulated(std::function<void(SCsStream &)> const & tabulated)
  {
    AddTab();
    tabulated(*this);
    RemoveTab();

    return *this;
  }

  SCsStream & Tabulated(std::function<SCsStream()> const & tabulated)
  {
    AddTab();
    *this << tabulated();
    RemoveTab();

    return *this;
  }

  SCsStream & AddTab()
  {
    m_offset += "\t";
    return *this;
  }

  SCsStream & RemoveTab()
  {
    if (m_offset.size() <= 1)
      m_offset = "";
    else
      m_offset = SCsStream::m_offset.substr(0, m_offset.size() - 1);
    return *this;
  }

  SCsStream & SetCurrentCommand(std::string const & name = "any")
  {
    m_lastCommand = m_currentCommand;
    m_currentCommand = name;
    return *this;
  }

  template <typename... Args>
  SCsStream & Attached(Args const &... args)
  {
    std::vector<std::string> vector{args...};
    for (auto const & item : vector)
      m_attached.emplace_back(item);

    return *this;
  }

  static void Clear()
  {
    m_offset = "";
    m_indent = 0;
    m_semicolons = ";";
    m_lastCommand = "";
    m_currentCommand = "";
    m_attached.clear();
  }

  operator std::string() override
  {
    return m_instance.str();
  }

private:
  static std::string m_offset;
  static uint32_t m_indent;
  static std::string m_semicolons;
  static std::string m_currentCommand;
  static std::string m_lastCommand;

  static std::vector<std::string> m_attached;

  static std::unordered_map<std::string, std::vector<std::string>> m_formats;
  static std::unordered_set<std::string> m_begins;

  void PreFormat(std::function<void()> const & format)
  {
    std::string const savedSemicolons = m_semicolons;
    std::string const savedLastCommand = m_lastCommand;
    std::string const savedCurrentCommand = m_currentCommand;

    bool const noOtherAttached = m_currentCommand != "(*";
    if (!m_attached.empty())
    {
      SetCurrentCommand("(*");
      m_lastCommand = savedLastCommand;
      *this << DefineSemicolons() << DefineEndline() << DefineOffset() << "(*";
      if (noOtherAttached)
        AddTab();

      std::for_each(m_attached.begin(), m_attached.end(), [this](std::string const & element) {
        SetCurrentCommand("any");
        *this << DefineSemicolons() << DefineEndline() << DefineOffset() << element;
      });

      if (noOtherAttached)
      {
        RemoveTab();
        SetCurrentCommand("*)");
        *this << DefineSemicolons() << DefineEndline() << DefineOffset() << "*)";

        m_semicolons = savedSemicolons;
      }
      else
        *this << ";;";

      SetCurrentCommand(savedCurrentCommand);
    }

    if (m_attached.empty() || noOtherAttached)
      format();

    m_attached.clear();
  }

  static std::string DefineSemicolons()
  {
    if (IsCommandHeader(m_lastCommand))
      return "";

    if (m_begins.find(m_lastCommand) != m_begins.cend())
      return "";

    if (!m_lastCommand.empty() && IsCommandHeader(m_currentCommand))
      return ";;";

    auto const & item = m_formats.find(m_currentCommand);
    if (item != m_formats.cend())
    {
      std::string const oldSemicolons = m_semicolons;

      auto const formats = item->second;
      if (formats.size() == 2)
      {
        auto const endStringType = formats.at(1);
        if (endStringType == "++")
          SetDoubleSemicolons();
        else if (endStringType == "--")
          UnsetDoubleSemicolons();
        else
          m_semicolons = endStringType;
      }

      auto const & begStringType = formats.at(0);
      if (begStringType == "cur")
        return oldSemicolons;

      return formats.at(0);
    }

    if (m_lastCommand.empty() && IsCommandHeader(m_currentCommand) || m_currentCommand.empty())
      return "";

    if ((m_lastCommand == "scnitem" || m_formats.find(m_lastCommand) != m_formats.cend()) && m_currentCommand == "scnitem")
      return ";";

    return m_semicolons;
  }

  static void SetDoubleSemicolons()
  {
    ++m_indent;
    m_semicolons = ";;";
  }

  static void UnsetDoubleSemicolons()
  {
    --m_indent;
    if (!m_indent)
      m_semicolons = ";";
  }

  static std::string DefineEndline()
  {
    if (m_lastCommand.empty() && IsCommandHeader(m_currentCommand))
      return "";

    if (IsCommandHeader(m_currentCommand))
      return "\n\n";

    return "\n";
  }

  static std::string DefineOffset()
  {
    return m_offset;
  }

  static bool IsCommandHeader(std::string const & name)
  {
    return name.find("header") != std::string::npos;
  }
};
