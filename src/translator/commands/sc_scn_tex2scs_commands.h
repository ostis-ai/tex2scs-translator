#pragma once

#include <unordered_map>
#include <unordered_set>

#include "sc_scn_tex_command_defines.h"

using ScSCnTexCommands = std::unordered_map<std::string, ScSCnTexCommand *>;

static ScSCnTexCommands const commands = {
    { "textit", new ScSCnTexTextitCommand() },
    { "mathbb", new ScSCnTexTextitCommand() },
    { "textbf", new ScSCnTexTextbfCommand() },
    { "bm", new ScSCnTexTextbfCommand() },
    { "mbox", new ScSCnTexTextbfCommand() },
    { "uline", new ScSCnTexUlineCommand() },
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
    { "includegraphics", new ScSCnTexIncludeGraphicsCommand() },

    { "currentname", new ScSCnTexCurrentNameCommand() },
    { "input", new ScSCnTexInputCommand() },
    { "scnheader", new ScSCnTexHeaderCommand() },
    { "scnfilelongheader", new ScSCnTexFileHeaderCommand() },
    { "scnheaderlocal", new ScSCnTexHeaderLocalCommand() },
    { "scnstructheader", new ScSCnTexStructHeaderCommand() },
    { "scnstructheaderlocal", new ScSCnTexStructHeaderLocalCommand() },
    { "scnsectionheader", new ScSCnTexSectionHeaderCommand() },
    { "scnsegmentheader", new ScSCnTexSegmentHeaderCommand() },

    { "scnstructidtf", new ScSCnTexStructIdtfCommand() },
    { "scnkeyword", new ScSCnTexKeywordCommand() },

    { "scnstartset", new ScSCnTexStartSetCommand() },
    { "scnendset", new ScSCnTexEndSetCommand() },
    { "scnstartsetlocal", new ScSCnTexStartSetLocalCommand() },
    { "scnstartsubstruct", new ScSCnTexStartSubstructCommand() },
    { "scnendsubstruct", new ScSCnTexEndSubstructCommand() },

    { "relation", new ScSCnTexNRelCommand() },
    { "math", new ScSCnTexMathCommand() },
};

using ScSCnTexIgnoreCommands = std::unordered_set<std::string>;

static ScSCnTexIgnoreCommands const ignoreCommands = {
    "scsection", "bigskip", "label", "linewidth", "scnendsegmentcomment", "scnendcurrentsectioncomment"
};
