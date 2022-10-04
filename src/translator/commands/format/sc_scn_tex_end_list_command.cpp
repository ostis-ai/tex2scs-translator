#include "sc_scn_tex_end_list_command.h"

ScScnTexCommandResult ScSCnTexEndListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & type = params.at(0);
  current_env.pop();
  ScStringStream stream;

  if (type == "scnitemize")
    stream << "</ul>\n";
  else if (type == "scnnumerize")
    stream << "</ol>\n";
  else if (type == "scnindent")
  {
    offset = offset.substr(0, offset.size() - 1);
    stream << ";;\n" << offset << "*)";
  }
  else if (type == "scnrelfromlist")
    offset = offset.substr(0, offset.size() - 1);
  else if (type == "scnreltolist")
    offset = offset.substr(0, offset.size() - 1);
  else if (type == "scnrelbothlist")
    offset = offset.substr(0, offset.size() - 1);
  else if (type == "scnrelfromset")
  {
    offset = offset.substr(0, offset.size() - 1);
    stream << "\n" << offset << "}";
  }
  else if (type == "scnrelfromvector")
  {
    offset = offset.substr(0, offset.size() - 1);
    stream << "\n" << offset << ">";
  }
  else if (type == "scnreltoset")
  {
    offset = offset.substr(0, offset.size() - 1);
    stream << "\n" << offset << "}";
  }
  else if (type == "scnreltovector")
  {
    offset = offset.substr(0, offset.size() - 1);
    stream << "\n" << offset << ">";
  }
  else if (type == "scnhaselementset")
  {
    offset = offset.substr(0, offset.size() - 1);
    stream << "\n" << offset << "}";
  }
  else if (type == "scnhaselementvector")
  {
    offset = offset.substr(0, offset.size() - 1);
    stream << "\n" << offset << ">";
  }
  else if (type == "scnhassubstruct")
  {
    offset = offset.substr(0, offset.size() - 1);
    stream << "\n" << offset << "}";
  }
  else if (type == "scnhassubset")
  {
    offset = offset.substr(0, offset.size() - 1);
    stream << "\n" << offset << "}";
  }
  return stream;
}
