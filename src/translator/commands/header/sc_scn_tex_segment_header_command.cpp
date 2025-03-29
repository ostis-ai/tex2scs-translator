#include "sc_scn_tex_segment_header_command.h"

ScSCnTexCommandResult ScSCnTexSegmentHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  return ScSCnTexStructHeaderCommand::Complete(history, tree, params);
}
