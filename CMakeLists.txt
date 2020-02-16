cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(
    example
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "An example of hosting Qt Quick items inside Qt Widgets"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

# Ensure C++ 17
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17 CACHE STRING "")
endif()

if(CMAKE_CXX_STANDARD LESS 17)
    message(WARNING "Incompatible C++ standard ${CMAKE_CXX_STANDARD}. Requires C++17")
endif()

# Turn-on all warnings
if(NOT MSVC)
    add_compile_options(-Wall -Wextra)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Qml CONFIG REQUIRED)
find_package(Qt5Quick CONFIG REQUIRED)
find_package(Qt5QuickControls2 CONFIG REQUIRED)
find_package(Qt5QuickTemplates2 CONFIG REQUIRED)
find_package(Qt5QuickWidgets CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(QT_QML_DEBUG)
endif()

set(example_sources
    src/main.cpp
    src/ColorPicker.cpp
    src/Window.cpp
    resources/resources.qrc
)
if(WIN32)
	list(APPEND example_sources example.exe.manifest)
	add_executable(example WIN32 ${example_sources})
else()
	add_executable(example ${loupe_sources})
endif()

target_link_libraries(example
    PRIVATE
    Qt5::Qml
    Qt5::Quick
    Qt5::QuickWidgets
    Qt5::Widgets
    Qt5::QuickControls2
    Qt5::QuickTemplates2
)
