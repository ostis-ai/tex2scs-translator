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
    formatted(*this << DefineSemicolons() << DefineEndline() << DefineOffset());
    return *this;
  }

  SCsStream & PreFormatted(std::function<void(SCsStream &)> const & formatted = {})
  {
    PreFormat();
    if (formatted)
      formatted(*this);
    return *this;
  }

  SCsStream & Formatted(std::function<SCsStream()> const & formatted)
  {
    *this << DefineSemicolons() << DefineEndline() << DefineOffset() << formatted();
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
    Tab();
    return *this;
  }

  SCsStream & RemoveTab()
  {
    Untab();
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

  void PreFormat()
  {
    if (m_lastCommand == "(*")
      return;

    if (m_formats.find(m_currentCommand) != m_formats.cend())
      return;

    std::string const savedCurrentCommand = m_currentCommand;

    auto const & BeginIndent = [this]() {
      SetCurrentCommand("(*");
      SetCurrentCommand("(*");
      *this << DefineEndline() << DefineOffset() << "(*";
      SetDoubleSemicolons();
    };

    auto const & EndIndent = [this](std::string const & savedCurrentCommand) {
      SetCurrentCommand("*)");
      *this << DefineSemicolons() << DefineEndline();
      UnsetDoubleSemicolons();
      *this << DefineOffset() << "*)";
      m_currentCommand = savedCurrentCommand;
    };

    bool const noOtherAttached = savedCurrentCommand != "(*";
    if (!m_attached.empty() || !noOtherAttached)
    {
      BeginIndent();

      std::for_each(m_attached.begin(), m_attached.end(), [this](std::string const & element) {
        SetCurrentCommand("any");
        *this << DefineSemicolons() << DefineEndline() << DefineOffset() << element;
      });

      if (noOtherAttached)
        EndIndent(savedCurrentCommand);
    }

    if (savedCurrentCommand == "*)")
      EndIndent("any");

    m_attached.clear();
  }

  static std::string DefineSemicolons()
  {
    if (m_lastCommand.empty())
      return "";

    if (IsCommandHeader(m_lastCommand) || IsCommandListHeaderBegin(m_lastCommand))
      return "";

    if (m_begins.find(m_lastCommand) != m_begins.cend())
      return "";

    if (IsCommandListHeaderEnd(m_lastCommand) || IsCommandListHeaderEnd(m_currentCommand))
      return "";

    if (IsCommandHeader(m_currentCommand) || IsCommandListHeaderBegin(m_currentCommand))
      return ";;";

    auto const & item = m_formats.find(m_currentCommand);
    if (item != m_formats.cend())
    {
      std::string const oldSemicolons = m_semicolons;

      auto const semicolonsTypes = item->second;
      auto const & beginSemicolonsType = semicolonsTypes.at(0);
      if (beginSemicolonsType == "cur")
        return oldSemicolons;

      return semicolonsTypes.at(0);
    }

    if ((m_lastCommand.find("item") != std::string::npos
      || m_begins.find(m_lastCommand) != m_begins.cend() || m_lastCommand == "any")
        && m_currentCommand.find("item") != std::string::npos)
      return ";";

    return m_semicolons;
  }

  static void Tab()
  {
    m_offset += "\t";
  }

  static void Untab()
  {
    if (m_offset.size() <= 1)
      m_offset = "";
    else
      m_offset = SCsStream::m_offset.substr(0, m_offset.size() - 1);
  }

  static void SetDoubleSemicolons()
  {
    ++m_indent;
    Tab();
    m_semicolons = ";;";
  }

  static void UnsetDoubleSemicolons()
  {
    --m_indent;
    Untab();
    if (!m_indent)
      m_semicolons = ";";
  }

  static std::string DefineEndline()
  {
    if (m_lastCommand.empty() && IsCommandHeader(m_currentCommand))
      return "";

    if (IsCommandListHeaderBegin(m_currentCommand))
      return "\n\n";

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

  static bool IsCommandListHeaderBegin(std::string const & name)
  {
    return name.find("listbegin") != std::string::npos;
  }

  static bool IsCommandListHeaderEnd(std::string const & name)
  {
    return name.find("listend") != std::string::npos;
  }
};
