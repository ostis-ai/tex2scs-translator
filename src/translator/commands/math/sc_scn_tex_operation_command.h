#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "translator/commands/sc_scn_tex_command.h"

class ScSCnTexOperationCommand : public ScSCnTexCommand
{
protected:
  uint8_t const COMMAND_POS = 0;
  uint8_t const FIRST_PARAM_POS = 1;
  uint8_t const SECOND_PARAM_POS = 2;

  uint8_t const FIRST_ARG_BEGIN_ATTR = 0;
  uint8_t const FIRST_ARG_END_ATTR = 1;
  uint8_t const SECOND_ARG_BEGIN_ATTR = 2;
  uint8_t const SECOND_ARG_END_ATTR = 3;

  uint8_t const COMMAND_SIZE_ZERO_ARG = 1;
  uint8_t const COMMAND_SIZE_ONE_ARG = 2;
  uint8_t const COMMAND_SIZE_TWO_ARGS = 4;

  std::unordered_map<std::string, std::vector<std::string>> m_mathTypes = {
   { "frac",       { "<sup>", "</sup>&frasl;", "<sub>", "</sub>" } },
   { "max",        { "max( ", " )" } },
   { "min",        { "min( ", " )" } },
   { "upperscore", { "<sup>", "</sup>" } },
   { "underscore", { "<sub>", "</sub>" } }
  };
  

  std::unordered_map<std::string, std::vector<std::string>> m_symbolTypes = {   
    { "newpage",             { "\n" } },
    { "newline",             { "\n" } },
    { "\\",                  { "\n" } },

    { "colon",               { ":" } },
    { "char59",              { ";" } },
    { "sim",                 { "~" } },
    { "tilde",               { "~" } },

    { "in",                  { "∈" } },
    { "notin",               { "∉" } },
    { "ni",                  { "∋" } },
    { "subseteq",            { "⊆" } },
    { "subset",              { "⊂" } },
    { "supseteq",            { "⊇" } },
    { "supset",              { "⊃" } },
    { "cup",                 { "⋃" } },
    { "cap",                 { "⋂" } },
    { "setminus",            { "/" } },
    { "Rightarrow",          { "⇒" } },
    { "rightarrow",          { "→" } },
    { "Leftrightarrow",      { "⇔" } },
    { "wedge",               { "∧" } },
    { "vee",                 { "∨" } },
    { "neg",                 { "¬" } },
    { "forall",              { "∀" } },
    { "exists",              { "∃" } },
    { "to",                  { "→" } },
    { "mapsto",              { "↦" } },
    { "bullet",              { "•" } },
    { "ldots",               { "..." } },
    { "eq",                  { "=" } },
    { "neq",                 { "≠" } },
    { "square",              { "□" } },
    { "not",                 { "/" } },
    { "leg",                 { ">" } },
    { "leq",                 { ">=" } },
    { "req",                 { "<" } },
    { "req",                 { "<=" } },
    { "langle",              { "<" } },
    { "rangle",              { ">" } },
    { "log",                 { "log" } },

    { "textunderscore",      { "_" } },

    {"times",                { "×" }  },
    {"'",                    { "'" }  },
    {"percent",              { "%" }  },

    {"alpha",                { "α" }  },
    {"beta",                 { "β" }  },
    {"gamma",                { "γ" }  },
    {"Gamma",                { "Γ" }  }, 
    {"Sigma",                { "Σ" }  }, 
    {"Delta",                { "Δ" }  }, 
    {"delta",                { "δ" }  }, 
    {"Epsilon",              { "Ε" }  }, 
    {"epsilon",              { "ε" }  }
  };

};
