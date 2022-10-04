#include "sc_scn_tex_begin_list_command.h"
#include "../relation/sc_scn_tex_rel_command.h"

ScScnTexCommandResult ScSCnTexBeginListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & type = params.at(0);
  ScStringStream stream;

  if (type == "scnitemize")
    stream << "\n<ul>\n";
  else if (type == "scnnumerize")
    stream << "\n<ol>\n";
  else if (type == "scnindent")
  {
    stream << " (*";
    offset += "\t";
  }
  else if (type == "scnrelfromlist")
  {
    ScSCnTexRelCommand rel;
    rel.scs_arrow = "=> ";
    ScScnTexCommandParams newParams = { params.at(1), "/" };
    stream << rel.Complete(history, tree, newParams);
  }
  else if (type == "scnreltolist")
  {
    ScSCnTexRelCommand rel;
    rel.scs_arrow = "<= ";
    ScScnTexCommandParams newParams = { params.at(1), "/" };
    stream << rel.Complete(history, tree, newParams);
  }
  else if (type == "scnrelbothlist")
  {
    ScSCnTexRelCommand rel;
    rel.scs_arrow = "<=> ";
    ScScnTexCommandParams newParams = { params.at(1), "/" };
    stream << rel.Complete(history, tree, newParams);
  }
  else if (type == "scnrelfromset")
  {
    ScSCnTexRelCommand rel;
    rel.scs_arrow = "=> ";
    ScScnTexCommandParams newParams = { params.at(1), "/" };
    stream << rel.Complete(history, tree, newParams) << " {";
    offset += "\t";
  }
  else if (type == "scnrelfromvector")
  {
    ScSCnTexRelCommand rel;
    rel.scs_arrow = "=> ";
    ScScnTexCommandParams newParams = { params.at(1), "/" };
    stream << rel.Complete(history, tree, newParams) << " <";
    offset += "\t";
  }
  else if (type == "scnreltoset")
  {
    ScSCnTexRelCommand rel;
    rel.scs_arrow = "<= ";
    ScScnTexCommandParams newParams = { params.at(1), "/" };
    stream << rel.Complete(history, tree, newParams) << " {";
    offset += "\t";
  }
  else if (type == "scnreltovector")
  {
    ScSCnTexRelCommand rel;
    rel.scs_arrow = "<= ";
    ScScnTexCommandParams newParams = { params.at(1), "/" };
    stream << rel.Complete(history, tree, newParams) << " <";
    offset += "\t";
  }
  else if (type == "scnhaselementset")
  {
    stream << StartLine(history) << "\n" << offset << "-> {";
    offset += "\t";
  }
  else if (type == "scnhaselementvector")
  {
    stream << StartLine(history) << "\n" << offset << "-> <";
    offset += "\t";
  }
  else if (type == "scnhassubstruct")
  {
    ScSCnTexRelCommand rel;
    rel.scs_arrow = "=> ";
    ScScnTexCommandParams newParams = { "погружение", "/" };
    stream << rel.Complete(history, tree, newParams) << " {";
    offset += "\t";
  }
  else if (type == "scnhassubset")
  {
    ScSCnTexRelCommand rel;
    rel.scs_arrow = "=> ";
    ScScnTexCommandParams newParams = { "включение", "/" };
    stream << rel.Complete(history, tree, newParams) << " {";
    offset += "\t";
  }
  current_env.push(type);

  return stream;
}
