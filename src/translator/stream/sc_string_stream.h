#pragma once

#include <string>
#include <sstream>
#include <iostream>

class ScStringStream
{
public:
  ScStringStream()
  {
    m_instance = std::stringstream();
  }

  ScStringStream & operator<< (std::string const & string)
  {
    m_instance << string;
    return *this;
  }

  void operator>> (std::string & string)
  {
    m_instance >> string;
  }

  operator std::string()
  {
    return m_instance.str();
  }

private:
  std::stringstream m_instance;
};
