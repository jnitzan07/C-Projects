cmake_minimum_required(VERSION 4.3)
project(EE200)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(EE200
        .idea/.gitignore
        .idea/editor.xml
        .idea/EE200.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/workspace.xml
        Attendance_9-11-26.c
        Attendance_9-11-26.exe
        Attendance_9-2-26.c
        Attendance_9-2-26.exe
        Homework_1-13-10-26.c
        Homework_1-13-10-26.exe
        random_number_generation.c
        random_number_generation.exe
        random_number_generation_example.c
        random_number_generation_example.exe
        stacks.c
        stacks.exe
        tic-tac-toe.c
        tic-tac-toe.exe
        utilities.c
        utilities.h)
