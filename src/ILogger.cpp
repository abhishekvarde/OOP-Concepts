#include "../inc/ILogger.h"

// ILogger::ILogger(){};

ILogger::LoggerType ILogger::get_type(){
    return UNDEFINED;
}

// virtual ILogger::~ILogger(){};

// get no of bytes used by logger
long long int ILogger::get_bytes_used(){
    return this->bytes_used;
};

// This function is called with reference to the derived class
std::string ILogger::get_logger_type(LoggerType loggerType){

    switch (loggerType)
    {
        case CONSOLE:
            return "CONSOLE";
            break;
        case FILE:
            return "FILE";
            break;
        case UNDEFINED:
            return "UNDEFINED";
            break;
        default:
            throw;
        break;
    }
}

char* ILogger::getCurrentTime(){
    time_t now = time(0);
    tm *gmtm = gmtime(&now);
    char* dt = asctime(gmtm);
    return dt;
}