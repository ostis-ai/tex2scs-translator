#pragma once

#include <string>

class SCsHelper
{
public:
  static std::string scNode;
  static std::string scNodeNonRoleRelation;
  static std::string scNodeRoleRelation;
  static std::string scNodeClass;
  static std::string scNodeStructure;

  static std::string GetNodeTypeByIdtf(std::string const & idtf);

  static std::string NoRole(std::string const & idtf);

  static std::string Role(std::string const & idtf);

  static std::string File(std::string const & idtf);

  static bool IsFile(std::string const & string);

  static void SetCurrentFile(std::string const & filePath);

  static std::string Url(std::string const & path);

  static std::string FileClass(std::string const & idtf);

  static bool IsURL(std::string const & string);

  static bool IsNoNamed(std::string const & string);

  static std::string GetFormat(std::string const & string);

  static std::string RemoveHtmlTags(std::string const & string);
private:
  static std::string m_currentFilePath;
  static std::string m_currentFileDirectoryName;
};

