#include "scs_stream.h"

std::string SCsStream::m_offset;
uint32_t SCsStream::m_indent = 0;
std::string SCsStream::m_semicolons = ";";
std::string SCsStream::m_lastCommand;
std::string SCsStream::m_currentCommand;

std::vector<std::string> SCsStream::m_attached;

std::unordered_map<std::string, std::vector<std::string>> SCsStream::m_formats = {
  { "(*", { "", "++" } },
  { "*)", { ";;", "--" } },
  { "[*", { "cur", ";;" } },
  { "*]", { ";;", ";" } },
  { "{",  { "cur" } },
  { "}",  { "" } },
  { "<",  { "cur" } },
  { ">",  { "" } },
  { "lb",  { "cur" } },
  { "le",  { "" } },
};

std::unordered_set<std::string> SCsStream::m_begins = {
  "(*", "[*", "{", "<", "lb"
};
