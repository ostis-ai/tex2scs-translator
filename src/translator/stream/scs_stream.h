#pragma once

#include <string>
#include <sstream>
#include <cstdint>

#include <functional>
#include <unordered_set>

#include "translator/stream/sc_string_stream.h"

class SCsStream : protected ScStringStream
{
public:
  SCsStream();

  template <typename... Args>
  SCsStream(Args const &... args)
  {
    std::vector<std::string> vector{args...};

    for (auto const & item : vector)
      *this << item;
  }

  SCsStream & operator<< (std::string const & string) override;

  SCsStream & Row(std::function<void(SCsStream &)> const & row);

  SCsStream & Row(std::function<SCsStream()> const & row);

  SCsStream & Offset(std::function<void(SCsStream &)> const & formatted);

  SCsStream & Offset(std::function<SCsStream()> const & formatted);

  SCsStream & Formatted(std::function<void(SCsStream &)> const & formatted);

  SCsStream & PreFormatted(std::function<void(SCsStream &)> const & formatted = {});

  SCsStream & Formatted(std::function<SCsStream()> const & formatted);

  SCsStream & Tabulated(std::function<void(SCsStream &)> const & tabulated);

  SCsStream & Tabulated(std::function<SCsStream()> const & tabulated);

  SCsStream & AddTab();

  SCsStream & RemoveTab();

  SCsStream & SetCurrentCommand(std::string const & name = "any");

  template <typename... Args>
  SCsStream & Attached(Args const &... args)
  {
    std::vector<std::string> vector{args...};
    for (auto const & item : vector)
      m_attached.emplace_back(item);

    return *this;
  }

  static void Clear();

  operator std::string() override;

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
