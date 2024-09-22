cmake_minimum_required(VERSION 3.20)

project(tarea1-SkiFree CXX)

add_subdirectory("third_party/rusty_audio")
add_subdirectory("third_party/nothofagus")

add_executable(SkiFree
    "main.cpp"
)

set_property(TARGET SkiFree PROPERTY CXX_STANDARD 20)
target_include_directories(SkiFree PRIVATE ${RUSTY_AUDIO_INCLUDE} ${NOTHOFAGUS_INCLUDE})
target_link_libraries(SkiFree PRIVATE rusty_audio nothofagus)