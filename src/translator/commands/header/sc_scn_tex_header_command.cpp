#include "sc_scn_tex_header_command.h"

std::string ScSCnTexHeaderCommand::lastHeader;

ScScnTexCommandResult ScSCnTexHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & idtf = params.at(1);
  std::string const & systemIdtf = tree.Add(idtf);
  lastHeader = idtf;

  return SCsStream()
    .SetCurrentCommand(params.at(0))
    .Formatted([&systemIdtf]() -> SCsStream {
      return { systemIdtf };
    })
    .SetCurrentCommand()
    .Formatted([this, &idtf]() -> SCsStream {
      return { "<- ", DefineNodeTypeByIdtf(idtf) };
    })
    .SetCurrentCommand()
    .Formatted([&idtf]() -> SCsStream {
      return { "=> nrel_main_idtf: [", idtf, "] (* <- lang_ru;; *)" };
    });
}

std::string ScSCnTexHeaderCommand::DefineNodeTypeByIdtf(std::string const & idtf)
{
  char lastSymb = idtf.at(idtf.size() - 1);

  if (lastSymb == '*')
    return "sc_node_norole_relation";
  else if (lastSymb == '\'')
    return "sc_node_role_relation";

  char firstSymb = idtf.at(0);

  if (std::islower(firstSymb))
    return "sc_node_class";
  else
    return "sc_node";
}
