
#include "ComServerSocket.h"
#include "ClientSocket.h"

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
	fprintf(stdout, "reception du client %i: %s\n",cs.m_socket, &buffer);
	std::string dd = (&buffer);
	
	(*(cs).info)[cs.m_n_vector] = "client : "+std::to_string(cs.m_socket)+" valeur : "+dd ;
	int size = (*(cs).info).size();
	int i = 0;
	char* cstr;
	std::cout<<"test1"<<std::endl;
	while(i<size)
	{
		cstr = new char[(*(cs).info)[cs.m_n_vector].length()+1];
		strcpy(cstr,(*(cs).info)[i].c_str());
		i++;
		std::cout<< cstr<<std::endl;
		(cs).socket_write(cstr,(*(cs).info)[cs.m_n_vector].length()+1);
	}
}
ComServerSocket::~ComServerSocket()
{
	close(socketId);
}
void t_connect(ComServerSocket *serveur)
{
	std::vector<std::string> info;
	info.push_back("toto");
	info.pop_back();
	//std::cout<<"Test3"<<std::endl;
	while(true)
	{
		ClientSocket* a = new ClientSocket(	accept(serveur->socketId, 
											(struct sockaddr*) &(serveur->serverStorage), 
											&(serveur->addr_size)));
		a->setEvent(myEvent);
		a->setInfoVector(&info);
		//a->setInfoVector(&info);
	}
}
void ComServerSocket::connect()
{
	std::thread tt(t_connect,this);
	tt.detach();
}

