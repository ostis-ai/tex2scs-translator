#include "sc_scn_tex_nrel_from_list_command.h"

ScScnTexCommandResult ScSCnTexNrelFromListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relation = tree.Add(params.at(0));

  ScStringStream stream;
  stream << StartLine(history) << offset << "=> " << relation << ":\n";

  size_t const START = 2;
  std::string subject;
  for (size_t i = START; i < params.size() - 1; ++i)
  {
    if (i != START)
      stream << StartLine(history);

    if (params.at(i) == "[")
      subject = params.at(i);
    else
      subject = tree.Add(params.at(i));
    stream << offset << "\t" << subject;
  }

  return stream;
}
