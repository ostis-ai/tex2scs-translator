#include "sc_scn_tex_begin_list_command.h"

ScScnTexCommandResult ScSCnTexBeginListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relationSetType = params.at(0);

  if (relationSetType == "scnitemize")
    return "\n<ul>\n";
  else if (relationSetType == "scnnumerize")
    return "\n<ol>\n";
  else if (relationSetType == "scnindent")
    return SCsStream().Formatted([]() { return "\n(*\n"; });

  std::string relIdtf = params.size() > 2 ? params.at(2) : "";

  auto const & item = m_setTypes.find(relationSetType);
  if (item != m_setTypes.cend())
  {
    return SCsStream().Row([&item, &tree, &relIdtf](SCsStream &stream) -> SCsStream {
      std::string const & edge = item->second[0];
      std::string beginBracket = item->second[1];

      if (relIdtf.empty())
        relIdtf = item->second.size() > 3 ? item->second[3] : "";

      stream.Formatted([&tree, &edge, &beginBracket, &relIdtf]() -> SCsStream {
        return { edge, " ", beginBracket, " ", tree.Add(relIdtf), ": \n" };
      });

      SCsStream::AddTab();
    });
  }

  return "";
}
