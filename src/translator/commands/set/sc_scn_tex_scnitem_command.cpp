#include "sc_scn_tex_scnitem_command.h"

#include "translator/helper/scs_helper.h"

ScSCnTexCommandResult ScSCnTexSCnItemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & name = params.at(0);
  std::string object = SCsHelper::RemoveHtmlTags(params.at(1));

  if (!SCsHelper::IsFile(object) && !SCsHelper::IsURL(object) && !SCsHelper::IsNoNamed(object))
    object = tree.Add(object, SCsHelper::GetNodeTypeByIdentifier(object));

  return SCsStream()
    .PreFormatted()
    .SetCurrentCommand(name)
    .Row([&](SCsStream & stream) {
      stream
      .Formatted([&object]() -> SCsStream {
          return { object };
      });

      if (SCsHelper::IsFile(object))
        stream.Attached("<- lang_ru", "=> nrel_format: format_html");
      else if (SCsHelper::IsURL(object))
        stream.Attached("<- concept_file", SCsHelper::GetFormat(object));
    });
}
