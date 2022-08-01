#include "sc_scn_tex_add_level_command.h"

ScScnTexCommandResult ScSCnTexAddLevelCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  int32_t number = std::stoi(params.at(0));

  ScStringStream stream;
  for (int i = 0; i < abs(number); ++i)
  {
    if (number < 0)
    {
      if (offset.size() > 1)
        offset = offset.substr(0, offset.size() - 1);
      else
        offset = "";
      stream << offset << "\t*)" << EndLine();
    }
    else
    {
      stream << "\n" << offset << "\t(*\n";
      offset += "\t";
    }
  }

  return stream;
}
