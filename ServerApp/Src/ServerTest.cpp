#include "Server.h"
#include <cstdlib>

int main(char argc, char *argv[]){
	if(argc <= 1 ){
		std::cout << "Error" << std::endl;
		return -1;
	}

	int port = std::atoi(argv[1]);

	ILogger *logger = new FileLogger("logFile.txt");

	auto server = std::unique_ptr<IServer>( new Server(port, logger) );
	server->run();

	return 0;
}