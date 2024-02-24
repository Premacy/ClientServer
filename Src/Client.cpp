#include "Client.h"

Client::~Client(){
	close(sock);
}

bool Client::tryConnect(int port){
	sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        std::cout << "Error create socket()" << std::endl;
        return false;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port); 
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        std::cout << "Error connection to port: " << port <<  std::endl;
        return false;
    }else{
        std::cout << "Successful connection to port: " << port <<  std::endl;
    }

    return true;
}

void Client::startSession(){
    TimerFunction timer;
    Session *session = new Session(sock, name);

    std::chrono::seconds sec{2};

    timer.setTimer(session, sec);
    timer.startTimerLoop();
}

void Session::operator() ( ){
    int bytesSend = 0;

    char msg[1024] = "Hello, server!\0";
    bytesSend = send(sock, msg, sizeof(msg), 0);

    if(bytesSend < 0){
        std::cout << "Error. Server not answered!" << std::endl;
    }
}