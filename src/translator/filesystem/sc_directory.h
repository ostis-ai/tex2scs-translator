#pragma once

#include <string>
#include <unordered_set>
#include <filesystem>
#include <functional>

class ScFile;

/*!
 * @brief Represents a directory in the file system.
 *
 * This class provides methods for interacting with directories, such as getting their path, checking if they exist,
 * removing directories, copying files and directories, counting files with specific extensions, and iterating through
 * the directory contents.
 */
class ScDirectory
{
public:
  /*!
   * @brief Constructs a ScDirectory object with the given path.
   *
   * @param path The path of the directory.
   */
  ScDirectory(std::string path);

  /*!
   * @brief Returns the path of the directory.
   *
   * @return The path of the directory.
   */
  [[nodiscard]] std::string GetPath() const;

  /*!
   * @brief Checks if the given path is a directory.
   *
   * @param path The path to check.
   * @return True if the path is a directory, false otherwise.
   */
  static bool IsDirectory(std::string const & path);

  /*!
   * @brief Removes the directory and all its contents.
   */
  void RemoveDirectory();

  /*!
   * @brief Copies a file from the current directory to a new location.
   *
   * @param file The file to be copied.
   * @param newExtension The new extension for the copied file (optional, default is "").
   * @param copyContent Whether to copy the file content (optional, default is false).
   * @return The copied file.
   */
  [[nodiscard]] ScFile CopyFile(ScFile const & file, std::string newExtension = "", bool copyContent = false) const;

  /*!
   * @brief Copies a subdirectory from the current directory to a new location.
   *
   * @param nestedDirectoryPath The path of the subdirectory to be copied.
   * @param targetDirectoryPath The path of the target directory where the subdirectory will be copied.
   * @return The copied subdirectory.
   */
  [[nodiscard]] ScDirectory CopyDirectory(std::string nestedDirectoryPath, std::string const & targetDirectoryPath) const;

  /*!
   * @brief Copies a subdirectory from the current directory to a new location.
   *
   * @param nestedDirectoryPath The path of the subdirectory to be copied.
   * @param targetDirectory The target directory where the subdirectory will be copied.
   * @return The copied subdirectory.
   */
  [[nodiscard]] ScDirectory CopyDirectory(std::string const & nestedDirectoryPath, ScDirectory const & targetDirectory) const;

  /*!
   * @brief Counts the number of files in the directory with specific extensions.
   *
   * @param extensions The set of extensions to count.
   * @return The number of files with the specified extensions.
   */
  [[nodiscard]] size_t CountFiles(std::unordered_set<std::string> const & extensions) const;

  /*!
   * @brief Finds a file in the directory by its name.
   *
   * @param fileName The name of the file to find.
   * @return The found file, or an empty ScFile object if the file is not found.
   */
  [[nodiscard]] ScFile GetFileByName(std::string const & fileName) const;

  /*!
   * @brief Executes a callback function for each directory and file in the directory.
   *
   * @param directoryCallback The callback function to be executed for each directory.
   * @param fileCallback The callback function to be executed for each file.
   */
  void ForEach(
      std::function<void(ScDirectory const & directory)> const & directoryCallback,
      std::function<void(ScFile const & file)> const & fileCallback);

private:
  /*!
   * @brief The path of the directory.
   */
  std::string m_path;
  /*!
   * @brief The directory entry for the current directory.
   *
   * This field is used for interacting with the directory using the std::filesystem library.
   */
  std::filesystem::directory_entry m_entry;

  /*!
   * @brief Constructs the full path of a file within the directory.
   *
   * @param workDirectory The current working directory.
   * @param fileName The name of the file.
   * @return The full path of the file.
   */
  std::string PathFiles(
      std::string const & workDirectory, std::string const & fileName) const;

  /*!
   * @brief Recursively counts the number of files with specific extensions within the directory.
   *
   * @param workDirectory The current working directory.
   * @param count A reference to the count of files with the specified extensions.
   * @param extensions The set of extensions to count.
   */
  void PathFiles(
      std::string const & workDirectory, size_t & count, std::unordered_set<std::string> const & extensions) const;
};
