#pragma once

#include <string>
#include <sstream>

class ScStringStream
{
public:
  ScStringStream();

  virtual ScStringStream & operator<< (std::string const & string);

  void operator>> (std::string & string);

  virtual operator std::string();

protected:
  std::stringstream m_instance;
};
