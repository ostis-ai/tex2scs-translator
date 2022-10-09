#include "sc_scn_tex_scnitem_command.h"

#include "../../helper/scs_helper.h"

ScScnTexCommandResult ScSCnTexScnitemCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & name = params.at(0);
  std::string object = params.at(1);

  if (!SCsHelper::IsFile(object) && !SCsHelper::IsURL(object) && !SCsHelper::IsNoNamed(object))
    object = tree.Add(object, SCsHelper::GetNodeTypeByIdtf(object));

  return SCsStream()
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
