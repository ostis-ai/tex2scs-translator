#include <iostream>
#include <memory>

#include <boost/program_options.hpp>

#include "translator/sc_scn_tex2scs_translator.h"

/*!
 * @brief The main function of the tex2scs-translator application.
 *
 * The main function parses command-line arguments, sets up the translator, and runs the translation process.
 * It also handles exceptions and provides usage information.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return EXIT_SUCCESS if the translation process is successful, EXIT_FAILURE otherwise.
 */
int main(int argc, const char * argv[]) try
{
  boost::program_options::options_description options_description("tex2scs-translator usage");
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
  size_t elementSysId = vm.count("id") && (vm["id"].as<int>() > 0) ? vm["id"].as<int>() : 0;

  auto translator = std::make_unique<ScSCnTex2SCsTranslator>(debugMode, clearMode);
  return translator->Run(workDirectory, targetDirectory, elementSysId) ? EXIT_SUCCESS : EXIT_FAILURE;
}
catch (std::exception const & e)
{
  std::cout << e.what() << std::endl;
  return EXIT_FAILURE;
}
