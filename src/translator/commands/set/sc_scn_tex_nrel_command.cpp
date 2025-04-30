#include "sc_scn_tex_nrel_command.h"

#include "../../helper/scs_helper.h"

/// 0: <command_name> 1: <relation>? 2: <subject>
ScSCnTexCommandResult ScSCnTexNRelCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & relationType = params.at(COMMAND_TYPE);
  bool isRoleRelation = relationType.find("role") != std::string::npos;

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

      auto const GetConnectorType = [&]() -> std::string {
        return attrs.at(CONNECTOR_ATTR_POS);
      };

      auto const GetRelationIdentifier = [&]() -> std::string {
        std::string const relationIdentifier =
          params.size() == MAX_PARAMS
          ? (isRoleRelation
            ? SCsHelper::Role(params.at(RELATION_PARAM_POS))
            : SCsHelper::NoRole(params.at(RELATION_PARAM_POS)))
          : (attrs.size() == MAX_RELATION_ATTRS
            ? attrs.at(RELATION_ATTR_POS)
            : "");

        return relationIdentifier.empty()
          ? relationIdentifier
          : (isRoleRelation
            ? tree.Add(relationIdentifier, SCsHelper::scNodeRoleRelation)
            : tree.Add(relationIdentifier, SCsHelper::scNodeNonRoleRelation));
      };

      auto const GetRelModifierSign = [&]() -> std::string {
        return attrs.size() == MAX_RELATION_ATTRS_WITH_RELATION_MODIFIER
          ? attrs.at(RELATION_MODIFIER_ATTR_POS)
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
                : tree.Add(object, SCsHelper::GetNodeTypeWithAdditionalClasses(object))
              : SCsHelper::Url(object)
            : SCsHelper::FileClass(object)
          : SCsHelper::File(object);
      };

      std::string const object = GetObject();

      stream
      .Formatted([&]() -> SCsStream {
        std::string const relationIdentifier = GetRelationIdentifier();
        if (relationIdentifier.empty())
          return { GetConnectorType(), " ", object };
        else
          return { GetConnectorType(), " ", relationIdentifier, GetRelModifierSign(), " ", object };
      });

      if (SCsHelper::IsFile(object))
        stream.Attached("<- lang_ru", "=> nrel_format: format_html");
      else if (SCsHelper::IsURL(object))
        stream.Attached("<- concept_file", SCsHelper::GetFormat(object));
      stream.SetCurrentCommand(relationType);
  });
}
