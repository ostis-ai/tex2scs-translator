#include "sc_scn_tex2scs_translator.h"

bool ScSCnTex2SCsTranslator::Run(std::string const & workDirectoryPath, std::string const & targetDirectoryPath)
{
  ScDirectory const & workDirectory{workDirectoryPath};
  m_filesCount = workDirectory.CountFiles(m_extensions);
  ScDirectory const & targetDirectory{targetDirectoryPath};

  std::string const & startDirectoryPath = workDirectory.GetPath();
  m_fileNumber = 0;

  std::cout << "SCn-tex sources directory: " << workDirectory.GetPath() << std::endl;
  std::cout << "Target SCs sources directory: " << targetDirectory.GetPath() << std::endl;

  std::cout << "Start translate scn-tex sources:" << std::endl;
  TranslateFiles(startDirectoryPath, workDirectory, targetDirectory);
  DumpIdentifiers(targetDirectory);
  std::cout << "Translation finished" << std::endl;

  return true;
}

void ScSCnTex2SCsTranslator::TranslateFiles(
    std::string const & nestedDirectoryPath,
    ScDirectory startDirectory,
    ScDirectory const & startTargetDirectory)
{
  ScDirectory targetDirectory = startDirectory.CopyDirectory(nestedDirectoryPath, startTargetDirectory);

  ScDirectory{nestedDirectoryPath}.ForEach(
      [this, &startDirectory, &startTargetDirectory](ScDirectory const & directory) {
        TranslateFiles(directory.GetPath(), startDirectory, startTargetDirectory);
      },
      [this, &targetDirectory](ScFile const & file) {
        if (!file.HasExtension(m_extensions))
          return;

        SCsStream::Clear();
        bool result = TranslateFile(file.GetPath(), targetDirectory);
        std::cout << "[" << ++m_fileNumber << "/" << m_filesCount << "]: " << file.GetPath()
                  << " - " << (result ? "OK" : "ERROR") << std::endl;
      });
}


bool ScSCnTex2SCsTranslator::TranslateFile(
    std::string const & filePath, ScDirectory const & targetDirectory)
{
  ScFile targetFile = targetDirectory.CopyFile(filePath, ".scs");

  std::string scsText;
  try
  {
    scsText = TranslateText(filePath);
  }
  catch (std::exception const & e)
  {
    std::cout << e.what() << std::endl;
    return false;
  }

  targetFile.Write(scsText);

  return true;
}

std::string ScSCnTex2SCsTranslator::TranslateText(std::string const & filePath)
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

void ScSCnTex2SCsTranslator::DumpIdentifiers(ScDirectory const & targetDirectory)
{
  std::string const targetDirPath = targetDirectory.GetPath();
  ScFile dumpFile = (targetDirPath.at(targetDirPath.size() - 1) == '/'
    ? targetDirPath : targetDirPath + "/") + "identifiers.scs";

  std::string const scsText = ScSCnPrefixTree::GetInstance()->Dump();
  dumpFile.Write(scsText);
}
