#include "translator/commands/format/sc_scn_tex_textit_command.h"
#include "translator/commands/format/sc_scn_tex_textbf_command.h"
#include "translator/commands/format/sc_scn_tex_uline_command.h"
#include "translator/commands/format/sc_scn_tex_qq_command.h"
#include "translator/commands/format/sc_scn_tex_qqi_command.h"
#include "translator/commands/format/sc_scn_tex_cite_command.h"
#include "translator/commands/format/sc_scn_tex_ref_command.h"

#include "translator/commands/file/sc_scn_tex_file_class_command.h"
#include "translator/commands/file/sc_scn_tex_file_image_command.h"
#include "translator/commands/file/sc_scn_tex_file_item_command.h"
#include "translator/commands/file/sc_scn_tex_file_long_command.h"
#include "translator/commands/file/sc_scn_tex_file_scg_item_command.h"
#include "translator/commands/file/sc_scn_tex_include_graphics_command.h"

#include "translator/commands/header/sc_scn_tex_current_name_command.h"
#include "translator/commands/header/sc_scn_tex_input_command.h"
#include "translator/commands/header/sc_scn_tex_header_command.h"
#include "translator/commands/header/sc_scn_tex_file_header_command.h"
#include "translator/commands/header/sc_scn_tex_header_local_command.h"
#include "translator/commands/header/sc_scn_tex_keyword_command.h"
#include "translator/commands/header/sc_scn_tex_section_header_command.h"
#include "translator/commands/header/sc_scn_tex_segment_header_command.h"
#include "translator/commands/header/sc_scn_tex_struct_header_command.h"
#include "translator/commands/header/sc_scn_tex_struct_header_local_command.h"
#include "translator/commands/header/sc_scn_tex_struct_identifier_command.h"

#include "translator/commands/set/sc_scn_tex_nrel_command.h"

#include "translator/commands/set/sc_scn_tex_begin_list_command.h"
#include "translator/commands/set/sc_scn_tex_list_item_command.h"
#include "translator/commands/set/sc_scn_tex_end_list_command.h"
#include "translator/commands/set/sc_scn_tex_scnitem_command.h"
#include "translator/commands/set/sc_scn_tex_start_set_command.h"
#include "translator/commands/set/sc_scn_tex_end_set_command.h"
#include "translator/commands/set/sc_scn_tex_start_set_local_command.h"
#include "translator/commands/set/sc_scn_tex_start_substruct_command.h"
#include "translator/commands/set/sc_scn_tex_end_substruct_command.h"

#include "translator/commands/math/sc_scn_tex_math_command.h"
