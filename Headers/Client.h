#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <string>
#include <iostream>
#include <chrono>

#include "TimerFunction.h"

class Session : public IFunctorType{
public:
	Session(int sock_, std::string name) : sock(sock_), clientName(name) {};

	void operator()() override;

private:
	std::string clientName;
	int sock;
};

class Client{
public:
	Client(){};
	~Client();

	bool tryConnect(int port);
	void startSession();

private:
	//void convectMessage();

private:

	bool isConnected;
	int sock;
	int secInterval;
	
	std::string name;

};