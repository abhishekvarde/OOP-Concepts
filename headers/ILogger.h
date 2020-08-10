#ifndef ILogger_H
#define ILogger_H
#include <string>
#include <ctime>

class ILogger{
    public:

    ILogger(){};

    virtual ~ILogger(){};

    virtual void log( std::string ) = 0;

    // enum is defined specially to use it into derived class.
    enum LoggerType {CONSOLE, FILE, UNDEFINED};

    // whenever object of this class get_type
    virtual LoggerType get_type();

    // This function is called with reference to the derived class
    static std::string get_logger_type(LoggerType);

    static char* getCurrentTime();

};

#endif