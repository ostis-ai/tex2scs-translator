#pragma once

#include "memory"
#include "translator/sc_scn_tex2scs_translator.h"
#include "translator/commands/sc_scn_tex_idtf_command_defines.h"

class ScSCnTex2SCsTranslatorBuilder
{
public:
  static std::unique_ptr<ScSCnTex2SCsTranslator> BuildDefaultTranslator()
  {
    ScSCnTexCommands const & commands = {
        { "scnidtf", new ScSCnTexIdtfCommand() },
    };

    return std::make_unique<ScSCnTex2SCsTranslator>(commands);
  }
};
