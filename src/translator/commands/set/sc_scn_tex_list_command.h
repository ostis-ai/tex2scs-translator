#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "../sc_scn_tex_command.h"

class ScSCnTexListCommand : public ScSCnTexCommand
{
protected:
  std::unordered_map<std::string, std::vector<std::string>> m_setTypes = {
    { "scnrelfromlist",      { "=>", "", "" } },
    { "scnrelfromset",       { "=>", "{", "}" } },
    { "scnrelfromvector",    { "=>", "<", ">" } },
    { "scnreltolist",        { "<=", "", "" } },
    { "scnreltoset",         { "<=", "{", "}" } },
    { "scnreltovector",      { "<=", "<", ">" } },
    { "scnrelbothlist",      { "<=>", "", "" } },
    { "scnrelbothset",       { "<=>", "{", "}" } },
    { "scnrelbothvector",    { "<=>", "<", ">" } },
    { "scnhaselementlist",   { "->", "", "" } },
    { "scnhaselementset",    { "->", "{", "}" } },
    { "scnhaselementvector", { "->", "<", ">" } },
    { "scnhassubstruct",     { "->", "[*", "*]" } },
    { "scnhassubset",        { "->", "{", "}" } },

    { "scnsubstruct",        { "=>", "[*", "*]", "включение" } },

    { "scnsubdividing",      { "=>", "{", "}", "разбиение" } },
    { "scnsdclass",          { "->", "", "", "класс объектов исследования" } },
    { "scnsdrelation",       { "->", "", "", "исследуемое отношение" } },
  };

  std::unordered_set<std::string> m_ignoredTypes = {
      "SCn"
  };

  std::unordered_map<std::string, std::vector<std::string>> m_elementTypes = {
    { "scnrelfrom",          { "=>" } },
    { "scnrelto",            { "<=" } },
    { "scnrelsuperset",      { "=>", "включение" } },
    { "scnsubset",           { "<=", "включение" } },
    { "scnvarrelfrom",       { "_=>" } },
    { "scnvarrelto",         { "_<=" } },
    { "scnvarrelsuperset",   { "_=>", "включение" } },
    { "scnvarrelsubset",     { "_<=", "включение" } },
    { "scnrelboth",          { "<=>" } },
    { "scneq",               { "=" } },
    { "scniselement",        { "<-" } },
    { "scniselementrole",    { "<-" } },
    { "scnhaselement",       { "->" } },
    { "scnhaselementrole",   { "->" } },
    { "scnisvarelement",     { "_<-" } },
    { "scnisvarelementrole", { "_<-" } },
    { "scnhasvarelementrole",{ "_->" } },

    { "scneqfile",           { "=" } },
    { "scneqimage",          { "=" } },
    { "scnidtftext",         { "=>", "идентификатор" } },
    { "scntext",             { "=>", "идентификатор" } },
    { "scnnote",             { "=>", "примечание" } },
    { "scnitdf",             { "=>", "примечание" } },
    { "scnexplanation",      { "=>", "пояснение" } },
    { "scnidtfdef",          { "=>", "пояснение" } },

    { "scnsdmainclasssingle",{ "->", "максимальный класс объектов исследования" } },
  };

  std::unordered_set<std::string> m_fileTypes = {
    "scneqfile", "scneqimage",
    "scnidtftext", "scntext",
    "scnnote", "scnidtf", "scnexplanation", "scnidtfdef"
  };
};
