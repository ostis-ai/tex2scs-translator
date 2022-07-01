grammar scn_tex;

options
{
  language = Cpp;
}

@parser::header
{
#include "../translator/commands/tree/sc_scn_prefix_tree.h"
}

scn_tex_text
  locals
  [
  ScSCnPrefixTree * prefixTree = new ScSCnPrefixTree();
  ]
  : scn_tex_command[$ctx->prefixTree, $ctx->commands]* EOF
  ;

scn_tex_command[ScSCnPrefixTree * prefixTree, ScSCnTexCommands * commands]
  : WS? '\\' name=scn_tex_command_name WS? ('{' arg=scn_tex_command_args '}')* WS?
  ('{'
      (scn_tex_command[$prefixTree, $commands]
      | scn_tex_command_content)*
  '}')?
  ;

scn_tex_command_args
  : TEXT
  ;

scn_tex_command_content
  : TEXT
  ;

scn_tex_command_name
  : TEXT
  ;

TEXT
  : ([а-яёЁА-Яa-zA-Z0-9_#+=> <'"«»/()*-]
  | '.' | ',' | '~' | '?' | '!')+
  ;

NAME
  : [a-z]+
  ;

WS
  : [ \t\r\n\u2028\u2029]+
  ;
