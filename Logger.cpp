#include <iostream>
#include <string>
#include <memory>
#include "FileLogger.h"
#include "ConsoleLogger.h"
using namespace std;

void process(shared_ptr<ILogger> &logger){
    // cout << logger->get_type() << endl;
    logger->log("Process function is called");
    cout << endl << "Current logger type : ";
    cout << logger->get_logger_type(logger->get_type()) << endl;
    
    if( logger->get_type() == ILogger::FILE ){
        FileLogger *fileLogger = reinterpret_cast<FileLogger*>(logger.get());
        cout << endl << "Current logger file_name : ";
        cout << fileLogger->get_file_name() << endl;
    }
    // else{
    //     //jabardasti for console
    //     FileLogger *fileLogger = reinterpret_cast<FileLogger*>(logger.get());
    //     cout << fileLogger->get_file_name() << endl;
    // }
}


int main(){

    // shared_ptr<ILogger> consoleLogger = make_shared<ConsoleLogger>();
    // consoleLogger->log("Log");


    shared_ptr<ILogger> fileLogger = make_shared<FileLogger>("loggerr.txt");
    fileLogger->log("Log written into file");


    shared_ptr<ILogger> consoleLogger = make_shared<ConsoleLogger>();
    consoleLogger->log("Console log called");

    process(fileLogger);
    process(consoleLogger);

    // ofstream MyFile("filename.txt");
    // // Write to the file
    // MyFile << "Files can be tricky, but it is fun enough!";
    // // Close the file
    // MyFile.close();

}


/*





*/