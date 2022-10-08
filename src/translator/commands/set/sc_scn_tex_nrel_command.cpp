#include "sc_scn_tex_nrel_command.h"

/// 0: <command_name> 1: <relation>? 2: <subject>
ScScnTexCommandResult ScSCnTexNRelCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relationSetType = params.at(0);

  auto const & item = m_elementTypes.find(relationSetType);
  if (item != m_elementTypes.cend())
  {
    std::string relIdtf = params.size() == 3 ? params.at(1) : "";
    std::string const & subject = params.size() == 3 ? params.at(2) : params.at(1);

    return SCsStream()
      .SetCurrentCommand(relationSetType)
      .Row([this, &relationSetType, &item, &tree, &relIdtf, &subject](SCsStream & stream) {
        std::string const & edge = item->second[0];

        if (relIdtf.empty())
          relIdtf = item->second.size() == 2 ? item->second[1] : "";

        if (relIdtf.empty())
          relIdtf = "";
        else
          relIdtf = tree.Add(relIdtf) + ": ";

        stream.Formatted([this, &relationSetType, &tree, &edge, &relIdtf, &subject]() -> SCsStream {
          auto const & item = m_fileTypes.find(relationSetType);
          if (item == m_fileTypes.cend())
            return { edge, " ", relIdtf , tree.Add(subject) };
          else
            return { edge, " ", relIdtf, "[<p>", subject, "</p>] (* <- lang_ru;; => nrel_format: format_html;; *)" };
        });
    });
  }

  return "";
}
