# Simulação do Crescimento Populacional Exponencial com Threads e Prevenção de Impasse

## Descrição

Nesta atividade, você irá implementar um programa em C que simula o crescimento de colônias de bactérias utilizando conceitos de programação concorrente com threads e mecanismos de travamento (mutexes). O objetivo é criar uma situação que permita a ocorrência de impasse (deadlock), mas que seja prevenida por meio de estratégias de gerenciamento de recursos e coordenação de threads.

Cada colônia de bactérias (representada por uma thread) precisa de recursos compartilhados (exemplo: nutrientes e espaço) para realizar seu crescimento em etapas. Esses recursos são escassos e precisam ser alocados simultaneamente para que uma colônia complete seu ciclo de crescimento. Sem os dois recursos, a colônia fica bloqueada. O objetivo é implementar uma solução para evitar esse bloqueio utilizando técnicas como ordenação de recursos, mutexes hierárquicos, ou timeout para garantir que não ocorra um impasse.

## Contexto de Crescimento Populacional

1. Cada colônia segue a fórmula de crescimento exponencial:

P(t)=P0⋅e^(rt)

- P(t) é a população no tempo t.
- P0 é a população inicial.
- r é a taxa de crescimento.
- t é o tempo.
- e é a base dos logaritmos naturais.

2. Para realizar cada etapa de crescimento, a colônia precisa de dois recursos compartilhados simultaneamente:
    - Recurso A: Por exemplo, nutrientes.
    - Recurso B: Por exemplo, espaço ou área de cultivo.

3. Se uma colônia obtiver apenas um dos recursos e ficar esperando pelo outro, ocorre uma situação de bloqueioque pode levar a um impasse.

## Objetivo

Criar um programa que permita a ocorrência de um impasse (deadlock) inicialmente, mas que posteriormente seja modificado para implementar prevenção de impasse com as seguintes técnicas:

    Prevenção por Ordenação de Recursos: Todas as colônias devem adquirir os recursos na mesma ordem.
    Mutex Hierárquico: As colônias devem seguir uma hierarquia de mutexes para evitar ciclos de dependência.
    Timeout ou Recurso de Recuperação: Se uma colônia ficar esperando por muito tempo, deve liberar o recurso que já possui e tentar novamente.

## Tarefas

1. Implementação do Problema com Deadlock:
    Crie um programa em C que simule o crescimento de várias colônias de bactérias (threads).
    Cada thread deve tentar obter dois recursos compartilhados: Recurso A e Recurso B.
    Inicialmente, projete o programa de forma que as threads tentem obter os recursos em ordens diferentes, o que leva à possibilidade de impasse.

    Exemplo:
      - Colônia 1: Tenta obter A e depois B.
      - Colônia 2: Tenta obter B e depois A.

2. Detecção e Análise de Deadlock:
    Permita que o impasse ocorra e implemente um mecanismo para detectar quando ele acontece.
    Imprima uma mensagem indicando que o deadlock foi detectado e quais threads estão envolvidas.

3. Implementação de Prevenção de Impasse:
    Modifique o programa para implementar uma técnica de prevenção de impasse.
    As soluções possíveis incluem:
        Ordenação Consistente: Todas as threads obtêm os recursos na mesma ordem.
        Hierarquia de Mutexes: Defina uma ordem para os mutexes que previne ciclos de dependência.
        Timeout e Retry: Se uma thread não conseguir obter ambos os recursos em um tempo limite, ela deve liberar o recurso que já possui e tentar novamente.
    Escolha uma das técnicas e implemente-a no programa para garantir que o impasse não ocorra mais.

4. Análise de Desempenho e Eficiência:
    Compare a versão que permite impasse com a versão que implementa a prevenção.
    Analise o impacto das técnicas de prevenção no desempenho e na complexidade do código.

## Requisitos do Programa

1. Parâmetros de Entrada:
    - População inicial P0: valor inicial para a população de cada colônia.
    - Taxa de crescimento r: taxa de crescimento para cada colônia.
    - Tempo total T: o tempo total a ser simulado.
    - Número de colônias: total de threads representando colônias.
    - Número total de recursos: quantidade de recursos compartilhados de cada tipo.

2. Recursos Compartilhados:
    - Crie dois arrays de mutexes para representar os recursos:
        - recursosA: um array de mutexes representando recursos do tipo A.
        - recursosB: um array de mutexes representando recursos do tipo B.

3. Ordem de Aquisição Inicial (permitindo deadlock):
    - Algumas threads devem tentar obter recursosA antes de recursosB.
    - Outras threads devem tentar obter recursosB antes de recursosA.

4. Implementação de Estratégias de Prevenção:
    - Após permitir que o impasse ocorra, implemente uma das seguintes estratégias:
        - Ordenação Consistente: Todas as threads seguem a mesma ordem para travamento.
        - Hierarquia de Mutexes: Defina uma prioridade para os recursos e siga uma ordem específica.
        - Timeout: Se uma thread ficar bloqueada por um tempo definido, ela deve liberar todos os recursos e tentar novamente.

## Entregáveis

1. Código Fonte:
    - Código-fonte bem documentado que implementa a simulação de crescimento populacional com impasse.
    - Código modificado com a técnica de prevenção de impasse.
    - O código deve ser devidamente comentado e estruturado.

2. Compilação do Programa:

    - Inclua instruções sobre como compilar o programa usando gcc. Use o seguinte comando para compilar:

    ```make
        gcc -o growth_simulation growth_simulation.c -pthread -lm
    ```

    - Este comando usa as flags -pthread para ligar a biblioteca de threads e -lm para a biblioteca matemática.

3. Relatório de Análise:
    - Um relatório detalhado que inclua:
        - Descrição do problema e abordagem utilizada.
        - Análise do comportamento com e sem a prevenção de impasse.
        - Discussão sobre o impacto das técnicas de prevenção no desempenho e complexidade do programa.

4. Execução e Testes:
    - Inclua um conjunto de testes para verificar a ocorrência de impasse na versão inicial.
    - Testes para validar que o impasse não ocorre mais após a implementação da prevenção.

## Recursos

    - Documentação da Biblioteca pthread
    - Funções Matemáticas em C (math.h)