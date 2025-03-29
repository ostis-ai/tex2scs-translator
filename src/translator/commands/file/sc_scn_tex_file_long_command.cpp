#include "sc_scn_tex_file_long_command.h"

#include "translator/helper/scs_helper.h"

ScSCnTexCommandResult ScSCnTexFileLongCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string content = params.at(params.size() - 1);

  return SCsStream()
  .Row([&content]() -> SCsStream {
    return { SCsHelper::File(content) };
  });
}
