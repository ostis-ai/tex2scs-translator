#pragma once

#include <string>
#include <unordered_set>

class ScDirectory;

class ScSCnFileStructsTree
{
public:
  static ScSCnFileStructsTree * GetInstance();

  void Add(std::string const & filePath);

  void Dump(ScDirectory const & targetDirectory) const;

protected:
  static ScSCnFileStructsTree * m_instance;
  std::unordered_set<std::string> m_file_structs;

  ScSCnFileStructsTree();

  ~ScSCnFileStructsTree();
};
