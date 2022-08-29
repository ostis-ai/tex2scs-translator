#include "sc_scn_tex_end_list_command.h"

ScScnTexCommandResult ScSCnTexEndListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & type = params.at(0);

  ScStringStream stream;
  stream << "<li>\n" << offset;

  if (type == "scnitemize")
    stream << "</ul>\n";
  else if (type == "scnnumerize")
    stream << "</ol>\n";
  else if (type == "scnindent")
  {
    stream << "\n" << offset << "*)";
    offset = offset.substr(0, offset.size() - 1);
  }

  return stream;
}
