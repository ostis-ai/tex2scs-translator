#include "sc_scn_tex_start_set_command.h"

ScSCnTexCommandResult ScSCnTexStartSetCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  return SCsStream()
  .PreFormatted()
  .Formatted([](SCsStream & stream) -> SCsStream {
    return { "{" };
  });
}
