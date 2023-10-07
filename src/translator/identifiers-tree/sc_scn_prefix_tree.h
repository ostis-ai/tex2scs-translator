#pragma once

#include <string>
#include <unordered_map>

#include "../commands/sc_scn_tex2scs_translations.h"
#include "../stream/scs_stream.h"

class ScSCnPrefixTree
{
public:
  static ScSCnPrefixTree * GetInstance();

  std::string Add(std::string const & key, std::string const & nodeType);

  std::string Get(std::string const & key);

  void SetNewElementNumber(size_t elementSysId);

  std::string GetFreeElementSystemIdentifier();

  std::string Dump() const;

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
