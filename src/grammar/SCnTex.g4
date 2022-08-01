grammar SCnTex;

options
{
  language = Cpp;
}

@parser::header
{
#include "tree/sc_scn_prefix_tree.h"
#include "commands/sc_scn_tex2scs_commands.h"
}

scnTexText
  returns [std::string resultText]
  locals
  [
  using ScSCnCommandsHistory = std::vector<std::string>,
  ScSCnCommandsHistory * history = new ScSCnCommandsHistory(),

  ScSCnPrefixTree * prefixTree = new ScSCnPrefixTree(),
  ]
  :
  {
  std::stringstream resultStream;
  }
  (result=scnTexCommand[$history, $prefixTree]
    {
    resultStream << $result.resultText;
    }
  )* EOF?
  {
  $resultText = resultStream.str();

  delete $prefixTree;
  delete $history;
  }
  ;

scnTexCommand[ScSCnCommandsHistory * history, ScSCnPrefixTree * prefixTree]
  returns [std::string resultText]
  locals [ScSCnTexCommand * command, std::string commandName]
  :
  WS? (name=scnTexCommandName
  {
  $commandName = $name.text.substr(1);
  auto const & it = commands.find($commandName);

  auto const & ignoreIt = ignoreCommands.find($commandName);
  if (ignoreIt == ignoreCommands.cend())
  {
    if (it != commands.cend())
      $command = it->second;
    else
      std::cout << "Not found: " << $commandName << std::endl;
  }
  else
  {
    std::cout << "Ignore command: " << $commandName << std::endl;
    $command = nullptr;
  }
  })
  WS?
  {
  ScScnTexCommandParams params;
  }
  (
   '{'
    WS?
    {
    std::stringstream argStream;
    }
    (
      sent=scnTexCommandContent
      {
      argStream << $sent.text;
      }
      | result=scnTexCommand[$history, $prefixTree]
      {
      argStream << $result.resultText;
      }
    )*
    {
    params.push_back(argStream.str());
    }
    (WS? ';' WS?
      {
      std::stringstream argStream;
      }
      (
        sent=scnTexCommandContent
        {
        argStream << $sent.text;
        }
        | result=scnTexCommand[$history, $prefixTree]
        {
        argStream << $result.resultText;
        }
      )*
      {
        params.push_back(argStream.str());
      }
    )*
    WS?
    '}'
    {
    params.push_back("/");
    }
  )*
  {
  if ($command != nullptr)
  {
    std::cout << "Interpreter command: " << $commandName << std::endl;
    $resultText = $command->Complete(*history, *prefixTree, params);
    history->push_back($commandName);
  }
  }
  WS?
  ;

scnTexCommandContent
  : TEXT
  ;

scnTexCommandName
  : NAME
  ;

TEXT
  : ([а-яёЁА-Яa-zA-Z0-9_#+=> <'"«»/()*-]
  | '.' | ',' | '~' | '?' | '!' | ':' | ';' | '`')+
  ;

NAME
  : '\\' ([a-zA-Z0-9\\])*
  ;

WS
  : [ \t\r\n\u2028\u2029]+
  ;
