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
  bool Run(std::string const & workDirectory, std::string const & targetDirectory)
  {
    auto const & dir = ScDirectory(workDirectory);
    m_filesCount = dir.CountFiles();

    std::cout << "SCn-tex sources directory: " << workDirectory << std::endl;
    std::cout << "Target SCs sources directory: " << targetDirectory << std::endl;

    std::cout << "Start translate scn-tex sources:" << std::endl;
    TranslateFiles(workDirectory, workDirectory, targetDirectory, 0);
    std::cout << "Translation finished" << std::endl;

    return true;
  }

private:
  size_t m_filesCount;

  void TranslateFiles(
      std::string const & workDirectory,
      std::string const & startDirectory,
      std::string const & startTargetDirectory,
      size_t fileNumber)
  {
    std::string targetDirectory = GetTargetDirectory(workDirectory, startDirectory, startTargetDirectory);

    std::filesystem::directory_entry dir{targetDirectory};
    if (!dir.exists())
      std::filesystem::create_directory(dir);

    auto const & it = std::filesystem::directory_iterator(workDirectory);
    for (auto & item : it)
    {
      std::string const & path = item.path();
      if (item.is_directory())
        TranslateFiles(path, startDirectory, startTargetDirectory, fileNumber);
      else
      {
        ScSCnTexAddLevelCommand::offset = "";
        bool result = TranslateFile(path, targetDirectory);
        std::cout << "[" << ++fileNumber << "/" << m_filesCount << "]: " << path
                  << " - " << (result ? "OK" : "ERROR") << std::endl;
      }
    }
  }

  std::string GetTargetDirectory(
      std::string const & workDirectory, std::string const & startDirectory, std::string const & startTargetDirectory)
  {
    std::string nestedDirectory = workDirectory;
    size_t pos = nestedDirectory.find(startDirectory);
    nestedDirectory.replace(pos, startDirectory.size(), "");

    std::string targetDirectory;
    ScStringStream stream;
    stream << startTargetDirectory << targetDirectory;
    stream >> targetDirectory;

    return targetDirectory;
  }

  bool TranslateFile(
      std::string const & filePath, std::string const & targetDirectory)
  {
    std::string targetFilePath = GetTargetFilePath(filePath, targetDirectory);
    std::string const & scsText = TranslateText(filePath);

    ScFile file{targetFilePath};
    file.Write(scsText);

    return true;
  }

  std::string GetTargetFilePath(std::string const & filePath, std::string const & targetDirectory)
  {
    std::string nestedFile = filePath.substr(filePath.rfind('/'), filePath.size());
    nestedFile = nestedFile.substr(0, nestedFile.rfind('.'));
    nestedFile = nestedFile.substr(1);

    ScStringStream stream;
    (targetDirectory.at(targetDirectory.size() - 1) == '/'
      ? stream << targetDirectory
      : stream << targetDirectory << "/")
      << nestedFile << ".scs";

    return stream;
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
