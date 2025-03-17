#include "sc_scn_tex_keyword_command.h"

ScScnTexCommandResult ScSCnTexKeywordCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & idtf = params.at(1);

  return SCsStream().Row([&idtf]() -> SCsStream {
    return { idtf };
  });
}
