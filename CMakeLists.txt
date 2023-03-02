cmake_minimum_required(VERSION 3.21)
project(sfml-pong LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(sfml-pong src/main.cpp src/gfx/bat.h src/gfx/bat.cpp src/gfx/ball.cpp src/gfx/ball.h)
target_link_libraries(sfml-pong PRIVATE sfml-graphics)
target_compile_features(sfml-pong PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET sfml-pong POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:sfml-pong> $<TARGET_FILE_DIR:sfml-pong> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS sfml-pong)
