#include "sc_scn_tex_header_command.h"

ScScnTexCommandResult ScSCnTexHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & idtf = params.at(0);
  std::string const & subject = tree.Add(idtf);

  ScStringStream stream;
  if (!history.empty())
    stream << ";;\n\n";

  stream << subject;

  char lastSymb = subject.at(subject.size() - 1);
  if (lastSymb == '*')
    stream << "\n<- sc_node_norole_relation";
  else if (lastSymb == '\'')
    stream << "\n<- sc_node_role_relation";
  else
    stream << "\n<- sc_node_class";

  stream << ";\n=> nrel_main_idtf: [" << idtf << "] (* <- lang_ru;; )";

  return stream;
}
