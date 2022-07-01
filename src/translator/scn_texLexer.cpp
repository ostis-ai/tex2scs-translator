
// Generated from /home/nikita/ostis-apps/develop/ostis-web-platform-1/tools/tex2scs-translator/src/grammar/scn_tex.g4 by ANTLR 4.10.1


#include "scn_texLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct Scn_texLexerStaticData final {
  Scn_texLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Scn_texLexerStaticData(const Scn_texLexerStaticData&) = delete;
  Scn_texLexerStaticData(Scn_texLexerStaticData&&) = delete;
  Scn_texLexerStaticData& operator=(const Scn_texLexerStaticData&) = delete;
  Scn_texLexerStaticData& operator=(Scn_texLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag scn_texlexerLexerOnceFlag;
Scn_texLexerStaticData *scn_texlexerLexerStaticData = nullptr;

void scn_texlexerLexerInitialize() {
  assert(scn_texlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<Scn_texLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "TEXT", "NAME", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'\\'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "", "", "", "TEXT", "NAME", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,6,34,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,1,0,
  	1,1,1,1,1,2,1,2,1,3,4,3,21,8,3,11,3,12,3,22,1,4,4,4,26,8,4,11,4,12,4,
  	27,1,5,4,5,31,8,5,11,5,12,5,32,0,0,6,1,1,3,2,5,3,7,4,9,5,11,6,1,0,3,12,
  	0,32,35,39,57,60,63,65,90,95,95,97,122,126,126,171,171,187,187,1025,1025,
  	1040,1103,1105,1105,1,0,97,122,4,0,9,10,13,13,32,32,8232,8233,36,0,1,
  	1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,
  	1,13,1,0,0,0,3,15,1,0,0,0,5,17,1,0,0,0,7,20,1,0,0,0,9,25,1,0,0,0,11,30,
  	1,0,0,0,13,14,5,92,0,0,14,2,1,0,0,0,15,16,5,123,0,0,16,4,1,0,0,0,17,18,
  	5,125,0,0,18,6,1,0,0,0,19,21,7,0,0,0,20,19,1,0,0,0,21,22,1,0,0,0,22,20,
  	1,0,0,0,22,23,1,0,0,0,23,8,1,0,0,0,24,26,7,1,0,0,25,24,1,0,0,0,26,27,
  	1,0,0,0,27,25,1,0,0,0,27,28,1,0,0,0,28,10,1,0,0,0,29,31,7,2,0,0,30,29,
  	1,0,0,0,31,32,1,0,0,0,32,30,1,0,0,0,32,33,1,0,0,0,33,12,1,0,0,0,5,0,20,
  	22,27,32,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  scn_texlexerLexerStaticData = staticData.release();
}

}

scn_texLexer::scn_texLexer(CharStream *input) : Lexer(input) {
  scn_texLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *scn_texlexerLexerStaticData->atn, scn_texlexerLexerStaticData->decisionToDFA, scn_texlexerLexerStaticData->sharedContextCache);
}

scn_texLexer::~scn_texLexer() {
  delete _interpreter;
}

std::string scn_texLexer::getGrammarFileName() const {
  return "scn_tex.g4";
}

const std::vector<std::string>& scn_texLexer::getRuleNames() const {
  return scn_texlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& scn_texLexer::getChannelNames() const {
  return scn_texlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& scn_texLexer::getModeNames() const {
  return scn_texlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& scn_texLexer::getVocabulary() const {
  return scn_texlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView scn_texLexer::getSerializedATN() const {
  return scn_texlexerLexerStaticData->serializedATN;
}

const atn::ATN& scn_texLexer::getATN() const {
  return *scn_texlexerLexerStaticData->atn;
}




void scn_texLexer::initialize() {
  std::call_once(scn_texlexerLexerOnceFlag, scn_texlexerLexerInitialize);
}
