#include "sc_scn_tex_begin_list_command.h"

#include "../../helper/scs_helper.h"

/// 0: begin 1: <command_name> 2: <relation>?
ScSCnTexCommandResult ScSCnTexBeginListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & relationSetType = params.at(COMMAND_TYPE_POS);

  auto const & ignItem = m_ignoredTypes.find(relationSetType);
  if (ignItem != m_ignoredTypes.cend())
    return "";

  if (relationSetType.find("scnitemize") != std::string::npos)
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
      .PreFormatted();
  else if (relationSetType == "scnset")
    return SCsStream()
      .PreFormatted()
      .SetCurrentCommand("listbegin")
      .Formatted([]() -> SCsStream { return { "{" }; })
      .AddTab();

  auto const & item = m_setTypes.find(relationSetType);
  if (item == m_setTypes.cend())
    return "";

  return SCsStream()
    .PreFormatted()
    .Row([&](SCsStream & stream) {
      auto const attrs = item->second;

      auto const GetConnectorType = [&]() -> std::string {
        return attrs[CONNECTOR_ATTR_POS];
      };

      auto const GetRelationIdentifier = [&]() -> std::string {
        std::string const relationIdentifier = params.size() == MAX_PARAMS
          ? SCsHelper::NoRole(params.at(RELATION_PARAM_POS))
          : attrs.size() == MAX_RELATION_ATTRS
            ? attrs.at(RELATION_ATTR_POS)
            : "";

          return relationIdentifier.empty()
            ? relationIdentifier
            : tree.Add(relationIdentifier, SCsHelper::scNodeNonRoleRelation);
      };

      auto const GetRelModifierSign = [&]() -> std::string {
        return attrs.size() == MAX_RELATION_ATTRS_WITH_RELATION_MODIFIER
         ? attrs.at(RELATION_MODIFIER_ATTR_POS)
         : ":";
      };

      auto const GetBeginBracket = [&]() -> std::string {
        return attrs[BEGIN_BRACKET_POS];
      };

      std::string const beginBracket = GetBeginBracket();

      stream
      .SetCurrentCommand(beginBracket.empty() ? "lb" : beginBracket)
      .Formatted([&]() -> SCsStream {
        std::string const relationIdentifier = GetRelationIdentifier();
        if (relationIdentifier.empty())
          return { GetConnectorType(), " ", beginBracket };
        else
          return { GetConnectorType(), " ", relationIdentifier, GetRelModifierSign(), " ", beginBracket };
      });
    })
    .AddTab();
}
