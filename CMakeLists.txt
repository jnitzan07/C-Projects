cmake_minimum_required(VERSION 3.26)
project(EE200 C)

set(CMAKE_C_STANDARD 11)

# Attendance
add_executable(Attendance_9-2-26 "Attendance/Attendance_9-2-26/main.c")
add_executable(Attendance_9-11-26 "Attendance/Attendance_9-11-26/main.c"
        Homework/Homework_2_9-20-26/main.c)

# Data Structures
add_executable(stacks_main "Data Structures/Stacks/main.c"
        "Data Structures/Stacks/stacks.h"
        "Data Structures/Stacks/stacks.c"
        "Data Structures/Stacks/stacks_utilities.c"
        "Data Structures/Stacks/stacks_utilities.h")

# Algorithms
add_executable(random_number_generation
        "Algorithms/Random Number Generation/main.c"
        "Algorithms/Random Number Generation/utilities.c"
        "Algorithms/Random Number Generation/utilities.h"
)

# Homework
add_executable(Homework_1-9-10-26 Homework/Homework_1_9-10-26/main.c)
add_executable(Homework_2-9-20-26 Homework/Homework_2_9-20-26/main.c)

# Misc
add_executable(tic-tac-toe Misc/Tic-Tac-Toe/main.c)