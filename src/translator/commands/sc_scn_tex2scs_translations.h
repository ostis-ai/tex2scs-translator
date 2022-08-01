#pragma once

#include <unordered_map>

using ScSCnTexTranslations = std::unordered_map<std::string, std::string>;

static ScSCnTexTranslations const translations = {
    { "примечание", "nrel_note" },
    { "пояснение", "nrel_explanation" },
    { "идентификатор", "nrel_idtf" },
    { "эпиграф", "nrel_epigraph" },
    { "аннотация", "nrel_summary" },
    { "включение", "nrel_inclusion" },
};
