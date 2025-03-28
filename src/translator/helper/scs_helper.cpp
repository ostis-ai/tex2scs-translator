#include "scs_helper.h"

#include <regex>
#include <sstream>
#include <functional>
#include <unordered_set>

std::string SCsHelper::scNode{"sc_node"};
std::string SCsHelper::scNodeNonRoleRelation{"sc_node_non_role_relation"};
std::string SCsHelper::scNodeRoleRelation{"sc_node_role_relation"};
std::string SCsHelper::scNodeClass{"sc_node_class"};
std::string SCsHelper::scNodeStructure{"sc_node_structure"};

std::string SCsHelper::entityClass{"entity_class"};

std::string SCsHelper::m_currentFilePath;
std::string SCsHelper::m_currentFileDirectoryName;

std::string SCsHelper::GetNodeTypeByIdentifier(std::string const & identifier)
{
  char lastSymbol = identifier.at(identifier.size() - 1);

  if (lastSymbol == '*')
    return scNodeNonRoleRelation;
  else if (lastSymbol == '\'')
    return scNodeRoleRelation;

  char firstSymbol = identifier.at(0);

  if (std::islower(firstSymbol))
    return scNodeClass;
  else
    return scNode;
}

std::list<std::string> SCsHelper::GetNodeAdditionalClassesByType(std::string const & type)
{
    if (type == scNodeClass)
        return {entityClass};

    return {};
}

std::list<std::string> SCsHelper::GetNodeTypeWithAdditionalClasses(std::string const & idtf)
{
    std::string type = GetNodeTypeByIdtf(idtf);
    std::list<std::string> additionalClasses = GetNodeAdditionalClassesByType(type);

    additionalClasses.emplace_front(type);
    return additionalClasses;
}

std::string SCsHelper::NoRole(std::string const & identifier)
{
  return identifier + "*";
}

std::string SCsHelper::Role(std::string const & identifier)
{
  return identifier + "'";
}

std::string SCsHelper::File(std::string const & identifier)
{
  return "[<p>" + identifier + "</p>]";
}

bool SCsHelper::IsFile(std::string const & string)
{
  return (string.find('[') != std::string::npos) || (string.rfind("![") != std::string::npos);
}

void SCsHelper::SetCurrentFile(std::string const & filePath)
{
  m_currentFilePath = filePath;
  std::string const & directoryPath = m_currentFilePath.substr(0, m_currentFilePath.rfind('/'));
  m_currentFileDirectoryName = directoryPath.substr(directoryPath.rfind('/') + 1);
}

std::string SCsHelper::Url(std::string const & path)
{
  std::string const & relativePath = path.find(m_currentFileDirectoryName) == std::string::npos
      ? path
      : path.substr(path.find(m_currentFileDirectoryName) + m_currentFileDirectoryName.size() + 1);

  return "\"file://" + relativePath + "\"";
}

std::string SCsHelper::FileClass(std::string const & identifier)
{
  return "![" + identifier + "]!";
}

bool SCsHelper::IsURL(std::string const & string)
{
  return string.find("\"file://") != std::string::npos;
}

bool SCsHelper::IsNoNamed(std::string const & string)
{
  return string == "...";
}

std::string SCsHelper::GetFormat(std::string const & string)
{
  size_t const pos = string.rfind('.');
  if (pos == std::string::npos)
    return "=> nrel_format: format_png";

  std::string fileExt = string.substr(pos + 1, string.size() - pos - 2);
  if (fileExt.at(fileExt.size() - 1) == '\"')
    fileExt = fileExt.substr(0, fileExt.size() - 1);
  return "=> nrel_format: format_" + fileExt;
}

std::string SCsHelper::RemoveHtmlTags(std::string const & string)
{
  std::regex htmlTagPattern("<[^>]*>");
  return std::regex_replace(string, htmlTagPattern, "");
}
