#include "sc_scn_tex_nrel_command.h"

#include "../../helper/scs_helper.h"

/// 0: <command_name> 1: <relation>? 2: <subject>
ScScnTexCommandResult ScSCnTexNRelCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relationType = params.at(COMMAND_TYPE);

  auto const & item = m_elementTypes.find(relationType);
  if (item == m_elementTypes.cend())
  {
    auto const & symbolItem = m_symbolTypes.find(relationType);
    if (symbolItem == m_symbolTypes.cend())
      return "";
    else
      return symbolItem->second.at(0);
  }

  return SCsStream()
    .PreFormatted()
    .SetCurrentCommand(relationType)
    .Row([&](SCsStream & stream) {
      auto const attrs = item->second;

      auto const GetEdgeType = [&]() -> std::string {
        return attrs.at(EDGE_ATTR_POS);
      };

      auto const GetRelIdtf = [&]() -> std::string {
        std::string const relIdtf =
          params.size() == MAX_PARAMS
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

      auto const GetObject = [&]() -> std::string {
        std::string const & object
          = params.size() == MAX_PARAMS
            ? params.at(MAX_OBJECT_PARAM_POS)
            : params.at(MIN_OBJECT_PARAM_POS);

        auto const & fileItem = m_fileTypes.find(relationType);
        auto const & fileClassItem = m_fileClassTypes.find(relationType);
        auto const & urlItem = m_urlTypes.find(relationType);
        return fileItem == m_fileTypes.cend()
          ? fileClassItem == m_fileClassTypes.cend()
            ? urlItem == m_urlTypes.cend()
              ? SCsHelper::IsURL(object) || SCsHelper::IsFile(object)
                ? object
                : tree.Add(object, SCsHelper::GetNodeTypeByIdtf(object))
              : SCsHelper::Url(object)
            : SCsHelper::FileClass(object)
          : SCsHelper::File(object);
      };

      std::string const object = GetObject();

      stream
      .Formatted([&]() -> SCsStream {
        std::string const relIdtf = GetRelIdtf();
        if (relIdtf.empty())
          return { GetEdgeType(), " ", object };
        else
          return { GetEdgeType(), " ", relIdtf, GetRelModifierSign(), " ", object };
      });

      if (SCsHelper::IsFile(object))
        stream.Attached("<- lang_ru", "=> nrel_format: format_html");
      else if (SCsHelper::IsURL(object))
        stream.Attached("<- concept_file", SCsHelper::GetFormat(object));
  });
}
