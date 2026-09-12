cmake_minimum_required(VERSION 3.26)
project(EE200 C)

set(CMAKE_C_STANDARD 11)

# Attendance
add_executable(Attendance_9-2-26 "Attendance/Attendance_9-2-26.c")
add_executable(Attendance_9-11-26 "Attendance/Attendance_9-11-26.c")

# Data Structures
add_executable(stacks_main "Data Structures/stacks_main.c"
        "Data Structures/stacks.h"
        "Data Structures/stacks.c"
        "Data Structures/stacks_utilities.c"
        "Data Structures/stacks_utilities.h")

# Algorithms
add_executable(random_number_generation "Algorithms/random_number_generation.c")

add_executable(random_number_generation_example
        Algorithms/random_number_generation_example.c
        Algorithms/utilities.c
        Algorithms/utilities.h
)

# Homework
add_executable(Homework_1-13-10-26 Homework/Homework_1-13-10-26.c)

# Misc
add_executable(tic-tac-toe Misc/tic-tac-toe.c)