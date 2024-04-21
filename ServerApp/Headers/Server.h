#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <thread>
#include <iostream>
#include <memory>

#include "Logger.h"

class ITask{};
class Thread{};

class TaskPool{};

class ClientSession{};

class IServer{
public:

	using IServer_t = std::unique_ptr<IServer>;

	virtual ~IServer() = 0;
	
	//virtual IServer_t instanse() = 0;

	virtual void run()  = 0;
	virtual void stop() = 0;
};

void clientSession(int socket, ILogger *logger);

class Server : public IServer{
public:
	~Server();

	void run () override;
	void stop() override;

	void setLogger(ILogger *logger);
	void setPort  (int port);

	IServer_t instanse();
	
private:
	Server(int port_, ILogger *logger_) : logger(logger_), port(port_);

private:
	IServer_t self;

	TaskPool sessionsPool;

	ILogger *logger;
	int port;
};

class Thread{
public:
	bool isFree();
	virtual void run() = 0;

private:
	std::thread t;
};

class ITask{
public:
	virtual void operator()() = 0;
};

class ClientSession : public ITask{
public:
	ClientSession(ILogger *logger, int sessionSocket);

	void operator()();
};

class TaskPool{
public:
	using ITask_ptr = std::shared_ptr<ITask>;

	void addTask(ITask_ptr task);

private:
	std::vector<ITask_ptr> tasks;
	int threadsCount;
};

class ClientSessionPool{

};