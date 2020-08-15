#ifndef ConsoleLogger_H
#define ConsoleLogger_H
#include "ILogger.h"
#include <iostream>

class ConsoleLogger : public ILogger{
    public:

        // used to write log
        void log( std::string );

        LoggerType get_type();

        ~ConsoleLogger();
};

#endif