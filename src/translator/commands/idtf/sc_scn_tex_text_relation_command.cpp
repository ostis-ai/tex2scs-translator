#include "sc_scn_tex_text_relation_command.h"

#include <sstream>
#include <iostream>

ScScnTexCommandResult ScSCnTexTextRelationCommand::Complete(
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relation = tree.Add(params.at(0));
  std::string const & content = params.at(2);

  std::stringstream stream;
  stream << "=> " << relation << ": [" << content << "];;\n";

  return stream.str();
}
