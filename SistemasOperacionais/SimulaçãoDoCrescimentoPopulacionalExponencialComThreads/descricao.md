
# Simulação do Crescimento Populacional Exponencial com Threads

Nesta atividade, você irá implementar um programa em C que simula o crescimento populacional de uma colônia de bactérias usando um modelo de crescimento exponencial. O objetivo é aplicar conceitos de programação usando threads para calcular o crescimento populacional em diferentes intervalos de tempo.

## Objetivo

- Aplicar a fórmula de crescimento exponencial para calcular a população ao longo do tempo:
    > P(t)=P0⋅ert \
    \
    __Onde:__ \
        P(t) - é a população no tempo t. \
        P0 - é a população inicial. \
        r - é a taxa de crescimento. \
        t - é o tempo. \
        e - é a base dos logaritmos naturais. \

- Utilize múltiplas threads para dividir o trabalho de cálculo entre intervalos de tempo.

## Tarefas

1. Implementação do Programa:
    - Crie um programa em C que receba os seguintes argumentos de linha de comando:
        - População inicial P0.
        - Taxa de crescimento r.
        - Tempo total T a ser simulado.
        - Número de threads para o cálculo paralelo.

2. Divisão de Trabalho:
    - Divida o tempo total T igualmente entre o número de threads especificado.
    - Cada thread deve calcular a população para seu intervalo de tempo específico e imprimir os resultados.

3. Cálculo Populacional:
    - Use a série de Taylor para calcular ert para cada intervalo de tempo.
    - Utilize a função exp da biblioteca math.h para os cálculos exponenciais;

4. Sincronização:
    - Garanta que todas as threads completem suas execuções antes que o programa principal termine usando pthread_join.

## Análise e Investigação

1. Análise de Desempenho:
    - Execute o programa com diferentes números de threads e meça o tempo de execução total.
    - Analise o impacto do uso de threads no tempo de execução e descreva como o número de threads afeta o desempenho.

2. Simulação de Cenários:
    - Ajuste a taxa de crescimento r e a população inicial P0 para simular diferentes cenários de crescimento.
    - Compare os resultados obtidos para diferentes parâmetros e discuta suas implicações.

## Entregáveis

1. Código Fonte:
    - O código-fonte em C, implementando a simulação do crescimento populacional com threads.
    - O código deve ser devidamente comentado e estruturado.

2. Compilação do Programa:

    - Inclua instruções sobre como compilar o programa usando gcc. Use o seguinte comando para compilar:

        ```bash
        gcc -o growth_simulation growth_simulation.c -pthread -lm
        ```

    - Este comando usa as flags -pthread para ligar a biblioteca de threads e -lm para a biblioteca matemática.

## Relatório de Análise

- Um relatório detalhado que inclua:
  - Descrição do problema e abordagem utilizada.
  - Discussão sobre os mecanismos de coordenação utilizados.
  - Resultados obtidos para diferentes configurações de parâmetros.
  - Conclusões sobre o uso de threads e paralelismo para a simulação.
