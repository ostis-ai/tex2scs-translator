#include "sc_scn_tex_has_element_set_command.h"

ScScnTexCommandResult ScSCnTexHasElementSetCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScStringStream stream;
  stream << StartLine() << offset << "->";

  stream << offset << "\n{\n";

  size_t const START = 0;
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

  stream << StartLine() << offset << "}";

  return stream;
}
