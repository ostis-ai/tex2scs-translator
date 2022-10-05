#pragma once

#include <string>
#include <sstream>
#include <iostream>

#include <functional>

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

  SCsStream & Formatted(std::function<void(SCsStream &)> const & formatted)
  {
    formatted(*this << DefineSemicolons() << DefineEndline() << m_offset);
    return *this;
  }

  SCsStream & Formatted(std::function<SCsStream()> const & formatted)
  {
    *this << DefineSemicolons() << DefineEndline() << m_offset << formatted();
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

  SCsStream & SetDoubleSemicolons()
  {
    m_semicolons = ";;";
    return *this;
  }

  SCsStream & UnsetDoubleSemicolons()
  {
    m_semicolons = ";";
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

  SCsStream & SetLastCommandName(std::string const & name = "any")
  {
    m_lastCommand = name;
    return *this;
  }

  static void Clear()
  {
    m_offset = "";
    m_semicolons = ";";
    m_lastCommand = "";
  }

  operator std::string() override
  {
    return m_instance.str();
  }

private:
  static std::string m_offset;
  static std::string m_semicolons;
  static std::string m_lastCommand;

  static std::string DefineSemicolons()
  {
    if (m_lastCommand.empty()
      || m_lastCommand == "begin"
      || m_lastCommand == "end"
      || m_lastCommand == "\\"
      || IsLastCommandHeader())
      return "";
    return m_semicolons;
  }

  static std::string DefineEndline()
  {
    if (m_lastCommand.empty() && IsLastCommandHeader())
      return "";
    return "\n";
  }

  static bool IsLastCommandHeader()
  {
    return m_lastCommand.find("header") != std::string::npos;
  }
};
