#ifndef FileLogger_H
#define FileLogger_H
#include "ILogger.h"
#include <fstream>
#include <iostream>
class FileLogger : public ILogger{

    std::string file_name;
    
    public:

        FileLogger(){};

        FileLogger( std::string );

        ~FileLogger(){};

        LoggerType get_type();

        void log( std::string );

        std::string get_file_name();

};

#endif