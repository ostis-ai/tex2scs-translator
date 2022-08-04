#include "sc_scn_tex_file_image_command.h"

ScScnTexCommandResult ScSCnTexFileImageCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & content = params.at(0);

  ScStringStream stream;
  stream << "\"" << content << "\"" << EndLine();

  return stream;
}
