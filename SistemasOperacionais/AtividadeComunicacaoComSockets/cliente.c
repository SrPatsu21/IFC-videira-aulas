/*
* Curso: Ciência da Computação
* Disciplina: Sistemas Operacionais
* Conteúdo: Comunicação entre tarefas
* Autora: Angelita Rettore de Araujo Zanella
*
* Comunicação direta usando sockets - Programa A (cliente)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 15522

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Olá, eu sou o processo A";
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n ERRO: não foi possível criar o socket \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nERRO: Endereço inválido ou não suportado\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nERRO: Conexão falhou\n");
        return -1;
    }

    send(sock, hello, strlen(hello), 0);
    printf("Mensagem enviada: %s\n", hello);
    read(sock, buffer, 1024);
    printf("Mensagem recebida: %s\n", buffer);

    close(sock);
    return 0;
}
