#include "sc_scn_tex_begin_list_command.h"

ScScnTexCommandResult ScSCnTexBeginListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & type = params.at(0);

  ScStringStream stream;

  if (type == "scnitemize")
    stream << "\n<ul>\n";
  else if (type == "scnnumerize")
    stream << "\n<ol>\n";
  else if (type == "scnindent")
  {
    stream << " (*\n";
    offset += "\t";
  }
  else if (type == "scnhaselementset")
  {
    stream << ";" << offset << "->\n{\n";
    offset += "\t";
  }

  return stream;
}
