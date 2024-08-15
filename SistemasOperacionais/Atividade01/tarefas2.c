#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>  // Necessário para a função wait()

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork FALHOU\n");
        return 1;
    } else if (pid == 0) {
        printf("> Iniciando processo filho\n");
        printf("> PID do processo filho: %d\n", getpid());
        printf("> PID do processo pai: %d\n", getppid());
        sleep(5);
        printf("> Finalizando processo filho\n");
    } else {
        printf("Iniciando processo pai\n");
        printf("PID do processo pai: %d\n", getpid());
        printf("PID do processo filho: %d\n", pid);
        wait(NULL);  // Espera o processo filho terminar
        printf("Finalizando processo pai\n");
    }

    return 0;
}
