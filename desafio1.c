#include <stdio.h>

int main() {
    int x;
    int y;
    int resultado;
    printf("Digite o X: ");
    scanf("%d", &x);
    printf("Digite o Y: ");
    scanf("%d", &y);
    resultado = x * y;
    printf("X * Y = %d", resultado);
}