#include "ILogger.h"
#include <fstream>
#include <iostream>
class FileLogger : public ILogger{

    std::string file_name;
    
    public:

        FileLogger( std::string file_name );

        ~FileLogger();

        LoggerType get_type();

        void log( std::string s );

        std::string get_file_name();

};