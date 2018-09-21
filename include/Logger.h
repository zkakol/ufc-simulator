/**
*@author Zachary Kakol
*@date 9/15/18
*@email zskakol@gmail.com
*/

#ifndef UFC_SIMULATOR_LOGGER_H
#define UFC_SIMULATOR_LOGGER_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cstring>

#ifdef __unix__
const std::string SYSTEM_LOG = "../log/system.log";
const std::string ERROR_LOG = "../log/error.log";
#elif defined(_WIN32) || defined(WIN_32)
const std::string SYSTEM_LOG = "C:\\Users\\Zack\\ClionProjects\\ufc-simulator\\log\\system.log";
const std::string ERROR_LOG = "C:\\Users\\Zack\\ClionProjects\\ufc-simulator\\log\\error.log";
#endif

namespace include{
    class Logger{
    private:
        std::string systemLog;
        std::string errorLog;
    public:
        explicit Logger(){
            this->systemLog = SYSTEM_LOG;
            this->errorLog = ERROR_LOG;
        }

        void notice(const std::string &message){
            std::ofstream outfile;
            outfile.open(this->systemLog, std::ios_base::app);
            std::chrono::system_clock::time_point time = std::chrono::system_clock::now();
            time_t timestamp = std::chrono::system_clock::to_time_t(time);
            char *timeString = ctime(&timestamp);
            if (timeString[strlen(timeString)-1] == '\n') timeString[strlen(timeString)-1] = '\0';
            outfile << "[NOTICE] [" << timeString << "] " << message << std::endl;
        }

        void error(const std::string &message){
            std::ofstream outfile;
            outfile.open(this->errorLog, std::ios_base::app);
            std::chrono::system_clock::time_point time = std::chrono::system_clock::now();
            time_t timestamp = std::chrono::system_clock::to_time_t(time);
            char *timeString = ctime(&timestamp);
            if (timeString[strlen(timeString)-1] == '\n') timeString[strlen(timeString)-1] = '\0';
            outfile << "[ERROR] [" << timeString << "] " << message << std::endl;
        }
    };
}



#endif //UFC_SIMULATOR_LOGGER_H
