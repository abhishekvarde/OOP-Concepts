g++ -g -c src/ILogger.cpp src/ConsoleLogger.cpp src/FileLogger.cpp src/main.cpp
g++ ILogger.o ConsoleLogger.o FileLogger.o main.o
# ./a.out