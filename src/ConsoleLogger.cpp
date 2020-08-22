#include "../inc/ConsoleLogger.h"

// used to write log
void ConsoleLogger::log( std::string s ){

    this->bytes_used += s.length()*sizeof('a');
    
    std::cout << ILogger::getCurrentTime() << s << std::endl;
    // throw s;
}

ILogger::LoggerType ConsoleLogger::get_type(){
    return CONSOLE;
}

ConsoleLogger::~ConsoleLogger(){
    std::cout << "Object deleted" << std::endl;
}