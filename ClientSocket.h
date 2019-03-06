
#ifndef   ClientSocket_H
#define   ClientSocket_H
#include <string>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include <random>
#include "ComServerSocket.h"
class ComServerSocket;
class ClientSocket
{
	public:
		int m_socket;
		std::string m_clientID;
		void (*iChange)(ClientSocket&,char&);
		ClientSocket(int socket);
		ComServerSocket * m_server;
		~ClientSocket();
		void setEvent(void (*iChange)(ClientSocket&,char&));
		void socket_write(char *buffer);
		void socket_write(char *buffer,int s);
		void setServer(ComServerSocket* server);
};
#endif