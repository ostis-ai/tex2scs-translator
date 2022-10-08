#include "sc_scn_tex_current_name_command.h"

ScScnTexCommandResult ScSCnTexCurrentNameCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  return lastHeader;
}
