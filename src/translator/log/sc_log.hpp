#pragma once

#include "sc_console.hpp"

#include <sstream>
#include <fstream>
#include "string"

namespace utils
{
class ScLog final
{
protected:
  ScLog();

  explicit ScLog(std::string const & logType, std::string const & logFile, std::string const & logLevel);

  ~ScLog();

public:
  enum class Type : uint8_t
  {
    Debug = 0,
    Info,
    Warning,
    Error,
  };

  enum class OutputType : uint8_t
  {
    Console = 0,
    File
  };

  static ScLog * GetInstance();

  static void SetDebugMode();

  void Shutdown();

  void Message(Type type, std::string const & msg, ScConsole::Color color = ScConsole::Color::White);

private:
  std::ofstream m_fileStream;
  Type m_mode;
  OutputType m_output_mode;

  static ScLog * m_instance;

  bool Initialize(std::string const & logFile);

  template <size_t N>
  static int FindEnumElement(const std::string (&elements)[N], const std::string & externalValue);
};

#define SC_LOG_COLOR(__type, __msg, __color) \
  { \
    std::stringstream ss; \
    ss << __msg; \
    ::utils::ScLog::GetInstance()->Message(__type, ss.str(), __color); \
  }

#define SC_LOG_DEBUG(__msg) ({SC_LOG_COLOR(::utils::ScLog::Type::Debug, __msg, ScConsole::Color::LightBlue)})
#define SC_LOG_INFO(__msg) ({SC_LOG_COLOR(::utils::ScLog::Type::Info, __msg, ScConsole::Color::Grey)})
#define SC_LOG_WARNING(__msg) ({SC_LOG_COLOR(::utils::ScLog::Type::Warning, __msg, ScConsole::Color::Yellow)})
#define SC_LOG_ERROR(__msg) ({SC_LOG_COLOR(::utils::ScLog::Type::Error, __msg, ScConsole::Color::Red)})
#define SC_LOG_INFO_COLOR(__msg, __color) ({SC_LOG_COLOR(::utils::ScLog::Type::Info, __msg, __color)})

}  // namespace utils
