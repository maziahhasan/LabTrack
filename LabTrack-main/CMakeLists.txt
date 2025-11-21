cmake_minimum_required(VERSION 3.16)

project(LabTrack VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Set up Qt6 automatic MOC, UIC, and RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Source files
set(SOURCES
    main.cpp
    login.cpp
    startpage.cpp
    hod_mainwindow.cpp
    ta_mainwindow.cpp
    ao_mainwindow.cpp
    instructor_mainwindow.cpp
)

# UI files
set(UI_FILES
    login.ui
    startpage.ui
    hod_mainwindow.ui
    ta_mainwindow.ui
    ao_mainwindow.ui
    instructor_mainwindow.ui
)

# Create executable
add_executable(labtrack ${SOURCES} ${UI_FILES})

# Link Qt6 libraries
target_link_libraries(labtrack Qt6::Core Qt6::Widgets)
