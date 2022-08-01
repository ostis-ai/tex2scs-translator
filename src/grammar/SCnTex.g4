grammar scn_tex;

options
{
  language = Cpp;
}

@parser::header
{
#include "../translator/commands/tree/sc_scn_prefix_tree.h"
#include "../sc_scn_tex2scs_commands.h"
}

scnTexText
  locals
  [
  ScSCnPrefixTree * prefixTree = new ScSCnPrefixTree();
  ]
  : scnTexCommand[$ctx->prefixTree]* EOF
  ;

scnTexCommand[ScSCnPrefixTree * prefixTree]
  returns [std::string resultText]
  : WS? '\\' name=scnTexCommandName WS?
  {
  std::cout << "Command: " << $name.text << std::endl;
  auto const & it = commands.find($name.text);
  ScSCnTexCommand * command;
  if (it != commands.cend())
    command = it->second;

  ScScnTexCommandParams params;
  }
  (
   '{'
    {
    std::stringstream argStream;
    }
    (
      sent=scnTexCommandContent
      {
      argStream << $sent.text;;
      }
      | result=scnTexCommand[$prefixTree]
      {
      argStream << $result.text;;
      }
    )*
    {
    params.push_back(argStream.str());
    argStream.clear();
    }
    (';'
      (
        sent=scnTexCommandContent
        {
        argStream << $sent.text;;
        }
        | result=scnTexCommand[$prefixTree]
        {
        argStream << $result.text;;
        }
      )*
      {
        params.push_back(argStream.str());
      }
    )*
    '}'
    {
    params.push_back("new");
    }
  )*
  {
  $resultText = command->Complete(*prefixTree, params);
  }
  WS?
  ;

scnTexCommandContent
  : TEXT
  ;

scnTexCommandName
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
