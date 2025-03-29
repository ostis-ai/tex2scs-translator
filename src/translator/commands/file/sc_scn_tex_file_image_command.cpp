#include "sc_scn_tex_file_image_command.h"

#include "translator/helper/scs_helper.h"

ScSCnTexCommandResult ScSCnTexFileImageCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & content = params.at(params.size() - 1);

  return SCsStream().Row([&content]() -> SCsStream {
    return { SCsHelper::Url(content) };
  });
}
