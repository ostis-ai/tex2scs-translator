#include "sc_scn_tex_input_command.h"

#include "translator/helper/scs_helper.h"
#include "translator/filesystem/sc_file.h"
#include "translator/file-structs/sc_scn_file_structs_tree.h"

ScSCnTexCommandResult ScSCnTexInputCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScSCnTexCommandParams const & params)
{
  std::string const & sourcePath = params.at(1);
  ScFile source{sourcePath};

  std::string const & name = source.GetName();
  ScSCnFileStructsTree::GetInstance()->Add(name);

  return SCsStream()
  .SetCurrentCommand("any")
  .Formatted([&name]() -> SCsStream {
    return { "=> nrel_inclusion: .", name };
  });
}
