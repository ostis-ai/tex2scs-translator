#include "sc_scn_tex_file_scg_item_command.h"

ScScnTexCommandResult ScSCnTexFileSCgItemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & content = tree.Add(params.at(0));

  ScStringStream stream;
  stream << "\"" << content << "\"" << EndLine();

  return stream;
}
