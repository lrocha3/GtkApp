# Project name and the supported languague for the project
PROJECT(GTK_APP CXX)

# Set the minimum version of cmake required to build this project
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# Add the compilation flags needed for GTK and MySQL Connector
# GTK: -export-dynamic
# MYSQL: -lmysqlcppconn -lmysqlcppconn-static
set (CMAKE_CXX_FLAGS "-export-dynamic -lmysqlcppconn -lmysqlcppconn-static") 

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# Add GTK headers
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})

# Inform the linker where to look for the GTK libraries
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add GTK compiler flags
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

# Add the header files present in the inc folder
include_directories(inc)

# My MySQL Connector headers
include_directories(/usr/local/include/mysql-connector-cpp/include)

# Add the sources used in the project
set(SOURCES src/gui_app.cpp src/gui_app_wrapper.cpp)

# Remove the assets from the build folder
file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/assets)

# Copy the assets to the build folder
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Add an executable
ADD_EXECUTABLE(gui_app ${SOURCES})

# Link the target to the GTK and MySQL connector libraries
TARGET_LINK_LIBRARIES(gui_app ${GTK3_LIBRARIES} mysqlcppconn)

#Set the c++ 14 standard for the target gui_app
set_property(TARGET gui_app PROPERTY CXX_STANDARD 14)