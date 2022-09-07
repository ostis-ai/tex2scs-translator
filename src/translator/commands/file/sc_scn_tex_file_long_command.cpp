#include "sc_scn_tex_file_long_command.h"

ScScnTexCommandResult ScSCnTexFileLongCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & content = params.at(0);

  ScStringStream stream;
  offset += "\t";
  stream << "[<p>" << content << "</p>] (*\n";
  stream << offset << "<- lang_ru;;\n";
  stream << offset << "=> nrel_format: format_html;;\n";
  offset = offset.substr(0, offset.size() - 1);
  stream << offset << "*)";
  
  return stream;
}
