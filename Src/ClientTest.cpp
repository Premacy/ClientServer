#include <string>
#include <cstdlib>

#include "Client.h"

int main(char argc, char *argv[]){
	int port, secInterval;
	std::string clientName;

	if(argc < 2){

	};

	clientName = argv[1];
	
	port = std::atoi(argv[2]);
	secInterval = std::atoi(argv[3]);

	Client client;

	if( !client.tryConnect(port) ){
		return -1;
	}

	client.startSession();

	return 0;
}