set(target_name cmdlib)

add_library(${target_name} STATIC
  cmdlib/parser.cpp
  cmdlib/parser.hpp
  cmdlib/indexer.cpp
  cmdlib/indexer.hpp
  cmdlib/searcher.cpp
  cmdlib/searcher.hpp)

include(CompileOptions)
set_compile_options(${target_name})

target_include_directories(
  ${target_name}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

