#include "sc_scn_tex_file_class_command.h"

#include "../../helper/scs_helper.h"

ScScnTexCommandResult ScSCnTexFileClassCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & content = params.at(params.size() - 1);

  return SCsStream().Row([&content]() -> SCsStream {
    return { SCsHelper::FileClass(content) };
  });
}
