#include "sc_scn_tex_file_item_command.h"

#include "translator/helper/scs_helper.h"

ScSCnTexCommandResult ScSCnTexFileItemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & name = params.at(0);
  std::string const & content = params.at(params.size() - 1);

  return SCsStream()
    .PreFormatted()
    .SetCurrentCommand(name)
    .Row([&](SCsStream & stream) {
      stream
      .Formatted([&content]() -> SCsStream {
          return { SCsHelper::File(content) };
      });
      stream.Attached("<- lang_ru", "=> nrel_format: format_html");
    });
}
