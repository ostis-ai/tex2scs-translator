#pragma once

#include <string>

#include "translator/commands/sc_scn_tex2scs_translations.h"

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

  ScSCnPrefixTree();

  ~ScSCnPrefixTree();

private:
  long long index;
  ScSCnTexTranslations m_translations;
};
