#pragma once

#include "unordered_map"

#include "../commands/sc_scn_tex2scs_translations.h"

class ScSCnPrefixTree
{
public:
  static ScSCnPrefixTree * GetInstance()
  {
    if (m_instance == nullptr)
      m_instance = new ScSCnPrefixTree();

    return m_instance;
  }

  std::string Add(std::string const & key)
  {
    auto const & item = m_translations.find(key);
    if (item != m_translations.end())
      return item->second;

    std::string const & value = "system_element_" + std::to_string(index);
    m_translations.insert({key, value});

    ++index;

    return value;
  }

  std::string Get(std::string const & key)
  {
    auto const & item = m_translations.find(key);
    if (item != m_translations.end())
      return item->second;

    return "";
  }

protected:
  static ScSCnPrefixTree * m_instance;

  ScSCnPrefixTree()
  {
    m_instance = nullptr;
    index = 0;
    m_translations = translations;
  }

  ~ScSCnPrefixTree()
  {
    delete m_instance;
    m_instance = nullptr;
  }

private:
  long long index;
  ScSCnTexTranslations m_translations;
};
