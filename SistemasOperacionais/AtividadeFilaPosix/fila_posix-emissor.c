/* 
* Curso: Ciência da Computação
* Disciplina: Sistemas Operacionais
* Conteúdo: Comunicação entre tarefas 
* Autora: Angelita Rettore de Araujo Zanella
* 
* Filas POSIX - emissor
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <unistd.h>

#define QUEUE_NAME "/my_queue"

int main() {
    mqd_t queue;        // descritor da fila de mensagens
    int msg;            // as mensagens são números inteiros

    // Abre a fila de mensagens, se existir
    if ((queue = mq_open(QUEUE_NAME, O_RDWR)) == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    // Envia mensagens em loop
    for (;;) {
        msg = random() % 100; // valor entre 0 e 99

        // Envia a mensagem
        if (mq_send(queue, (char*)&msg, sizeof(msg), 0) < 0) {
            perror("mq_send");
            exit(1);
        }
        printf("Enviando mensagem: valor %d\n", msg);
        sleep(1);       // Espera 1 segundo antes de enviar a próxima mensagem
    }

    // Fecha a fila de mensagens (isso normalmente não será alcançado devido ao loop infinito)
    mq_close(queue);

    return 0;
}
