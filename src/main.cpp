#include <boost/program_options.hpp>

#include <iostream>

#include "sc_scn_tex2scs_translator_builder.h"

int main(int argc, const char * argv[]) try
{
  boost::program_options::options_description options_description("SCn-Tex2SCs-Translator usage");
  options_description.add_options()
      ("help", "Display this message")
      ("sources,s", boost::program_options::value<std::string>(), "Path with tex sources")
      ("target,t", boost::program_options::value<std::string>(), "Path to target directory for scs sources")
      ("clear,c", "Clear path to target directory for scs sources")
      ("debug,d", "Run translator in debug mode")
      ("id,i", boost::program_options::value<int>(),
          "Set id number for the first sc-element system identifier (by default 0)");

  boost::program_options::variables_map vm;
  boost::program_options::store(
      boost::program_options::command_line_parser(argc, argv).options(options_description).run(), vm);
  boost::program_options::notify(vm);

  std::string workDirectory;
  if (vm.count("sources"))
    workDirectory = vm["sources"].as<std::string>();

  std::string targetDirectory;
  if (vm.count("target"))
    targetDirectory = vm["target"].as<std::string>();

  if (vm.count("help"))
  {
    std::cout << options_description;
    return EXIT_SUCCESS;
  }

  bool debugMode = vm.count("debug");
  bool clearMode = vm.count("clear");
  size_t elementSysId = vm.count("id") && (vm["id"].as<int>() > 0) ? vm["id"].as<size_t>() : 0;

  auto translator = ScSCnTex2SCsTranslatorBuilder::BuildDefaultTranslator(debugMode, clearMode);
  return translator->Run(workDirectory, targetDirectory, elementSysId) ? EXIT_SUCCESS : EXIT_FAILURE;
}
catch (std::exception const & e)
{
  std::cout << e.what() << std::endl;
}
