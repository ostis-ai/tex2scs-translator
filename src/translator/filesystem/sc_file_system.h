#pragma once

#include <string>
#include <unordered_set>
#include <fstream>
#include <utility>
#include <filesystem>
#include <functional>

#include "../stream/sc_string_stream.h"

class ScFile
{
public:
  explicit ScFile(std::string path)
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
    file.open(m_path);

    file << text;

    file.close();
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
  explicit ScDirectory(std::string path)
    : m_path(std::move(path))
  {
    m_entry = std::filesystem::directory_entry{m_path};
    if (!m_entry.exists())
      std::filesystem::create_directory(m_entry);
  }

  [[nodiscard]] std::string GetPath() const
  {
    return m_path;
  }

  [[nodiscard]] ScFile CopyFile(std::string const & filePath, std::string const & newExtension) const
  {
    std::string const & fileName = filePath.substr(filePath.rfind('/') + 1, filePath.size());
    std::string const & fileNameWithoutExtension = fileName.substr(0, fileName.rfind('.'));

    ScStringStream stream;
    (m_path.at(m_path.size() - 1) == '/'
     ? stream << m_path
     : stream << m_path << "/")
        << fileNameWithoutExtension << (newExtension.at(0) == '.' ? newExtension : "." + newExtension);

    return ScFile{stream};
  }

  [[nodiscard]] ScFile CopyFile(ScFile const & file, std::string const & newExtension) const
  {
    return CopyFile(file.GetPath(), newExtension);
  }

  [[nodiscard]] ScDirectory CopyDirectory(std::string nestedDirectoryPath, std::string const & targetDirectoryPath) const
  {
    size_t pos = nestedDirectoryPath.find(m_path);
    std::string const & nestedDirectoryName = nestedDirectoryPath.replace(pos, m_path.size(), "");

    ScStringStream stream;
    stream << targetDirectoryPath << nestedDirectoryName;

    return ScDirectory{stream};
  }

  [[nodiscard]] ScDirectory CopyDirectory(std::string const & nestedDirectoryPath, ScDirectory const & targetDirectory) const
  {
    return CopyDirectory(nestedDirectoryPath, targetDirectory.GetPath());
  }

  [[nodiscard]] size_t CountFiles(std::unordered_set<std::string> const & extensions) const
  {
    size_t count = 0;
    PathFiles(m_path, count, extensions);

    return count;
  }

  void ForEach(
      std::function<void(ScDirectory const & directory)> const & directoryCallback,
      std::function<void(ScFile const & file)> const & fileCallback)
  {
    auto const & it = std::filesystem::directory_iterator(m_path);
    for (auto const & item : it)
    {
      if (item.is_directory() && directoryCallback)
      {
        fileCallback(ScFile(item.path()));
      }
      else if (fileCallback)
      {
        directoryCallback(ScDirectory(item.path()));
      }
    }
  }

private:
  std::string m_path;
  std::filesystem::directory_entry m_entry;

  void PathFiles(
      std::string const & workDirectory, size_t & count, std::unordered_set<std::string> const & extensions) const
  {
    auto const & it = std::filesystem::directory_iterator{workDirectory};
    for (auto & item : it)
    {
      std::string const & path = item.path();

      if (item.is_directory())
      {
        PathFiles(path, count, extensions);
      }
      else if (ScFile{path}.HasExtension(extensions))
      {
        ++count;
      }
    }
  }
};
