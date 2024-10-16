# Relatório de Análise

## Compilar

Use o make file, nele tem a configuração para rodar os 2 programas. RunDeadLock para rodar o programa com deadlock e RunFix para rodar o programa com prevenção de deadlock.

## Problema

A colonia de bactéria tem um comportamento simples e pode ser facilmente calculada, a grande dificuldade vem com a gerência dos recursos. A gestão de mutex é complexa por si só. Para gerenciar dois array de mutex, criei outros dois array de inteiro, para permitir a construção de uma ¨fila¨ de espera, para distribuir melhor o uso dos mutex, evitando uma espera muito grande em um dos recursos. Uso de 4 funções para gerenciar tudo isso, 2 para dar lock e 2 para unlock. Para dar lock, percorro o array de mutex testando se o mutex está livre, se não estiver, percorro o array de inteiro que representa quantas threads estão esperando o recurso, e escolho o que tem o menor número.

Para manter a main viva, fiz o uso de um mutex para evitar que o código avance e o processo acabe. Basicamente, dou um lock no início das threads e uso outro mutex para controlar uma variável de número de threads e verifico quantas rodaram toda vez que uma delas acaba. Quando todas terminaram, dou unlock e a main finaliza.

A função da colonia é bem simples inicialmente. Dá print que está iniciando e entra em um for até ¨t¨. Ela tem um rand() com os mutex em ordem diferente, para forcar deadlock. A função dorme por 100 ms, para simular uma operação mais longa. Soma do crescimento e print dos resultados. Ao fim do for, a função dá print nos resultados.

A main tem as variáveis da equação, e elas devem ser alteradas lá. Não fiz input do usuário, pois achei desnecessário. Tomaria muito tempo e não representava uma melhora do código. Na main também ocorre a inicialização dos mutex e das threads. As threads começam a funcionar da forma citada anteriormente.

## Prevenção de deadlock

O comportamento sem prevenção de impasse é mais lento, se considerarmos que a prevenção que fiz foi a de timeout. Sem prevenção, o código levou 5.36 segundo, isso depois de muitas tentativas. Com timeout, o código levou 5.9 segundos, uma diferença de 0.54s, muito dessa diferença se dá pelo tempo de timeout. O timeout não é a melhor opção, eu fiz como desafio, porém a melhor escolha seria a mais simples, reorganizar os mutex e talvez até analisar qual recurso está mais abundante e colocá-lo na frente.

Inicialmente a minha ideia de timeout era destruir uma função que estava há muito tempo travada e reconstruí-la, essa estrategia deu certo porem às vezes era bem lenta e causou um problema tao ruim quanto deadlock, ciclo de timeout, a resolução desse problema causava uma mudança muito grande no código. Então, o timeout foi feito em nível de mutex apenas, uma das funções teve que perder a capacidade de ter fila, para que não ficasse travada, assim coloquei em um loop com um sleep para que, em determinado tempo, a thread tentasse dar lock novamente. Para trazer um sistema mais eficiente em timeout, é interessante trabalhar com semáforo ou pthread_cond_timedwait().

## Impacto das prevenções

Independente do impacto, é essencial para se obter resultados e manter o multiprocessamento de forma eficiente. Algumas técnicas de desempenhas chegam a melhorar a velocidade do programa, como a técnica de ordenamento. Técnicas de hierarquia são muito úteis em sistemas operacionais, principalmente em servidores e sistemas de tempo real. Técnicas de timeout são interessantes para SOS pessoais, que rodam com uma grande variedade de programas com comportamento desconhecido. Quanto a complexidade, varia muito, sendo de extremamente complexo a simplório. Em geral, a complexidade acompanha a complexidade do sistema, quanto mais diverso o sistema, mais robusta deve ser a técnica.
