// Geralmente todos os programas usam esta primeira biblioteca pois ela armazena as funcoes de entrada e saida.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// O "#..." significa diretivas. E aqui esta declarando uma CONSTANTE.
// #define NUMERO_DE_TENTATIVAS 3;

int main() {

    // Imprime o cabecalho do jogo.
    printf("************************************\n");
    printf("* Bem vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");

    // Gera o timestamp.
    int segundos = time(0);
    // Coloca a semente na funcao.
    srand(segundos);
    // Gera um numero randomico muito grande.
    int numerogrande = rand();
    // Pega o resto da divisao de 1 a 99.
    int numerosecreto = numerogrande % 100;
    // Tudo em duas linhas:
    // srand(time(0));
    // int numerosecreto = rand() % 100;

    int chute;
    int acertou = 0;
    int tentativas = 1;
    double pontos = 1000;

    while(!acertou) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        printf("Seu chute foi %d\n", chute);

        // A linguagem sem nao tem o tipo "boolean", então usar a convencao "int 0 == false" e "int 1 == true".
        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou) {
            printf("Parabéns! Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");
            break;
        } else if(maior) {
            printf("Seu chute foi maior do que o número secreto!\n");
        } else {
            printf("Seu chute foi menor do que o número secreto!\n");
        }

        tentativas++;

        // Vc precisa fazer o "casting" pq o compilador le da direita para esquerda, entao ele inseri um "int" na variavel mesmo ela sendo "double".
        double pontosperdidos = abs(chute - numerosecreto) / (double) 2;
        // "if" para resolver o bug do chute 30, pq o "-(-1)" dava "+" e o jogador ganhava pontos por errar. Vc tmb pode usar a funcao "abs()" que transforma tudo em positivo pq ela devolve o valor absoluto.
        // if (pontosperdidos < 0) {
        //     pontosperdidos = pontosperdidos * -1;
        // }
        pontos = pontos - pontosperdidos;
    }

    printf("Você acertou em %d tentativas!", tentativas);
    // O "%.2f" exibe com duas casas decimais.
    printf("Você fez %.2f pontos!\n", pontos);
    printf("Fim de jogo!\n");
}