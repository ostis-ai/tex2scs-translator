set(GRAMMAR_DIR "${CMAKE_CURRENT_LIST_DIR}/grammar")
set(TRANSLATOR_DIR "${CMAKE_CURRENT_LIST_DIR}/translator")

find_package(Java REQUIRED)

add_custom_command(
    OUTPUT
        "${GRAMMAR_DIR}/SCnTexLexer.cpp"
        "${GRAMMAR_DIR}/SCnTexLexer.h"
        "${GRAMMAR_DIR}/SCnTexParser.cpp"
        "${GRAMMAR_DIR}/SCnTexParser.h"
    COMMAND "${Java_JAVA_EXECUTABLE}" -jar "${ANTLR_DIR}/antlr-4.7.1-complete.jar"
        -o "${GRAMMAR_DIR}" "${GRAMMAR_DIR}/SCnTex.g4"
        -no-listener -no-visitor
    WORKING_DIRECTORY "${GRAMMAR_DIR}"
    DEPENDS "${GRAMMAR_DIR}/SCnTex.g4"
    COMMENT "Generating SCnTexParser"
)

add_library(SCnTexParser STATIC
    "${GRAMMAR_DIR}/SCnTexLexer.cpp"
    "${GRAMMAR_DIR}/SCnTexParser.cpp"
)
target_include_directories(SCnTexParser
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${ANTLR_DIR}/runtime/src
    PUBLIC ${GRAMMAR_DIR}
)

file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp")
add_executable(scn-tex2scs ${SOURCES})

find_package(Boost REQUIRED COMPONENTS filesystem program_options)
target_link_libraries(scn-tex2scs
    LINK_PRIVATE SCnTexParser
    LINK_PRIVATE antlr4_static
    LINK_PRIVATE Boost::filesystem
    LINK_PRIVATE Boost::program_options
)

target_include_directories(scn-tex2scs
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)
