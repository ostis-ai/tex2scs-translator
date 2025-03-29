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

add_custom_target(SCnTexParser ALL
    DEPENDS
        "${GRAMMAR_DIR}/SCnTexLexer.cpp"
        "${GRAMMAR_DIR}/SCnTexParser.cpp"
)

file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS filesystem program_options)

add_executable(scn-tex2scs ${SOURCES})
target_link_libraries(scn-tex2scs
    LINK_PRIVATE antlr4_static
    LINK_PRIVATE ${Boost_LIBRARIES}
)
target_include_directories(scn-tex2scs
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${GRAMMAR_DIR}
    PRIVATE ${ANTLR_DIR}/runtime/src
)

add_dependencies(scn-tex2scs
    antlr4_static
    SCnTexParser
)
