#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <time.h>
#include <mutex>
#include "../inc/FileLogger.h"
#include "../inc/ConsoleLogger.h"
using namespace std;

void process(shared_ptr<ILogger> &logger){
    // cout << logger->get_type() << endl;
    logger->log("Process function is called");
    cout << endl << "Current logger type : ";
    cout << logger->get_logger_type(logger->get_type()) << endl;
    
    if( logger->get_type() == ILogger::FILE ){
        FileLogger *fileLogger = reinterpret_cast<FileLogger*>(logger.get());
        cout << endl << "Current logger file_name : ";
    }
}

int thread_var = 0;
mutex mutex_var;

void multiThreading(){

    unique_lock<mutex> lock(mutex_var);

    int var = thread_var;
    var++;

    int rand_num = rand()%100;
    this_thread::sleep_for(chrono::milliseconds(rand_num));

    thread_var = var;

    lock.unlock();

}

shared_ptr<ILogger> fileLogger;

void process_filelogger(){
    process(fileLogger);
}

int main(){

    // cout << "Entered in main" << endl;

    fileLogger = make_shared<FileLogger>("src/loggerr.txt");
    fileLogger->log("Log written into file");


    shared_ptr<ILogger> consoleLogger = make_shared<ConsoleLogger>();
    consoleLogger->log("Console log called");

    process(fileLogger);
    process(consoleLogger);
    

    // Thread implementation 

    // thread *t1[100];

    // for( int i = 0 ; i < 2 ; i++ ){
    //     t1[i] = new thread(process, fileLogger);
    // }

    // for( int i = 0 ; i < 2 ; i++ ){
    //     t1[i]->join();
    // }

    thread t1(process_filelogger);
    thread t2(process_filelogger);
    t1.join();
    t2.join();

    cout << "Thread var : " << thread_var << endl;

    return 0;

}


/*


echo "# OOP-Concepts" >> README.md
git init
git add .
git commit -m "first commit"
git remote add origin https://github.com/abhishekvarde/OOP-Concepts.git

*/