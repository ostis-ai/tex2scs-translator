#include "sc_scn_tex_file_item_command.h"

#include "../../helper/scs_helper.h"

ScScnTexCommandResult ScSCnTexFileItemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & content = params.at(params.size() - 1);

  return SCsStream().Row([&content]() -> SCsStream {
    return { SCsHelper::File(content) };
  });
}
