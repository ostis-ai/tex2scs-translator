#pragma once

#include "sc_scn_tex_list_command.h"

class ScSCnTexNRelCommand : public ScSCnTexListCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;

  uint8_t const MAX_PARAMS = 3;
  uint8_t const REL_PARAM_POS = 1;
  uint8_t const MAX_OBJECT_PARAM_POS = 2;
  uint8_t const MIN_OBJECT_PARAM_POS = 1;

  uint8_t const MAX_REL_ATTRS = 3;
  uint8_t const EDGE_ATTR_POS = 0;
  uint8_t const REL_MODIFIER_ATTR_POS = 1;
  uint8_t const REL_ATTR_POS = 2;
  uint8_t const MAX_REL_ATTRS_WITH_REl_MODIFIER = 2;
};
