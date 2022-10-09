#include "sc_scn_tex_file_long_command.h"

#include "../../helper/scs_helper.h"

ScScnTexCommandResult ScSCnTexFileLongCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string content = params.at(params.size() - 1);

  return SCsStream().Tabulated([&content](SCsStream & stream) {
    stream.Row([&content]() -> SCsStream {
      return { SCsHelper::File(content) };
    });
  });
}
