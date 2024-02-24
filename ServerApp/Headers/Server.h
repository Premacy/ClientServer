#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <thread>
#include <iostream>

#include "Logger.h"

class IServer{
public:

	//virtual ~IServer() = 0;
	
	virtual void run()  = 0;
	virtual void stop() = 0;
};

void clientSession(int socket, ILogger *logger);

class Server : public IServer{
public:
	Server(int port_, ILogger *logger_) : logger(logger_), port(port_) {};
	~Server();

	void run()  override;
	void stop() override;

private:
	ILogger *logger;
	int port;
};