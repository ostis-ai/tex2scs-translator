grammar SCnTex;

options
{
  language = Cpp;
}

@parser::header
{
#include "../translator/tree/sc_scn_prefix_tree.h"
#include "../translator/commands/sc_scn_tex2scs_commands.h"
}

scnTexText
  returns [std::string resultText]
  locals
  [
  using ScSCnCommandsHistory = std::vector<std::string>,
  ScSCnCommandsHistory * history = new ScSCnCommandsHistory(),

  ScSCnPrefixTree * prefixTree = ScSCnPrefixTree::GetInstance(),
  ]
  :
  {
  std::stringstream resultStream;
  }
  (result=scnTexCommand[$history, $prefixTree]
    {
    resultStream << $result.resultText;
    }
  | lineComment WS
  )* EOF?
  {
  resultStream << ";;\n";
  $resultText = resultStream.str();

  delete $history;
  }
  ;

scnTexCommand[ScSCnCommandsHistory * history, ScSCnPrefixTree * prefixTree]
  returns [std::string resultText]
  locals [ScSCnTexCommand * command, std::string commandName]
  :
  (name=scnTexCommandName
  {
  $commandName = $name.text.substr(1);
  auto const & it = commands.find($commandName);

  auto const & ignoreIt = ignoreCommands.find($commandName);
  if (ignoreIt == ignoreCommands.cend())
  {
    if (it != commands.cend())
      $command = it->second;
    else
      $command = commands.find("relation")->second;
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
  params.push_back($commandName);
  }
  (
    WS? ('{' | '[') WS?
    {
    std::stringstream argStream;
    }
    (
      WS? sent=scnTexCommandContent
      {
      argStream << $sent.text;
      }
      | WS? result=scnTexCommand[$history, $prefixTree]
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
        WS? sent=scnTexCommandContent
        {
        argStream << $sent.text;
        }
        | WS? result=scnTexCommand[$history, $prefixTree]
        {
        argStream << $result.resultText;
        }
      )*
      {
        params.push_back(argStream.str());
      }
    )*
    WS? ('}' | ']') WS?
  )*
  {
  if ($command != nullptr)
  {
    std::cout << "Interpreter command: " << $commandName << std::endl;
    history->push_back($commandName);
    $resultText = $command->Complete(*history, *prefixTree, params);
  }
  $command == nullptr;
  }
  ;

scnTexCommandContent
  : TEXT
  ;

scnTexCommandName
  : NAME
  ;

TEXT
  : ([а-яёЁА-Яa-zA-Z0-9_#+=> <^'"«»/()$*-]
  | '.' | ',' | '~' | '?' | '!' | ':' | '`' | '–' | '…' | '—')+
  ;

NAME
  : '\\' ([a-zA-Z0-9\\])*
  ;

WS
  : [ \t\r\n\u2028\u2029]+
  ;

lineComment
  : '%' (NAME | TEXT | '{' | '}')*
  ;
