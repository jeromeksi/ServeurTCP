#include <iostream>
#include <thread>
#include <chrono>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctime>
#include "ComServerSocket.h"
#include <vector>

std::string generate_string();
//putty.exe -ssh jerome@172.20.83.83 -pw jerome -m C:\exec.cmd -t
int main()
{	
	ComServerSocket* serverSocket = new ComServerSocket(7777);
	serverSocket->connect();

	char a ='a';
	while(true)
	{
		a= getchar();
		switch(a)
		{
			case 'q' :
				std::cout<<"Arret du serveur TCP"<<std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				serverSocket->~ComServerSocket();	
				std::this_thread::sleep_for(std::chrono::milliseconds(3000));
				return 0;
			break;
			case 't' :		
				std::cout<<"Send ALL client"<<std::endl;
				serverSocket->sendTest();

			break;
		}
	}	
}