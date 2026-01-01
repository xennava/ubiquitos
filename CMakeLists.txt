cmake_minimum_required(VERSION 3.16)
project(TicTacToe C)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_UNITY_BUILD ON)
set(CMAKE_UNITY_BUILD_BATCH_SIZE 0)

file(GLOB SRCS src/*.c src/*.h)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  include(CheckIPOSupported)
  check_ipo_supported(RESULT ipo_supported OUTPUT error)

  if(ipo_suppoerted)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
  endif()

  add_compile_options(-O3 -march=native -flto)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_options(-Wall -Werror -fsanitize=address)
  add_link_options(-fsanitize=address)
endif()

add_executable(ttt ${SRCS})
