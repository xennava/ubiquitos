cmake_minimum_required(VERSION 3.20)
project(TicTacToe C)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_UNITY_BUILD ON)
# set(CMAKE_UNITY_BUILD_BATCH_SIZE 0)

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.c)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  include(CheckIPOSupported)
  check_ipo_supported(RESULT ipo_supported OUTPUT error)

  if(ipo_suppoerted)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
  endif()

  add_compile_options(-O3 -march=native -flto -Wl,--fatal-warnings)
  add_link_options(-flto -Wl,--fatal-warnings)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wstrict-prototypes)
  add_compile_options(-Wtypedef-redefinition -Wmissing-declarations)
  add_compile_options(-Wredundant-decls -Werror
    -fsanitize=address,leak,undefined)

  add_link_options(-fsanitize=address,leak,undefined)
endif()

add_link_options(-fuse-ld=lld)

add_executable(ubiquitos ${SRCS})

target_compile_definitions(ubiquitos PRIVATE
    $<$<CONFIG:Debug>:UBIQUITOUS_DEBUG>
)

target_include_directories(ubiquitos PRIVATE include)
