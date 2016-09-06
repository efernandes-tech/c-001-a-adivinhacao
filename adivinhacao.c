#include <stdio.h>

int main() {
    printf("************************************\n");
    printf("* Bem vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");
	
	int chute;

	printf("Qual é o seu chute? ");
	scanf("%d", &chute);
	printf("Seu chute foi %d\n", chute);
}