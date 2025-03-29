#include "sc_scn_tex_section_header_command.h"

ScSCnTexCommandResult ScSCnTexSectionHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  return ScSCnTexStructHeaderCommand::Complete(history, tree, params);
}
