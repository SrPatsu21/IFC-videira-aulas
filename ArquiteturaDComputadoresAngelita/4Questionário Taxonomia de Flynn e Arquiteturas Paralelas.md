# Questionario 4

## nota 6

## Respostas que resultaram a nota

1. Em um sistema MIMD, como são organizadas as instruções e os dados? \
    **Múltiplas instruções, múltiplos dados.** \
    fonte:<https://wiki.sj.ifsc.edu.br/index.php/MI1022806_2020_2_AULA12>
2. Qual é a classificação correta para máquinas que executam uma única instrução em múltiplos dados? \
    **SISD** \
    fonte:<https://blog.botcity.dev/pt-br/2023/12/05/processamento-paralelo/>
3. Qual das seguintes é uma desvantagem das arquiteturas NUMA? \
    **Dificuldade em escalar o sistema.** \
    fonte:(Obs: nao ajudou)  <https://expressvps.com.br/glossario/o-que-e-non-uniform-memory-access-numa/>
4. Considere as seguintes afirmações sobre a Taxonomia de Flynn:
I SIMD se refere a máquinas que executam uma única instrução em múltiplos dados simultaneamente.
II SISD é a arquitetura típica dos computadores modernos de uso geral.
III MIMD pode executar múltiplas instruções em múltiplos dados ao mesmo tempo.
IV MISD é uma arquitetura amplamente usada em processamento paralelo.
V A classificação de Flynn ajuda a entender a organização do paralelismo em sistemas de computação.
Selecione a alternativa correta: \
    **I, III, IV e V** \
    fonte:<https://youtu.be/H176SrVF2ew?si=nX10AV_BbI_v2kDz>
5. Qual é a principal vantagem das máquinas SIMD em relação às máquinas SISD? \
    **Melhor desempenho em aplicações com grande paralelismo de dados.** \
    fonte:<https://youtu.be/H176SrVF2ew?si=nX10AV_BbI_v2kDz>
6. Sobre máquinas paralelas e multithreading, considere as seguintes afirmações:
I UMA significa Uniform Memory Access, onde todos os processadores têm acesso uniforme à memória.
II SMT permite a execução simultânea de múltiplas threads em um único núcleo.
III Em multiprocessadores NUMA, o tempo de acesso à memória é uniforme.
IV Multithreading intercalado (IMT) troca threads a cada ciclo de clock.
V O "clock wall" foi uma das razões para a transição de single-core para multi-core.
Selecione a alternativa correta: \
    **I, II, IV e V** \
    fonte:<https://www.qconcursos.com/questoes-de-concursos/questoes/3e2b15f0-c7><https://www.ic.unicamp.br/~rodolfo/Cursos/mo401/2s2005/Trabalho/930886-thread.pdf>
7. Em que tipo de aplicação as arquiteturas MISD são tipicamente usadas, apesar de serem raras? \
    **Análise de dados em larga escala.** \
    fonte:<https://andreprzybysz.com/2023/04/19/classificacao-de-flynn-para-categorizar-as-arquiteturas-de-processadores/><https://pt.stackoverflow.com/questions/257086/qual-o-significado-das-siglas-sisd-simd-misd-mimd-qual-a-sua-rela%C3%A7%C3%A3o-com-pro>
8. Qual é a principal vantagem do multithreading simultâneo (SMT) em comparação com o multithreading bloqueado (BMT)? \
    **Execução de múltiplas threads ao mesmo tempo.** \
    fonte:<https://youtu.be/H176SrVF2ew?si=nX10AV_BbI_v2kDz>
9. Considere as seguintes afirmações sobre a classificação de Flynn e arquiteturas paralelas:
I Arquiteturas SIMD são ideais para aplicações com grande paralelismo de dados, como processamento de imagem.
II Arquiteturas MIMD são mais flexíveis que SIMD, pois podem executar diferentes instruções em diferentes dados.
III SISD é a única categoria da Taxonomia de Flynn que não suporta paralelismo.
IV Processadores superescalares são um exemplo de MIMD.
V Em arquiteturas NUMA, todos os processadores têm o mesmo tempo de acesso à memória.
Selecione a alternativa correta: \
    **I, II e IV** \
    fonte:<https://andreprzybysz.com/2023/04/19/classificacao-de-flynn-para-categorizar-as-arquiteturas-de-processadores/>
10. O que significa UMA em multiprocessadores? \
    **Uniform Memory Access** \
    fonte:<https://www.docentes.univasf.edu.br/max.santana/material/OAC-II/multiprocessadores.pdf>