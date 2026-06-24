cmake_minimum_required(VERSION 3.27)
project(programming)

set(CMAKE_CXX_STANDARD 17)

# Get a list of all .cpp files in the "programming" directory
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/programming/*.cpp")

# Specify the directory where executables should be placed
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Loop through the source files and create an executable for each
foreach(SOURCE_FILE ${SOURCE_FILES})
    # Extract the filename without an extension (CMake 3.14 or newer)
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)

    # Create an executable for each source file
    add_executable(${FILE_NAME} ${SOURCE_FILE})

    # Set the output directory for each executable
    set_target_properties(${FILE_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
endforeach()
