cmake_minimum_required(VERSION 3.20)
project(tema3-POO)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(${PROJECT_NAME}
    main.cpp
    src/Persoana.cpp
    src/Student.cpp
    src/Profesor.cpp
    src/Parinte.cpp
    src/Catalog.cpp
    src/Director.cpp
)
