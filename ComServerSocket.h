

#ifndef   ComServerSocket_H
#define   ComServerSocket_H
#include <iostream>
#include <thread>
#include <chrono>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctime>
#include <vector>
#include "ClientSocket.h"
class ComServerSocket
{
	private:
		std::string name;
		struct sockaddr_in serverAddr;
		int socketId;
		struct sockaddr_storage serverStorage;
		socklen_t addr_size;
		std::vector<ClientSocket*> listClient;		
	public:
		~ComServerSocket();
		ComServerSocket(int);
		void connect();
		void t_connect();
		void sendTest();
};
#endif