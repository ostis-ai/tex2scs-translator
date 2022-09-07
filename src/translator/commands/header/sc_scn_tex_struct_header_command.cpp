#include "sc_scn_tex_struct_header_command.h"

ScScnTexCommandResult ScSCnTexStructHeaderCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & idtf = params.at(0);
  std::string const & subject = tree.Add(idtf);

  ScStringStream stream;
  stream << StartLine(history) << "\n" << subject;
  stream << "\n<- sc_node_struct;";
  stream << "\n=> nrel_main_idtf: [" << idtf << "] (* <- lang_ru;; *)";

  return stream;
}
