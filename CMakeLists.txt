cmake_minimum_required(VERSION 3.26)
project(EE200 C)

set(CMAKE_C_STANDARD 23)

# Attendance
add_executable(Attendance_9-2-26 "Attendance/Attendance_9-2-26/main.c")
add_executable(Attendance_9-16-26 "Attendance/Attendance_9-16-26/main.c")
add_executable(Attendance_9-11-26 "Attendance/Attendance_9-11-26/main.c")
add_executable(Attendance_9-21-26 "Attendance/Attendance_9-21-26/main.c")
add_executable(Attendance_9-23-26 "Attendance/Attendance_9-23-26/main.c")
add_executable(Attendance_9-25-26 "Attendance/Attendance_9-25-26/main.c")
add_executable(Attendance_9-30-26 "Attendance/Attendance_9-30-26/main.c")
add_executable(Attendance_10-2-26 "Attendance/Attendance_10-2-26/main.c")


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
add_executable(Homework_3-9-27-26 Homework/Homework_3_9-27-26/main.c)
add_executable(Homework-4-9-28-26 "Homework/Homework_4-9-28-26/main.c")
add_executable(Homework-5-10-5-26 "Homework/Homework_5-10-5-26/main.c")

#Leetcode
add_executable(Add-2-Numbers "Leetcode/Add Two Numbers/main.c")
add_executable(Longest-Substring "Leetcode/Longest Substring Without Repeating Characters/main.c")
add_executable(2-Sum "Leetcode/2 Sum/main.c")
add_executable(Median-of-Two-Sorted-Arrays "Leetcode/Median of Two Sorted Arrays/main.c")


# Misc
add_executable(tic-tac-toe Misc/Tic-Tac-Toe/main.c)