/* 
* Curso: Ciência da Computação
* Disciplina: Sistemas Operacionais
* Conteúdo: Comunicação entre tarefas 
* Autora: Angelita Rettore de Araujo Zanella
* 
* Comunicação direta usando sockets - Programa B (servidor)
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 15522

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *response = "Oi, eu sou o processo B";
    setbuf(stdout, NULL);

    
    printf("Comunicação indireta usando sockets - Programa B (servidor)\n");

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("ERRO: falha ao criar o socket\n");
        exit(EXIT_FAILURE);
    }
    
    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }else{
        printf("Socket criado com sucesso\n");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("ERRO: falha ao associar o socket ao endereço e porta (bind)");
        exit(EXIT_FAILURE);
    }
    
   // Obter e exibir IP e porta associados ao socket
    struct sockaddr_in sin;
    socklen_t len = sizeof(sin);
    if (getsockname(server_fd, (struct sockaddr *)&sin, &len) == -1) {
        perror("getsockname");
        exit(EXIT_FAILURE);
    } else {
        printf("Servidor rodando no IP: %s, Porta: %d\n", inet_ntoa(sin.sin_addr), ntohs(sin.sin_port));
    }

    if (listen(server_fd, 3) < 0) {
        perror("Aguardando conexões");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("Conexão estabelecida com sucesso");
        exit(EXIT_FAILURE);
    }

    read(new_socket, buffer, 1024);
    printf("Mensagem recebida: %s\n", buffer);
    send(new_socket, response, strlen(response), 0);
    printf("Mensagem enviada: %s\n", response);

    close(new_socket);
    close(server_fd);
    return 0;
}
