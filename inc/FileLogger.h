#ifndef FileLogger_H
#define FileLogger_H
#include "ILogger.h"
#include <fstream>
#include <iostream>
#include <mutex>
class FileLogger : public ILogger{

    std::string file_name;

    std::mutex file_mutex;
    
    public:

        FileLogger(){}

        FileLogger(const FileLogger&);

        FileLogger( std::string );

        ~FileLogger(){}

        LoggerType get_type();

        void log( std::string );

        std::string get_file_name();

};

#endif