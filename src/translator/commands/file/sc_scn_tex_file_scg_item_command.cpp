#include "sc_scn_tex_file_scg_item_command.h"

ScScnTexCommandResult ScSCnTexFileSCgItemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & content = params.at(1);

  return SCsStream().Row([&content]() -> SCsStream {
    return {"\"", content, "\""};
  });
}
