#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int grau;
    scanf("%d", &grau);
    int grau1 = grau + 1;
    float* vetor = (float *)malloc(grau1 * sizeof(float));
    if (vetor ==  NULL){
        printf("Sem memoria");
        return 1;
    }
    for (int a = 0; a < grau + 1; a++){
        if(a % 2  == 0){
            scanf("%f", &vetor[a]);
            continue;
        }
        scanf("%f", &vetor[a]);
    }
    float x;
    scanf("%f",&x);
    float soma;
    for (int b = 0; b < grau + 1; b++){
        soma += vetor[b] * pow(x, b);
    } 
    printf("%.2f\n", soma);

}