# Questionario 1

## nota 7

## Respostas que resultaram a nota

1. O que é uma exceção em um sistema de computação? \
    **Um evento que desvia a execução normal do programa.** \
    fonte:<https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.listennotes.com%2Fpodcasts%2Ffonte-vozes-da-minha-cabe%25C3%25A7a-fonte-vozes-da--tuiIpzJ9dX%2F&psig=AOvVaw17iGqlAHUZ_aIgK25RRqQJ&ust=1719798905144000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOinsqucgocDFQAAAAAdAAAAABAE>
2. Qual registrador é usado para armazenar o endereço da instrução que causou uma exceção no MIPS? \
    **MAR.** \
    fonte:<https://docente.ifrn.edu.br/moisessouto/disciplinas/organizacao-e-manutencao-de-computadores-i/oc-05-material-extre-sobre-pipeline>
3. Como o Reorder Buffer (ROB) ajuda a implementar exceções precisas? \
    **Armazena resultados intermediários até que possam ser confirmados como precisos.** \
    fonte:<https://www.ic.unicamp.br/~ducatte/mo401/Slides/ILP_dinamico_02_1s06-6.pdf>
4. Por que é importante garantir exceções precisas em um pipeline de execução de instruções? \
    **Para manter a consistência do estado arquitetural.** \
    fonte:<https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.listennotes.com%2Fpodcasts%2Ffonte-vozes-da-minha-cabe%25C3%25A7a-fonte-vozes-da--tuiIpzJ9dX%2F&psig=AOvVaw17iGqlAHUZ_aIgK25RRqQJ&ust=1719798905144000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOinsqucgocDFQAAAAAdAAAAABAE>
5. O que acontece com as instruções no pipeline quando uma exceção precisa é detectada? \
    **As instruções anteriores à exceção são descartadas.** \
    fonte:<https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.listennotes.com%2Fpodcasts%2Ffonte-vozes-da-minha-cabe%25C3%25A7a-fonte-vozes-da--tuiIpzJ9dX%2F&psig=AOvVaw17iGqlAHUZ_aIgK25RRqQJ&ust=1719798905144000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOinsqucgocDFQAAAAAdAAAAABAE>
6. Qual técnica pode ser usada para resolver dependências de saída (WAW) e anti-dependências (WAR) em execução fora de ordem? \
    **Renomeação de registradores.** \
    fonte:<https://pt.wikipedia.org/wiki/Renomea%C3%A7%C3%A3o_de_registradores>
7. Em que circunstâncias uma interrupção de alta prioridade deve ser tratada imediatamente? \
    **Quando uma exceção ocorre ao mesmo tempo.** \
    fonte:<https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.listennotes.com%2Fpodcasts%2Ffonte-vozes-da-minha-cabe%25C3%25A7a-fonte-vozes-da--tuiIpzJ9dX%2F&psig=AOvVaw17iGqlAHUZ_aIgK25RRqQJ&ust=1719798905144000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOinsqucgocDFQAAAAAdAAAAABAE>
8. Considere as seguintes afirmações sobre exceções precisas:
I Exceções precisas garantem que o estado do processador seja consistente antes da exceção ser tratada.
II Exceções podem ser ignoradas se não afetarem a execução do programa.
III Para uma exceção precisa, todas as instruções anteriores devem ter sido completamente terminadas.
IV Instruções posteriores à exceção podem ser completadas antes da exceção ser tratada.
V O uso de um buffer de reordenação ajuda a implementar exceções precisas. \
    **I, III e V** \
    fonte:<https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.listennotes.com%2Fpodcasts%2Ffonte-vozes-da-minha-cabe%25C3%25A7a-fonte-vozes-da--tuiIpzJ9dX%2F&psig=AOvVaw17iGqlAHUZ_aIgK25RRqQJ&ust=1719798905144000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOinsqucgocDFQAAAAAdAAAAABAE>
9. Qual é a principal vantagem de usar o ROB em processadores com execução fora de ordem? \
    **Suporte eficiente para exceções precisas.** \
    fonte:<https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.listennotes.com%2Fpodcasts%2Ffonte-vozes-da-minha-cabe%25C3%25A7a-fonte-vozes-da--tuiIpzJ9dX%2F&psig=AOvVaw17iGqlAHUZ_aIgK25RRqQJ&ust=1719798905144000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOinsqucgocDFQAAAAAdAAAAABAE>
10. Sobre o tratamento de interrupções e exceções, considere as seguintes afirmações:
I Interrupções são geradas por eventos externos ao processador.
II Traps são exceções causadas por condições especificadas pelo programador.
III Exceções sempre ocorrem devido a erros de hardware.
IV Exceções podem ser tratadas a qualquer momento, independentemente do contexto.
V O EPC (Exception Program Counter) armazena o endereço da instrução que causou a exceção.
Selecione a alternativa correta: \
    **I, II e V** \
    fonte:<https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.listennotes.com%2Fpodcasts%2Ffonte-vozes-da-minha-cabe%25C3%25A7a-fonte-vozes-da--tuiIpzJ9dX%2F&psig=AOvVaw17iGqlAHUZ_aIgK25RRqQJ&ust=1719798905144000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCOinsqucgocDFQAAAAAdAAAAABAE>
