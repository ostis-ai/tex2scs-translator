#include "sc_scn_prefix_tree.h"

ScSCnPrefixTree * ScSCnPrefixTree::m_instance;

ScSCnPrefixTree * ScSCnPrefixTree::GetInstance()
{
  if (m_instance == nullptr)
    m_instance = new ScSCnPrefixTree();

  return m_instance;
}

std::string ScSCnPrefixTree::Add(std::string const & key, std::string const & nodeType)
{
  auto const & item = m_translations.find(key);
  if (item != m_translations.end())
    return item->second.first;

  std::string const & value = ".system_element_" + std::to_string(index);
  m_translations.insert({ key, { value, nodeType } });

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
      return { item.second.first, " => nrel_main_idtf: [", item.first, "] "
                                                                       "(* <- lang_ru;; => nrel_format: format_html;; *);;\n",
               item.second.first, " <- ", item.second.second, ";;\n\n" };
    });
  }
  return stream;
}
