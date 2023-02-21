#ifndef HTTP_TCPSERVER 
#define HTTP_TCPSERVER 

#include <iostream>
#include <unistd.h>
#include <stdint.h>

#include "Socket.cpp"

#define port 8888

namespace http {
    class  tcpserver {
    private:
        int m_port = port ;
        int m_socket ;
        int new_socket ;
        unsigned int m_sockaddr_len ; 
        struct sockaddr_in m_sockaddr ; 

    public:

        void startServer(int m_port , int m_socket,sockaddr_in m_sockaddr ){
              Socket socket = Socket(m_port , m_socket,m_sockaddr);
              return  ;
        }
        int closeServer() ; 
        tcpserver ( int m_socket , int new_socket , int m_sockaddr_len , struct sockaddr_in m_sockaddr );
        ~ tcpserver ();
    };

    tcpserver::tcpserver ( int m_socket , int new_socket , int m_sockaddr_len , struct sockaddr_in m_sockaddr ){

        this->m_socket = m_socket ; 
        this->new_socket = new_socket; 
        this->m_sockaddr = m_sockaddr ; 
        this->m_sockaddr_len = m_sockaddr_len ; 
        this->m_sockaddr =  m_sockaddr ; 

        this-> startServer(this->m_port , this->m_socket,this->m_sockaddr) ;
    }

    tcpserver ::~ tcpserver ()
    {
        // this->closeServer() ; 
    }
}

#endif
