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
    { "разбиение", "nrel_subdividing" },
    { "максимальный класс объектов исследования", "rrel_maximum_studied_object_class" },
    { "класс объектов исследования", "rrel_studied_object_class" },
    { "исследуемое отношение", "rrel_explored_relation" },
};
