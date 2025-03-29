#include "sc_scn_tex_header_command.h"

#include "translator/helper/scs_helper.h"

std::string ScSCnTexHeaderCommand::lastHeader;

ScScnTexCommandResult ScSCnTexHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & idtf = SCsHelper::RemoveHtmlTags(params.at(1));
  std::string const & systemIdtf = tree.Add(idtf, SCsHelper::GetNodeTypeByIdtf(idtf));
  lastHeader = idtf;

  return SCsStream()
    .PreFormatted()
    .SetCurrentCommand(params.at(0))
    .Formatted([&systemIdtf]() -> SCsStream {
      return { systemIdtf };
    });
}
