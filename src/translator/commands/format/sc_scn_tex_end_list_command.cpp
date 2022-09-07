#include "sc_scn_tex_end_list_command.h"

ScScnTexCommandResult ScSCnTexEndListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & type = params.at(0);

  ScStringStream stream;

  if (type == "scnitemize")
    stream << "</ul>\n";
  else if (type == "scnnumerize")
    stream << "</ol>\n";
  else if (type == "scnindent")
  {
    offset = offset.substr(0, offset.size() - 1);
    stream << "\n" << offset << "*)";
  }
  else if (type == "scnhaselementset")
  {
    stream << "\n" << offset << "}";
  }
  return stream;
}
