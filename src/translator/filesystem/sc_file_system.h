#pragma once

#include <string>
#include <unordered_set>
#include <queue>
#include <fstream>
#include <utility>
#include <filesystem>
#include <functional>

#include "../stream/sc_string_stream.h"

class ScFile
{
public:
  ScFile(std::string path)
    : m_path(std::move(path))
  {
  }

  [[nodiscard]] std::string GetPath() const
  {
    return m_path;
  }

  void Write(std::string const & text)
  {
    std::ofstream file;
    file.open(m_path, std::ios::app);

    file << text;

    file.close();
  }

  void Read(std::stringstream & text)
  {
    std::ifstream file;
    file.open(m_path);

    std::string line;
    while (std::getline(file, line))
      text << line + "\n";

    file.close();
  }

  [[nodiscard]] std::string GetName() const
  {
    std::string const & fileNameWithExt = m_path.substr(m_path.rfind('/') + 1, m_path.size());
    std::string const & fileName = fileNameWithExt.substr(0, fileNameWithExt.rfind('.'));
    return fileName;
  }

  [[nodiscard]] bool HasExtension(std::unordered_set<std::string> const & extensions) const
  {
    return extensions.find(m_path.substr(m_path.rfind('.'))) != extensions.cend();
  }

private:
  std::string m_path;
};

class ScDirectory
{
public:
  ScDirectory(std::string path);

  [[nodiscard]] std::string GetPath() const;

  static bool IsDirectory(std::string const & path);

  void RemoveDirectory();

  [[nodiscard]] ScFile CopyFile(std::string const & filePath, std::string const & newExtension) const;

  [[nodiscard]] ScFile CopyFile(ScFile const & file, std::string const & newExtension) const;

  [[nodiscard]] ScDirectory CopyDirectory(std::string nestedDirectoryPath, std::string const & targetDirectoryPath) const;

  [[nodiscard]] ScDirectory CopyDirectory(std::string const & nestedDirectoryPath, ScDirectory const & targetDirectory) const;

  [[nodiscard]] size_t CountFiles(std::unordered_set<std::string> const & extensions) const;

  [[nodiscard]] ScFile GetFileByName(std::string const & fileName) const;

  void ForEach(
      std::function<void(ScDirectory const & directory)> const & directoryCallback,
      std::function<void(ScFile const & file)> const & fileCallback);

private:
  std::string m_path;
  std::filesystem::directory_entry m_entry;

  std::string PathFiles(
      std::string const & workDirectory, std::string const & fileName) const;

  void PathFiles(
      std::string const & workDirectory, size_t & count, std::unordered_set<std::string> const & extensions) const;
};
