#include "translator/stream/sc_string_stream.h"

ScStringStream::ScStringStream()
{
  m_instance = std::stringstream();
}

ScStringStream & ScStringStream::operator<< (std::string const & string)
{
  m_instance << string;
  return *this;
}

void ScStringStream::operator>> (std::string & string)
{
  m_instance >> string;
}

ScStringStream::operator std::string()
{
  return m_instance.str();
}
