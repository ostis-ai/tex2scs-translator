
#include "tree/sc_scn_prefix_tree.h"
#include "commands/sc_scn_tex2scs_commands.h"


// Generated from SCnTex.g4 by ANTLR 4.7.2



#include "SCnTexParser.h"


using namespace antlrcpp;
using namespace antlr4;

SCnTexParser::SCnTexParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SCnTexParser::~SCnTexParser() {
  delete _interpreter;
}

std::string SCnTexParser::getGrammarFileName() const {
  return "SCnTex.g4";
}

const std::vector<std::string>& SCnTexParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SCnTexParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ScnTexTextContext ------------------------------------------------------------------

SCnTexParser::ScnTexTextContext::ScnTexTextContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SCnTexParser::ScnTexTextContext::EOF() {
  return getToken(SCnTexParser::EOF, 0);
}

std::vector<SCnTexParser::ScnTexCommandContext *> SCnTexParser::ScnTexTextContext::scnTexCommand() {
  return getRuleContexts<SCnTexParser::ScnTexCommandContext>();
}

SCnTexParser::ScnTexCommandContext* SCnTexParser::ScnTexTextContext::scnTexCommand(size_t i) {
  return getRuleContext<SCnTexParser::ScnTexCommandContext>(i);
}


size_t SCnTexParser::ScnTexTextContext::getRuleIndex() const {
  return SCnTexParser::RuleScnTexText;
}


SCnTexParser::ScnTexTextContext* SCnTexParser::scnTexText() {
  ScnTexTextContext *_localctx = _tracker.createInstance<ScnTexTextContext>(_ctx, getState());
  enterRule(_localctx, 0, SCnTexParser::RuleScnTexText);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

      std::stringstream resultStream;
      
    setState(14);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SCnTexParser::NAME

    || _la == SCnTexParser::WS) {
      setState(9);
      dynamic_cast<ScnTexTextContext *>(_localctx)->result = scnTexCommand(_localctx->history, _localctx->prefixTree);

          resultStream << dynamic_cast<ScnTexTextContext *>(_localctx)->result->resultText;
          
      setState(16);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(18);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(17);
      match(SCnTexParser::EOF);
      break;
    }

    }

      dynamic_cast<ScnTexTextContext *>(_localctx)->resultText =  resultStream.str();

      delete _localctx->prefixTree;
      delete _localctx->history;
      
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScnTexCommandContext ------------------------------------------------------------------

SCnTexParser::ScnTexCommandContext::ScnTexCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SCnTexParser::ScnTexCommandContext::ScnTexCommandContext(ParserRuleContext *parent, size_t invokingState, ScSCnCommandsHistory * history, ScSCnPrefixTree * prefixTree)
  : ParserRuleContext(parent, invokingState) {
  this->history = history;
  this->prefixTree = prefixTree;
}

std::vector<tree::TerminalNode *> SCnTexParser::ScnTexCommandContext::WS() {
  return getTokens(SCnTexParser::WS);
}

tree::TerminalNode* SCnTexParser::ScnTexCommandContext::WS(size_t i) {
  return getToken(SCnTexParser::WS, i);
}

SCnTexParser::ScnTexCommandNameContext* SCnTexParser::ScnTexCommandContext::scnTexCommandName() {
  return getRuleContext<SCnTexParser::ScnTexCommandNameContext>(0);
}

std::vector<SCnTexParser::ScnTexCommandContentContext *> SCnTexParser::ScnTexCommandContext::scnTexCommandContent() {
  return getRuleContexts<SCnTexParser::ScnTexCommandContentContext>();
}

SCnTexParser::ScnTexCommandContentContext* SCnTexParser::ScnTexCommandContext::scnTexCommandContent(size_t i) {
  return getRuleContext<SCnTexParser::ScnTexCommandContentContext>(i);
}

std::vector<SCnTexParser::ScnTexCommandContext *> SCnTexParser::ScnTexCommandContext::scnTexCommand() {
  return getRuleContexts<SCnTexParser::ScnTexCommandContext>();
}

SCnTexParser::ScnTexCommandContext* SCnTexParser::ScnTexCommandContext::scnTexCommand(size_t i) {
  return getRuleContext<SCnTexParser::ScnTexCommandContext>(i);
}


size_t SCnTexParser::ScnTexCommandContext::getRuleIndex() const {
  return SCnTexParser::RuleScnTexCommand;
}


SCnTexParser::ScnTexCommandContext* SCnTexParser::scnTexCommand(ScSCnCommandsHistory * history,ScSCnPrefixTree * prefixTree) {
  ScnTexCommandContext *_localctx = _tracker.createInstance<ScnTexCommandContext>(_ctx, getState(), history, prefixTree);
  enterRule(_localctx, 2, SCnTexParser::RuleScnTexCommand);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(23);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SCnTexParser::WS) {
      setState(22);
      match(SCnTexParser::WS);
    }

    setState(25);
    dynamic_cast<ScnTexCommandContext *>(_localctx)->name = scnTexCommandName();

      dynamic_cast<ScnTexCommandContext *>(_localctx)->commandName =  (dynamic_cast<ScnTexCommandContext *>(_localctx)->name != nullptr ? _input->getText(dynamic_cast<ScnTexCommandContext *>(_localctx)->name->start, dynamic_cast<ScnTexCommandContext *>(_localctx)->name->stop) : nullptr).substr(1);
      auto const & it = commands.find(_localctx->commandName);

      auto const & ignoreIt = ignoreCommands.find(_localctx->commandName);
      if (ignoreIt == ignoreCommands.cend())
      {
        if (it != commands.cend())
          dynamic_cast<ScnTexCommandContext *>(_localctx)->command =  it->second;
        else
          std::cout << "Not found: " << _localctx->commandName << std::endl;
      }
      else
      {
        std::cout << "Ignore command: " << _localctx->commandName << std::endl;
        dynamic_cast<ScnTexCommandContext *>(_localctx)->command =  nullptr;
      }
      
    setState(29);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(28);
      match(SCnTexParser::WS);
      break;
    }

    }

      ScScnTexCommandParams params;
      
    setState(81);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SCnTexParser::T__0) {
      setState(32);
      match(SCnTexParser::T__0);
      setState(34);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
      case 1: {
        setState(33);
        match(SCnTexParser::WS);
        break;
      }

      }

          std::stringstream argStream;
          
      setState(45);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(43);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case SCnTexParser::TEXT: {
              setState(37);
              dynamic_cast<ScnTexCommandContext *>(_localctx)->sent = scnTexCommandContent();

                    argStream << (dynamic_cast<ScnTexCommandContext *>(_localctx)->sent != nullptr ? _input->getText(dynamic_cast<ScnTexCommandContext *>(_localctx)->sent->start, dynamic_cast<ScnTexCommandContext *>(_localctx)->sent->stop) : nullptr);
                    
              break;
            }

            case SCnTexParser::NAME:
            case SCnTexParser::WS: {
              setState(40);
              dynamic_cast<ScnTexCommandContext *>(_localctx)->result = scnTexCommand(_localctx->history, _localctx->prefixTree);

                    argStream << dynamic_cast<ScnTexCommandContext *>(_localctx)->result->resultText;
                    
              break;
            }

          default:
            throw NoViableAltException(this);
          } 
        }
        setState(47);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      }

          params.push_back(argStream.str());
          
      setState(71);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(50);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == SCnTexParser::WS) {
            setState(49);
            match(SCnTexParser::WS);
          }
          setState(52);
          match(SCnTexParser::T__1);
          setState(54);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
          case 1: {
            setState(53);
            match(SCnTexParser::WS);
            break;
          }

          }

                std::stringstream argStream;
                
          setState(65);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(63);
              _errHandler->sync(this);
              switch (_input->LA(1)) {
                case SCnTexParser::TEXT: {
                  setState(57);
                  dynamic_cast<ScnTexCommandContext *>(_localctx)->sent = scnTexCommandContent();

                          argStream << (dynamic_cast<ScnTexCommandContext *>(_localctx)->sent != nullptr ? _input->getText(dynamic_cast<ScnTexCommandContext *>(_localctx)->sent->start, dynamic_cast<ScnTexCommandContext *>(_localctx)->sent->stop) : nullptr);
                          
                  break;
                }

                case SCnTexParser::NAME:
                case SCnTexParser::WS: {
                  setState(60);
                  dynamic_cast<ScnTexCommandContext *>(_localctx)->result = scnTexCommand(_localctx->history, _localctx->prefixTree);

                          argStream << dynamic_cast<ScnTexCommandContext *>(_localctx)->result->resultText;
                          
                  break;
                }

              default:
                throw NoViableAltException(this);
              } 
            }
            setState(67);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
          }

                  params.push_back(argStream.str());
                 
        }
        setState(73);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      }
      setState(75);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SCnTexParser::WS) {
        setState(74);
        match(SCnTexParser::WS);
      }
      setState(77);
      match(SCnTexParser::T__2);

          params.push_back("/");
          
      setState(83);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

      if (_localctx->command != nullptr)
      {
        std::cout << "Interpreter command: " << _localctx->commandName << std::endl;
        dynamic_cast<ScnTexCommandContext *>(_localctx)->resultText =  _localctx->command->Complete(*history, *prefixTree, params);
        history->push_back(_localctx->commandName);
      }
      
    setState(86);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(85);
      match(SCnTexParser::WS);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScnTexCommandContentContext ------------------------------------------------------------------

SCnTexParser::ScnTexCommandContentContext::ScnTexCommandContentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SCnTexParser::ScnTexCommandContentContext::TEXT() {
  return getToken(SCnTexParser::TEXT, 0);
}


size_t SCnTexParser::ScnTexCommandContentContext::getRuleIndex() const {
  return SCnTexParser::RuleScnTexCommandContent;
}


SCnTexParser::ScnTexCommandContentContext* SCnTexParser::scnTexCommandContent() {
  ScnTexCommandContentContext *_localctx = _tracker.createInstance<ScnTexCommandContentContext>(_ctx, getState());
  enterRule(_localctx, 4, SCnTexParser::RuleScnTexCommandContent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(SCnTexParser::TEXT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScnTexCommandNameContext ------------------------------------------------------------------

SCnTexParser::ScnTexCommandNameContext::ScnTexCommandNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SCnTexParser::ScnTexCommandNameContext::NAME() {
  return getToken(SCnTexParser::NAME, 0);
}


size_t SCnTexParser::ScnTexCommandNameContext::getRuleIndex() const {
  return SCnTexParser::RuleScnTexCommandName;
}


SCnTexParser::ScnTexCommandNameContext* SCnTexParser::scnTexCommandName() {
  ScnTexCommandNameContext *_localctx = _tracker.createInstance<ScnTexCommandNameContext>(_ctx, getState());
  enterRule(_localctx, 6, SCnTexParser::RuleScnTexCommandName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(SCnTexParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> SCnTexParser::_decisionToDFA;
atn::PredictionContextCache SCnTexParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SCnTexParser::_atn;
std::vector<uint16_t> SCnTexParser::_serializedATN;

std::vector<std::string> SCnTexParser::_ruleNames = {
  "scnTexText", "scnTexCommand", "scnTexCommandContent", "scnTexCommandName"
};

std::vector<std::string> SCnTexParser::_literalNames = {
  "", "'{'", "';'", "'}'"
};

std::vector<std::string> SCnTexParser::_symbolicNames = {
  "", "", "", "", "TEXT", "NAME", "WS"
};

dfa::Vocabulary SCnTexParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SCnTexParser::_tokenNames;

SCnTexParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x8, 0x5f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 
    0x2, 0xf, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x12, 0xb, 0x2, 0x3, 0x2, 0x5, 
    0x2, 0x15, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x5, 0x3, 0x1a, 0xa, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x20, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x25, 0xa, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x2e, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x31, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x35, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x39, 0xa, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 
    0x3, 0x42, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x45, 0xb, 0x3, 0x3, 0x3, 0x7, 
    0x3, 0x48, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x4b, 0xb, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x4e, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x52, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x55, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x59, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x2, 0x2, 0x6, 
    0x2, 0x4, 0x6, 0x8, 0x2, 0x2, 0x2, 0x69, 0x2, 0xa, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x19, 0x3, 0x2, 0x2, 0x2, 0x6, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x8, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x10, 0x8, 0x2, 0x1, 0x2, 0xb, 0xc, 0x5, 0x4, 
    0x3, 0x2, 0xc, 0xd, 0x8, 0x2, 0x1, 0x2, 0xd, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0xb, 0x3, 0x2, 0x2, 0x2, 0xf, 0x12, 0x3, 0x2, 0x2, 0x2, 0x10, 0xe, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x3, 0x2, 0x2, 0x2, 0x11, 0x14, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x10, 0x3, 0x2, 0x2, 0x2, 0x13, 0x15, 0x7, 0x2, 
    0x2, 0x3, 0x14, 0x13, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x15, 0x16, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x8, 0x2, 0x1, 0x2, 
    0x17, 0x3, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1a, 0x7, 0x8, 0x2, 0x2, 0x19, 
    0x18, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x5, 0x8, 0x5, 0x2, 0x1c, 0x1d, 0x8, 
    0x3, 0x1, 0x2, 0x1d, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x20, 0x7, 0x8, 
    0x2, 0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x53, 0x8, 0x3, 0x1, 0x2, 
    0x22, 0x24, 0x7, 0x3, 0x2, 0x2, 0x23, 0x25, 0x7, 0x8, 0x2, 0x2, 0x24, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 
    0x3, 0x2, 0x2, 0x2, 0x26, 0x2f, 0x8, 0x3, 0x1, 0x2, 0x27, 0x28, 0x5, 
    0x6, 0x4, 0x2, 0x28, 0x29, 0x8, 0x3, 0x1, 0x2, 0x29, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x2b, 0x5, 0x4, 0x3, 0x2, 0x2b, 0x2c, 0x8, 0x3, 0x1, 
    0x2, 0x2c, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x2d, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x31, 0x3, 0x2, 0x2, 0x2, 0x2f, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x49, 0x8, 
    0x3, 0x1, 0x2, 0x33, 0x35, 0x7, 0x8, 0x2, 0x2, 0x34, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x38, 0x7, 0x4, 0x2, 0x2, 0x37, 0x39, 0x7, 0x8, 0x2, 0x2, 
    0x38, 0x37, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 0x2, 0x2, 0x39, 
    0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x43, 0x8, 0x3, 0x1, 0x2, 0x3b, 0x3c, 
    0x5, 0x6, 0x4, 0x2, 0x3c, 0x3d, 0x8, 0x3, 0x1, 0x2, 0x3d, 0x42, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x3f, 0x5, 0x4, 0x3, 0x2, 0x3f, 0x40, 0x8, 0x3, 
    0x1, 0x2, 0x40, 0x42, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x41, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x42, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x46, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x46, 0x48, 
    0x8, 0x3, 0x1, 0x2, 0x47, 0x34, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x4e, 0x7, 0x8, 0x2, 0x2, 0x4d, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x50, 0x7, 0x5, 0x2, 0x2, 0x50, 0x52, 0x8, 0x3, 0x1, 0x2, 0x51, 0x22, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x55, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 
    0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 0x8, 0x3, 0x1, 
    0x2, 0x57, 0x59, 0x7, 0x8, 0x2, 0x2, 0x58, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x5b, 0x7, 0x6, 0x2, 0x2, 0x5b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 
    0x7, 0x7, 0x2, 0x2, 0x5d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x11, 0x10, 0x14, 
    0x19, 0x1f, 0x24, 0x2d, 0x2f, 0x34, 0x38, 0x41, 0x43, 0x49, 0x4d, 0x53, 
    0x58, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SCnTexParser::Initializer SCnTexParser::_init;
