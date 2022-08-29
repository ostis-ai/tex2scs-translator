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
    { "scnheaderlocal", new ScSCnTexHeaderLocalCommand() },
    { "currentname", new ScSCnTexCurrentNameCommand() },
    { "scnstructheader", new ScSCnTexStructHeaderCommand() },
    { "scnstructheaderlocal", new ScSCnTexStructHeaderLocalCommand() },
    { "scnsectionheader", new ScSCnTexSectionHeaderCommand() },
    { "scnsegmentheader", new ScSCnTexSegmentHeaderCommand() },

    { "scnstructidtf", new ScSCnTexStructIdtfCommand() },
    { "scnkeyword", new ScSCnTexKeywordCommand() },

    { "scntext", new ScSCnTexTextRelationCommand() },
    { "scnidtf", new ScSCnTexIdtfCommand() },
    // { "scnidtftext", new ScSCnTexIdtfTextCommand() },
    { "scnnote", new ScSCnTexNoteCommand() }, // DEPRECATED 
    { "scnidtfexp", new ScSCnTexNoteCommand() }, // DEPRECATED 
    { "scnexplanation", new ScSCnTexExplanationCommand() }, // DEPRECATED
    { "scnidtfdef", new ScSCnTexExplanationCommand() }, // DEPRECATED

    { "scniselement", new ScSCnTexIsElementCommand() },
    { "scnisvarelement", new ScSCnTexIsVarElementCommand() },
    { "scniselementrole", new ScSCnTexIsElementRoleCommand() },
    { "scnhaselement", new ScSCnTexHasElementCommand() },
    { "scnhasvarelement", new ScSCnTexHasVarElementCommand() },
    { "scnhaselementrole", new ScSCnTexHasElementRoleCommand() },
    { "scnhasvarelementrole", new ScSCnTexHasVarElementRoleCommand() },
    { "scnhaselementset", new ScSCnTexHasElementSetCommand() }, // DEPRECATED
    { "scnhaselementlist", new ScSCnTexHasElementListCommand() }, // DEPRECATED
    { "scnsdmainclasssingle", new ScSCnTexSdMainClassCommand() }, // DEPRECATED
    { "scnsdclass", new ScSCnTexSdClassCommand() }, // DEPRECATED
    { "scnsdrelation", new ScSCnTexSdRelationCommand() }, // DEPRECATED
    { "scnrelto", new ScSCnTexNrelToCommand() },
    { "scnvarrelto", new ScSCnTexVarNrelToCommand() },
    { "scnsuperset", new ScSCnTexSupersetCommand() },
    { "scnrelfrom", new ScSCnTexNrelFromCommand() },
    //{ "scnrelsuperset", new ScSCnTexRelSupersetCommand() },
    { "scnvarrelfrom", new ScSCnTexVarNrelFromCommand() },
    { "scnsubset", new ScSCnTexSubsetCommand() },
    { "scnnotsubset", new ScSCnTexNotSubsetCommand() },
    { "scnrelfromset", new ScSCnTexNrelFromSetCommand() },
    { "scnsubdividing", new ScSCnTexSubdividingCommand() },
    { "scnrelfromlist", new ScSCnTexNrelFromListCommand() },
    { "scnrelfromvector", new ScSCnTexNrelFromVectorCommand() },
    { "scnrelboth", new ScSCnTexNrelBothCommand() },
    { "scnstartset", new ScSCnTexStartSetCommand() },
    { "scnstartsetlocal", new ScSCnTexStartSetLocalCommand() },
    { "scnstartsubstruct", new ScSCnTexStartSubstructCommand() },
    { "scnendstruct", new ScSCnTexEndStructCommand() },
    //{ "scneq", new ScSCnTexEqCommand() },
    //{ "scneqfile", new ScSCnTexEqFileCommand() },
    //{ "scneqimage", new ScSCnTexEqImageCommand() },
    //{ "scnfiletable", },
    //{ "scneqtable", },
    //{ "scnfileclass", new ScSCnTexFileClassCommand() },
    //{ "scneqfileclass", new ScSCnTexEqFileClassCommand() },

    { "scnfileitem", new ScSCnTexFileItemCommand() }, // DEPRECATED
    { "scnfilescg", new ScSCnTexFileSCgItemCommand() }, // DEPRECATED
    { "scnfileimage", new ScSCnTexFileImageCommand() },
    { "includegraphics", new ScSCnTexIncludeGraphicsCommand() },
    { "scnfilelong", new ScSCnTexFileLongCommand() },

    { "scnnonamednode", new ScSCnTexNoNamedNodeCommand() },
    { "scnrolesign", new ScSCnTexRoleSignCommand() },
    { "scnsupergroupsign", new ScSCnTexSupergroupSignCommand() },
};

using ScSCnTexIgnoreCommands = std::unordered_set<std::string>;

static ScSCnTexIgnoreCommands const ignoreCommands = {
    "scnbigspace", "bigskip", "mbox", "label", "scncite", "nameref", "linewidth"
};
