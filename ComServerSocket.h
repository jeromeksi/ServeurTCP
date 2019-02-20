#include <iostream>
#include <thread>
#include <chrono>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctime>

class ComServerSocket
{
	private:
		std::string name;
		
	public:
		struct sockaddr_in serverAddr;
		int socketId;
		struct sockaddr_storage serverStorage;
		socklen_t addr_size;
		~ComServerSocket();
		ComServerSocket(int);
		void connect();
};
