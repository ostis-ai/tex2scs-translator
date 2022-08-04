#include "sc_scn_tex_file_item_command.h"

ScScnTexCommandResult ScSCnTexFileItemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & content = tree.Add(params.at(0));

  ScStringStream stream;
  stream << "[<p>" << content << "</p>]" << EndLine();

  return stream;
}