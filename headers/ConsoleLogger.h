#include "ILogger.h"
#include <iostream>

class ConsoleLogger : public ILogger{
    public:

        // used to write log
        void log( std::string s );

        LoggerType get_type();

        ~ConsoleLogger();
};
