#include "sc_scn_tex_struct_header_local_command.h"

ScScnTexCommandResult ScSCnTexStructHeaderLocalCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & idtf = params.at(0);
  std::string const & subject = tree.Add(idtf);

  ScStringStream stream;

  stream << StartLine(history) << "\n" << offset << subject;
  stream << "\n" << offset << "<- sc_node_struct;";
  stream << "\n" << offset << "=> nrel_main_idtf: [" << idtf << "] (* <- lang_ru;; *)";

  return stream;
}
