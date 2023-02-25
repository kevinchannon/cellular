# CMakeList.txt : CMake project for cellular, include source and define
# project specific logic here.
#
include(FetchContent)

add_executable (cellular "main.cpp")
add_library(libcellular "cellular.cpp")
add_executable(tests "cellular_tests.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET libcellular PROPERTY CXX_STANDARD 20)
  set_property(TARGET cellular PROPERTY CXX_STANDARD 20)
  set_property(TARGET tests PROPERTY CXX_STANDARD 20)
endif()

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.3.1
)

FetchContent_MakeAvailable(Catch2)

target_link_libraries(cellular
  libcellular
)

target_link_libraries(tests
  Catch2::Catch2WithMain
  libcellular
)
