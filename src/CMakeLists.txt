set(GRAMMAR_DIR "${CMAKE_CURRENT_LIST_DIR}/grammar")
set(TRANSLATOR_DIR "${CMAKE_CURRENT_LIST_DIR}/translator")

find_package(Java)

add_custom_command(OUTPUT
    "${GRAMMAR_DIR}/SCnTexLexer.cpp"
    "${GRAMMAR_DIR}/SCnTexLexer.h"
    "${GRAMMAR_DIR}/SCnTexParser.cpp"
    "${GRAMMAR_DIR}/SCnTexParser.h"
    COMMAND "${Java_JAVA_EXECUTABLE}" -jar "${ANTLR_DIR}/antlr4-4.7.2-complete.jar"
        ${GRAMMAR_DIR}/SCnTex.g4 -no-listener -no-visitor
    WORKING_DIRECTORY "${TRANSLATOR_DIR}"
    DEPENDS ${GRAMMAR_DIR}/SCnTex.g4
)

file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.71.0 COMPONENTS filesystem program_options)

add_executable(scn-tex2scs
    ${SOURCES}
    ${Boost_INCLUDE_DIRS}
    "${ANTLR_DIR}/runtime/src"
)

target_include_directories(scn-tex2scs PRIVATE ${ANTLR_DIR}/runtime/src)
target_link_libraries(scn-tex2scs antlr4_static ${Boost_LIBRARIES} ${LIBCURL_LIBRARIES})

add_dependencies(scn-tex2scs antlr4_static)
