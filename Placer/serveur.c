#include "../grille/Socket.h"
void serveur(void){
	/* Socket et contexte d'adressage du serveur */
	    SOCKADDR_IN sin;
	    SOCKET sock;
	    socklen_t recsize = sizeof(sin);
	    
	    /* Socket et contexte d'adressage du client */
	    SOCKADDR_IN csin;
	    SOCKET csock;
	    socklen_t crecsize = sizeof(csin);
	    
	sin.sin_addr.s_addr = htonl(INADDR_ANY);   
	sin.sin_family = AF_INET;
	sin.sin_port = htons(23);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	listen(sock, 5);
	socklen_t taille = sizeof(csin);
	csock = accept(sock, (SOCKADDR*)&csin, &taille);
	bind(sock, (SOCKADDR*)&sin, sizeof(sin));
}
