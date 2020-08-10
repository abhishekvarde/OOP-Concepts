#include "FileLogger.h"

FileLogger::FileLogger( std::string file_name ){
    this->file_name = file_name;
}

FileLogger::~FileLogger(){
}

FileLogger::LoggerType get_type(){
    return ILogger::FILE;
}

void FileLogger::log( std::string s ){

    std::cout << std::endl << "Currently logger is called of class file" << std::endl;
    std::ofstream MyFile2ndObj(file_name, std::ios::out | std::ios::app);
    MyFile2ndObj << "Date : " << getCurrentTime() << "Content start from next line : \n-->>>"<< s << "\n\n";
    MyFile2ndObj.close();

}