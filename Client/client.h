#include "socket.h"

class Client {
public:
  Client(struct sockaddr_in sock_addr){
  	sock_address = sock_addr;
  }

  void mk_socket(){
		socket_d = socket(AF_INET, SOCK_STREAM, 0);
		if (socket_d < 0){
			std::cerr << "Клиент: Не удалось создать сокет.\n";
		}
		std::cout << "Клиент: Сокет успешно создан.\n";
	}

private:
  int socket_d; // дескриптор сокета
  struct sockaddr_in sock_address;
};
