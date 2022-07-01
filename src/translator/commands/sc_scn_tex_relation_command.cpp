#include "sc_scn_tex_relation_command.h"

#include <sstream>

ScScnTexCommandResult ScSCnTexRelationCommand::Complete(
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string subject = tree.Add(params.at(0));
  std::string relation = tree.Add(params.at(1));

  std::stringstream stream;

  std::string object;
  if (params.at(2) == "link")
    object = '[' + params.at(3) + ']';
  else
    object = tree.Add(params.at(3));

  stream << subject << " => " << relation << ": " << object << ";;";
  return stream.str();
}
