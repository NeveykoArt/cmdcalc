set(target_name cmdcalc)

add_executable(${target_name})

include(CompileOptions)
set_compile_options(${target_name})

target_sources(
  ${target_name}
  PRIVATE
    app/cmdcalc.cpp
)

target_link_libraries(
  ${target_name}
  PRIVATE
    cmdlib
    cxxopts
)

