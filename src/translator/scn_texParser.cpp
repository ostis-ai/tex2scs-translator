


// Generated from /home/nikita/ostis-apps/develop/ostis-web-platform-1/tools/tex2scs-translator/src/grammar/scn_tex.g4 by ANTLR 4.10.1



#include "scn_texParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct Scn_texParserStaticData final {
  Scn_texParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Scn_texParserStaticData(const Scn_texParserStaticData&) = delete;
  Scn_texParserStaticData(Scn_texParserStaticData&&) = delete;
  Scn_texParserStaticData& operator=(const Scn_texParserStaticData&) = delete;
  Scn_texParserStaticData& operator=(Scn_texParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag scn_texParserOnceFlag;
Scn_texParserStaticData *scn_texParserStaticData = nullptr;

void scn_texParserInitialize() {
  assert(scn_texParserStaticData == nullptr);
  auto staticData = std::make_unique<Scn_texParserStaticData>(
    std::vector<std::string>{
      "scn_tex_text", "scn_tex_command", "scn_tex_command_args", "scn_tex_command_content", 
      "scn_tex_command_name"
    },
    std::vector<std::string>{
      "", "'\\'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "", "", "", "TEXT", "NAME", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,6,56,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,5,0,12,8,0,10,0,
  	12,0,15,9,0,1,0,1,0,1,1,3,1,20,8,1,1,1,1,1,1,1,3,1,25,8,1,1,1,1,1,1,1,
  	1,1,5,1,31,8,1,10,1,12,1,34,9,1,1,1,3,1,37,8,1,1,1,1,1,1,1,5,1,42,8,1,
  	10,1,12,1,45,9,1,1,1,3,1,48,8,1,1,2,1,2,1,3,1,3,1,4,1,4,1,4,0,0,5,0,2,
  	4,6,8,0,0,58,0,13,1,0,0,0,2,19,1,0,0,0,4,49,1,0,0,0,6,51,1,0,0,0,8,53,
  	1,0,0,0,10,12,3,2,1,0,11,10,1,0,0,0,12,15,1,0,0,0,13,11,1,0,0,0,13,14,
  	1,0,0,0,14,16,1,0,0,0,15,13,1,0,0,0,16,17,5,0,0,1,17,1,1,0,0,0,18,20,
  	5,6,0,0,19,18,1,0,0,0,19,20,1,0,0,0,20,21,1,0,0,0,21,22,5,1,0,0,22,24,
  	3,8,4,0,23,25,5,6,0,0,24,23,1,0,0,0,24,25,1,0,0,0,25,32,1,0,0,0,26,27,
  	5,2,0,0,27,28,3,4,2,0,28,29,5,3,0,0,29,31,1,0,0,0,30,26,1,0,0,0,31,34,
  	1,0,0,0,32,30,1,0,0,0,32,33,1,0,0,0,33,36,1,0,0,0,34,32,1,0,0,0,35,37,
  	5,6,0,0,36,35,1,0,0,0,36,37,1,0,0,0,37,47,1,0,0,0,38,43,5,2,0,0,39,42,
  	3,2,1,0,40,42,3,6,3,0,41,39,1,0,0,0,41,40,1,0,0,0,42,45,1,0,0,0,43,41,
  	1,0,0,0,43,44,1,0,0,0,44,46,1,0,0,0,45,43,1,0,0,0,46,48,5,3,0,0,47,38,
  	1,0,0,0,47,48,1,0,0,0,48,3,1,0,0,0,49,50,5,4,0,0,50,5,1,0,0,0,51,52,5,
  	4,0,0,52,7,1,0,0,0,53,54,5,4,0,0,54,9,1,0,0,0,8,13,19,24,32,36,41,43,
  	47
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  scn_texParserStaticData = staticData.release();
}

}

scn_texParser::scn_texParser(TokenStream *input) : scn_texParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

scn_texParser::scn_texParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  scn_texParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *scn_texParserStaticData->atn, scn_texParserStaticData->decisionToDFA, scn_texParserStaticData->sharedContextCache, options);
}

scn_texParser::~scn_texParser() {
  delete _interpreter;
}

const atn::ATN& scn_texParser::getATN() const {
  return *scn_texParserStaticData->atn;
}

std::string scn_texParser::getGrammarFileName() const {
  return "scn_tex.g4";
}

const std::vector<std::string>& scn_texParser::getRuleNames() const {
  return scn_texParserStaticData->ruleNames;
}

const dfa::Vocabulary& scn_texParser::getVocabulary() const {
  return scn_texParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView scn_texParser::getSerializedATN() const {
  return scn_texParserStaticData->serializedATN;
}


//----------------- Scn_tex_textContext ------------------------------------------------------------------

scn_texParser::Scn_tex_textContext::Scn_tex_textContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scn_texParser::Scn_tex_textContext::EOF() {
  return getToken(scn_texParser::EOF, 0);
}

std::vector<scn_texParser::Scn_tex_commandContext *> scn_texParser::Scn_tex_textContext::scn_tex_command() {
  return getRuleContexts<scn_texParser::Scn_tex_commandContext>();
}

scn_texParser::Scn_tex_commandContext* scn_texParser::Scn_tex_textContext::scn_tex_command(size_t i) {
  return getRuleContext<scn_texParser::Scn_tex_commandContext>(i);
}


size_t scn_texParser::Scn_tex_textContext::getRuleIndex() const {
  return scn_texParser::RuleScn_tex_text;
}


scn_texParser::Scn_tex_textContext* scn_texParser::scn_tex_text() {
  Scn_tex_textContext *_localctx = _tracker.createInstance<Scn_tex_textContext>(_ctx, getState());
  enterRule(_localctx, 0, scn_texParser::RuleScn_tex_text);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(13);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scn_texParser::T__0

    || _la == scn_texParser::WS) {
      setState(10);
      scn_tex_command();
      setState(15);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(16);
    match(scn_texParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Scn_tex_commandContext ------------------------------------------------------------------

scn_texParser::Scn_tex_commandContext::Scn_tex_commandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scn_texParser::Scn_tex_command_nameContext* scn_texParser::Scn_tex_commandContext::scn_tex_command_name() {
  return getRuleContext<scn_texParser::Scn_tex_command_nameContext>(0);
}

std::vector<tree::TerminalNode *> scn_texParser::Scn_tex_commandContext::WS() {
  return getTokens(scn_texParser::WS);
}

tree::TerminalNode* scn_texParser::Scn_tex_commandContext::WS(size_t i) {
  return getToken(scn_texParser::WS, i);
}

std::vector<scn_texParser::Scn_tex_command_argsContext *> scn_texParser::Scn_tex_commandContext::scn_tex_command_args() {
  return getRuleContexts<scn_texParser::Scn_tex_command_argsContext>();
}

scn_texParser::Scn_tex_command_argsContext* scn_texParser::Scn_tex_commandContext::scn_tex_command_args(size_t i) {
  return getRuleContext<scn_texParser::Scn_tex_command_argsContext>(i);
}

std::vector<scn_texParser::Scn_tex_commandContext *> scn_texParser::Scn_tex_commandContext::scn_tex_command() {
  return getRuleContexts<scn_texParser::Scn_tex_commandContext>();
}

scn_texParser::Scn_tex_commandContext* scn_texParser::Scn_tex_commandContext::scn_tex_command(size_t i) {
  return getRuleContext<scn_texParser::Scn_tex_commandContext>(i);
}

std::vector<scn_texParser::Scn_tex_command_contentContext *> scn_texParser::Scn_tex_commandContext::scn_tex_command_content() {
  return getRuleContexts<scn_texParser::Scn_tex_command_contentContext>();
}

scn_texParser::Scn_tex_command_contentContext* scn_texParser::Scn_tex_commandContext::scn_tex_command_content(size_t i) {
  return getRuleContext<scn_texParser::Scn_tex_command_contentContext>(i);
}


size_t scn_texParser::Scn_tex_commandContext::getRuleIndex() const {
  return scn_texParser::RuleScn_tex_command;
}


scn_texParser::Scn_tex_commandContext* scn_texParser::scn_tex_command() {
  Scn_tex_commandContext *_localctx = _tracker.createInstance<Scn_tex_commandContext>(_ctx, getState());
  enterRule(_localctx, 2, scn_texParser::RuleScn_tex_command);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(19);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scn_texParser::WS) {
      setState(18);
      match(scn_texParser::WS);
    }
    setState(21);
    match(scn_texParser::T__0);
    setState(22);
    scn_tex_command_name();
    setState(24);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(23);
      match(scn_texParser::WS);
      break;
    }

    default:
      break;
    }
    setState(32);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(26);
        match(scn_texParser::T__1);
        setState(27);
        antlrcpp::downCast<Scn_tex_commandContext *>(_localctx)->arg = scn_tex_command_args();
        setState(28);
        match(scn_texParser::T__2); 
      }
      setState(34);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
    setState(36);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(35);
      match(scn_texParser::WS);
      break;
    }

    default:
      break;
    }
    setState(47);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scn_texParser::T__1) {
      setState(38);
      match(scn_texParser::T__1);
      setState(43);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << scn_texParser::T__0)
        | (1ULL << scn_texParser::TEXT)
        | (1ULL << scn_texParser::WS))) != 0)) {
        setState(41);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case scn_texParser::T__0:
          case scn_texParser::WS: {
            setState(39);
            scn_tex_command();
            break;
          }

          case scn_texParser::TEXT: {
            setState(40);
            scn_tex_command_content();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(45);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(46);
      match(scn_texParser::T__2);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Scn_tex_command_argsContext ------------------------------------------------------------------

scn_texParser::Scn_tex_command_argsContext::Scn_tex_command_argsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scn_texParser::Scn_tex_command_argsContext::TEXT() {
  return getToken(scn_texParser::TEXT, 0);
}


size_t scn_texParser::Scn_tex_command_argsContext::getRuleIndex() const {
  return scn_texParser::RuleScn_tex_command_args;
}


scn_texParser::Scn_tex_command_argsContext* scn_texParser::scn_tex_command_args() {
  Scn_tex_command_argsContext *_localctx = _tracker.createInstance<Scn_tex_command_argsContext>(_ctx, getState());
  enterRule(_localctx, 4, scn_texParser::RuleScn_tex_command_args);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(scn_texParser::TEXT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Scn_tex_command_contentContext ------------------------------------------------------------------

scn_texParser::Scn_tex_command_contentContext::Scn_tex_command_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scn_texParser::Scn_tex_command_contentContext::TEXT() {
  return getToken(scn_texParser::TEXT, 0);
}


size_t scn_texParser::Scn_tex_command_contentContext::getRuleIndex() const {
  return scn_texParser::RuleScn_tex_command_content;
}


scn_texParser::Scn_tex_command_contentContext* scn_texParser::scn_tex_command_content() {
  Scn_tex_command_contentContext *_localctx = _tracker.createInstance<Scn_tex_command_contentContext>(_ctx, getState());
  enterRule(_localctx, 6, scn_texParser::RuleScn_tex_command_content);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    match(scn_texParser::TEXT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Scn_tex_command_nameContext ------------------------------------------------------------------

scn_texParser::Scn_tex_command_nameContext::Scn_tex_command_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scn_texParser::Scn_tex_command_nameContext::TEXT() {
  return getToken(scn_texParser::TEXT, 0);
}


size_t scn_texParser::Scn_tex_command_nameContext::getRuleIndex() const {
  return scn_texParser::RuleScn_tex_command_name;
}


scn_texParser::Scn_tex_command_nameContext* scn_texParser::scn_tex_command_name() {
  Scn_tex_command_nameContext *_localctx = _tracker.createInstance<Scn_tex_command_nameContext>(_ctx, getState());
  enterRule(_localctx, 8, scn_texParser::RuleScn_tex_command_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(scn_texParser::TEXT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void scn_texParser::initialize() {
  std::call_once(scn_texParserOnceFlag, scn_texParserInitialize);
}
