cmake_minimum_required(VERSION 3.31)
project(FretBored)

set(CMAKE_CXX_STANDARD 20)
# Copy data to build directory
# This currently does not update
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})
# Disable JSON Install
set(JSON_Install OFF CACHE INTERNAL "")
add_subdirectory(thirdparty/nlohmann_json)


add_executable(FretBored src/main.cpp
        src/Scale.cpp)
target_include_directories (FretBored PUBLIC
        includes/atypes
        includes/FretBoredApp
)
target_link_libraries(FretBored PRIVATE nlohmann_json::nlohmann_json)
