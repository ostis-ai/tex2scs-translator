#include "sc_scn_tex_file_long_command.h"

ScScnTexCommandResult ScSCnTexFileLongCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string content = params.at(1);

  return SCsStream().Tabulated([&content](SCsStream & stream) {
    stream.Row([&content]() -> SCsStream {
      return { "[<p>", content, "</p>] (* <- lang_ru;; => nrel_format: format_html;; *)" };
    });
  });
}
