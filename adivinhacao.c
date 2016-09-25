// Geralmente todos os programas usam esta primeira biblioteca pois ela armazena as funcoes de entrada e saida.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// O "#..." significa diretivas. E aqui esta declarando uma CONSTANTE.
// #define NUMERO_DE_TENTATIVAS 3;

int main() {

    // Imprime o cabecalho do jogo.
    printf("\n\n");
    printf("          P  /_\\  P                               \n");
    printf("         /_\\_|_|_/_\\                             \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao      \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!  \n");
    printf("    |" "  |  |_|  |"  " |                          \n");
    printf("    |_____| ' _ ' |_____|                          \n");
    printf("          \\__|_|__/                               \n");
    printf("\n\n");

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
    int acertou;
    int nivel;
    int totaldetentativas;

    // Definindo a quantidade de pontos inicial.
    double pontos = 1000;

    // Escolhendo o nivel de dificuldade.
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch (nivel) {
        case 1:
            totaldetentativas = 20;
            break;
        case 2:
            totaldetentativas = 15;
            break;
        default:
            totaldetentativas = 6;
            break;
    }

    // Loop principal do jogo.
    for (int i = 1; i <= totaldetentativas; i++) {

        printf("-> Tentativa %d de %d\n", i, totaldetentativas);

        printf("Chute um número: ");
        scanf("%d", &chute);

        // Tratando chute de numero negativo.
        if (chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            i--;
            continue;
        }

        // A linguagem sem nao tem o tipo "boolean", então usar a convencao "int 0 == false" e "int 1 == true".
        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if (acertou) {
            break;
        } else if (maior) {
            printf("Seu chute foi maior do que o número secreto!\n");
        } else {
            printf("Seu chute foi menor do que o número secreto!\n");
        }

        // Vc precisa fazer o "casting" pq o compilador le da direita para esquerda, entao ele inseri um "int" na variavel mesmo ela sendo "double".
        double pontosperdidos = abs(chute - numerosecreto) / (double) 2;
        // "if" para resolver o bug do chute 30, pq o "-(-1)" dava "+" e o jogador ganhava pontos por errar. Vc tmb pode usar a funcao "abs()" que transforma tudo em positivo pq ela devolve o valor absoluto.
        // if (pontosperdidos < 0) {
        //     pontosperdidos = pontosperdidos * -1;
        // }
        pontos = pontos - pontosperdidos;
    }

    // Imprimindo mensagem de vitoria ou derrota.
    printf("\n");
    if (acertou) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\nParabéns! Você acertou!\n");
        // O "%.2f" exibe com duas casas decimais.
        printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
    } else {
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
        printf("\nVocê perdeu! Tente novamente!\n\n");
    }

}