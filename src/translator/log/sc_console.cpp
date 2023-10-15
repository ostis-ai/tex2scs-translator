#include "sc_console.hpp"

/// Common C++ headers
#include <iostream>
#include <string>

#define SC_CONSOLE_PRINT(st) std::cout << st

namespace impl
{
const std::string ANSI_ATTRIBUTE_RESET = "\033[0m";
const std::string ANSI_BLACK = "\033[22;30m";
const std::string ANSI_RED = "\033[22;31m";
const std::string ANSI_GREEN = "\033[22;32m";
const std::string ANSI_BROWN = "\033[22;33m";
const std::string ANSI_BLUE = "\033[22;34m";
const std::string ANSI_MAGENTA = "\033[22;35m";
const std::string ANSI_CYAN = "\033[22;36m";
const std::string ANSI_GREY = "\033[22;37m";
const std::string ANSI_DARKGREY = "\033[01;30m";
const std::string ANSI_LIGHTRED = "\033[01;31m";
const std::string ANSI_LIGHTGREEN = "\033[01;32m";
const std::string ANSI_YELLOW = "\033[01;33m";
const std::string ANSI_LIGHTBLUE = "\033[01;34m";
const std::string ANSI_LIGHTMAGENTA = "\033[01;35m";
const std::string ANSI_LIGHTCYAN = "\033[01;36m";
const std::string ANSI_WHITE = "\033[01;37m";
const std::string ANSI_EMPTY = "";

std::string const & GetANSIColor(ScConsole::Color const c)
{
  switch (c)
  {
  case ScConsole::Color::Reset:
    return ANSI_ATTRIBUTE_RESET;
  case ScConsole::Color::Black:
    return ANSI_BLACK;
  case ScConsole::Color::Blue:
    return ANSI_BLUE;  // non-ANSI
  case ScConsole::Color::Green:
    return ANSI_GREEN;
  case ScConsole::Color::Cyan:
    return ANSI_CYAN;  // non-ANSI
  case ScConsole::Color::Red:
    return ANSI_RED;  // non-ANSI
  case ScConsole::Color::Magneta:
    return ANSI_MAGENTA;
  case ScConsole::Color::Brown:
    return ANSI_BROWN;
  case ScConsole::Color::Grey:
    return ANSI_GREY;
  case ScConsole::Color::DarkGrey:
    return ANSI_DARKGREY;
  case ScConsole::Color::LightBlue:
    return ANSI_LIGHTBLUE;  // non-ANSI
  case ScConsole::Color::LightGreen:
    return ANSI_LIGHTGREEN;
  case ScConsole::Color::LightCyan:
    return ANSI_LIGHTCYAN;  // non-ANSI;
  case ScConsole::Color::LightRed:
    return ANSI_LIGHTRED;  // non-ANSI;
  case ScConsole::Color::LightMagneta:
    return ANSI_LIGHTMAGENTA;
  case ScConsole::Color::Yellow:
    return ANSI_YELLOW;  // non-ANSI
  case ScConsole::Color::White:
    return ANSI_WHITE;
  }
  return ANSI_EMPTY;
}

}  // namespace impl

void ScConsole::SetColor(Color c)
{
  SC_CONSOLE_PRINT(impl::GetANSIColor(c));
}

void ScConsole::ResetColor()
{
  SC_CONSOLE_PRINT(impl::ANSI_ATTRIBUTE_RESET);
}
