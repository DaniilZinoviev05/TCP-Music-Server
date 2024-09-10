#include "../socket.h"
#include <SFML/Audio.hpp>
#include <cstring>

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

  void connection(){
    int conn = connect(socket_d, (struct sockaddr*)&sock_address, sizeof(sock_address));
    if (conn < 0){
      std::cerr << "Клиент: Ошибка соединения.\n";
    }
    std::cout << "Клиент: Соединение установлено." << std::endl;
    accept_music();
  }

private:
  int socket_d; // дескриптор сокета
  struct sockaddr_in sock_address;
};
