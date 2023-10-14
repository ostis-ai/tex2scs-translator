#pragma once

#include <string>
#include <unordered_set>
#include "../filesystem/sc_file_system.h"

class ScSCnFileStructsTree
{
public:
  static ScSCnFileStructsTree * GetInstance();

  void Add(std::string const & filePath);

  void Dump(ScDirectory const & targetDirectory) const;

protected:
  static ScSCnFileStructsTree * m_instance;
  std::unordered_set<std::string> m_file_structs;

  ScSCnFileStructsTree()
  {
    m_instance = nullptr;
  }

  ~ScSCnFileStructsTree()
  {
    delete m_instance;
    m_instance = nullptr;
  }
};
