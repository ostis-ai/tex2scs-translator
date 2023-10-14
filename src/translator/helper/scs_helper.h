#pragma once

#include <string>
#include <sstream>
#include <iostream>

#include <functional>
#include <unordered_set>

class SCsHelper
{
public:
  static std::string GetNodeTypeByIdtf(std::string const & idtf)
  {
    char lastSymb = idtf.at(idtf.size() - 1);

    if (lastSymb == '*')
      return scNodeNoRoleRelation;
    else if (lastSymb == '\'')
      return scNodeRoleRelation;

    char firstSymb = idtf.at(0);

    if (std::islower(firstSymb))
      return scNodeClass;
    else
      return scNode;
  }

  static std::string NoRole(std::string const & idtf)
  {
    return idtf + "*";
  }

  static std::string Role(std::string const & idtf)
  {
    return idtf + "'";
  }

  static std::string File(std::string const & idtf)
  {
    return "[<p>" + idtf + "</p>]";
  }

  static bool IsFile(std::string const & string)
  {
    return (string.find('[') != std::string::npos) || (string.rfind("![") != std::string::npos);
  }

  static std::string Url(std::string const & idtf)
  {
    return "\"file://" + idtf + "\"";
  }

  static std::string FileClass(std::string const & idtf)
  {
    return "![" + idtf + "]!";
  }

  static bool IsURL(std::string const & string)
  {
    return string.find("\"file://") != std::string::npos;
  }

  static bool IsNoNamed(std::string const & string)
  {
    return string == "...";
  }

  static std::string GetFormat(std::string const & string)
  {
    size_t const pos = string.rfind('.');
    if (pos == std::string::npos)
      return "=> nrel_format: format_png";

    std::string fileExt = string.substr(pos + 1, string.size() - pos - 2);
    if (fileExt.at(fileExt.size() - 1) == '\"')
      fileExt = fileExt.substr(0, fileExt.size() - 1);
    return "=> nrel_format: format_" + fileExt;
  }

  static std::string scNode;
  static std::string scNodeNoRoleRelation;
  static std::string scNodeRoleRelation;
  static std::string scNodeClass;
  static std::string scNodeStruct;
};


