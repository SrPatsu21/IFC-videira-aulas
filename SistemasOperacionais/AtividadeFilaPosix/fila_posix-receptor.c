/* 
* Curso: Ciência da Computação
* Disciplina: Sistemas Operacionais
* Conteúdo: Comunicação entre tarefas 
* Autora: Angelita Rettore de Araujo Zanella
* 
* Filas POSIX - receptor
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <errno.h>

#define QUEUE_NAME "/my_queue"
#define MAX_SIZE 1024

int main() {
    mqd_t queue;            // descritor da fila de mensagens
    struct mq_attr attr;    // atributos da fila de mensagens
    int msg;                // as mensagens são números inteiros
    ssize_t bytes_read;

    // Inicializa os atributos da fila de mensagens
    attr.mq_flags = 0;              // sem flags especiais
    attr.mq_maxmsg = 10;            // número máximo de mensagens na fila
    attr.mq_msgsize = sizeof(int);  // tamanho máximo de cada mensagem
    attr.mq_curmsgs = 0;            // número de mensagens atualmente na fila

    // Abre ou cria a fila com permissões 0666
    if ((queue = mq_open(QUEUE_NAME, O_RDWR | O_CREAT, 0666, &attr)) == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    // Recebe cada mensagem e imprime seu conteúdo
    for (;;) {
        bytes_read = mq_receive(queue, (char*)&msg, sizeof(msg), NULL);
        if (bytes_read < 0) {
            perror("mq_receive");
        } else {
            printf("Recebendo mensagem: valor %d\n", msg);
        }
    }

    // Fecha a fila de mensagens (isso normalmente não será alcançado devido ao loop infinito)
    mq_close(queue);

    // Remove a fila de mensagens (opcional)
    mq_unlink(QUEUE_NAME);

    return 0;
}
