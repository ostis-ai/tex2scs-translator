#include "sc_scn_tex_nrel_from_set_command.h"

ScScnTexCommandResult ScSCnTexNrelFromSetCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relation = tree.Add(params.at(0));

  ScStringStream stream;
  stream << StartLine() << offset << "=> " << relation << ": ";

  stream << offset << "\n{\n";

  size_t const START = 2;
  std::string subject;
  for (size_t i = START; i < params.size() - 1; ++i)
  {
    if (i != START)
      stream << StartLine();

    subject = params.at(i);
    stream << offset << "\t" << subject;

    if (i != params.size() - 2)
      stream << EndLine();
  }

  stream << "\n" << offset << offset << "}";

  return stream;
}
