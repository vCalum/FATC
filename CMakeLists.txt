cmake_minimum_required(VERSION 3.10)

# Project name
project(FAT_Project)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Add source files
set(SOURCE_FILES shell.c filesys.c filesys.h)

# Add executable target
add_executable(prog ${SOURCE_FILES})

# Add custom command for hexdump
add_custom_target(hexdump
        COMMAND prog && powershell -Command "Format-Hex Virtual_Disk > virtual_disk.txt"
        DEPENDS prog
        COMMENT "Running the program to create Virtual_Disk and generating hex dump"
)