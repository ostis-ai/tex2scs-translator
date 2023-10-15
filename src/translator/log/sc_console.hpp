#pragma once

// Originaly got it there: https://github.com/tapio/rlutil/blob/master/rlutil.h

#include <cinttypes>
#include <iostream>
#include <string>

class ScConsole final
{
public:
  enum class Color : uint8_t
  {
    Reset = 0,
    Black,
    Blue,
    Green,
    Cyan,
    Red,
    Magneta,
    Brown,
    Grey,
    DarkGrey,
    LightBlue,
    LightGreen,
    LightCyan,
    LightRed,
    LightMagneta,
    Yellow,
    White
  };

  class Output final
  {
  public:
    Output(bool isNewLine = false)
      : m_isNewLine(isNewLine)
    {
      ScConsole::ResetColor();
    }

    ~Output()
    {
      ScConsole::ResetColor();
      if (m_isNewLine)
        std::cout << std::endl;

      std::cout << std::flush;
    }

    template <typename T>
    Output & operator<<(T v)
    {
      std::cout << v;
      return *this;
    }

  private:
    bool m_isNewLine = false;
  };

public:
  static void SetColor(Color c);
  static Color GetDefaultColor();
  static void ResetColor();
};

namespace impl
{
std::string const & GetANSIColor(ScConsole::Color c);
}

template <>
inline ScConsole::Output & ScConsole::Output::operator<< <ScConsole::Color>(ScConsole::Color v)
{
  ScConsole::SetColor(v);
  return *this;
}
