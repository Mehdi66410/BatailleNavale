#include "../grille/Socket.h"
    SOCKET sock;
void serveur(void){
	 #if defined (WIN32)
        WSADATA WSAData;
        int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
    #else
        int erreur = 0;
    #endif
    
    /* Socket et contexte d'adressage du serveur */
    SOCKADDR_IN sin;

    socklen_t recsize = sizeof(sin);
    
    /* Socket et contexte d'adressage du client */
    SOCKADDR_IN csin;
    SOCKET csock;
    socklen_t crecsize = sizeof(csin);
    int sock_err;    
    if(!erreur)
    {
        /* Création d'une socket */
        sock = socket(AF_INET, SOCK_STREAM, 0);
        
        /* Si la socket est valide */
        if(sock != INVALID_SOCKET)
        {
            printw("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);
            
            /* Configuration */
            sin.sin_addr.s_addr = htonl(INADDR_ANY);  /* Adresse IP automatique */
            sin.sin_family = AF_INET;                 /* Protocole familial (IP) */
            sin.sin_port = htons(PORT);               /* Listage du port */
            sock_err = bind(sock, (SOCKADDR*)&sin, recsize);
            
            /* Si la socket fonctionne */
            if(sock_err != SOCKET_ERROR)
            {
                /* Démarrage du listage (mode server) */
                sock_err = listen(sock, 5);
                printw("Listage du port %d...\n", PORT);
                
                /* Si la socket fonctionne */
                if(sock_err != SOCKET_ERROR)
                {
                    /* Attente pendant laquelle le client se connecte */
                    printw("Patientez pendant que le client se connecte sur le port %d...\n", PORT);
                    csock = accept(sock, (SOCKADDR*)&csin, &crecsize);
                    printw("Un client se connecte avec la socket %d de %s:%d \n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
                }
                else
                    perror("listen");
            }
            else
                perror("bind");
            
            /* Fermeture de la socket client et de la socket serveur 
            printw("Fermeture de la socket client\n");
            closesocket(csock);
            printw("Fermeture de la socket serveur\n");
            closesocket(sock);
            printw("Fermeture du serveur terminée\n");*/
        }
        else
            perror("socket");
        
        #if defined (WIN32)
            WSACleanup();
        #endif
    }
}