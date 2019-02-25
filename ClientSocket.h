
#ifndef   ClientSocket_H
#define   ClientSocket_H
#include <string>
#include <vector>

class ClientSocket
{
	public:
		int m_socket;
		std::string m_clientID;
		int m_n_vector;
		void (*iChange)(ClientSocket&,char&);
		ClientSocket(int socket);
		~ClientSocket();
		//void receive();
		void setEvent(void (*iChange)(ClientSocket&,char&));
		void socket_write(char *buffer);
		void socket_write(char *buffer,int s);
};
#endif