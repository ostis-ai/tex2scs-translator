#pragma once

#include "../sc_scn_tex_command.h"

class ScSCnTexListCommand : public ScSCnTexCommand
{
protected:
  std::unordered_map<std::string, std::vector<std::string>> m_setTypes = {
    { "scnrelfromlist",      { "=>", "", "" } },
    { "scnrelfromset",       { "=>", "(", ")" } },
    { "scnrelfromvector",    { "=>", "<", ">" } },
    { "scnreltolist",        { "<=", "", "" } },
    { "scnreltoset",         { "<=", "(", ")" } },
    { "scnreltovector",      { "<=", "<", ">" } },
    { "scnrelbothlist",      { "<=>", "", "" } },
    { "scnrelbothset",       { "<=>", "(", ")" } },
    { "scnrelbothvector",    { "<=>", "<", ">" } },
    { "scnhaselementset",    { "->", "(", ")" } },
    { "scnhaselementvector", { "->", "<", ">" } },
    { "scnhassubstruct",     { "->", "[*", "*]", "погружение" } },
    { "scnhassubset",        { "->", "(", ")", "включение" } },
  };
};
