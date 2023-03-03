cmake_minimum_required(VERSION 3.0.0)
project(jam)

file(GLOB source 
    "src/*.*"
    "src/Jam/*.*"
    "src/Jam/Math/*.*"
)

set(includes 
    include
    include/glad
)

#add_executable(jam ${source})
add_library(jam SHARED ${source})
include_directories(${includes})

target_link_libraries(jam SDL2)

find_package(OpenGL REQUIRED)
target_link_libraries(jam OpenGL::GL)

add_compile_options(-msse)
