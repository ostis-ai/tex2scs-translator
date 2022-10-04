#include "sc_scn_tex_command.h"

std::string ScSCnTexCommand::offset = "";
std::string ScSCnTexCommand::default_command_separator = ";";
std::stack<std::string> ScSCnTexCommand::current_env;

std::string ScSCnTexCommand::StartLine(ScSCnCommandsHistory & history)
{
  std::string current_command, prev_command;
  std::string env = current_env.top();
  if (history.size() > 0)
  {
    current_command = history.at(history.size() - 1);
    if (history.size() > 1)
      prev_command = history.at(history.size() - 2);
  }
  else
    return "";
  if (current_command == "scnheader")
    return ";;\n";
  if (current_command == "scnstructheader")
    return ";;\n\n";
  if (prev_command == "begin")
  {
    if (env == "scnrelfromset")
      default_command_separator = ";;";
    else if (env == "scnrelfromvector")
      default_command_separator = ";;";
    else if (env == "scnreltoset")
      default_command_separator = ";;";
    else if (env == "scnreltovector")
      default_command_separator = ";;";
    else if (env == "scnhaselementset")
      default_command_separator = ";;";
    else if (env == "scnhaselementvector")
      default_command_separator = ";;";
    else if (env == "scnhassubstruct")
      default_command_separator = ";;";
    else if (env == "scnhassubset")
      default_command_separator = ";;";
    return "";
  }
  else if (prev_command == "end")
  {
    if (env == "scnrelfromset")
      default_command_separator = ";;";
    if (env == "scnrelfromvector")
      default_command_separator = ";;";
    else if (env == "scnreltoset")
      default_command_separator = ";;";
    else if (env == "scnreltovector")
      default_command_separator = ";;";
    else if (env == "scnhaselementset")
      default_command_separator = ";;";
    else if (env == "scnhaselementvector")
      default_command_separator = ";;";
    else if (env == "scnhassubstruct")
      default_command_separator = ";;";
    else if (env == "scnhassubset")
      default_command_separator = ";;";
    else default_command_separator = ";";
  }
    
  return default_command_separator;
}
