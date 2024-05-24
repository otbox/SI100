#include <stdio.h>

int main () {
    char operador;
    float a, b;
    scanf("%f%c%f", &a, &operador, &b);

    switch(operador){
        case '+':
            printf("%0.3f%c%0.3f=%0.3f\n", a, operador, b,a+b);
            break;
        case '-':
            printf("%0.3f%c%0.3f=%0.3f\n", a, operador, b,a-b);
            break;
        case '*':
            printf("%0.3f%c%0.3f=%0.3f\n", a, operador, b,a*b);
            break;
        case '/':
            printf("%0.3f%c%0.3f=%0.3f\n", a, operador, b,a/b);
            break;
        default:
            printf("Operador invalido\n");
            break;
    }

}