#include "sc_scn_tex_header_command.h"

#include "translator/helper/scs_helper.h"

std::string ScSCnTexHeaderCommand::lastHeader;

ScSCnTexCommandResult ScSCnTexHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & identifier = SCsHelper::RemoveHtmlTags(params.at(1));
  std::string const & systemIdentifier = tree.Add(identifier, SCsHelper::GetNodeTypeWithAdditionalClasses(identifier));
  lastHeader = identifier;

  return SCsStream()
    .PreFormatted()
    .SetCurrentCommand(params.at(0))
    .Formatted([&systemIdentifier]() -> SCsStream {
      return { systemIdentifier };
    });
}
