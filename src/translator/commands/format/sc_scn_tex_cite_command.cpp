#include "sc_scn_tex_cite_command.h"

ScScnTexCommandResult ScSCnTexCiteCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::cout << params.at(1);
  return params.at(1);
}
