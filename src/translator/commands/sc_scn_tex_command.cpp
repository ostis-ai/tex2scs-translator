#include "sc_scn_tex_command.h"

std::string ScSCnTexCommand::offset = "";
std::string ScSCnTexCommand::default_command_separator = ";";

std::string ScSCnTexCommand::StartLine(ScSCnCommandsHistory & history)
{
  std::string current_command;
  if (history.size() > 1)
    current_command = history.at(history.size() - 1);
  else
    return "";
  if (current_command == "scnheader")
    return ";;\n";
  if (current_command == "scnstructheader")
    return ";;\n\n";
  // if (prev_command == "begin")
  //   default_command_separator = "";
  // else if (prev_command == "end")
  //   default_command_separator = ";";
  
  return default_command_separator;
}
