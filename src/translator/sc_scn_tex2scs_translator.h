#pragma once

#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <filesystem>

class ScSCnTexCommand;
class ScFile;
class ScDirectory;

using ScSCnTexCommands = std::unordered_map<std::string, ScSCnTexCommand *>;

/*!
 * @brief The ScSCnTex2SCsTranslator class is responsible for translating sc.n-represented *.tex files into *.scs files.
 *
 * The class provides methods for running the translation process, handling debug and clear modes, and managing the translation progress.
 * It also includes private methods for translating individual files, dumping identifiers, and dumping file structures.
 */
class ScSCnTex2SCsTranslator {
private:
  bool m_debugMode; ///< Indicates whether the translator should run in debug mode.
  bool m_clearMode; ///< Indicates whether the target directory should be cleared before translation.
  std::unordered_set<std::string> m_extensions = { ".tex" }; ///< The file extensions to be translated.
  size_t m_filesCount = 0; ///< The total number of files to be translated.
  size_t m_fileNumber = 0; ///< The current file number being translated.

public:
  /*!
   * @brief Constructs a ScSCnTex2SCsTranslator object.
   * @param debugMode Indicates whether the translator should run in debug mode.
   * @param clearMode Indicates whether the target directory should be cleared before translation.
   */
  ScSCnTex2SCsTranslator(bool debugMode, bool clearMode);

  /*!
   * @brief Runs the translation process.
   * @param workDirectoryPath The path to the directory containing the sc.n-represented *.tex files.
   * @param targetDirectoryPath The path to the directory where the translated *.scs files will be saved.
   * @param elementSysId The starting element system identifier for the translation.
   * @return True if the translation process is successful, false otherwise.
   */
  bool Run(std::string const & workDirectoryPath, std::string const & targetDirectoryPath, size_t elementSysId);

private:
  /*!
   * @brief Translates all files within a given directory and its subdirectories.
   * @param nestedDirectoryPath The path to the directory to be translated.
   * @param startDirectory The original starting directory for the translation.
   * @param startTargetDirectory The original target directory for the translation.
   */
  void TranslateFiles(std::string const & nestedDirectoryPath, ScDirectory startDirectory, ScDirectory const & startTargetDirectory);

  /*!
   * @brief Translates a single file from sc.n-represented *.tex to *.scs.
   * @param file The file to be translated.
   * @param targetDirectory The target directory where the translated file will be saved.
   * @return True if the file is successfully translated, false otherwise.
   */
  bool TranslateFile(ScFile const & file, ScDirectory const & targetDirectory);

  /*!
   * @brief Translates the text content of a sc.n-represented *.tex file into the corresponding *.scs text.
   * @param filePath The path to the sc.n-represented *.tex file.
   * @return The translated *.scs text.
   */
  std::string TranslateText(std::string const & filePath);

  /*!
   * @brief Dumps the identifiers used during the translation process into a file.
   * @param targetDirectory The target directory where the identifiers file will be saved.
   */
  void DumpIdentifiers(ScDirectory const & targetDirectory);

  /*!
   * @brief Dumps the file structures used during the translation process into separate files.
   * @param targetDirectory The target directory where the file structures will be saved.
   */
  void DumpFileStructs(ScDirectory const & targetDirectory);
};
