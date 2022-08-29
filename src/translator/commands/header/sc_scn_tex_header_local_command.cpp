#include "sc_scn_tex_header_local_command.h"

ScScnTexCommandResult ScSCnTexHeaderLocalCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & idtf = params.at(0);
  std::string const & subject = tree.Add(idtf);
  lastHeader = idtf;

  ScStringStream stream;
  if (!history.empty())
    stream << ";;\n";

  stream << offset << subject;

  char lastSymb = subject.at(subject.size() - 1);
  if (lastSymb == '*')
    stream << "\n" << offset << "<- sc_node_norole_relation";
  else if (lastSymb == '\'')
    stream << "\n" << offset << "<- sc_node_role_relation";
  else if (std::islower(subject.at(0)))
    stream << "\n" << offset << "<- sc_node_class";
  else
    stream << "\n" << offset << "<- sc_node";

  stream << ";\n" << offset << "=> nrel_main_idtf: [" << idtf << "] (* <- lang_ru;; *)";

  return stream;
}
