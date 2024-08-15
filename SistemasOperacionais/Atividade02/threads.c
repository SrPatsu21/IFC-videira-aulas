#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // Biblioteca para threads
#include <unistd.h>  // Para a função sleep
#include <time.h>    // Para inicializar o gerador de números aleatórios

// Função que será executada por cada thread
void* threadFunction(void* arg) {
    int* threadNum = (int*)arg;
    
    // Gerar um número aleatório de segundos para dormir (1 a 5 segundos)
    int sleepTime = rand() % 10 + 1;
    printf("Thread %d: Olá, mundo! Vou dormir por %d segundos.\n", *threadNum, sleepTime);
    
    // A thread dorme pelo número de segundos aleatórios
    sleep(sleepTime);
    
    printf("Thread %d: Acordei!\n", *threadNum);
    
    free(threadNum); // Liberar memória alocada para o argumento
    pthread_exit(NULL); // Termina a thread
}

int main() {
    pthread_t threads[5]; // Array para armazenar os IDs das threads
    int i, result;

    // Inicializar o gerador de números aleatórios com base no tempo atual
    srand(time(NULL));

    // Criar 5 threads
    for (i = 0; i < 5; i++) {
        int* threadNum = malloc(sizeof(int)); // Alocar memória para o número da thread
        if (threadNum == NULL) {
            fprintf(stderr, "Erro de alocação de memória\n");
            exit(EXIT_FAILURE);
        }

        *threadNum = i + 1; // Definir o número da thread

        // Criar a thread
        result = pthread_create(&threads[i], NULL, threadFunction, threadNum);
        if (result != 0) {
            fprintf(stderr, "Erro ao criar a thread %d\n", i + 1);
            exit(EXIT_FAILURE);
        }
    }

    // Aguardar a conclusão de todas as threads
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Todas as threads terminaram.\n");

    return 0;
}
