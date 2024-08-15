#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Processo iniciado com sucesso. Meu PID é %d\n", getpid());
    sleep(50);
    printf("Processo finalizado.");
    return 0;
}
