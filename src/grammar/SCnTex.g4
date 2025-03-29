grammar SCnTex;

options
{
  language = Cpp;
}

@parser::header
{
#include "translator/identifiers-tree/sc_scn_prefix_tree.h"
#include "translator/file-structs/sc_scn_file_structs_tree.h"
#include "translator/commands/sc_scn_tex2scs_commands.h"
#include "translator/log/sc_log.hpp"
}

scnTexText
  returns [std::string resultText]
  locals
  [
  using ScSCnCommandsHistory = std::vector<std::string>,
  ScSCnCommandsHistory * history = new ScSCnCommandsHistory(),

  ScSCnPrefixTree * prefixTree = ScSCnPrefixTree::GetInstance(),
  ScSCnFileStructsTree * fileStructsTree = ScSCnFileStructsTree::GetInstance(),
  ]
  :
  {
  std::stringstream resultStream;
  }
  (result=scnTexCommand[$history, $prefixTree]
    {
    resultStream << $result.resultText;
    }
  | COMMENT | WS
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
  ('$'? name=scnTexCommandName
    {
      $commandName = $name.text.substr(1);
      auto const & it = commands.find($commandName);

      auto const & ignoreIt = ignoreCommands.find($commandName);
      if (ignoreIt == ignoreCommands.cend())
      {
        if (it != commands.cend())
          $command = it->second;
        else if (commands.find("relation") != commands.cend() && $commandName.find("scn") == 0)
          $command = commands.find("relation")->second;
        else
          $command = commands.find("math")->second;
      }
      else
      {
        SC_LOG_WARNING("Ignore command: " << $commandName);
        $command = nullptr;
      }
    }
  )
  WS?
  {
    ScSCnTexCommandParams params;
    params.push_back($commandName);
  }
  (WS? b=('{' | '[') WS?
    {
      std::stringstream argStream;
    }
    (WS? result=scnTexCommand[$history, $prefixTree]
      {
        argStream << $result.resultText;
      }
      | WS? '$'? sent=scnTexCommandContent '$'?
      {
        if ($ctx->b->getText() == "{")
          argStream << $sent.text;
      }
      | '~'
    )*
    {
      if ($ctx->b->getText() == "{")
        params.push_back(argStream.str());
    }
  WS? ('}' | ']') WS?
  )*
  '$'?
    {
      if ($command != nullptr)
      {
        SC_LOG_DEBUG("Interpreter command: " << $commandName);
        history->push_back($commandName);
        $resultText = $command->Complete(*history, *prefixTree, params);
      }
      $command = nullptr;
    }
  COMMENT?
  ;

scnTexCommandContent
  : TEXT
  ;

scnTexCommandName
  : NAME
  ;

TEXT
  : ([а-яёЁА-Яa-zA-Z0-9]
  | '!' | '@' | '#' | '%' | '^' | '&' | '(' | ')'
  | '_' | '+' | '-' | '=' | '/' | '*' | '.' | '`'
  | ',' | '|' | ' ' | ':' | ';' | '<' | '>' | '?')+
  ;

NAME
  : ('\\' ([a-zA-Z0-9]) ([a-zA-Z0-9_])*)
  | '\\'
  ;

WS
  : [ \t\r\n\u2028\u2029]+
  ;

COMMENT
  : [ ]* '%' (~[\\])*
  ;
