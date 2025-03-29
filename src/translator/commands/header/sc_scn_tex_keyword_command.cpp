#include "sc_scn_tex_keyword_command.h"

ScSCnTexCommandResult ScSCnTexKeywordCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & identifier = params.at(1);

  return SCsStream().Row([&identifier]() -> SCsStream {
    return { identifier };
  });
}
