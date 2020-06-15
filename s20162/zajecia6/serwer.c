#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg);

int main(int argc, char *argv[])
{
     int n;
     char buff[512];
     int socked, newSocked, portNr;
     socklen_t client;
     struct sockaddr_in serverAddres, clientAddres;
    
     if (argc < 2) {
         fprintf(stderr,"nie podano nr portu\n");
         exit(1);
     }
     socked = socket(AF_INET, SOCK_STREAM, 0);
     if (socked < 0) 
        error("błąd otwarcia gniazda");

     bzero((char *) &serverAddres, sizeof(serverAddres));
     portNr = atoi(argv[1]);
     serverAddres.sin_family = AF_INET;
     serverAddres.sin_addr.s_addr = INADDR_ANY;
     serverAddres.sin_port = htons(portNr);
     if (bind(socked, (struct sockaddr *) &serverAddres,sizeof(serverAddres)) < 0) 
        error("błąd przypisywania");

     listen(socked, 5);
     client = sizeof(clientAddres);
     newSocked = accept(socked, (struct sockaddr *) &clientAddres, &client);
     if (newSocked < 0) 
          error("błąd przy zatwierdzaniu");

     bzero(buff, 512);
     n = read(newSocked, buff, 511);
     if (n < 0) error("błąd czytania z gniazda");
     printf("Wiadomosc to: %s\n", buff);

     n = write(newSocked,"otrzymałem wiadomość", 20);
     if (n < 0) error("błąd zapisu do gniazda");

     close(newSocked);
     close(socked);
     return 0; 
}
void error(const char *msg)
{
    perror(msg);
    exit(1);
}