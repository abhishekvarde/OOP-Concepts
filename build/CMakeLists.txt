cmake_minimum_required(VERSION 3.10)

project(OOP)

add_executable(
                OOP  # this is project name
                ../src/ILogger.cpp 
                ../src/ConsoleLogger.cpp 
                ../src/FileLogger.cpp 
                ../src/main.cpp
            )