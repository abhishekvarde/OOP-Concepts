#include <string>
#include <ctime>

class ILogger{
    public:

    virtual ~ILogger(){}

    virtual void log( std::string s ) = 0;

    // enum is defined specially to use it into derived class.
    enum LoggerType {CONSOLE, FILE, UNDEFINED};

    // whenever object of this class get_type
    virtual LoggerType get_type();

    // This function is called with reference to the derived class
    static std::string ILogger::get_logger_type(LoggerType loggerType);

    static char* getCurrentTime();

};
