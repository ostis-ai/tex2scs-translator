#pragma once

#include "unordered_map"

class ScSCnPrefixTree
{
public:
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
  std::unordered_map<std::string, std::string> m_instance;
};
