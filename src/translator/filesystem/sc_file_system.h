#pragma once

#include <string>
#include <unordered_set>
#include <fstream>
#include <utility>
#include <filesystem>

class ScFile
{
public:
  explicit ScFile(std::string path)
    : m_path(std::move(path))
  {
  }

  void Write(std::string const & text)
  {
    std::ofstream file;
    file.open(m_path);

    file << text;

    file.close();
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
  }

  [[nodiscard]] size_t CountFiles(std::unordered_set<std::string> const & extensions) const
  {
    size_t count = 0;
    PathFiles(m_path, count, extensions);

    return count;
  }

private:
  std::string m_path;

  void PathFiles(std::string const & workDirectory, size_t & count, std::unordered_set<std::string> const & extensions) const
  {
    auto const & it = std::filesystem::directory_iterator(workDirectory);
    for (auto & item : it)
    {
      std::string const & path = item.path();

      if (item.is_directory())
      {
        PathFiles(path, count, extensions);
      }
      else if (extensions.find(path.substr(path.rfind('.'))) != extensions.cend())
      {
        ++count;
      }
    }
  }
};
