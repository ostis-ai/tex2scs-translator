#include "sc_scn_tex_end_list_command.h"

/// 0: end 1: <command_name> 2: <relation>?
ScSCnTexCommandResult ScSCnTexEndListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & relationSetType = params.at(COMMAND_TYPE_POS);

  if (relationSetType.find("scnitemize") != std::string::npos)
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
      .PreFormatted([](SCsStream & stream) {});
  else if (relationSetType == "scnset")
    return SCsStream()
      .SetCurrentCommand("listend")
      .RemoveTab()
      .Formatted([]() -> SCsStream { return { "}" }; });

  auto const & item = m_setTypes.find(relationSetType);
  if (item == m_setTypes.cend())
    return "";

  return SCsStream()
    .PreFormatted([&](SCsStream & stream) {
      auto const attrs = item->second;

      auto const GetEndBracket = [&]() -> std::string {
        return attrs[END_BRACKET_POS];
      };

      std::string const endBracket = GetEndBracket();

      stream
      .RemoveTab()
      .SetCurrentCommand(endBracket.empty() ? "le" : endBracket)
      .Formatted([&]() -> SCsStream {
        return { endBracket };
      });
    });
}
