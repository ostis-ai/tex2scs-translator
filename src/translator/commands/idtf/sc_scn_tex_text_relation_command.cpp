#include "sc_scn_tex_text_relation_command.h"
#include "../file/sc_scn_tex_file_long_command.h"

ScScnTexCommandResult ScSCnTexTextRelationCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScScnTexCommandParams newParams;
  newParams.push_back(params.at(params.size() - 2));
  ScSCnTexFileLongCommand subj_text;
  std::string subject = subj_text.Complete(history, tree, newParams);
  newParams = params;
  newParams.erase(newParams.end() - 1);
  newParams.insert(newParams.end() - 1, subject);
  
  return ScSCnTexNrelFromCommand::Complete(history, tree, newParams);
}
