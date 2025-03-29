#include "sc_scn_tex_current_name_command.h"

ScSCnTexCommandResult ScSCnTexCurrentNameCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  return lastHeader;
}
