set(target_name cmd)

add_library(${target_name} STATIC
  cmdlib/parser.cpp
  cmdlib/parser.hpp
  cmdlib/stack.cpp
  cmdlib/stack.hpp
  cmdlib/calculator.cpp
  cmdlib/calculator.hpp)

include(CompileOptions)
set_compile_options(${target_name})

target_include_directories(
  ${target_name}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

