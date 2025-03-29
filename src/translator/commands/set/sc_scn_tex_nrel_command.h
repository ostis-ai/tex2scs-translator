#pragma once

#include "sc_scn_tex_list_command.h"

class ScSCnTexNRelCommand : public ScSCnTexListCommand
{
public:
  ScSCnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScSCnTexCommandParams const & params) override;

  uint8_t const MAX_PARAMS = 3;
  uint8_t const RELATION_PARAM_POS = 1;
  uint8_t const MAX_OBJECT_PARAM_POS = 2;
  uint8_t const MIN_OBJECT_PARAM_POS = 1;

  uint8_t const MAX_RELATION_ATTRS = 3;
  uint8_t const CONNECTOR_ATTR_POS = 0;
  uint8_t const RELATION_MODIFIER_ATTR_POS = 1;
  uint8_t const RELATION_ATTR_POS = 2;
  uint8_t const MAX_RELATION_ATTRS_WITH_RELATION_MODIFIER = 2;
};
