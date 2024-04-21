#pragma once

#include <string>
#include <mutex>
#include <fstream>

class ILogger_t{
public:
    virtual std::unique_ptr<ILogger> create() = 0;
    virtual void log(std::string msg) = 0;

	virtual ~ILogger() = default;
};

class FileLogger : public ILogger{
public:
	~FileLogger();

	void log(std::string msg) override;
	std::unique_ptr<ILogger> create() override;

private:
	FileLogger(std::string filepath);

private:
	std::ofstream outFile;
	std::mutex lockMutex;

	FileLogger ;
};