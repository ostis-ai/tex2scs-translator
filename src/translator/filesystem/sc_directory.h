#pragma once

#include <string>
#include <unordered_set>
#include <filesystem>
#include <functional>

class ScFile;

class ScDirectory
{
public:
  ScDirectory(std::string path);

  [[nodiscard]] std::string GetPath() const;

  static bool IsDirectory(std::string const & path);

  void RemoveDirectory();

  [[nodiscard]] ScFile CopyFile(ScFile const & file, std::string newExtension = "", bool copyContent = false) const;

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
