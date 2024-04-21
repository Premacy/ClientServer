#include "Logger.h"

FileLogger::FileLogger(std::string logPath){
	std::ofstream outFile;
	outFile.open(logPath, std::ios::app); 
}

FileLogger::~FileLogger(){
	outFile.close();
}

void FileLogger::log(std::string msg){
	const std::lock_guard<std::mutex> lock(lockMutex);
    outFile << msg;
}