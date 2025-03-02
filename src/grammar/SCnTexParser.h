
#include "../translator/identifiers-tree/sc_scn_prefix_tree.h"
#include "../translator/file-structs/sc_scn_file_structs_tree.h"
#include "../translator/commands/sc_scn_tex2scs_commands.h"
#include "../translator/log/sc_log.hpp"


// Generated from /Users/nikitazotov/Development/apps/ostis/ostis-ai/tex2scs-translator/src/grammar/SCnTex.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  SCnTexParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, TEXT = 7, 
    NAME = 8, WS = 9, COMMENT = 10
  };

  enum {
    RuleScnTexText = 0, RuleScnTexCommand = 1, RuleScnTexCommandContent = 2, 
    RuleScnTexCommandName = 3
  };

  SCnTexParser(antlr4::TokenStream *input);
  ~SCnTexParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ScnTexTextContext;
  class ScnTexCommandContext;
  class ScnTexCommandContentContext;
  class ScnTexCommandNameContext; 

  class  ScnTexTextContext : public antlr4::ParserRuleContext {
  public:
    std::string resultText;
    using ScSCnCommandsHistory = std::vector<std::string>;
    ScSCnCommandsHistory * history = new ScSCnCommandsHistory();
    ScSCnPrefixTree * prefixTree = ScSCnPrefixTree::GetInstance();
    ScSCnFileStructsTree * fileStructsTree = ScSCnFileStructsTree::GetInstance();
    SCnTexParser::ScnTexCommandContext *result = nullptr;;
    ScnTexTextContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> COMMENT();
    antlr4::tree::TerminalNode* COMMENT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    antlr4::tree::TerminalNode *EOF();
    std::vector<ScnTexCommandContext *> scnTexCommand();
    ScnTexCommandContext* scnTexCommand(size_t i);

   
  };

  ScnTexTextContext* scnTexText();

  class  ScnTexCommandContext : public antlr4::ParserRuleContext {
  public:
    ScSCnCommandsHistory * history;
    ScSCnPrefixTree * prefixTree;
    std::string resultText;
    ScSCnTexCommand * command;
    std::string commandName;
    SCnTexParser::ScnTexCommandNameContext *name = nullptr;;
    antlr4::Token *b = nullptr;;
    SCnTexParser::ScnTexCommandContext *result = nullptr;;
    SCnTexParser::ScnTexCommandContentContext *sent = nullptr;;
    ScnTexCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ScnTexCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState, ScSCnCommandsHistory * history, ScSCnPrefixTree * prefixTree);
    virtual size_t getRuleIndex() const override;
    ScnTexCommandNameContext *scnTexCommandName();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    antlr4::tree::TerminalNode *COMMENT();
    std::vector<ScnTexCommandContext *> scnTexCommand();
    ScnTexCommandContext* scnTexCommand(size_t i);
    std::vector<ScnTexCommandContentContext *> scnTexCommandContent();
    ScnTexCommandContentContext* scnTexCommandContent(size_t i);

   
  };

  ScnTexCommandContext* scnTexCommand(ScSCnCommandsHistory * history,ScSCnPrefixTree * prefixTree);

  class  ScnTexCommandContentContext : public antlr4::ParserRuleContext {
  public:
    ScnTexCommandContentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEXT();

   
  };

  ScnTexCommandContentContext* scnTexCommandContent();

  class  ScnTexCommandNameContext : public antlr4::ParserRuleContext {
  public:
    ScnTexCommandNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();

   
  };

  ScnTexCommandNameContext* scnTexCommandName();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

