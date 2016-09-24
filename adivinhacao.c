#include <stdio.h>

// O "#..." significa diretivas.
#define NUMERO_DE_TENTATIVAS 3;

int main() {
    printf("************************************\n");
    printf("* Bem vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");

    int chute;
    int numerosecreto = 42;

    for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++) {
        printf("Qual é o seu %do. chute? ", i);
        scanf("%d", &chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos\n");
            i--;
            continue;
        }

        // A linguagem sem nao tem o tipo "boolean", então usar a convencao "int 0 == false" e "int 1 == true".
        int acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if(acertou) {
            printf("Parabéns! Você acertou!\n");
            break;
        } else if(maior) {
            printf("Seu chute foi maior do que o número secreto!\n");
        } else {
            printf("Seu chute foi menor do que o número secreto!\n");
        }
    }

    printf("Obrigado por jogar!\n");
}