#pragma once

#include <string>
#include <mutex>
#include <fstream>

class ILogger{
public:
	//virtual ~ILogger() = 0;
	virtual void log(std::string msg) = 0;
};

class FileLogger : public ILogger{
public:

	FileLogger(std::string filepath);
	~FileLogger();

	void log(std::string msg) override;

private:

	std::ofstream outFile;
	std::mutex lockMutex;
};