#pragma once

#include <unordered_map>
#include <unordered_set>

#include "sc_scn_tex_command_defines.h"

using ScSCnTexCommands = std::unordered_map<std::string, ScSCnTexCommand *>;

static ScSCnTexCommands const commands = {
    { "textit", new ScSCnTexTextitCommand() },
    { "textbf", new ScSCnTexTextbfCommand() },
    { "uline", new ScSCnTexUlineCommand() },
    { "\\", new ScSCnTexNewLineCommand() },
    { "newpage", new ScSCnTexNewLineCommand() },
    { "begin", new ScSCnTexBeginListCommand() },
    { "item", new ScSCnTexListItemCommand() },
    { "end", new ScSCnTexEndListCommand() },
    { "scnqq", new ScSCnTexQQCommand() },
    { "scnqqi", new ScSCnTexQQICommand() },
    { "scnitem", new ScSCnTexScnitemCommand() },
    { "cite", new ScSCnTexCiteCommand() },
    { "scncite", new ScSCnTexCiteCommand() },
    { "nameref", new ScSCnTexRefCommand() },

    { "scnfileclass", new ScSCnTexFileClassCommand() },
    { "scnfileimage", new ScSCnTexFileImageCommand() },
    { "scnfileitem", new ScSCnTexFileItemCommand() },
    { "scnfilelong", new ScSCnTexFileLongCommand() },
    { "scnfilescgitem", new ScSCnTexFileSCgItemCommand() },
    { "scnincludegraphics", new ScSCnTexIncludeGraphicsCommand() },

    { "scnheader", new ScSCnTexHeaderCommand() },
    { "scnheaderlocal", new ScSCnTexHeaderLocalCommand() },
    { "currentname", new ScSCnTexCurrentNameCommand() },
    { "scnstructheader", new ScSCnTexStructHeaderCommand() },
    { "scnstructheaderlocal", new ScSCnTexStructHeaderLocalCommand() },
    { "scnsectionheader", new ScSCnTexSectionHeaderCommand() },
    { "scnsegmentheader", new ScSCnTexSegmentHeaderCommand() },

    { "scnstructidtf", new ScSCnTexStructIdtfCommand() },
    { "scnkeyword", new ScSCnTexKeywordCommand() },

    { "relation", new ScSCnTexNRelCommand() },

    { "scnstartset", new ScSCnTexStartSetCommand() },
    { "scnendset", new ScSCnTexEndSetCommand() },
    { "scnstartsetlocal", new ScSCnTexStartSetLocalCommand() },
    { "scnstartsubstruct", new ScSCnTexStartSubstructCommand() },
    { "scnendsubstruct", new ScSCnTexEndSubstructCommand() },

    { "scnnonamednode", new ScSCnTexNoNamedNodeCommand() },
    { "scnrolesign", new ScSCnTexRoleSignCommand() },
    { "scnsupergroupsign", new ScSCnTexSupergroupSignCommand() },
};

using ScSCnTexIgnoreCommands = std::unordered_set<std::string>;

static ScSCnTexIgnoreCommands const ignoreCommands = {
    "scsection", "bigskip", "mbox", "label", "linewidth"
};
