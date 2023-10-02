
#include "../translator/tree/sc_scn_prefix_tree.h"
#include "../translator/commands/sc_scn_tex2scs_commands.h"


// Generated from ./src/grammar/SCnTex.g4 by ANTLR 4.7.1



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

std::vector<tree::TerminalNode *> SCnTexParser::ScnTexTextContext::COMMENT() {
  return getTokens(SCnTexParser::COMMENT);
}

tree::TerminalNode* SCnTexParser::ScnTexTextContext::COMMENT(size_t i) {
  return getToken(SCnTexParser::COMMENT, i);
}

std::vector<tree::TerminalNode *> SCnTexParser::ScnTexTextContext::WS() {
  return getTokens(SCnTexParser::WS);
}

tree::TerminalNode* SCnTexParser::ScnTexTextContext::WS(size_t i) {
  return getToken(SCnTexParser::WS, i);
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
      
    setState(16);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SCnTexParser::NAME)
      | (1ULL << SCnTexParser::WS)
      | (1ULL << SCnTexParser::COMMENT))) != 0)) {
      setState(14);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SCnTexParser::NAME: {
          setState(9);
          dynamic_cast<ScnTexTextContext *>(_localctx)->result = scnTexCommand(_localctx->history, _localctx->prefixTree);

              resultStream << dynamic_cast<ScnTexTextContext *>(_localctx)->result->resultText;
              
          break;
        }

        case SCnTexParser::COMMENT: {
          setState(12);
          match(SCnTexParser::COMMENT);
          break;
        }

        case SCnTexParser::WS: {
          setState(13);
          match(SCnTexParser::WS);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(18);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(20);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(19);
      match(SCnTexParser::EOF);
      break;
    }

    }

      resultStream << ";;\n";
      dynamic_cast<ScnTexTextContext *>(_localctx)->resultText =  resultStream.str();

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

SCnTexParser::ScnTexCommandNameContext* SCnTexParser::ScnTexCommandContext::scnTexCommandName() {
  return getRuleContext<SCnTexParser::ScnTexCommandNameContext>(0);
}

std::vector<tree::TerminalNode *> SCnTexParser::ScnTexCommandContext::WS() {
  return getTokens(SCnTexParser::WS);
}

tree::TerminalNode* SCnTexParser::ScnTexCommandContext::WS(size_t i) {
  return getToken(SCnTexParser::WS, i);
}

tree::TerminalNode* SCnTexParser::ScnTexCommandContext::COMMENT() {
  return getToken(SCnTexParser::COMMENT, 0);
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
    setState(24);
    dynamic_cast<ScnTexCommandContext *>(_localctx)->name = scnTexCommandName();

      dynamic_cast<ScnTexCommandContext *>(_localctx)->commandName =  (dynamic_cast<ScnTexCommandContext *>(_localctx)->name != nullptr ? _input->getText(dynamic_cast<ScnTexCommandContext *>(_localctx)->name->start, dynamic_cast<ScnTexCommandContext *>(_localctx)->name->stop) : nullptr).substr(1);
      auto const & it = commands.find(_localctx->commandName);

      auto const & ignoreIt = ignoreCommands.find(_localctx->commandName);
      if (ignoreIt == ignoreCommands.cend())
      {
        if (it != commands.cend())
          dynamic_cast<ScnTexCommandContext *>(_localctx)->command =  it->second;
        else
          dynamic_cast<ScnTexCommandContext *>(_localctx)->command =  commands.find("relation")->second;
      }
      else
      {
        std::cout << "Ignore command: " << _localctx->commandName << std::endl;
        dynamic_cast<ScnTexCommandContext *>(_localctx)->command =  nullptr;
      }
      
    setState(28);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(27);
      match(SCnTexParser::WS);
      break;
    }

    }

      ScScnTexCommandParams params;
      params.push_back(_localctx->commandName);
      
    setState(97);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(32);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SCnTexParser::WS) {
          setState(31);
          match(SCnTexParser::WS);
        }
        setState(34);
        dynamic_cast<ScnTexCommandContext *>(_localctx)->b = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == SCnTexParser::T__0

        || _la == SCnTexParser::T__1)) {
          dynamic_cast<ScnTexCommandContext *>(_localctx)->b = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(36);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          setState(35);
          match(SCnTexParser::WS);
          break;
        }

        }

            std::stringstream argStream;
            
        setState(53);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(51);
            _errHandler->sync(this);
            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
            case 1: {
              setState(40);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == SCnTexParser::WS) {
                setState(39);
                match(SCnTexParser::WS);
              }
              setState(42);
              dynamic_cast<ScnTexCommandContext *>(_localctx)->sent = scnTexCommandContent();

                    if (_localctx->b->getText() == "{")
                      argStream << (dynamic_cast<ScnTexCommandContext *>(_localctx)->sent != nullptr ? _input->getText(dynamic_cast<ScnTexCommandContext *>(_localctx)->sent->start, dynamic_cast<ScnTexCommandContext *>(_localctx)->sent->stop) : nullptr);
                    
              break;
            }

            case 2: {
              setState(46);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == SCnTexParser::WS) {
                setState(45);
                match(SCnTexParser::WS);
              }
              setState(48);
              dynamic_cast<ScnTexCommandContext *>(_localctx)->result = scnTexCommand(_localctx->history, _localctx->prefixTree);

                    argStream << dynamic_cast<ScnTexCommandContext *>(_localctx)->result->resultText;
                    
              break;
            }

            } 
          }
          setState(55);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
        }

            if (_localctx->b->getText() == "{")
              params.push_back(argStream.str());
            
        setState(85);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(58);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == SCnTexParser::WS) {
              setState(57);
              match(SCnTexParser::WS);
            }
            setState(60);
            match(SCnTexParser::T__2);
            setState(62);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
            case 1: {
              setState(61);
              match(SCnTexParser::WS);
              break;
            }

            }

                  std::stringstream argStream;
                  
            setState(79);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
            while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
              if (alt == 1) {
                setState(77);
                _errHandler->sync(this);
                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
                case 1: {
                  setState(66);
                  _errHandler->sync(this);

                  _la = _input->LA(1);
                  if (_la == SCnTexParser::WS) {
                    setState(65);
                    match(SCnTexParser::WS);
                  }
                  setState(68);
                  dynamic_cast<ScnTexCommandContext *>(_localctx)->sent = scnTexCommandContent();

                          argStream << (dynamic_cast<ScnTexCommandContext *>(_localctx)->sent != nullptr ? _input->getText(dynamic_cast<ScnTexCommandContext *>(_localctx)->sent->start, dynamic_cast<ScnTexCommandContext *>(_localctx)->sent->stop) : nullptr);
                          
                  break;
                }

                case 2: {
                  setState(72);
                  _errHandler->sync(this);

                  _la = _input->LA(1);
                  if (_la == SCnTexParser::WS) {
                    setState(71);
                    match(SCnTexParser::WS);
                  }
                  setState(74);
                  dynamic_cast<ScnTexCommandContext *>(_localctx)->result = scnTexCommand(_localctx->history, _localctx->prefixTree);

                          argStream << dynamic_cast<ScnTexCommandContext *>(_localctx)->result->resultText;
                          
                  break;
                }

                } 
              }
              setState(81);
              _errHandler->sync(this);
              alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
            }

                    params.push_back(argStream.str());
                   
          }
          setState(87);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
        }
        setState(89);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SCnTexParser::WS) {
          setState(88);
          match(SCnTexParser::WS);
        }
        setState(91);
        _la = _input->LA(1);
        if (!(_la == SCnTexParser::T__3

        || _la == SCnTexParser::T__4)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(93);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          setState(92);
          match(SCnTexParser::WS);
          break;
        }

        } 
      }
      setState(99);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }

      if (_localctx->command != nullptr)
      {
        std::cout << "Interpreter command: " << _localctx->commandName << std::endl;
        history->push_back(_localctx->commandName);
        dynamic_cast<ScnTexCommandContext *>(_localctx)->resultText =  _localctx->command->Complete(*history, *prefixTree, params);
      }
      _localctx->command == nullptr;
      
    setState(102);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(101);
      match(SCnTexParser::COMMENT);
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
    setState(104);
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
    setState(106);
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
  "", "'{'", "'['", "'\\and'", "'}'", "']'"
};

std::vector<std::string> SCnTexParser::_symbolicNames = {
  "", "", "", "", "", "", "TEXT", "NAME", "WS", "COMMENT"
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
    0x3, 0xb, 0x6f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x11, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x14, 0xb, 
    0x2, 0x3, 0x2, 0x5, 0x2, 0x17, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x1f, 0xa, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x23, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x27, 0xa, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2b, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x31, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x7, 0x3, 0x36, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x39, 0xb, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x3d, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x41, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x45, 0xa, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x4b, 0xa, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x7, 0x3, 0x50, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x53, 0xb, 
    0x3, 0x3, 0x3, 0x7, 0x3, 0x56, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x59, 0xb, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x5c, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x60, 0xa, 0x3, 0x7, 0x3, 0x62, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x65, 
    0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x69, 0xa, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x2, 0x2, 0x6, 0x2, 0x4, 0x6, 0x8, 
    0x2, 0x4, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x6, 0x7, 0x2, 0x80, 0x2, 0xa, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x6c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x12, 0x8, 0x2, 0x1, 0x2, 
    0xb, 0xc, 0x5, 0x4, 0x3, 0x2, 0xc, 0xd, 0x8, 0x2, 0x1, 0x2, 0xd, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x11, 0x7, 0xb, 0x2, 0x2, 0xf, 0x11, 0x7, 0xa, 
    0x2, 0x2, 0x10, 0xb, 0x3, 0x2, 0x2, 0x2, 0x10, 0xe, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0xf, 0x3, 0x2, 0x2, 0x2, 0x11, 0x14, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x10, 0x3, 0x2, 0x2, 0x2, 0x12, 0x13, 0x3, 0x2, 0x2, 0x2, 0x13, 0x16, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x12, 0x3, 0x2, 0x2, 0x2, 0x15, 0x17, 0x7, 
    0x2, 0x2, 0x3, 0x16, 0x15, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x17, 0x18, 0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x8, 0x2, 0x1, 
    0x2, 0x19, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x5, 0x8, 0x5, 0x2, 
    0x1b, 0x1c, 0x8, 0x3, 0x1, 0x2, 0x1c, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1d, 
    0x1f, 0x7, 0xa, 0x2, 0x2, 0x1e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 0x63, 0x8, 
    0x3, 0x1, 0x2, 0x21, 0x23, 0x7, 0xa, 0x2, 0x2, 0x22, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x26, 0x9, 0x2, 0x2, 0x2, 0x25, 0x27, 0x7, 0xa, 0x2, 0x2, 
    0x26, 0x25, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 0x2, 0x2, 0x27, 
    0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x37, 0x8, 0x3, 0x1, 0x2, 0x29, 0x2b, 
    0x7, 0xa, 0x2, 0x2, 0x2a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x5, 0x6, 
    0x4, 0x2, 0x2d, 0x2e, 0x8, 0x3, 0x1, 0x2, 0x2e, 0x36, 0x3, 0x2, 0x2, 
    0x2, 0x2f, 0x31, 0x7, 0xa, 0x2, 0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 
    0x33, 0x5, 0x4, 0x3, 0x2, 0x33, 0x34, 0x8, 0x3, 0x1, 0x2, 0x34, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x35, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x35, 0x30, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3a, 0x3, 0x2, 0x2, 
    0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x57, 0x8, 0x3, 0x1, 0x2, 
    0x3b, 0x3d, 0x7, 0xa, 0x2, 0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 
    0x7, 0x5, 0x2, 0x2, 0x3f, 0x41, 0x7, 0xa, 0x2, 0x2, 0x40, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x51, 0x8, 0x3, 0x1, 0x2, 0x43, 0x45, 0x7, 0xa, 0x2, 
    0x2, 0x44, 0x43, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x5, 0x6, 0x4, 0x2, 0x47, 
    0x48, 0x8, 0x3, 0x1, 0x2, 0x48, 0x50, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4b, 
    0x7, 0xa, 0x2, 0x2, 0x4a, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x5, 0x4, 
    0x3, 0x2, 0x4d, 0x4e, 0x8, 0x3, 0x1, 0x2, 0x4e, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0x4f, 0x44, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0x50, 0x53, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x52, 0x3, 0x2, 0x2, 0x2, 0x52, 0x54, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x56, 0x8, 0x3, 0x1, 0x2, 0x55, 0x3c, 0x3, 
    0x2, 0x2, 0x2, 0x56, 0x59, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5c, 0x7, 0xa, 0x2, 0x2, 
    0x5b, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5f, 0x9, 0x3, 0x2, 0x2, 0x5e, 0x60, 
    0x7, 0xa, 0x2, 0x2, 0x5f, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x62, 0x3, 0x2, 0x2, 0x2, 0x61, 0x22, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x65, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x66, 0x3, 0x2, 0x2, 0x2, 
    0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x66, 0x68, 0x8, 0x3, 0x1, 0x2, 0x67, 
    0x69, 0x7, 0xb, 0x2, 0x2, 0x68, 0x67, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x5, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x7, 
    0x8, 0x2, 0x2, 0x6b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x9, 
    0x2, 0x2, 0x6d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x17, 0x10, 0x12, 0x16, 0x1e, 
    0x22, 0x26, 0x2a, 0x30, 0x35, 0x37, 0x3c, 0x40, 0x44, 0x4a, 0x4f, 0x51, 
    0x57, 0x5b, 0x5f, 0x63, 0x68, 
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
