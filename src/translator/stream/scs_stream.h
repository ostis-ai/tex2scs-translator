#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <cstdint>

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

  void PreFormat();

  static std::string DefineSemicolons();

  static void Tab();

  static void Untab();

  static void SetDoubleSemicolons();

  static void UnsetDoubleSemicolons();

  static std::string DefineEndline();

  static std::string DefineOffset();

  static bool IsCommandHeader(std::string const & name);

  static bool IsCommandListHeaderBegin(std::string const & name);

  static bool IsCommandListHeaderEnd(std::string const & name);
};
