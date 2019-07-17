#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 4242

#define LEN 4096


int main() {

    struct sockaddr_in client, server;

    int serverfd, clientfd;

    char buffer[LEN];
    char buffer_out[LEN];

    printf("Iniciando Servidor..\n");

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverfd == -1) {
        printf("Nao foi possivel criar o socket");
        return 0;
    }
    printf("Socket do servidor criado com o fd: %d\n", serverfd);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memset(server.sin_zero, 0x0, 8);


    int op = 1;
    if(setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR,
                  &op, sizeof(int)) == -1) {
        printf("Erro ao setar opcoes de socket");
        return 0;
    }

    if(bind(serverfd, (struct sockaddr*)&server, sizeof(server)) == -1 ) {
        printf("Erro de bind");
        return 0;
    }

    if(listen(serverfd, 1) == -1) {
        printf("Erro de listen");
        return 0;
    }
    
    printf("Escutando na porta %d\n", PORT);

    socklen_t client_len = sizeof(client);

    if ((clientfd=accept(serverfd,
        (struct sockaddr *) &client, &client_len )) == -1) {
        printf("Erro de conexao:");
        return 0;
    }

    strcpy(buffer, "Bem vindo!\n\0");


    if (send(clientfd, buffer, strlen(buffer), 0)) {
        printf("Cliente conectado.\n");
	
	while (1) {

        memset(buffer, 0x0, LEN);
        memset(buffer_out, 0x0, LEN);

	int message_len = 0;

	if((message_len = recv(clientfd, buffer, LEN, 0)) > 0) {
                buffer[message_len - 1] = '\0';
                printf("Cliente: %s\n", buffer);
        }

         if(strcmp(buffer, "//") == 0){
		send(clientfd, "//", 2, 0);            
		break;
	 }
 	 else{
	 	
        	printf("Servidor: ");
        	fgets(buffer_out, LEN, stdin);

        	send(clientfd, buffer_out, strlen(buffer_out), 0);

         }
    	}

    }


    close(clientfd);

    close(serverfd);

    printf("Conexao encerrada\n\n");

    return 0;
}
