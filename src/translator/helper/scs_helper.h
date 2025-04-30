#pragma once

#include <string>
#include <list>

class SCsHelper
{
public:
  static std::string scNode;
  static std::string scNodeNonRoleRelation;
  static std::string scNodeRoleRelation;
  static std::string scNodeClass;
  static std::string scNodeStructure;

  static std::string entityClass;

  static std::string GetNodeTypeByIdentifier(std::string const & identifier);

  static std::list<std::string> GetNodeAdditionalClassesByType(std::string const & type);

  static std::list<std::string> GetNodeTypeWithAdditionalClasses(std::string const & identifier);

  static std::string NoRole(std::string const & identifier);

  static std::string Role(std::string const & identifier);

  static std::string File(std::string const & identifier);

  static bool IsFile(std::string const & string);

  static void SetCurrentFile(std::string const & filePath);

  static std::string Url(std::string const & path);

  static std::string FileClass(std::string const & identifier);

  static bool IsURL(std::string const & string);

  static bool IsNoNamed(std::string const & string);

  static std::string GetFormat(std::string const & string);

  static std::string RemoveHtmlTags(std::string const & string);
private:
  static std::string m_currentFilePath;
  static std::string m_currentFileDirectoryName;
};

