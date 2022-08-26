#pragma once

#include <utility>
#include <unordered_map>
#include <fstream>
#include <filesystem>
#include <iostream>

#include "filesystem/sc_file_system.h"

#include "commands/sc_scn_tex_command.h"

#include "SCnTexLexer.h"
#include "SCnTexParser.h"

using ScSCnTexCommands = std::unordered_map<std::string, ScSCnTexCommand *>;

class ScSCnTex2SCsTranslator
{
public:
  bool Run(std::string const & workDirectoryPath, std::string const & targetDirectoryPath)
  {
    ScDirectory const & workDirectory{workDirectoryPath};
    m_filesCount = workDirectory.CountFiles(m_extensions);
    ScDirectory const & targetDirectory{targetDirectoryPath};

    std::string const & startDirectoryPath = workDirectory.GetPath();
    size_t const startFileIndex = 0;

    std::cout << "SCn-tex sources directory: " << workDirectory.GetPath() << std::endl;
    std::cout << "Target SCs sources directory: " << targetDirectory.GetPath() << std::endl;

    std::cout << "Start translate scn-tex sources:" << std::endl;
    TranslateFiles(startDirectoryPath, workDirectory, targetDirectory, startFileIndex);
    std::cout << "Translation finished" << std::endl;

    return true;
  }

private:
  std::unordered_set<std::string> m_extensions = {".tex"};
  size_t m_filesCount;

  void TranslateFiles(
      std::string const & nestedDirectoryPath,
      ScDirectory const & startDirectory,
      ScDirectory const & startTargetDirectory,
      size_t fileNumber)
  {
    ScDirectory targetDirectory = startDirectory.CopyDirectory(nestedDirectoryPath, startTargetDirectory);

    targetDirectory.ForEach(
    [this, &startDirectory, &startTargetDirectory, &fileNumber](ScDirectory const & directory) {
      TranslateFiles(directory.GetPath(), startDirectory, startTargetDirectory, fileNumber);
    },
    [this, &fileNumber, &targetDirectory](ScFile const & file) {
      ScSCnTexAddLevelCommand::offset = "";
      bool result = TranslateFile(file.GetPath(), targetDirectory);
      std::cout << "[" << ++fileNumber << "/" << m_filesCount << "]: " << file.GetPath()
                << " - " << (result ? "OK" : "ERROR") << std::endl;
    });
  }


  bool TranslateFile(
      std::string const & filePath, ScDirectory const & targetDirectory)
  {
    ScFile targetFile = targetDirectory.CopyFile(filePath, ".scs");

    std::string const & scsText = TranslateText(filePath);

    targetFile.Write(scsText);

    return true;
  }

  std::string TranslateText(std::string const & filePath)
  {
    std::ifstream file(filePath, std::ios_base::in);
    antlr4::ANTLRInputStream input(file);
    SCnTexLexer lexer(&input);

    antlr4::CommonTokenStream tokens(&lexer);
    SCnTexParser parser(&tokens);

    SCnTexParser::ScnTexTextContext * ctx = parser.scnTexText();
    file.close();
    return ctx->resultText;
  }
};
