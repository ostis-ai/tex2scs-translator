set(ANTRL_DIR "${CMAKE_CURRENT_LIST_DIR}/../thirdparty/antlr")
set(GRAMMAR_DIR "${CMAKE_CURRENT_LIST_DIR}/grammar")
set(TRANSLATOR_DIR "${CMAKE_CURRENT_LIST_DIR}/translator")

add_subdirectory(${ANTRL_DIR}/runtime)

add_custom_command(OUTPUT
    "${TRANSLATOR_DIR}/sc_scn_tex_lexer.cpp"
    "${TRANSLATOR_DIR}/sc_scn_tex_lexer.h"
    "${TRANSLATOR_DIR}/sc_scn_tex_parser.cpp"
    "${TRANSLATOR_DIR}/sc_scn_tex_parser.h"
    COMMAND "${Java_JAVA_EXECUTABLE}" -jar "${ANTRL_DIR}/antlr-4.7.1-complete.jar"
        ${GRAMMAR_DIR}/scn_tex.g4 -no-listener -package translator
    WORKING_DIRECTORY "${TRANSLATOR_DIR}"
    DEPENDS ${GRAMMAR_DIR}/scn_tex.g4
)

set(TRANSLATOR_SOURCES
    "${TRANSLATOR_DIR}/sc_scn_tex_parser.cpp"
    "${TRANSLATOR_DIR}/sc_scn_tex_lexer.h"
    "${TRANSLATOR_DIR}/sc_scn_tex_parser.cpp"
    "${TRANSLATOR_DIR}/sc_scn_tex_parser.h"
    "${TRANSLATOR_DIR}/sc_scn_tex2scs_translator.cpp"
    "${TRANSLATOR_DIR}/sc_scn_tex2scs_translator.h"
)

file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.71.0 COMPONENTS filesystem program_options)

include_directories(${Boost_INCLUDE_DIRS})

add_library(scn-tex2scs-lib SHARED ${SOURCES} ${TRANSLATOR_SOURCES})

target_include_directories(scn-tex2scs-lib
    PRIVATE ${GLIB2_INCLUDE_DIRS}
    PRIVATE ${Boost_LIBRARIES}
    PRIVATE ${ANTRL_DIR}/runtime/src
    PRIVATE ${SC_MEMORY_SRC}
)

add_executable(scn-tex2scs
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${TRANSLATOR_SOURCES}
    ${SOURCES}
    ${Boost_INCLUDE_DIRS}
    "${ANTRL_DIR}/runtime/src"
)

target_include_directories(scn-tex2scs PRIVATE ${ANTRL_DIR}/runtime/src)

target_link_libraries(scn-tex2scs antlr4_static ${Boost_LIBRARIES} ${LIBCURL_LIBRARIES})

add_dependencies(scn-tex2scs antlr4_static)
