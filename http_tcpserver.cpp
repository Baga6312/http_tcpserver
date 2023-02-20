#include <iostream>
#include <unistd.h>
#include <stdint.h>

#include "http_tcpserver.hpp"

using namespace http  ;

class http_tcpserver{

	private: 

	int m_socket ; 
	int new_socket ; 
	int m_socketaddr_len ; 

	struct sockaddr_in m_sockaddr ; 

	public : 
	http_tcpserver() { 
	tcpserver(this->m_socket, this->new_socket , this->m_socketaddr_len,this->m_sockaddr) ; 
	}

};
int main () {
	http_tcpserver http ; 

}
