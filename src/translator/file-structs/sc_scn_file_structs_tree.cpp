#include "translator/file-structs/sc_scn_file_structs_tree.h"

#include "translator/stream/scs_stream.h"
#include "translator/filesystem/sc_file.h"
#include "translator/filesystem/sc_directory.h"

std::unique_ptr<ScSCnFileStructsTree> ScSCnFileStructsTree::m_instance = nullptr;

ScSCnFileStructsTree::ScSCnFileStructsTree() = default;

ScSCnFileStructsTree::~ScSCnFileStructsTree() = default;

ScSCnFileStructsTree & ScSCnFileStructsTree::GetInstance()
{
  if (m_instance == nullptr)
    m_instance = std::unique_ptr<ScSCnFileStructsTree>(new ScSCnFileStructsTree());

  return *m_instance;
}

void ScSCnFileStructsTree::Add(std::string const & filePath)
{
  auto const & item = m_file_structs.find(filePath);
  if (item != m_file_structs.cend())
    return;

  m_file_structs.insert(filePath);
}

void ScSCnFileStructsTree::Dump(ScDirectory const & targetDirectory) const
{
  for (auto const & fileName : m_file_structs)
  {
    ScFile source = targetDirectory.GetFileByName(fileName + ".scs");

    std::stringstream fileText;
    source.Read(fileText);

    source.Write(
      SCsStream().Row([&fileName, &fileText]() -> SCsStream {
        return { ".", fileName, " = [*\n", fileText.str(), "\n*];;"};
      })
    );
  }
}
