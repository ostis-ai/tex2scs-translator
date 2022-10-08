#include "sc_scn_tex_segment_header_command.h"

ScScnTexCommandResult ScSCnTexSegmentHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  return ScSCnTexStructHeaderCommand::Complete(history, tree, params);
}
