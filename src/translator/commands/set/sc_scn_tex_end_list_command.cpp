#include "sc_scn_tex_end_list_command.h"

/// 0: end 1: <command_name> 2: <relation>?
ScScnTexCommandResult ScSCnTexEndListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relationSetType = params.at(1);

  if (relationSetType == "scnitemize")
    return SCsStream()
      .Row([]() -> SCsStream { return { "</li>" };})
      .RemoveTab()
      .Offset([]() -> SCsStream { return { "<ul>" };});
  else if (relationSetType == "scnnumerize")
    return SCsStream()
      .Row([]() -> SCsStream { return { "</li>" };})
      .RemoveTab()
      .Offset([]() -> SCsStream { return { "<ol>" };});
  else if (relationSetType == "scnindent")
    return SCsStream()
      .SetCurrentCommand("*)")
      .RemoveTab()
      .Formatted([]() -> SCsStream { return { "*)" }; });

  auto const & item = m_setTypes.find(relationSetType);
  if (item != m_setTypes.cend()) {
    return SCsStream()
      .RemoveTab()
      .Row([&item](SCsStream & stream) {
        std::string const & endBracket = item->second[2];

        stream
        .SetCurrentCommand(endBracket.empty() ? "le" : endBracket)
        .Formatted([&endBracket]() -> SCsStream {
          return { endBracket };
        });
      });
  }

  return "";
}
