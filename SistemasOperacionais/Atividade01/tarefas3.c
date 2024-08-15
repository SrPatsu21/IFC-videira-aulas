#include <stdio.h>
#include <stdlib.h>  // Necessário para rand() e srand()
#include <unistd.h>  // Necessário para fork() e sleep()
#include <sys/wait.h>  // Necessário para a função wait()
#include <time.h>    // Necessário para time()

int main() {
    pid_t pid;
    int processos_filho = 3;

    for (int i = 0; i < processos_filho; i++) {
        pid = fork();

        if (pid < 0) {
            fprintf(stderr, "Fork FALHOU\n");
            return 1;
        } else if (pid == 0) {
            // Inicializa o gerador de números aleatórios com base no PID do processo filho
            srand(time(NULL) ^ (getpid() << 16));

            // Cada processo filho tem um tempo de espera aleatório entre 1 e 10 segundos
            int sleep_time = rand() % 10 + 1;

            printf("> Processo filho número %d\n", i + 1);
            printf("> PID do processo filho numero %d: %d\n", i + 1, getpid());
            printf("> PID do processo pai: %d\n", getppid());
            printf("> Processo filho número %d vai dormir por %d segundos\n", i + 1, sleep_time);

            sleep(sleep_time);

            printf("> Finalizando processo filho número %d\n", i + 1);
            return 0;  // Cada filho deve terminar o loop ao retornar
        }
    }

    // Apenas o processo pai executa esta parte
    for (int i = 0; i < processos_filho; i++) {
        wait(NULL);  // Espera cada processo filho terminar
    }

    printf("Iniciando processo pai\n");
    printf("PID do processo pai: %d\n", getpid());

    return 0;
}
