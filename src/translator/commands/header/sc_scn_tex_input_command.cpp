#include "sc_scn_tex_input_command.h"

#include "../../helper/scs_helper.h"
#include "../../filesystem/sc_file_system.h"
#include "../../file-structs/sc_scn_file_structs_tree.h"

ScScnTexCommandResult ScSCnTexInputCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
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
