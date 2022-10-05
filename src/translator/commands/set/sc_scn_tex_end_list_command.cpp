#include "sc_scn_tex_end_list_command.h"

ScScnTexCommandResult ScSCnTexEndListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relationSetType = params.at(0);

  SCsStream::RemoveTab();

  if (relationSetType == "scnitemize")
    return "\n</ul>\n";
  else if (relationSetType == "scnnumerize")
    return "\n</ol>\n";
  else if (relationSetType == "scnindent")
    return SCsStream().Formatted([]() { return "\n*);\n"; });

  std::string const & relIdtf = params.size() > 2 ? params.at(1) : "";

  return SCsStream().Row([this, &relationSetType](SCsStream & stream) -> SCsStream {
    auto const & item = m_setTypes.find(relationSetType);

    if (item != m_setTypes.cend()) {
      std::string endBracket = item->second[2];

      stream.Formatted([&endBracket]() -> SCsStream {
        return { "\n", endBracket, ";\n" };
      });
    }
  });
}
