#include <boost/program_options.hpp>

#include <iostream>

#include "translator/sc_scn_tex2scs_translator.h"


int main(int argc, const char * argv[]) try
{
  ScSCnTex2SCsTranslator translator {};

  return translator.Run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
catch (std::exception const & e)
{
  std::cout << e.what();
}
