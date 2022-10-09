#include "sc_scn_tex_begin_list_command.h"

#include "../../helper/scs_helper.h"

/// 0: begin 1: <command_name> 2: <relation>?
ScScnTexCommandResult ScSCnTexBeginListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relationSetType = params.at(COMMAND_TYPE_POS);

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
      .Formatted([]() -> SCsStream { return { "(*" }; });

  auto const & item = m_setTypes.find(relationSetType);
  if (item == m_setTypes.cend())
    return "";

  return SCsStream()
    .Row([&](SCsStream & stream) {
      auto const attrs = item->second;

      auto const GetEdgeType = [&]() -> std::string {
        return attrs[EDGE_ATTR_POS];
      };

      auto const GetRelIdtf = [&]() -> std::string {
        std::string const relIdtf = params.size() == MAX_PARAMS
          ? SCsHelper::NoRole(params.at(REL_PARAM_POS))
          : attrs.size() == MAX_REL_ATTRS
            ? attrs.at(REL_ATTR_POS)
            : "";

          return relIdtf.empty()
            ? relIdtf
            : tree.Add(relIdtf, SCsHelper::scNodeNoRoleRelation);
      };

      auto const GetRelModifierSign = [&]() -> std::string {
        return attrs.size() == MAX_REL_ATTRS_WITH_REl_MODIFIER
         ? attrs.at(REL_MODIFIER_ATTR_POS)
         : ":";
      };

      auto const GetBeginBracket = [&]() -> std::string {
        return attrs[BEGIN_BRACKET_POS];
      };

      std::string const beginBracket = GetBeginBracket();

      stream
      .SetCurrentCommand(beginBracket.empty() ? "lb" : beginBracket)
      .Formatted([&]() -> SCsStream {
        std::string const relIdtf = GetRelIdtf();
        if (relIdtf.empty())
          return { GetEdgeType(), " ", beginBracket };
        else
          return { GetEdgeType(), " ", relIdtf, GetRelModifierSign(), " ", beginBracket };
      });
    })
    .AddTab();
}
