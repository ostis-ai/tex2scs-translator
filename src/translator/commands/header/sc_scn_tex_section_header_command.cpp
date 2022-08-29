#include "sc_scn_tex_section_header_command.h"

ScScnTexCommandResult ScSCnTexSectionHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  return ScSCnTexStructHeaderCommand::Complete(history, tree, params);
}
