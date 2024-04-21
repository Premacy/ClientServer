#include "Server.h"

void clientSession(int sock, ILogger *logger){
	int bytes_read(1);
	const int BUFF_SIZE = 256;

	char buff[BUFF_SIZE];

	while(bytes_read > 0)
     {
            bytes_read = recv(sock, buff, BUFF_SIZE, 0);

            if(bytes_read <= 0) break;

           	std::cout << buff << std::endl;
            //logger->log(buff);
     }

     std::cout << "Disconnected! " << std::endl;
     close(sock);
}

// vse eto d otelnom potoke poidee
void Server::run(){

	std::cout << "Start server..." << std::endl;

	int sock, listener;
    struct sockaddr_in addr;
    int bytes_read;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0)
    {
        logger->log("Server false");
        return;
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        logger->log("Server false");
        return;
    }

    std::cout << "Wait to connections. Listen port : " <<  port << std::endl;
    listen(listener, 1);

    while(1){

    	sock = accept(listener, NULL, NULL);

    	std::cout << "Try to accept new connection..." << std::endl;

    	if(sock < 0)
        {
        	std::cout << "Connection false" << std::endl;
            logger->log("Connection false");
            continue;
        }

        std::cout << "New connection accepted!" << std::endl;
        
        
        std::thread t(clientSession, sock, logger);
        t.detach();
	}
}

void Server::stop(){

}

Server::~Server(){

}