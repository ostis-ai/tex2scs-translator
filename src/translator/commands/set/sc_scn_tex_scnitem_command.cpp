#include "sc_scn_tex_scnitem_command.h"

ScScnTexCommandResult ScSCnTexScnitemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & name = params.at(0);
  std::string subject = params.at(1);

  if (params.at(1)[0] != '[')
    subject = tree.Add(subject);

  return SCsStream()
    .SetCurrentCommand(name)
    .Formatted([&subject]() -> SCsStream {
      return { subject };
    });
}
