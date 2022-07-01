#include "sc_scn_tex_relation_command.h"

#include <sstream>

ScScnTexCommandResult ScSCnTexRelationCommand::Complete(
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string subject = tree.Add(params.at(0));
  std::string relation = tree.Add(params.at(2));

  std::stringstream stream;

  std::string object = params.at(4);
  if (params.at(3) == "link")
  {
    std::string link = '[' + object + ']';
    object = tree.Add(link);

    stream << object << " = " << link << ";;\n";
  }
  else
    object = tree.Add(object);

  stream << subject << "\n\t => " << relation << ": " << object << ";;\n";
  return stream.str();
}
