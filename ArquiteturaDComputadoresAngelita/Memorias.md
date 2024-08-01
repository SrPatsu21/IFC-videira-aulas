# Memórias

## Introdução

    Nesta atividade de pesquisa, vamos explorar os diferentes tipos de memórias utilizadas em sistemas de computação, como memória cache, DRAM e memória virtual. As perguntas a seguir foram elaboradas para guiá-los no entendimento desses conceitos essenciais. A ideia é que, ao responder essas perguntas, vocês possam adquirir uma compreensão mais profunda de como essas memórias funcionam, como elas se complementam e como impactam o desempenho dos sistemas.

## Memória Cache

### Definição e Propósito Memória Cache

- O que é a memória cache e qual é sua função principal nos sistemas de computação?

    O cache ou memória cache é uma espécie de biblioteca que existe dentro de computadores e dispositivos móveis. Ele funciona para guardar dados, informações e processos temporários acessados com frequência

### Níveis de Cache

- Quais são os diferentes níveis de cache (L1, L2, L3) e quais são suas características em termos de capacidade, velocidade e localização?

    A memória cache fica dentro do processador e é dividida em níveis (L1, L2 e L3) que determinam a proximidade com o núcleo. Quanto mais próxima do núcleo, mais rápida é a velocidade da memória. \
    A localização exata dos níveis de memória cache pode variar conforme a arquitetura do processador. Em geral, o cache L1 fica dentro do núcleo da CPU e não é compartilhado com nenhum outro núcleo. O L2 pode ser exclusivo ou compartilhado entre núcleos. Já o L3 tem maior capacidade e geralmente está fora de um núcleo.

### Mapeamento de Cache

- Explique as diferenças entre mapeamento direto, mapeamento associativo e mapeamento associativo por conjunto.
    mapeamento direto é a forma mais simples de mapeamento, a posição na cache depende do endereco da palavra na memoria principal. Cada palavra tem uma possição fixa?????????????????

    ???????????????

- Como o mapeamento de cache afeta o desempenho do sistema?
    pode causar uma diferença de 23% no desempenho de uma aplicação e 30% em seu consumo energético.

### Políticas de Substituição

- O que são políticas de substituição na memória cache?

    A política de substituição ocorre quando a memória cache está completamente preenchida, e o processador faz a requisição de um endereço de dado que não está na memória cache, sendo então necessário que este endereço seja encontrado na memória principal. Este novo bloco de dados deve ser atualizado na memória cache, tendo que substituir algum dos blocos de endereço mais antigo. Para escolher qual bloco será retirado é necessária a utilização de uma estratégia chamada de política de substituição. Essa estratégia é definida por alguns algoritmos, a saber: LRU (Least Recently Used), FIFO (First In First Out), LFU (Least Frequently Usedmente Usada) e Random (Aleatória) (STALLINGS, 2009).
- Compare as políticas FIFO, LRU e LFU. Quais são as vantagens e desvantagens de cada uma?

    O algoritmo de substituição LRU é conhecido como o mais eficaz dentre os citados, pois ele é baseado na política de substituição do bloco menos recentemente usado. O algoritmo FIFO substitui o primeiro bloco que foi armazenado na cache (o que está há mais tempo), pois de acordo com sua política de substituição o primeiro a entrar é o primeiro a sair. O algoritmo LFU substitui o bloco que foi menos frequentemente usado (ou seja, usado menos vezes), enquanto que o algoritmo Random realiza a substituição de uma das linhas da cache aleatoriamente.

### Cache Hits e Misses

- O que são cache hits e cache misses?

    O cache miss, ou falha de cache, acontece quando o sistema de cache não encontra os dados solicitados armazenados em sua memória. Contrariamente, o cache hit, ou êxito de cache, acontece quando o cache localiza em sua memória os dados requeridos, respondendo à solicitação com sucesso.
- Como a taxa de hits e misses afeta o desempenho geral do sistema?

    Quando um cache miss acontece, o sistema de cache precisa realizar buscas mais aprofundadas nas unidades de memória da CPU para encontrar a informação desejada. Em outras palavras, se o cache não consegue localizar os dados solicitados no nível L1, ele irá buscar pelo cache de nível dois, o L2.

    Quanto mais níveis de cache o sistema precisa verificar, mais tempo ele leva para responder à solicitação do usuário visitante. Isso resulta em um aumento na taxa de cache miss, principalmente quando o sistema precisa buscar os dados armazenados no banco de dados principal (L3).

## Memória DRAM

### Definição e Evolução

- O que é a DRAM e por que é usada como memória principal nos computadores?

    Dynamic Random Acess Memory, É dinâmica pois necessita constantemente de atualização nos pulsos para manter os dados ativos enquanto trabalha. Essa característica faz com que a DRAM seja mais lenta que a SRAM. Os projetistas de memória reduziram o número de elementos por bit, menos transistores, assim economizaram área do chip para criar a DRAM. Como resultado, a produção de DRAM é mais barata do que a SRAM. São amplamente encontradas como memória principal devido ao baixo custo, sendo economicamente mais viáveis.

- Descreva a evolução da DRAM, mencionando FPM DRAM, EDO/BEDO, SDRAM, e DDR.

    Dentro da família de memórias DRAM, existem vários tipos, incluindo assíncronas, síncronas (que são abordadas separadamente), EDO, BEDO, FPM e outras.
    FPM DRAM ou Fast Page Mode DRAM foi projetado para ser mais rápido que os tipos convencionais de DRAM. Como tal, era o principal tipo de DRAM usado em PCs, embora agora esteja bem desatualizado, pois só era capaz de suportar velocidades de barramento de memória de até 66 MHz.
    Extended Data Out DRAM, EDO DRAM era uma forma de DRAM que fornecia um aumento de desempenho em relação ao FPM DRAM. No entanto, esse tipo de DRAM ainda só era capaz de operar em velocidades de até cerca de 66 MHz.
    O Burst EDO DRAM era um tipo de DRAM que melhorava o desempenho do EDO DRAM direto. A vantagem do tipo BEDO DRAM é que ele pode processar quatro endereços de memória em uma rajada, economizando três ciclos de clock quando comparado à memória EDO. Isso foi feito adicionando um contador de endereços no chip para contar o próximo endereço.
    SDRAM: Synchronous DRAM é um tipo de DRAM que é muito mais rápido do que as formas convencionais anteriores de RAM e DRAM. Opera em modo síncrono, sincronizando com o barramento dentro da UCP.
    RDRAM: Este é o Rambus DRAM – um tipo de DRAM que foi desenvolvido pela Rambus Inc, obviamente levando o nome da empresa. Era um concorrente do SDRAM e DDR SDRAM e era capaz de operar em velocidades muito mais rápidas do que as versões anteriores do DRAM

### Comparação entre DRAM e SRAM

- Compare DRAM e SRAM em termos de densidade, latência de acesso, capacidade e custo.

| *SRAM* | *DRAM* |
|:------------- | ---------------:|
|Ele armazena informações enquanto a energia for fornecida. |Ele armazena informações enquanto a energia for fornecida ou alguns milissegundos quando a energia for desligada. |
|Os transistores são usados ​​para armazenar informações na SRAM. |Capacitores são usados ​​para armazenar dados em DRAM. |
|Os capacitores não são usados, portanto, nenhuma atualização é necessária. |Para armazenar informações por mais tempo, o conteúdo do capacitor precisa ser atualizado periodicamente.|
|SRAM é mais rápido em comparação com DRAM. |DRAM fornece velocidades de acesso lentas. |
|Não possui unidade refrescante. |Possui uma unidade refrescante. |
|Estes são caros. |Estes são mais baratos. |
|SRAMs são dispositivos de baixa densidade. |DRAMs são dispositivos de alta densidade. |
|Neste bits são armazenados em forma de tensão. |Neste bits são armazenados na forma de energia elétrica. |
|Eles são usados ​​em memórias cache. |Eles são usados ​​nas memórias principais. |
|Consome menos energia e gera menos calor. |Usa mais energia e gera mais calor. |
|SRAMs têm menor latência |DRAM tem mais latência que SRAM |
|SRAMs são mais resistentes à radiação do que DRAM | DRAMs são menos resistentes à radiação que SRAMs|
|SRAM tem maior taxa de transferência de dados | DRAM tem menor taxa de transferência de dados|
|SRAM é usado em memória cache de alta velocidade | DRAM é usada na memória principal de baixa velocidade|
|SRAM é usada em aplicações de alto desempenho | DRAM é usado em aplicativos de uso geral|

### Organização da Memória Principal

- Explique a organização do subsistema de memória, incluindo conceitos como canal, DIMM, rank, chip (DRAM), banco, linha e coluna.
    ????????????????????????????????????????//

### Funcionamento da DRAM

- Descreva como ocorre a operação básica da DRAM, incluindo os passos para acessar uma linha (closed row e open row).
    Uma memória DRAM pode ser pensada como um arranjo de células, como uma tabela ou planilha. Estas células são feitas de capacitores e contém um ou mais bits de dados, a depender da configuração do chip. Esta tabela é endereçada através de decodificadores de linha e coluna, que por sua vez recebem seus sinais de geradores de clock, denominados geradores CAS (Column Address Strobe) e RAS (Row Address Strobe). De modo a minimizar o tamanho do pacote de dados, os endereços de linha e coluna são multiplexados em buffers. \
    fonte:<https://www.eecis.udel.edu/~portnoi/academic/academic-files/dram.html>

### Tecnologias Recentes

- O que é o Hybrid Memory Cube (HMC) e como ele se compara com a DDR3 em termos de arquitetura e desempenho?
    Hybrid Memory Cube é uma tecnologia de memória de alto desempenho que combina os melhores recursos de DRAM e SRAM para fornecer um aumento significativo de desempenho em relação às tecnologias de memória tradicionais. O Hybrid Memory Cube oferece diversas vantagens em relação às tecnologias de memória tradicionais, incluindo maior largura de banda, menor consumo de energia e maior densidade.
    Um Hybrid Memory Cube (HMC) é um dispositivo de memória de alto desempenho que combina DRAM e circuitos lógicos em um único substrato de silício. O HMC oferece vantagens significativas de desempenho e potência em relação aos dispositivos de memória tradicionais. O HMC fornece uma interface de alta largura de banda e baixa latência entre a DRAM e o circuito lógico, permitindo uma transferência de dados mais eficiente entre os dois. O HMC também utiliza menos energia que os dispositivos de memória tradicionais, tornando-o ideal para uso em aplicações de computação de alto desempenho.
    Um Hybrid Memory Cube (HMC) é um dispositivo de memória de alto desempenho que combina DRAM e lógica em um único chip. O HMC fornece até oito vezes a largura de banda dos dispositivos de memória DDR3 existentes e consome até 70% menos energia. \
    fonte:<https://www.linkedin.com/pulse/solomon-d-5f>

## Memória Virtual

### Definição e Propósito Memória Virtual

- O que é memória virtual e por que é necessária nos sistemas de computação?
    A memória virtual é um recurso utilizado pelos sistemas operacionais para gerenciar a memória RAM de um computador de forma mais eficiente. Ela permite que um sistema utilize mais memória do que está fisicamente disponível, armazenando temporariamente dados menos utilizados no disco rígido.
    Isso ajuda a otimizar o desempenho do sistema, garantindo que os programas possam ser executados mesmo quando a memória RAM está sobrecarregada.
    fonte:<https://escolalbk.com.br/glossario/o-que-e-memoria-virtual/>

### Paginação e Segmentação

- Explique os conceitos de paginação e segmentação. Quais são as diferenças principais entre essas duas técnicas? \
    Swap: Um dos métodos mais comuns de implementação da memória virtual é o uso de um arquivo de troca, também conhecido como swap. Esse arquivo é uma área reservada no disco rígido que é utilizada pelo sistema operacional para armazenar páginas de memória quando a RAM está cheia.

    Paging: Outro método utilizado para implementar a memória virtual é a paginação. Nesse caso, o sistema operacional divide a memória em páginas de tamanho fixo e as armazena tanto na RAM quanto no disco rígido. Quando uma página é necessária, o sistema a transfere da memória virtual para a memória física. Esse processo é transparente para o usuário e ajuda a otimizar o uso da memória.

    diferença: ginação: invisível ao programador, serve para prover um espaço maior de endereçamento. Memória dividida em páginas de igual tamanho, com qualquer conteúdo. Segmentação: em geral visível ao programador, serve para organizar programas e dados, associando atributos de privilégio e proteção a instruções e dados. Os segmentos de um programa residem no disco. Apenas segmentos em uso são carregados na memória. O tamanho de um segmento não é fixo.

    fonte:<https://escolalbk.com.br/glossario/o-que-e-memoria-virtual/><https://www.ime.usp.br/~song/mac344/slides07-virtual-memory.pdf><https://gustavoschroeder.wordpress.com/2015/06/25/paginacao-x-segmentacao/>
- Como a tabela de páginas é usada para mapear endereços virtuais para endereços físicos?

    ??????????????????????????

### Page Fault e Swapping

- O que é um page fault e como o sistema lida com essa situação?
    O erro de página é uma interrupção que ocorre quando o  software tenta acessar um endereço de  memória virtual que não está mapeado para um endereço físico real. Embora o uso de  memória virtual apresente vantagens, como a possibilidade de compartilhar a memória entre processos e o gerenciamento mais eficiente da memória, o erro de página pode reduzir o desempenho do sistema e consumir recursos adicionais do sistema.
    fonte:<https://www.dic.app.br/2010/09/page-fault.html>

- Explique o processo de swapping e como ele ajuda a gerenciar a memória virtual.
    É uma técnica aplicada a gerência de memória, onde o sistema escolhe um programa residente que é levado da memória para o disco (Swapp out), retornando posteriormente para a memória principal RAM com se nada tivesse ocorrido. Quando o programa tiver que ser executado novamente, então ele é novamente carregado para a memória principal (swapp in). Esta operação pode até causar o "swapp out" de um outro programa.
    fonte:<https://pt.wikiversity.org/wiki/Swapping>

### Translation Lookaside Buffer (TLB)

- O que é o TLB e qual é sua função no gerenciamento de memória?
    TLB (do inglês Translation Lookaside Buffer) é um dispositivo de hardware implementado a partir de uma pequena memória associativa que fica integrada na Unidade de Gerenciamento de Memória de um processador. Destina-se a facilitar a tradução de endereços lineares em endereços físicos, evitando a consulta à tabela de páginas localizada na memória
    fonte:<https://pt.wikipedia.org/wiki/Translation_lookaside_buffer>

### Algoritmos de Substituição

- Quais são os principais algoritmos de substituição de páginas? Explique como cada um funciona.
  - FIFO (First In, First Out)
  - OPT (Algoritmo ótimo)
  - LRU (Least Recently Used)
    fonte:<https://wiki.inf.ufpr.br/maziero/doku.php?id=so:algoritmos_de_substituicao_de_paginas>

## Questões Gerais

### Comparação e Escolhas de Memória

- Como os diferentes tipos de memória (cache, DRAM, memória virtual) se complementam em um sistema de computação?
  - Cache: pequena em armazenamento, rápida, fica mais perto e dentro do processador.
  - DRAM: Relativamente rápida, perde os dados após a descarga, mais barata.
  - Memória virtual: fica em uma memória mais lenta e muito mais barata, é basicamente um espaço separado da memória de armazenamento.
- Quais são os trade-offs (compensações) envolvidos na escolha de diferentes tipos de memória para um sistema?
    Economia de espaço e de dinheiro sem afetar muito o desempenho geral.

### Desempenho e Eficiência

- Como a eficiência da memória afeta o desempenho geral de um sistema de computação?
    Quanto mais lenta a memória é, maior o tempo de espera para poder realizar uma operação, e se essa tiver dependências, pode se tornar uma avalanche.
- Quais são as principais métricas usadas para avaliar o desempenho da memória?
    Tempo de resposta, velocidade de saida, tamanho, dinamica ou não, uso de energia.

## Fontes interessantes

[kingston glossary, explica varios conceitos](https://www.kingston.com/br/memory/kingston-glossary)
