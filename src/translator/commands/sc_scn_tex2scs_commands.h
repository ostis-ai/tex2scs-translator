#pragma once

#include <unordered_map>
#include <unordered_set>

#include "sc_scn_tex_command_defines.h"

using ScSCnTexCommands = std::unordered_map<std::string, ScSCnTexCommand *>;

static ScSCnTexCommands const commands = {
    { "textit", new ScSCnTexTextitCommand() },
    { "textb", new ScSCnTexTextbCommand() },
    { "uline", new ScSCnTexUlineCommand() },
    { "\\", new ScSCnTexNewLineCommand() },

    { "scnheader", new ScSCnTexHeaderCommand() },
    { "scnstructheader", new ScSCnTexStructHeaderCommand() },
    { "scnsectionheader", new ScSCnTexSectionHeaderCommand() },
    { "scnsegmentheader", new ScSCnTexSegmentHeaderCommand() },

    { "scntext", new ScSCnTexTextRelationCommand() },
    { "scnidtf", new ScSCnTexIdtfCommand() },
    { "scnnote", new ScSCnTexNoteCommand() },

    { "scniselement", new ScSCnTexIsElementCommand() },
    { "scnrelto", new ScSCnTexNrelToCommand() },
    { "scnsuperset", new ScSCnTexSupersetCommand() },

    { "scnaddlevel", new ScSCnTexAddLevelCommand() },
};

using ScSCnTexIgnoreCommands = std::unordered_set<std::string>;

static ScSCnTexIgnoreCommands const ignoreCommands = {
    "newpage", "scnbigspace ", "bigskip", "mbox",
};
