
#include "ComServerSocket.h"
ComServerSocket::ComServerSocket(int port)
{
	socketId = socket(PF_INET,SOCK_STREAM,0);
	bzero((char*)&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	
	bind(socketId,(struct sockaddr *) &serverAddr,sizeof(serverAddr));
	/* Listen Server TCP */
	listen(socketId,10);
    addr_size = sizeof serverStorage;

	std::cout<<"Création du serveur TCP : OK"<<std::endl;
}
void myEvent(ClientSocket &cs,char &buffer)
{
	fprintf(stdout, "reception du client %s: %s\n",cs.m_clientID.c_str(), &buffer);
	std::string dd = &buffer;
	if(dd =="INIT")
	{		
		fprintf(stdout, "Demande d'initialisation du client %s\n",cs.m_clientID.c_str());
		char* cstr;
		int size =("INIT:NAME="+cs.m_clientID).size();
		cstr = new char[size];
		strcpy(cstr,("INIT:NAME="+cs.m_clientID).c_str());
		cs.socket_write(cstr,size);
	}
	else{
		std::cout<<"je sais ap frere"<<std::endl;
	}
}
ComServerSocket::~ComServerSocket()
{
	close(socketId);
}
void ComServerSocket::t_connect()
{

	//std::cout<<"Test3"<<std::endl;
	while(true)
	{
		ClientSocket* a = new ClientSocket(	
								accept(socketId, 
								(struct sockaddr*) &(serverStorage), 
								&(addr_size)));
		a->setEvent(myEvent);
		listClient.push_back(a);
		
	}
}
void ComServerSocket::connect()
{
	std::thread tt(&ComServerSocket::t_connect,this);
	tt.detach();
}
void ComServerSocket::sendTest()
{
	std::string vv = "test";
	char* cstr;
	cstr = new char[5];
	strcpy(cstr,vv.c_str());
	for(int i(0);i<listClient.size();i++)
	{
		listClient[i]->socket_write(cstr,5);
	}
	std::cout<<listClient.size()<<std::endl;
}
