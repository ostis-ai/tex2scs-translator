#pragma once

#include <string>
#include <unordered_map>

using ScSCnTexTranslations = std::unordered_map<std::string, std::pair<std::string, std::string>>;

static ScSCnTexTranslations const translations = {
    { "примечание*", { "nrel_note", "sc_node_norole_relation" } },
    { "пояснение*", { "nrel_explanation", "sc_node_norole_relation" } },
    { "идентификатор*", { "nrel_idtf", "sc_node_norole_relation" } },
    { "эпиграф*", { "nrel_epigraph", "sc_node_norole_relation" } },
    { "аннотация*", { "nrel_summary", "sc_node_norole_relation" } },
    { "включение*", { "nrel_inclusion", "sc_node_norole_relation" } },
    { "разбиение*", { "nrel_subdividing", "sc_node_norole_relation" } },
    { "максимальный класс объектов исследования*", { "rrel_maximum_studied_object_class", "sc_node_role_relation" } },
    { "класс объектов исследования*", { "rrel_studied_object_class", "sc_node_role_relation" } },
    { "исследуемое отношение*", { "rrel_explored_relation", "sc_node_role_relation" } },
};
