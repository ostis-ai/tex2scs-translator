#include "sc_scn_tex_text_relation_command.h"

ScScnTexCommandResult ScSCnTexTextRelationCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relation = tree.Add(params.at(0));
  std::string const & content = params.at(2);

  ScStringStream stream;
  stream << StartLine() << offset << "=> " << relation
         << ": [<p>" << content << "</p>] (* <- lang_ru;; => nrel_format: format_html;; *)" << EndLine();

  return stream;
}
