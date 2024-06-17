cmake_minimum_required(VERSION 3.10)
project(BookingSystem)

# Add C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Source files
set(SOURCES
    ./Booking.cpp
    ./BookingHashTable.cpp
    ./main.cpp
)

# Executable for main application
add_executable(BookingSystem ${SOURCES})

# Test executable
add_executable(TestRunner
    test/TestRunner.cpp
    test/BookingUnitTest.cpp
)

# Link BookingSystem executable
target_link_libraries(TestRunner BookingSystem)

# Optionally, if you want to run tests automatically with `make test`
enable_testing()
add_test(NAME TestRunner COMMAND TestRunner)