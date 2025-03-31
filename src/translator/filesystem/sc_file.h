#pragma once

#include <string>
#include <unordered_set>

/*!
 * @brief Represents a file in the file system.
 *
 * This class provides methods for interacting with files, such as getting their path, name, extension,
 * reading and writing their content, and checking if they have specific extensions.
 */
class ScFile
{
public:
  /*!
   * @brief Constructs a ScFile object with the given path.
   *
   * @param path The path of the file.
   */
  ScFile(std::string path);

  /*!
   * @brief Returns the path of the file.
   *
   * @return The path of the file.
   */
  [[nodiscard]] std::string GetPath() const;

  /*!
   * @brief Writes the given text to the file.
   *
   * @param text The text to be written to the file.
   */
  void Write(std::string const & text);

  /*!
   * @brief Reads the content of the file into the given stringstream.
   *
   * @param text The stringstream to store the file content.
   */
  void Read(std::stringstream & text) const;

  /*!
   * @brief Returns the name of the file without the extension.
   *
   * @return The name of the file.
   */
  [[nodiscard]] std::string GetName() const;

  /*!
   * @brief Returns the extension of the file.
   *
   * @return The extension of the file.
   */
  [[nodiscard]] std::string GetExtension() const;

  /*!
   * @brief Checks if the file has any of the specified extensions.
   *
   * @param extensions The set of extensions to check against.
   * @return True if the file has any of the specified extensions, false otherwise.
   */
  [[nodiscard]] bool HasExtension(std::unordered_set<std::string> const & extensions) const;

private:
  std::string m_path;
};
