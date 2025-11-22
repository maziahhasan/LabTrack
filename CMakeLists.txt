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

# Include directories (add backend folders, models, repositories, services)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/backend/models)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/backend/repositories)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/backend/services)

## Core sources (only .cpp files here)
set(SOURCES
    main.cpp
    login.cpp
    signup.cpp
    startpage.cpp
    hod_mainwindow.cpp
    ta_mainwindow.cpp
    ao_mainwindow.cpp
    instructor_mainwindow.cpp
)

# Backend repository/service sources (explicit list to avoid missing/typo issues)
set(BACKEND_SOURCES
    backend/repositories/BuildingRepository.cpp
    backend/repositories/TARepository.cpp
    backend/repositories/UserRepository.cpp
    backend/repositories/RoomRepository.cpp
    backend/repositories/MakeupRequestRepository.cpp
    backend/repositories/LabRespository.cpp
    backend/repositories/InstructorRepository.cpp
    backend/repositories/HODRepository.cpp
    backend/repositories/ActualTimingRepository.cpp
    backend/repositories/AcademicOfficerRepository.cpp

    backend/services/MakeupService.cpp
    backend/services/ReportGenerator.cpp
    backend/services/LabService.cpp
    backend/services/AuthService.cpp
    backend/services/ReportService.cpp
)

# Combine all sources
list(APPEND SOURCES ${BACKEND_SOURCES})

# UI files
# UI files (AUTOUIC will process these)
set(UI_FILES
    login.ui
    startpage.ui
    hod_mainwindow.ui
    ta_mainwindow.ui
    ao_mainwindow.ui
    instructor_mainwindow.ui
)

# Create executable (include backend sources!)
add_executable(labtrack WIN32 ${SOURCES} ${UI_FILES})

# Ensure the generated UI/moc include path is visible to the target
target_include_directories(labtrack PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/backend/models
    ${CMAKE_CURRENT_SOURCE_DIR}/backend/repositories
    ${CMAKE_CURRENT_SOURCE_DIR}/backend/services
    ${CMAKE_CURRENT_BINARY_DIR}/labtrack_autogen/include
)

# Link Qt6 libraries
target_link_libraries(labtrack PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core)

# Use C++17
target_compile_features(labtrack PRIVATE cxx_std_17)
