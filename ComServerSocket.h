

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
#include <algorithm>
#include "ClientSocket.h"
class ClientSocket;
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
		void t_ClientConnect();
		void sendTest();
		void t_Routine();
		void t_deleteClient(ClientSocket * cs);		
		void t_majClient();		
		void t_sendAll(std::string s);
};
#endif