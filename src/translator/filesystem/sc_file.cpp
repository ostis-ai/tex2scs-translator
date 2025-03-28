#include "translator/filesystem/sc_file.h"

#include <fstream>
#include <sstream>

ScFile::ScFile(std::string path)
  : m_path(std::move(path))
{
}

std::string ScFile::GetPath() const
{
  return m_path;
}

void ScFile::Write(std::string const & text)
{
  std::ofstream file;
  file.open(m_path, std::ios::trunc);

  file << text;

  file.close();
}

void ScFile::Read(std::stringstream & text) const
{
  std::ifstream file;
  file.open(m_path);

  std::string line;
  while (std::getline(file, line))
    text << line + "\n";

  file.close();
}

std::string ScFile::GetName() const
{
  std::string const & fileNameWithExt = m_path.substr(m_path.rfind('/') + 1);
  std::string const & fileName = fileNameWithExt.substr(0, fileNameWithExt.rfind('.'));
  return fileName;
}

std::string ScFile::GetExtension() const
{
  std::string const & fileNameWithExt = m_path.substr(m_path.rfind('/') + 1);
  std::string const & fileExt = fileNameWithExt.substr(fileNameWithExt.rfind('.'));
  return fileExt;
}

bool ScFile::HasExtension(std::unordered_set<std::string> const & extensions) const
{
  return extensions.find(GetExtension()) != extensions.cend();
}
