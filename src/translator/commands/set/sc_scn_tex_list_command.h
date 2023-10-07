#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "../sc_scn_tex_command.h"

class ScSCnTexListCommand : public ScSCnTexCommand
{
protected:
  uint8_t const MAX_PARAMS = 3;
  uint8_t const COMMAND_TYPE_POS = 1;
  uint8_t const REL_PARAM_POS = 2;

  uint8_t const MAX_REL_ATTRS = 5;
  uint8_t const EDGE_ATTR_POS = 0;
  uint8_t const BEGIN_BRACKET_POS = 1;
  uint8_t const END_BRACKET_POS = 2;
  uint8_t const REL_MODIFIER_ATTR_POS = 3;
  uint8_t const REL_ATTR_POS = 4;
  uint8_t const MAX_REL_ATTRS_WITH_REl_MODIFIER = 4;

  std::unordered_map<std::string, std::vector<std::string>> m_setTypes = {
    { "scnrelfromlist",      { "=>", "", "", ":" } },
    { "scnrelfromset",       { "=>", "{", "}", ":" } },
    { "scnrelfromvector",    { "=>", "<", ">", ":" } },
    { "scnreltolist",        { "<=", "", "", ":" } },
    { "scnreltoset",         { "<=", "{", "}", ":" } },
    { "scneqtoset",          { "<=>", "{", "}", ":", "эквивалентность*" } },
    { "scnreltovector",      { "<=", "<", ">", ":" } },
    { "scneqtovector",       { "<=>", "<", ">", ":", "эквивалентность*" } },
    { "scnrelbothlist",      { "<=>", "", "", ":" } },
    { "scnrelbothset",       { "<=>", "{", "}", ":" } },
    { "scnrelbothvector",    { "<=>", "<", ">", ":" } },
    { "scnhaselementlist",   { "->", "", "", ":" } },
    { "scnhaselementrolelist", { "->", "", "", ":" } },
    { "scnhaselementset",    { "->", "{", "}", ":" } },
    { "scnhaselementvector", { "->", "<", ">", ":" } },
    { "scnhassubstruct",     { "->", "[*", "*]", ":" } },
    { "scnhassubset",        { "->", "{", "}", ":" } },

    { "scnstruct",           { "=", "[*", "*]" } },
    { "scnsubstruct",        { "=>", "[*", "*]", ":", "включение*" } },

    { "scnsubdividing",      { "=>", "{", "}", ":", "разбиение*" } },
    { "scnsdclass",          { "->", "", "", ":", "класс объектов исследования'" } },
    { "scnsdrelation",       { "->", "", "", ":", "исследуемое отношение'" } },
  };

  std::unordered_set<std::string> m_ignoredTypes = {
      "SCn"
  };

  std::unordered_map<std::string, std::vector<std::string>> m_elementTypes = {
    { "scnrelfrom",          { "=>", ":" } },
    { "scnrelto",            { "<=", ":" } },
    { "scnsuperset",         { "=>", ":", "включение*" } },
    { "scnsubset",           { "<=", ":", "включение*" } },
    { "scnrelsuperset",      { "=>", ":" } },
    { "scnvarrelfrom",       { "_=>", "::" } },
    { "scnvarrelto",         { "_<=", "::" } },
    { "scnrelboth",          { "<=>", ":" } },
    { "scneq",               { "<=>", ":" } },
    { "scniselement",        { "<-", ":" } },
    { "scniselementrole",    { "<-", ":" } },
    { "scnhaselement",       { "->", ":" } },
    { "scnhaselementrole",   { "->", ":" } },
    { "scnisvarelement",     { "_<-", "::" } },
    { "scnisvarelementrole", { "_<-", "::" } },
    { "scnhasvarelement",    { "_->", "::" } },
    { "scnhasvarelementrole",{ "_->", "::" } },

    { "scneqfile",           { "<=>", ":", "семантическая эквивалентность*" } },
    { "scneqfileclass",      { "<=>", ":", "семантическая эквивалентность*" } },
    { "scneqimage",          { "<=>", ":", "семантическая эквивалентность*" } },
    { "scnidtftext",         { "=>", ":", "идентификатор*" } },
    { "scntext",             { "=>", ":" } },
    { "scnnote",             { "=>", ":", "примечание*" } },
    { "scnidtf",             { "=>", ":", "идентификатор*" } },
    { "scnexplanation",      { "=>", ":", "пояснение*" } },
    { "scnidtfdef",          { "=>", ":", "пояснение*" } },

    { "scncomment",          { "=>", ":", "комментарий*" } },
    { "scnsourcecomment",    { "=>", ":", "комментарий*" } },
    { "scnciteannotation",   { "=>", ":", "аннотация*" } },

    { "scnsdmainclasssingle",{ "->", ":", "максимальный класс объектов исследования'" } },
  };

  std::unordered_map<std::string, std::vector<std::string>> m_symbolTypes = {
    { "scnnonamednode",      { "..." } },

    { "scnsupergroupsign",   { "^" } },
    { "scnrolesign",         { "'" } },

    { "newpage",             { "\n" } },
    { "newline",             { "\n" } },
    { "\\",                  { "\n" } },

    { "scnleftcurlbrace",    { "{" } },
    { "scnrightcurlbrace",   { "}" } },
    { "scnleftsquarebrace",  { "\\[" } },
    { "scnrightsquarebrace", { "\\]" } },
    { "scnslash",            { "/" } },
    { "scnhyphen",           { "-" } },
    { "scnstar",             { "\\*" } },

    { "in",                  { "∈" } },
    { "notin",               { "∉" } },
    { "ni",                  { "∋" } },
    { "subseteq",            { "⊆" } },
    { "subset",              { "⊂" } },
    { "supseteq",            { "⊇" } },
    { "supset",              { "⊃" } },
    { "cup",                 { "⋃" } },
    { "cap",                 { "⋂" } },
    { "setminus",            { "\\" } },
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

    { "textunderscore",      { "_" } },
  };

  std::unordered_set<std::string> m_fileTypes = {
    "scnfileimage", "scnfileitem", "scnfilelong", "scnfilescgitem",
    "scnidtftext", "scntext",
    "scnnote", "scnidtf", "scnexplanation", "scnidtfdef", "scncomment",
    "scnsourcecomment", "scnciteannotation",
  };

  std::unordered_set<std::string> m_fileClassTypes = {
    "scnfileclass", "scneqfileclass"
  };

  std::unordered_set<std::string> m_urlTypes = {
    "scneqfile", "scneqimage",
  };
};
