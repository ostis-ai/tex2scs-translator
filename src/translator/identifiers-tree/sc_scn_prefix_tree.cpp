#include "sc_scn_prefix_tree.h"

#include <unordered_map>

#include "translator/stream/scs_stream.h"

std::unique_ptr<ScSCnPrefixTree> ScSCnPrefixTree::m_instance;

ScSCnPrefixTree::ScSCnPrefixTree()
{
  index = 0;
  m_translations = translations;
}

ScSCnPrefixTree::~ScSCnPrefixTree() = default;

ScSCnPrefixTree & ScSCnPrefixTree::GetInstance()
{
  if (m_instance == nullptr)
    m_instance = std::unique_ptr<ScSCnPrefixTree>(new ScSCnPrefixTree());

  return *m_instance;
}

std::string ScSCnPrefixTree::Add(std::string const & key, std::string const & nodeType)
{
    return Add(key, std::list{nodeType});
}

std::string ScSCnPrefixTree::Add(std::string const & key, std::list<std::string> const & nodeTypeWithAdditionalClasses)
{
  auto const & it = m_translations.find(key);
  if (it != m_translations.end())
  {
    std::string const & identifier = it->second.first;
    std::string const & type = it->second.second.front();
    if (type == "sc_node")
      m_translations[it->first] = {identifier, nodeTypeWithAdditionalClasses};
    return identifier;
  } 

  std::string const & value = ".system_element_" + std::to_string(index);
  m_translations.insert({ key, { value, nodeTypeWithAdditionalClasses } });

  ++index;

  return value;
}

std::string ScSCnPrefixTree::Get(std::string const & key)
{
  auto const & item = m_translations.find(key);
  if (item != m_translations.end())
    return item->second.first;

  return "";
}

void ScSCnPrefixTree::SetNewElementNumber(size_t elementSysId)
{
  m_instance->index = elementSysId;
}

std::string ScSCnPrefixTree::GetFreeElementSystemIdentifier()
{
  return ".system_element_" + std::to_string(m_instance->index);
}

std::string ScSCnPrefixTree::Dump() const
{
  SCsStream stream;
  for (auto const & item : m_translations)
  {
    stream.Row([&item]() -> SCsStream {
      std::list<std::string> const & classesWithAdditionalTypes = item.second.second;

      std::string classesWithAdditionalTypesStr = item.second.first + " <- ";
      for (auto const & typeOrClass : classesWithAdditionalTypes)
        classesWithAdditionalTypesStr += typeOrClass + "; ";
      classesWithAdditionalTypesStr.pop_back();// we want ";;" after last element, not a "; ;"
      classesWithAdditionalTypesStr += ";\n";

      return { item.second.first, " => nrel_main_idtf: [", item.first, "] "
               "(* <- lang_ru;; => nrel_format: format_html;; *);;\n",
               classesWithAdditionalTypesStr, "\n" };
    });
  }
  return stream;
}
