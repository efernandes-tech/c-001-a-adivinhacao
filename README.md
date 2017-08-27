# c-001-a-adivinhacao

##### Anotações:

1 - IDE gratuita que ja instala o compilador GCC:
    http://www.codeblocks.org/
2 - Quando a condicao (if, while, ...) for muito grande, é interessante armazenar o resultado em uma variavel com um nome que explique a condicao.
    int acertou = (i == 42 || i == 23 || i == 32 || i == 7);
3 - Comando para compilar a classe no Windows e Linux:
    gcc adivinhacao.c -o adivinhacao.exe
    gcc adivinhacao.c -o adivinhacao
4 - Comando para executar a programa no Windows e Linux:
    adivinhacao
    ./adivinhacao
5 - Os "números mágicos" são aqueles que tem um significado importante para o código mas estão jogados. Então use CONSTANTES.
6 - Em C sempre que uma variavel é declarada, ela fica com o valor que ja estava no espaco de memoria. Entao nunca a use sem inicializala com algum valor. O Java não deixa.
7 - Cuidado com o "casting" de variaveis. Vc pode perder dados. Lembre-se do foguete que explodiu pq era "float" e nao "double".
8 - PCs so conseguem gerar numeros "pseudo-randomicos". Entao vc precisa passar uma semente para a funcao que gera o numero randomico. Assim vc nao fica em um loop de um numero so.
