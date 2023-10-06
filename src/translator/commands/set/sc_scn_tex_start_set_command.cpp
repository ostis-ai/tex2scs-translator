#include "sc_scn_tex_start_set_command.h"

ScScnTexCommandResult ScSCnTexStartSetCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  return SCsStream()
  .PreFormatted()
  .Formatted([](SCsStream & stream) -> SCsStream {
    return { "{" };
  });
}
