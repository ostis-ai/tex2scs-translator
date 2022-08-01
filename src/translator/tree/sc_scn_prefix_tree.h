#pragma once

#include "unordered_map"

#include "../commands/sc_scn_tex2scs_translations.h"

class ScSCnPrefixTree
{
public:
  ScSCnPrefixTree()
  {
    m_instance = translations;
  }

  std::string Add(std::string const & key)
  {
    auto const & item = m_instance.find(key);
    if (item != m_instance.end())
      return item->second;

    m_instance.insert({key, key}); // todo: implement addr creating

    return key;
  }

private:
  std::string cached;
  ScSCnTexTranslations m_instance;
};
