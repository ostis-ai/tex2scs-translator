#include "sc_scn_tex_scnitem_command.h"

ScScnTexCommandResult ScSCnTexScnitemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScStringStream stream;
  std::string subject;
  if (params.at(0)[0] == '[')
    subject = params.at(0);
  else
    subject = tree.Add(params.at(0));

  return SCsStream().Formatted([&subject]() -> SCsStream {
    return { subject, ";\t" };
  });
}
