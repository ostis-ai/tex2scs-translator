#include "sc_scn_tex2scs_translator.h"
#include "log/sc_log.hpp"

ScSCnTex2SCsTranslator::ScSCnTex2SCsTranslator(bool debugMode, bool clearMode)
{
  m_debugMode = debugMode;
  m_clearMode = clearMode;
}

bool ScSCnTex2SCsTranslator::Run(
    std::string const & workDirectoryPath, std::string const & targetDirectoryPath, size_t elementSysId = 0)
{
  if (!ScDirectory::IsDirectory(workDirectoryPath))
  {
    SC_LOG_ERROR("Source path is not directory");
    return false;
  }

  SC_LOG_INFO("Start translate scn-tex sources:");

  if (m_debugMode)
  {
    SC_LOG_INFO("Set debug mode");
    utils::ScLog::SetDebugMode();
  }
  else
    SC_LOG_INFO("Set release mode");

  ScSCnPrefixTree::GetInstance()->SetNewElementNumber(elementSysId);
  SC_LOG_WARNING("First element system identifier: "
    << ScSCnPrefixTree::GetInstance()->GetFreeElementSystemIdentifier());

  ScDirectory const & workDirectory{workDirectoryPath};
  m_filesCount = workDirectory.CountFiles(m_extensions);
  ScDirectory const & targetDirectory{targetDirectoryPath};

  std::string const & startDirectoryPath = workDirectory.GetPath();
  m_fileNumber = 0;

  SC_LOG_INFO("SCn-tex sources directory: " << workDirectory.GetPath());
  SC_LOG_INFO("Target SCs sources directory: " << targetDirectory.GetPath());

  if (m_clearMode)
  {
    SC_LOG_INFO("Clear target SCs sources directory");
    ScDirectory{targetDirectory}.RemoveDirectory();
  }

  TranslateFiles(startDirectoryPath, workDirectory, targetDirectory);
  DumpIdentifiers(targetDirectory);
  DumpFileStructs(targetDirectory);

  SC_LOG_WARNING("Free element system identifier: "
    << ScSCnPrefixTree::GetInstance()->GetFreeElementSystemIdentifier());
  SC_LOG_INFO("Translation finished");

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
        SC_LOG_INFO("[" << ++m_fileNumber << "/" << m_filesCount << "]: " << file.GetPath()
                  << " - " << (result ? "OK" : "ERROR"));
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
    targetFile.Write(e.what());
    SC_LOG_ERROR(e.what());
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

void ScSCnTex2SCsTranslator::DumpFileStructs(ScDirectory const & targetDirectory)
{
  ScSCnFileStructsTree::GetInstance()->Dump(targetDirectory);
}
