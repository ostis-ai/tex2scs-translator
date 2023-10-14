#include "scs_helper.h"

std::string SCsHelper::scNode{"sc_node"};
std::string SCsHelper::scNodeNoRoleRelation{"sc_node_norole_relation"};
std::string SCsHelper::scNodeRoleRelation{"sc_node_role_relation"};
std::string SCsHelper::scNodeClass{"sc_node_class"};
std::string SCsHelper::scNodeStruct{"sc_node_struct"};

std::string SCsHelper::GetNodeTypeByIdtf(std::string const & idtf)
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

std::string SCsHelper::NoRole(std::string const & idtf)
{
  return idtf + "*";
}

std::string SCsHelper::Role(std::string const & idtf)
{
  return idtf + "'";
}

std::string SCsHelper::File(std::string const & idtf)
{
  return "[<p>" + idtf + "</p>]";
}

bool SCsHelper::IsFile(std::string const & string)
{
  return (string.find('[') != std::string::npos) || (string.rfind("![") != std::string::npos);
}

std::string SCsHelper::Url(std::string const & idtf)
{
  return "\"file://" + idtf + "\"";
}

std::string SCsHelper::FileClass(std::string const & idtf)
{
  return "![" + idtf + "]!";
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
