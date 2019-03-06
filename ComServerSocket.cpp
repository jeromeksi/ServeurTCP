
#include "ComServerSocket.h"
void myEvent(ClientSocket &cs,char &buffer);
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
	//listClient = new std::vector<ClientSocket*>();
	std::cout<<"Création du serveur TCP : OK"<<std::endl;
}

ComServerSocket::~ComServerSocket()
{
	close(socketId);
}
void ComServerSocket::t_sendAll(std::string s){

	char* cstr;
	cstr = new char[s.length()];
	strcpy(cstr,s.c_str());
	for(int i(0);i<listClient.size();i++)
	{
		listClient[i]->socket_write(cstr,s.length());
	}
}

void ComServerSocket::t_majClient()
{
	std::string str_info;
	for(int i(0);i<listClient.size();i++)
	{
		str_info = "INFO:"<<"pos=x:0;"<<"y:0;"; 
		listClient[j]->t_sendAll(str_info);
	}
}

void ComServerSocket::t_ClientConnect()
{

	//std::cout<<"Test3"<<std::endl;
	while(true)
	{
		ClientSocket* client = new ClientSocket(	
								accept(socketId, 
								(struct sockaddr*) &(serverStorage), 
								&(addr_size)));
		client->setEvent(myEvent);
		listClient.push_back(client);
		client->setServer(this);
		t_majClient();
	}
}
void ComServerSocket::connect()
{
	std::thread t_Client(&ComServerSocket::t_ClientConnect,this);
	//std::thread t_Routine(&ComServerSocket::t_Routine,this);
	
	t_Client.detach();
	//t_Routine.detach();
}
void ComServerSocket::sendTest()
{
	std::string vv = "test";
	t_sendAll(vv);
}
void ComServerSocket::t_Routine()
{
	while(true)
	{

	}
}
void ComServerSocket::t_deleteClient(ClientSocket * cs)
{
	listClient.erase(std::remove(listClient.begin(), listClient.end(), cs), listClient.end());
}
void myEvent(ClientSocket &cs,char &buffer)
{
	fprintf(stdout, "reception du client %s: %s\n",cs.m_clientID.c_str(), &buffer);
	std::string str_msg = &buffer;
	if(str_msg =="INIT")
	{		
		fprintf(stdout, "Demande d'initialisation du client %s\n",cs.m_clientID.c_str());
		char* cstr;
		int size =("INIT:NAME="+cs.m_clientID).size();
		cstr = new char[size];
		strcpy(cstr,("INIT:NAME="+cs.m_clientID).c_str());
		cs.socket_write(cstr,size);
	}
	else if(str_msg.rfind("INFO:"))
	{
		string



	}
	else{
		std::cout<<"je sais ap frere"<<std::endl;
	}
}