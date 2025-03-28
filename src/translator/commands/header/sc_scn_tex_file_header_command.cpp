#include "sc_scn_tex_file_header_command.h"

#include "translator/helper/scs_helper.h"

ScScnTexCommandResult ScSCnTexFileHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & text = params.at(1);

  return SCsStream()
    .PreFormatted()
    .SetCurrentCommand(params.at(0))
    .Formatted([&text]() -> SCsStream {
      return { SCsHelper::File(text) };
    });
}
