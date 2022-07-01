grammar scn_tex;

options
{
  language = Cpp;
}

@parser::header
{
}

scn_tex_text
  : scn_tex_command* EOF
  ;

scn_tex_command
  : WS? '\\' scn_tex_command_name WS? ('{' scn_tex_command_args '}')* WS?
  ('{'
      (scn_tex_command
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
  : ([а-яёЁА-Яa-zA-Z0-9._#+=> <'"«»/()*-]
  | '.' | ',' | '.' | '?' | '!')+
  ;

NAME
  : [a-z]+
  ;

WS
  : [ \t\r\n\u2028\u2029]+
  ;
