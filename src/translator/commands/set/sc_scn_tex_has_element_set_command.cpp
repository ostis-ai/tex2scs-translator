#include "sc_scn_tex_has_element_set_command.h"

ScScnTexCommandResult ScSCnTexHasElementSetCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  ScStringStream stream;
  stream << StartLine(history) << offset << "->";

  stream << offset << "\n{\n";

  size_t const START = 0;
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

  stream << StartLine(history) << offset << "}";

  return stream;
}
