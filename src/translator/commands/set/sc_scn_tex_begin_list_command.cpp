#include "sc_scn_tex_begin_list_command.h"

/// 0: begin 1: <command_name> 2: <relation>?
ScScnTexCommandResult ScSCnTexBeginListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relationSetType = params.at(1);

  auto const & ignItem = m_ignoredTypes.find(relationSetType);
  if (ignItem != m_ignoredTypes.cend())
    return "";

  if (relationSetType == "scnitemize")
    return SCsStream()
      .Offset([]() -> SCsStream { return { "<ul>" }; })
      .AddTab()
      .Offset([]() -> SCsStream { return { "<li>" }; });
  else if (relationSetType == "scnnumerize")
    return SCsStream()
      .Offset([]() -> SCsStream { return { "<ol>" }; })
      .AddTab()
      .Offset([]() -> SCsStream { return { "<li>" }; });
  else if (relationSetType == "scnindent")
    return SCsStream()
      .SetCurrentCommand("(*")
      .Formatted([]() -> SCsStream { return { "(*" }; })
      .AddTab();

  std::string relIdtf = params.size() > 2 ? params.at(2) : "";

  auto const & item = m_setTypes.find(relationSetType);
  if (item != m_setTypes.cend())
  {
    return SCsStream()
      .Row([&item, &tree, &relIdtf](SCsStream &stream) {
        std::string const & edge = item->second[0];
        std::string const & beginBracket = item->second[1];

        if (relIdtf.empty())
          relIdtf = item->second.size() == 4 ? item->second[3] : "";

        stream
        .SetCurrentCommand(beginBracket.empty() ? "lb" : beginBracket)
        .Formatted([&tree, &edge, &beginBracket, &relIdtf]() -> SCsStream {
          if (relIdtf.empty())
            return { edge, " ", beginBracket };
          else
            return { edge, " ", tree.Add(relIdtf), ": ", beginBracket };
        });
      })
      .AddTab();
  }

  return "";
}
