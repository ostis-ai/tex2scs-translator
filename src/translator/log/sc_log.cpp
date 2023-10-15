#include "sc_log.hpp"

#include <iostream>

namespace
{
// should be synced with ScLog::Type
const std::string kTypeToStr[] = {"Debug", "Info", "Warning", "Error"};

// should be synced with ScLog::OutputType
const std::string kOutputTypeToStr[] = {"Console", "File"};

}

namespace utils
{
ScLog * ScLog::m_instance = nullptr;

ScLog * ScLog::GetInstance()
{
  if (!m_instance)
    return m_instance = new ScLog();

  return m_instance;
}

void ScLog::SetDebugMode()
{
  m_instance->m_mode = Type::Debug;
}

ScLog::ScLog()
{
  m_mode = Type::Info;
  m_output_mode = OutputType::Console;
}

ScLog::ScLog(std::string const & logType, std::string const & logFile, std::string const & logLevel)
{
  int modeIndex = FindEnumElement(kTypeToStr, logLevel);
  m_mode = modeIndex != -1 ? Type(modeIndex) : Type::Info;

  int outputTypeIndex = FindEnumElement(kOutputTypeToStr, logType);
  m_output_mode = outputTypeIndex != -1 ? OutputType(outputTypeIndex) : OutputType::Console;

  if (m_output_mode == OutputType::File)
    Initialize(logFile);
}

ScLog::~ScLog()
{
  Shutdown();
}

bool ScLog::Initialize(std::string const & logFile)
{
  m_fileStream.open(logFile, std::ofstream::out | std::ofstream::trunc);
  return m_fileStream.is_open();
}

void ScLog::Shutdown()
{
  if (m_fileStream.is_open())
  {
    m_fileStream.flush();
    m_fileStream.close();
  }
}

void ScLog::Message(ScLog::Type type, std::string const & msg, ScConsole::Color color /*= ScConsole::Color::White*/)
{
  if (m_mode <= type)
  {
    if (m_output_mode == OutputType::Console)
    {
      ScConsole::SetColor(color);
      std::cout << msg << std::endl;

      ScConsole::ResetColor();
    }
    else
    {
      if (m_fileStream.is_open())
      {
        m_fileStream << msg << std::endl;
        m_fileStream.flush();
      }
    }
  }
}

template <size_t N>
int ScLog::FindEnumElement(const std::string (&elements)[N], const std::string & externalValue)
{
  size_t size = N;
  int index = -1;
  for (size_t i = 0; i < size; i++)
  {
    std::string mode = elements[i];
    if (externalValue == mode)
    {
      index = (int)i;
      break;
    }
  }
  return index;
}

}  // namespace utils
