#include "sc_scn_tex_end_set_command.h"

ScScnTexCommandResult ScSCnTexEndSetCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  return SCsStream().Formatted([](SCsStream & stream) -> SCsStream {
    return { ")" };
  });
}
