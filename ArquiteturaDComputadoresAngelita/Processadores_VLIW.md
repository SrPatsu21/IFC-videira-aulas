# Processadores VLIW

## Exercicios VLIW

### 1. O que é uma arquitetura de processador VLIW e como ela difere das arquiteturas superescalares?

    Um processador VLIW explora o paralelismo no nível de instrução (ILP) de forma eficiente, ele junta várias instruções que não são dependentes e não interferem uma na outra. Eles diferem significativamente das arquiteturas superescalares em termos de como as instruções são organizadas e executadas.

### 2. Quais são as principais vantagens e desvantagens dos processadores VLIW em termos de eficiência e simplicidade de hardware?

    Vantagens: Hardware simples; consumo de energia reduzido; paralelismo é decidido em tempo de compilação, o que pode facilitar a otimização e depuração do código.

    Desvantagens: compilador muito mais complexo, compilador acaba gerando muitas instruções no-op, tem dificuldade em mudar a dependência de dados em tempo real.

### 3. Como o compilador contribui para a execução paralela em processadores VLIW?

    O compilador cria as (Very Long Instruction Word) VLIW, que basicamente é a forma como o paralelismo funciona nesses processadores, pegando essa VLIW, que na verdade é um conjunto de instruções que não geram interferência entre elas, e joga todas dentro do mesmo pipeline.

### 4. Quais são alguns exemplos de processadores que utilizam a arquitetura VLIW e em que contextos eles são geralmente aplicados?

    Intel Itanium, usado para  servidores de alta performance. Transmeta Crusoe, permite emular o 
    Intel x86 instruction set (instruções do intel x86).

### 5. Quais são os principais desafios enfrentados na implementação de processadores VLIW, especialmente em relação à compilação e tamanho do código?

    O tamanho do código pode aumentar muito pois é um processador RISC (reduced instruction set computer) que usa instruções no-op, o que causa uma quantidade gigantesca de código com processos repetidos. 
    O Compilador tem uma complexidade muito grande, juntar as instruções em uma VLIW e que essas instruções não tenham nenhuma dependência e ainda visando um no-op é algo extremamente complicado.
    Apesar de ser simples, fazer com que a VLIW seja executada por completo ao mesmo tempo é algo difícil e que cria mais complexidade no hardware.
