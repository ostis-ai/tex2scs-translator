#include "sc_file_system.h"

ScDirectory::ScDirectory(std::string path)
  : m_path(std::move(path))
{
  m_entry = std::filesystem::directory_entry{m_path};
  if (!m_entry.exists())
    std::filesystem::create_directory(m_entry);
}

std::string ScDirectory::GetPath() const
{
  return m_path;
}

bool ScDirectory::IsDirectory(std::string const & path)
{
  return std::filesystem::is_directory(path);
}

void ScDirectory::RemoveDirectory()
{
  std::filesystem::remove_all(m_path);
}

ScFile ScDirectory::CopyFile(ScFile const & file, std::string newExtension, bool copyContent) const
{
  std::string const & fileName = file.GetName();

  if (newExtension.empty())
    newExtension = file.GetExtension();

  ScStringStream pathStream;
  pathStream << m_path;
  if (m_path.back() != '/')
    pathStream << "/";
  pathStream << fileName << (newExtension.front() == '.' ? newExtension : "." + newExtension);

  ScFile copiedFile{pathStream};
  if (copyContent)
  {
    std::stringstream contentStream;
    file.Read(contentStream);
    copiedFile.Write(contentStream.str());
  }

  return copiedFile;
}

ScDirectory ScDirectory::CopyDirectory(std::string nestedDirectoryPath, std::string const & targetDirectoryPath) const
{
  size_t pos = nestedDirectoryPath.find(m_path);
  std::string const & nestedDirectoryName = nestedDirectoryPath.replace(pos, m_path.size(), "");

  ScStringStream stream;
  stream
    << (targetDirectoryPath.at(targetDirectoryPath.size() - 1) == '/'
      ? targetDirectoryPath
      : targetDirectoryPath + "/")
    << nestedDirectoryName;

  return ScDirectory{stream};
}

ScDirectory ScDirectory::CopyDirectory(std::string const & nestedDirectoryPath, ScDirectory const & targetDirectory) const
{
  return CopyDirectory(nestedDirectoryPath, targetDirectory.GetPath());
}

size_t ScDirectory::CountFiles(std::unordered_set<std::string> const & extensions) const
{
  size_t count = 0;
  PathFiles(m_path, count, extensions);

  return count;
}

ScFile ScDirectory::GetFileByName(std::string const & fileName) const
{
  return ScFile{PathFiles(m_path, fileName)};
}

void ScDirectory::ForEach(
    std::function<void(ScDirectory const & directory)> const & directoryCallback,
    std::function<void(ScFile const & file)> const & fileCallback)
{
  auto const & it = std::filesystem::directory_iterator(m_path);
  for (auto const & item : it)
  {
    if (item.is_directory() && directoryCallback)
      directoryCallback(ScDirectory(item.path()));
    else if (fileCallback)
      fileCallback(ScFile(item.path()));
  }
}

std::string ScDirectory::PathFiles(
    std::string const & workDirectory, std::string const & fileName) const
{
  std::string foundPath;

  auto const & it = std::filesystem::directory_iterator{workDirectory};
  for (auto & item : it)
  {
    auto const & path = item.path();

    if (item.is_directory())
      foundPath = PathFiles(path, fileName);
    else if (item.is_regular_file() && path.filename() == fileName)
      foundPath = path;

    if (!foundPath.empty())
      return foundPath;
  }

  return "";
}

void ScDirectory::PathFiles(
    std::string const & workDirectory, size_t & count, std::unordered_set<std::string> const & extensions) const
{
  auto const & it = std::filesystem::directory_iterator{workDirectory};
  for (auto & item : it)
  {
    std::string const & path = item.path();

    if (item.is_directory())
      PathFiles(path, count, extensions);
    else if (ScFile{path}.HasExtension(extensions))
      ++count;
  }
}
