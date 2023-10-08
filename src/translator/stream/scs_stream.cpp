#include "scs_stream.h"

std::string SCsStream::m_offset;
uint32_t SCsStream::m_indent = 0;
std::string SCsStream::m_semicolons = ";";
std::string SCsStream::m_lastCommand;
std::string SCsStream::m_currentCommand;

std::vector<std::string> SCsStream::m_attached;

std::unordered_map<std::string, std::vector<std::string>> SCsStream::m_formats = {
  { "[*", { "cur" } },
  { "*]", { ";;" } },
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

void SCsStream::PreFormat()
{
  if (m_lastCommand == "(*")
  {
    m_attached.clear();
    return;
  }

  if (m_formats.find(m_currentCommand) != m_formats.cend())
  {
    m_attached.clear();
    return;
  }

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
    SetCurrentCommand(savedCurrentCommand);
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

std::string SCsStream::DefineSemicolons()
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

void SCsStream::Tab()
{
  m_offset += "\t";
}

void SCsStream::Untab()
{
  if (m_offset.size() <= 1)
    m_offset = "";
  else
    m_offset = SCsStream::m_offset.substr(0, m_offset.size() - 1);
}

void SCsStream::SetDoubleSemicolons()
{
  ++m_indent;
  Tab();
  m_semicolons = ";;";
}

void SCsStream::UnsetDoubleSemicolons()
{
  --m_indent;
  Untab();
  if (!m_indent)
    m_semicolons = ";";
}

std::string SCsStream::DefineEndline()
{
  if (m_lastCommand.empty() && IsCommandHeader(m_currentCommand))
    return "";

  if (IsCommandListHeaderBegin(m_currentCommand))
    return "\n\n";

  if (IsCommandHeader(m_currentCommand))
    return "\n\n";

  return "\n";
}

std::string SCsStream::DefineOffset()
{
  return m_offset;
}

bool SCsStream::IsCommandHeader(std::string const & name)
{
  return name.find("header") != std::string::npos;
}

bool SCsStream::IsCommandListHeaderBegin(std::string const & name)
{
  return name.find("listbegin") != std::string::npos;
}

bool SCsStream::IsCommandListHeaderEnd(std::string const & name)
{
  return name.find("listend") != std::string::npos;
}
