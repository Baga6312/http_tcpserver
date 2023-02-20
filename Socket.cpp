#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/select.h>

using namespace std ; 
class Socket {

    private:

    sockaddr_in hint  ;
    int m_socket ;


    int createSocket(int m_socket) {
        m_socket = socket(AF_INET , SOCK_STREAM , 0) ; 
        if (m_socket = socket(AF_INET , SOCK_STREAM , 0)==-1){ 
            usleep(500000);
            cerr<<"[-] Error creating socket : exit code "<<m_socket<<endl ;
            return -1 ; 
            exit(1);
        }
        usleep(800000); 
        cout <<"[+] Socket created."<<endl ; 
        return 0 ; 
    }


    int bindSocket(int port , int m_socket , sockaddr_in hint ) {
        hint.sin_family = AF_INET ; 
        hint.sin_port = htons(port);
        inet_pton(AF_INET,"0.0.0.0",&hint.sin_addr);

        bind(m_socket,(sockaddr*)&hint,sizeof(hint)) ;

        if ( bind(m_socket,(sockaddr*)&hint,sizeof(hint))==-1){ 
            usleep(500000);
            cerr<<"[-] Error binding to socket :";
            cerr<<" exit code "<< bind(m_socket,(sockaddr*)&hint,sizeof(hint))<<endl;
            return -1 ; 
            exit(1);
        }
        usleep(800000); 
        cout <<"[+] Binding Socket."<<endl ; 
        return 0 ;  
    }


    int setListening(){
        if ( listen(m_socket,SOMAXCONN)== -1 ){ 
            usleep(500000);
            cerr << "[-] Error listening to socket : exit code " ; 
            cerr << listen(m_socket,SOMAXCONN) <<endl ;     
            usleep(500000);
            return -1 ; 
            exit(1);
        }
        usleep(800000) ; 
        cout <<"[+] Listening..." <<endl ;  
        return 0; 
    } 

    public:
    Socket(int m_port , int m_socket, sockaddr_in hint) {
    this->hint=hint; 
    this->createSocket(m_socket) ; 
    this->bindSocket(m_port ,m_socket ,hint) ; 
    this->setListening() ;
    usleep(900000);
    }

};