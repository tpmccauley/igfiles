cmake_minimum_required(VERSION 2.8)
project(igfiles)
enable_testing()

set(LIBRARY_OUTPUT_PATH build)
set(EXECUTABLE_OUTPUT_PATH build)
set(CMAKE_CURRENT_BINARY_DIR build)
set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.5)
#set(CMAKE_OSX_SYSROOT /Developer/SDKs/MacOSX10.5.sdk)

file(GLOB SOURCES "src/*.cc" "src/*.c")
file(GLOB HEADERS "src/*.h")
include_directories("src")
add_library(IgFiles STATIC ${SOURCES})
# By default CMake uses the framework installed from the official package.
# We want to use the static library we compiled.

find_library(ZLIB_LIBRARY z REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)

# Build igdumpstats
add_executable(igdumpstats bin/igdumpstats.cpp)
target_link_libraries(igdumpstats IgFiles)

# Build unit tests for igfiles.
file(GLOB TESTS_SOURCES "tests/test_igfiles-*.cpp")
add_executable(test_igfiles ${TESTS_SOURCES})
target_link_libraries(test_igfiles IgFiles z)

# Build unit tests for style parser.
add_executable(test_StyleParser "tests/test_StyleParser.cpp")
target_link_libraries(test_StyleParser IgFiles)
add_test(test_StyleParser ${EXECUTABLE_OUTPUT_PATH}/test_StyleParser)

add_test(test_igfiles ${EXECUTABLE_OUTPUT_PATH}/test_igfiles)

install(DIRECTORY src/ DESTINATION include FILES_MATCHING PATTERN "*.h")
install(TARGETS igdumpstats DESTINATION bin)
install(TARGETS IgFiles DESTINATION lib)