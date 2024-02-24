#include "Logger.h"

FileLogger::FileLogger(std::string logPath){
	std::ofstream outFile;
	outFile.open(logPath, std::ios::app); 
}

FileLogger::~FileLogger(){
	outFile.close();
}

void FileLogger::log(std::string msg){
	lockMutex.lock();
		outFile << msg;
	lockMutex.unlock();
}