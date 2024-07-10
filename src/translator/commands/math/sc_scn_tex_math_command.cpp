#include "sc_scn_tex_math_command.h"

/// 0: command 1: <expression> 2: <expression>
ScScnTexCommandResult ScSCnTexMathCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & commandType = params.at(COMMAND_POS);

  auto const & item = m_mathTypes.find(commandType);
  if (item == m_mathTypes.cend())
  {
    auto const & symbolItem = m_symbolTypes.find(commandType);
    if (symbolItem == m_symbolTypes.cend())
      return "";
    else 
      return symbolItem->second.at(0);
  }

  return SCsStream()
    .Row([&](SCsStream & stream) {
      auto const attrs = item->second;

      auto const OpenBracketOfFirstArg = [&]() -> std::string {
        return attrs[FIRST_ARG_BEGIN_ATTR];
      };

      auto const ClosedBracketOfFirstArg = [&]() -> std::string {
        return attrs[FIRST_ARG_END_ATTR];
      };

      auto const OpenBracketOfSecondArg = [&]() -> std::string {
        return attrs[SECOND_ARG_BEGIN_ATTR];
      };

      auto const ClosedBracketOfSecondArg = [&]() -> std::string {
        return attrs[SECOND_ARG_END_ATTR];
      };

      if (attrs.size() == COMMAND_SIZE_ONE_ARG)
      {
        std::string const & firstArgument = params.at(FIRST_PARAM_POS);
        stream
        .Row([&]() -> SCsStream {
          return {OpenBracketOfFirstArg(), firstArgument, ClosedBracketOfFirstArg()};
        });
      }
      else if (attrs.size() == COMMAND_SIZE_TWO_ARGS)
      {
        std::string const & firstArgument = params.at(FIRST_PARAM_POS);
        std::string const & secondArgument = params.at(SECOND_PARAM_POS);
        stream
        .Row([&]() -> SCsStream {
          return {OpenBracketOfFirstArg(), firstArgument, ClosedBracketOfFirstArg(),
              OpenBracketOfSecondArg(), secondArgument, ClosedBracketOfSecondArg()};
        });
      }
      return "";
    });
}
