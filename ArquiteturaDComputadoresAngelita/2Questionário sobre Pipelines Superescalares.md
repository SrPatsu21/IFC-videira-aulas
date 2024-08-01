# Questionario 2

## nota 9

## Respostas que resultaram a nota

1. Qual foi o primeiro processador superescalar RISC? \
    **IBM Power-1** \
    fonte:<https://ic.unicamp.br/~rodolfo/Cursos/mo401/2s2005/Trabalho/029043-superescalar.pdf>
2. O que é uma dependência de controle (procedural)?
    **Conflito causado por instruções de desvio (branches).** \
    fonte:<https://images3.memedroid.com/images/UPLOADED6/5d265c52d07c7.jpeg>
3. Qual técnica é usada para eliminar dependências de saída e antidependências em arquiteturas superescalares? \
    **Renomeação de registradores** \
    fonte:<https://ic.unicamp.br/~rodolfo/Cursos/mo401/2s2005/Trabalho/029043-superescalar.pdf> \
    *Obs: fala de register renaming.*
4. Em que consiste a técnica de execução especulativa em processadores superescalares? \
    **Executar instruções antes que as dependências sejam completamente resolvidas.** \
    fonte:<https://www.ic.unicamp.br/~ducatte/mo401/1s2009/T2/971766-t2>
5. Sobre as técnicas de execução em arquiteturas superescalares, considere as seguintes afirmações: \
    I A execução especulativa permite executar instruções antes da resolução completa das dependências.
    II O escalonamento dinâmico é realizado em tempo de compilação.
    III Predição de desvios ajuda a reduzir stalls causados por branches.
    IV Dependências de dados sempre podem ser eliminadas pelo compilador.
    V Processadores superescalares podem despachar múltiplas instruções em paralelo.
    Selecione a alternativa correta: \
    **I, III e V** \
    fonte:<https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRSJsavUwWigzqxnTJU4h1TjnvERGnyvY-9Bg&s>
6. Qual é o papel das "unidades funcionais" em uma arquitetura superescalar? \
    **Executar operações específicas como adição, multiplicação e acesso à memória.** \
    fonte:<https://pt.wikipedia.org/wiki/Superescalar>
7. Em que consiste a técnica de "software pipelining" em arquiteturas superescalares? \
    **Uso de hardware adicional para aumentar a paralelização.** \
    fonte:<https://youtu.be/2Aeg__3wl5Y?si=vM8pLE5WaypSomq9>
8. Considere as seguintes afirmações sobre conflitos de dados e técnicas de otimização em arquiteturas superescalares:
    I Conflitos de dados do tipo RAW (Read After Write) não podem ser eliminados por técnicas de hardware.
    II O uso de renomeação de registradores pode eliminar dependências de saída (WAW).
    III Conflitos por recursos ocorrem quando múltiplas instruções competem pelo mesmo recurso.
    IV Dependências de controle podem ser mitigadas com predição de desvios.
    V Software pipelining não é aplicável em arquiteturas superescalares.
    Selecione a alternativa correta: \
    **II, III e IV** \
    fonte:<https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSXnc2d7g2KQqkWkgNukXrc8GVxyj3G66evHA&s>
9. Qual é a principal diferença entre escalonamento estático e dinâmico em processadores superescalares?
    **Escalonamento estático ocorre em tempo de compilação, enquanto o dinâmico ocorre em tempo de execução.**
    fonte:<https://youtu.be/myS3A6p5xuA?si=Lh-3co66dzeAS7aC>
10. Quais são os três tipos de dependências de dados que podem ocorrer em arquiteturas superescalares? \
    **RAW (Read After Write), WAR (Write After Read) e WAW (Write After Write).** \
    fonte:<https://a-static.mlcdn.com.br/450x450/caneca-meme-flork-meu-ovo-lunabu/lunabuvilamaria/100900012/c451eb2407272132bc78f98d605e4a0c.jpeg>
