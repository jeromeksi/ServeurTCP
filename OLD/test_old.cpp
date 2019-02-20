#include <iostream>
#include <thread>
#include <chrono>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctime>
#include "ClientSocket.h"
#include "ServerSocket.h"
#include <vector>

std::string generate_string();
void threadUpdateClient(std::vector<ClientSocket*> * list, std::vector<std::string> *t_info);
/*void myEvent(ClientSocket &cs,char &buffer)
{

	//fprintf(stdout, "reception du client %i: %s\n",cs.m_socket, &buffer);
	std::string dd = (&buffer);
	(*(cs).info)[cs.m_n_vector] = "client : "+std::to_string(cs.m_socket)+" valeur : "+dd ;
	int size = (*(cs).info).size();
	int i = 0;
	char* cstr;
	while(i<size)
	{
		cstr = new char[(*(cs).info)[cs.m_n_vector].length()+1];
		strcpy(cstr,(*(cs).info)[i].c_str());
		i++;
		std::cout<< cstr<<std::endl;
		(cs).socket_write(cstr,(*(cs).info)[cs.m_n_vector].length()+1);
	}
}
*/
int main()
{	
	ServerSocket* toto = new ServerSocket(7777);
	toto->connect();
	std::cout<<std::flush;
	/*
	int socketId = socket(PF_INET,SOCK_STREAM,0);
	struct sockaddr_in serverAddr;
	bzero((char*)&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7777);
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	
	bind(socketId,(struct sockaddr *) &serverAddr,sizeof(serverAddr));
	listen(socketId,10);
	struct sockaddr_storage serverStorage;


    socklen_t addr_size   = sizeof serverStorage;*/

	std::vector<ClientSocket*> * list = new std::vector<ClientSocket*>();	
	std::vector<std::string> info;
	info.push_back("toto");
	info.pop_back();
char a ='a';
while(a!='q')
{
std::cin>>a;
}
toto->~ServerSocket();
	//std::thread threadUpdate(threadUpdateClient,list,&info);
	//threadUpdate.detach();
	//threadUpdate.join();
	//threadUpdate.join();
	/*while(true)
	{
		fprintf(stdout, "Attente d'un client\n");
		//int newSocket= accept(socketId, (struct sockaddr*)&serverStorage, &addr_size);
		//ClientSocket* a= new ClientSocket(newSocket);
		//a->setEvent(myEvent);
		//a->setInfoVector(&info);
		list->push_back(new ClientSocket(accept(socketId, (struct sockaddr*)&serverStorage, &addr_size)));
		list->back()->setEvent(myEvent);
		list->back()->setInfoVector(&info);
		fprintf(stdout, "CLient %i connecté\n",list->back()->m_socket);
	}
	close(socketId);*/
	return 0;
}
void threadUpdateClient(std::vector<ClientSocket*> * list, std::vector<std::string> *t_info)
{
	while(true)
	{
		for(ClientSocket* client : *list)		
		{
			if(client == 0)
			{
				fprintf(stdout, "Test\n");
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

std::string generate_string()
{
	srand(rand());
	uint len = 10;
	std::string charIndex = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	uint ri[15];
	std::string rs = "";
	
	for(uint i = 0;i<len;i++)				
		rs += charIndex[rand() % charIndex.length()];
	return rs;
	
}












