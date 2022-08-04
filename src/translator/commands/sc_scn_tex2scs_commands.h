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

    { "scnheader", new ScSCnTexHeaderCommand() },
    { "currentname", new ScSCnTexCurrentNameCommand() },
    { "scnstructheader", new ScSCnTexStructHeaderCommand() },
    { "scnsectionheader", new ScSCnTexSectionHeaderCommand() },
    { "scnsegmentheader", new ScSCnTexSegmentHeaderCommand() },

    { "scntext", new ScSCnTexTextRelationCommand() },
    { "scnidtf", new ScSCnTexIdtfCommand() },
    { "scnnote", new ScSCnTexNoteCommand() },
    { "scnidtfexp", new ScSCnTexNoteCommand() },
    { "scnexplanation", new ScSCnTexExplanationCommand() },
    { "scnidtfdef", new ScSCnTexExplanationCommand() },

    { "scniselement", new ScSCnTexIsElementCommand() },
    { "scniselementrole", new ScSCnTexIsElementRoleCommand() },
    { "scnhaselement", new ScSCnTexHasElementCommand() },
    { "scnhaselementrole", new ScSCnTexHasElementRoleCommand() },
    { "scnhaselementset", new ScSCnTexHasElementSetCommand() },
    { "scnhaselementlist", new ScSCnTexHasElementListCommand() },
    { "scnsdmainclasssingle", new ScSCnTexSdMainClassCommand() },
    { "scnsdclass", new ScSCnTexSdClassCommand() },
    { "scnsdrelation", new ScSCnTexSdRelationCommand() },
    { "scnrelto", new ScSCnTexNrelToCommand() },
    { "scnsuperset", new ScSCnTexSupersetCommand() },
    { "scnrelfrom", new ScSCnTexNrelFromCommand() },
    { "scnsubset", new ScSCnTexSubsetCommand() },
    { "scnrelfromset", new ScSCnTexNrelFromSetCommand() },
    { "scnsubdividing", new ScSCnTexSubdividingCommand() },
    { "scnrelfromlist", new ScSCnTexNrelFromListCommand() },
    { "scnrelfromvector", new ScSCnTexNrelFromVectorCommand() },
    { "scnrelboth", new ScSCnTexNrelBothCommand() },
    { "scnstartset", new ScSCnTexStartSetCommand() },
    { "scnstartsetlocal", new ScSCnTexStartSetLocalCommand() },
    { "scnstartsubstruct", new ScSCnTexStartSubstructCommand() },
    { "scnendstruct", new ScSCnTexEndStructCommand() },

    { "scnfileitem", new ScSCnTexFileItemCommand() },
    { "scnfilescg", new ScSCnTexFileSCgItemCommand() },
    { "scnfileimage", new ScSCnTexFileImageCommand() },
    { "includegraphics", new ScSCnTexIncludeGraphicsCommand() },
    { "scnfilelong", new ScSCnTexFileLongCommand() },

    { "scnaddlevel", new ScSCnTexAddLevelCommand() },

    { "scnrolesign", new ScSCnTexRoleSignCommand() },
    { "scnsupergroupsign", new ScSCnTexSupergroupSignCommand() },
};

using ScSCnTexIgnoreCommands = std::unordered_set<std::string>;

static ScSCnTexIgnoreCommands const ignoreCommands = {
    "scnbigspace", "bigskip", "mbox", "label", "scncite", "nameref", "linewidth"
};
