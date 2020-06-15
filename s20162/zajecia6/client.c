#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg);

int main(int argc, char *argv[])
{
    char buff[512];
    int socked, portNr, n;
    struct hostent *server;
    struct sockaddr_in serverAddres;
    
    if (argc < 3) {
       fprintf(stderr," %s wymaga podania nazwy hosta i nr portu w argumentach\n", argv[0]);
       exit(0);
    }
    portNr = atoi(argv[2]);
    socked = socket(AF_INET, SOCK_STREAM, 0);

    if (socked < 0) 
        error("nie dało sie otworzyc gniazda\n");
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "brak odpowiedniego hosta\n");
        exit(0);
    }
    bzero((char *) &serverAddres, sizeof(serverAddres));
    serverAddres.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serverAddres.sin_addr.s_addr, server->h_length);
    serverAddres.sin_port = htons(portNr);

    if (connect(socked,(struct sockaddr *) &serverAddres,sizeof(serverAddres)) < 0) 
        error("błąd połączenia");

    printf("Podaj treść wiadomość: ");
    bzero(buff, 512);
    fgets(buff, 511, stdin);
    n = write(socked, buff, strlen(buff));

    if (n < 0) 
         error("błąd zapisawania do gniazda");
    bzero(buff, 512);
    n = read(socked, buff, 511);

    if (n < 0) 
         error("błąd czytania z gniazda");
    printf("%s\n", buff);
    close(socked);
    return 0;
}
void error(const char *msg)
{
    perror(msg);
    exit(0);
}