#include "socket.h"

class Server 
{
public:
	Server(){
		mk_socket();
	}

private:
	int socket_d; // дескриптор сокета
	struct sockaddr_in sock_addr; 

	void mk_socket(){
		socket_d = socket(AF_INET, SOCK_STREAM, 0);
		if (socket_d < 0){
			std::cerr << "Не удалось создать сокет.";
		}	
		std::cout << "Сокет успешно создан.";
	}
};