#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define PORT 4242

#define LEN 4096

#define SERVER_ADDR "127.0.0.1"


int main() {

   
    struct sockaddr_in server;
 
    int sockfd;

    int slen;


    char buffer_in[LEN];

    char buffer_out[LEN];


    printf("Iniciando cliente...\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Nao foi possivel criar o socket");
        return 0;
    }
    printf("Socket do criado criado com o fd: %d\n", sockfd);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    memset(server.sin_zero, 0x0, 8);


    if (connect(sockfd, (struct sockaddr*) &server, sizeof(server)) == -1) {
        perror("Não foi possivel conectar com o servidor");
        return 0;
    }


    if ((slen = recv(sockfd, buffer_in, LEN, 0)) > 0) {
        buffer_in[slen + 1] = '\0';
        printf("Servidor: %s\n", buffer_in);
    }

    while (1) {

        memset(buffer_in, 0x0, LEN);
        memset(buffer_out, 0x0, LEN);

        printf("Cliente: ");
        fgets(buffer_out, LEN, stdin);

        send(sockfd, buffer_out, strlen(buffer_out), 0);
	
        recv(sockfd, buffer_in, LEN, 0);
        printf("Servidor: %s\n", buffer_in);

        if(strcmp(buffer_in, "//") == 0)
            break;
    }

    close(sockfd);

    printf("Conexao encerrada!\n");

    return 0;
}
