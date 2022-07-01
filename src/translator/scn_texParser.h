


// Generated from /home/nikita/ostis-apps/develop/ostis-web-platform-1/tools/tex2scs-translator/src/grammar/scn_tex.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  scn_texParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, TEXT = 4, NAME = 5, WS = 6
  };

  enum {
    RuleScn_tex_text = 0, RuleScn_tex_command = 1, RuleScn_tex_command_args = 2, 
    RuleScn_tex_command_content = 3, RuleScn_tex_command_name = 4
  };

  explicit scn_texParser(antlr4::TokenStream *input);

  scn_texParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~scn_texParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class Scn_tex_textContext;
  class Scn_tex_commandContext;
  class Scn_tex_command_argsContext;
  class Scn_tex_command_contentContext;
  class Scn_tex_command_nameContext; 

  class  Scn_tex_textContext : public antlr4::ParserRuleContext {
  public:
    Scn_tex_textContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Scn_tex_commandContext *> scn_tex_command();
    Scn_tex_commandContext* scn_tex_command(size_t i);

   
  };

  Scn_tex_textContext* scn_tex_text();

  class  Scn_tex_commandContext : public antlr4::ParserRuleContext {
  public:
    scn_texParser::Scn_tex_command_argsContext *arg = nullptr;
    Scn_tex_commandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Scn_tex_command_nameContext *scn_tex_command_name();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    std::vector<Scn_tex_command_argsContext *> scn_tex_command_args();
    Scn_tex_command_argsContext* scn_tex_command_args(size_t i);
    std::vector<Scn_tex_commandContext *> scn_tex_command();
    Scn_tex_commandContext* scn_tex_command(size_t i);
    std::vector<Scn_tex_command_contentContext *> scn_tex_command_content();
    Scn_tex_command_contentContext* scn_tex_command_content(size_t i);

   
  };

  Scn_tex_commandContext* scn_tex_command();

  class  Scn_tex_command_argsContext : public antlr4::ParserRuleContext {
  public:
    Scn_tex_command_argsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEXT();

   
  };

  Scn_tex_command_argsContext* scn_tex_command_args();

  class  Scn_tex_command_contentContext : public antlr4::ParserRuleContext {
  public:
    Scn_tex_command_contentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEXT();

   
  };

  Scn_tex_command_contentContext* scn_tex_command_content();

  class  Scn_tex_command_nameContext : public antlr4::ParserRuleContext {
  public:
    Scn_tex_command_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEXT();

   
  };

  Scn_tex_command_nameContext* scn_tex_command_name();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

