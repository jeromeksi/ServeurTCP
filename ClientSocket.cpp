
#include "ClientSocket.h"
void receive (ClientSocket *cs);

std::string generate_string(uint len)
{
	std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,61); // distribution in range [1, 6]

    //std::cout << dist6(rng) << std::endl;
	std::string charIndex = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::string rs = "";
	
	for(uint i = 0;i<len;i++)				
		rs += charIndex[dist6(rng)];
	return rs;
	
}
ClientSocket::ClientSocket(int socket)
{
	std::cout<<"Connexion d'un client, n°"<<socket<<std::endl;	
	m_clientID = generate_string(5);

	std::cout<<"Génération d'un nom pour le client : "<<m_clientID<<std::endl;	
	m_socket = socket;	
	std::thread tt(receive,this);
	tt.detach();
	std::cout<<"Client :   "<<m_clientID<<"En attente de recption..."<<std::endl;	
}
ClientSocket::~ClientSocket()
{
	std::cout<<"Deconnexion du client : "<<m_clientID<<std::endl;	
	close(m_socket);
	m_server->t_deleteClient(this);
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
			//fprintf(stdout, "reception du client %i : %s\n",socket, buffer);
		}	
		else
		{			
			break;
		}	
	}
	cs->~ClientSocket();
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
void ClientSocket::setServer(ComServerSocket* server)
{
	m_server = server;
}

