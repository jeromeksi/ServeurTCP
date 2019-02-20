#include <string>
#include <vector>

class ClientSocket
{
	public:
		int m_socket;
		int m_n_vector;
		void setInfo(std::string s);
		std::vector<std::string> * info;
		void (*iChange)(ClientSocket&,char&);
		void setInfoVector(std::vector<std::string> *t_info);
		ClientSocket(int socket);
		~ClientSocket();
		//void receive();
		void setEvent(void (*iChange)(ClientSocket&,char&));
		void socket_write(char *buffer);
		void socket_write(char *buffer,int s);
};
