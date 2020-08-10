#include "ConsoleLogger.h"

// used to write log
void log( std::string s ){
    std::cout << ILogger::getCurrentTime() << " " << s << std::endl;
    // throw s;
}

ConsoleLogger::LoggerType get_type(){
    return ILogger::CONSOLE;
}

ConsoleLogger::~ConsoleLogger(){
    std::cout << "Object deleted" << std::endl;
}