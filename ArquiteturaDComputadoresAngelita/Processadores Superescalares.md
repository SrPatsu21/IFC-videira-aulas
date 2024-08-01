# Processadores Superescalares

## Exercicios Superescalares

### 1. Quais são os principais tipos de processadores de múltiplo issue discutidos no artigo, e qual empresa foi pioneira no desenvolvimento do primeiro processador superescalar?

    Basicamente de dois tipos: Processadores superescalares e processadores VLIW. A pioneira foi a IBM com seu Power-1 da linha RS/6000.

### 2. Quais são as três categorias de limitações que devem ser consideradas para a otimização do uso do pipeline superescalar, conforme mencionado no artigo?

    Conflitos por recursos, quando 2 ou mais instruções competem pelo mesmo recurso(memória, registrador, unidade funcional) ao mesmo tempo; Dependência de controle, branchs e CISC(tamanho variado); Dependências de dados produzidas por dependências entre instruções.

### 3. Como a técnica de previsão de desvios e execução especulativa contribui para a melhoria do desempenho das arquiteturas superescalares, e quais são os desafios associados a essas técnicas?

    A previsão de desvio ajuda a evitar gargalos em salto, tomando eles antecipadamente, sendo o desafio aumentar os acertos e corrigir erros, caso acerte o processamento continua normalmente, caso erre o processamento irá apagar os processos posteriores e recomeçar, isso permite que toda vez q um salto ocorra há uma chance grande de ganhar algumas instruções por clock.

    Execução especulativa: a CPU tenta adivinhar qual código precisa ser executado em seguida e, então, executa esse código antes de ser solicitado a fazê-lo.

### 4. O que é paralelismo no nível de instrução (ILP) e como os processadores superescalares exploram esse conceito para aumentar o desempenho?

    Permite executar várias instruções em cada ciclo de relógio. Modificações na microarquitetura do processador para possibilitar a execução paralela de instruções. Abordagens: Paralelismo temporal: encadeamento no fluxo de execução das instruções (pipeline);

### 5. Quais são as principais diferenças entre execução estática e execução dinâmica em processadores superescalares, e quais são as vantagens de cada abordagem?

    Na execução dinâmica as instruções são separadas em hardware e o próprio processador cria as dependências e segura a execução, na execução estática tudo isso deve ser feito pelo compilador.
    O estático é mais rápido, mais barato, porém consome muito mais memória. O dinâmico é mais lento, mais complexo, porém usa menos a memória

### 6. Como a presença de dependências de dados (RAW, WAR, WAW) e dependências de controle afeta a execução de instruções em processadores superescalares, e quais técnicas podem ser usadas para mitigar esses efeitos?

    Reorder Buffer (ROB) e Register Alias Table (RAT) - são tabelas que ajudam a mitigar a dependência de dados e de saída, e também ajuda na dependência de controle. Duas tabelas são criadas, a RAT associada ao banco de registradores e a ROB fica na saída das UF (Unidade Funcional), quando alguma instrução vai escrever em X registrador é escrito na RAT que X registrador esta sendo usado e o seu valor mais atualizado está no ROB Y, ai que entra o ROB, ele é uma tabela que é adicionado as instruções na ordem de despache, guardando algumas informações como o OP.Code, o Reg.Dest, Valor.Dest, Valido.Dest e Executado?. todas essas informações auxiliam ao processador a saber em qual registrador essa instrução vai escrever, e caso ocorrer dependencia real de dados, a instrução que é dependente pode procurar o dado no ROB.
