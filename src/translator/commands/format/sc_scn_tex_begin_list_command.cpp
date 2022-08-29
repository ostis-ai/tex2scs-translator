#include "sc_scn_tex_begin_list_command.h"

ScScnTexCommandResult ScSCnTexBeginListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & type = params.at(0);

  ScStringStream stream;
  stream << "\n" << offset;

  if (type == "scnitemize")
    stream << "<ul>\n";
  else if (type == "scnnumerize")
    stream << "<ol>\n";
  else if (type == "scnindent")
  {
    offset += "\t";
    stream << offset << "(*\n";
  }

  return stream;
}
