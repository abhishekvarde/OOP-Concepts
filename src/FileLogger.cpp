#include "../inc/FileLogger.h"

// FileLogger::FileLogger(){};


FileLogger::FileLogger(const FileLogger& f){
    file_name = f.file_name; 
}

FileLogger::FileLogger( std::string file_name ){
    this->file_name = file_name;
}

// FileLogger::~FileLogger(){};

ILogger::LoggerType FileLogger::get_type(){
    return FILE;
}

void FileLogger::log( std::string s ){

    std::unique_lock<std::mutex> lock(file_mutex);

    std::cout << std::endl << "Currently logger is called of class file" << std::endl;
    std::ofstream MyFile2ndObj(file_name, std::ios::out | std::ios::app);
    MyFile2ndObj << "Date : " << getCurrentTime() << "Content start from next line : \n-->>>"<< s << "\n\n";
    MyFile2ndObj.close();


}

std::string FileLogger::get_file_name(){
    return this->file_name;
}