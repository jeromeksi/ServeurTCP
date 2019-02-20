#include <iostream>
#include <thread>
#include <chrono>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctime>
#include "ClientSocket.h"
void receive (ClientSocket *cs);
ClientSocket::ClientSocket(int socket)
{
	m_socket = socket;	
	std::thread tt(receive,this);
	tt.detach();
}
ClientSocket::~ClientSocket()
{
	std::cout<<"Deconnexion du client n° : "<<m_socket<<std::endl;	
	close(m_socket);
	(*info).pop_back();
	std::cout<<m_socket;
}
void receive (ClientSocket *cs)
{
	char* buffer = new char[100];
	int size=1;
	while(true)
	{
		int size = read(cs->m_socket, buffer, 100-1);
		
		if(size>0)
		{		
			cs->iChange(*cs,*buffer);
			std::cout<<"test2"<<std::endl;
			//fprintf(stdout, "reception du client %i : %s\n",socket, buffer);
		}	
		else
		{			
			break;
		}	
	}
	cs->~ClientSocket();
}
void ClientSocket::setInfoVector(std::vector<std::string> *t_info)
{
	info = t_info;
	m_n_vector = (*t_info).size();
	//std::string nbuffer= "client : "+std::to_string(vv)+" value : ";
	std::string nbuffer= "start";

	(*t_info).push_back(nbuffer);
}
void ClientSocket::setInfo(std::string s)
{
(*info)[m_n_vector]=s;
}
void ClientSocket::socket_write(char *buffer)
{
	write(m_socket,buffer,100);
}
void ClientSocket::socket_write(char *buffer,int s)
{
	write(m_socket,buffer,s);
}
void ClientSocket::setEvent(void (*iChangeHandler)(ClientSocket&,char&))
{
	this->iChange = iChangeHandler;
}

