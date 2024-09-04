#include <stdio.h>
#include <stdlib.h>

void imprimirmatriz(int** matriz, int c, int l){
    for(int j = 0; j < l; j++){
        for (int i = 0; i < c; i++){
            printf("%d ",matriz[j][i]);
        }   
        printf("\n");
    }
}
int main() {
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    int** matriz = (int **)malloc(linhas * sizeof(int*));
    // int** matrizT = (int **)malloc(colunas * sizeof(int*));
    for (int i = 0; i <  linhas; i++){
        matriz[i] = (int *)malloc(colunas*sizeof(int));
    } 
    // for (int i = 0; i <  colunas; i++){
    //     matrizT[i] = (int *)malloc(linhas*sizeof(int));
    // } 
    for(int j = 0; j < linhas; j++){
        for (int i = 0; i < colunas; i++){
            scanf("%d",&matriz[j][i]);
            // matriz[i][j] = matriz[j][i];
        }   
    }
    // imprimirmatriz(matriz, colunas, linhas);
    if (linhas != colunas){
        printf("Nao eh simetrica\n");
        return 0;
    }
    int n = 0;
    for(int j = 0; j < linhas; j++){
        for (int i = 0; i < colunas; i++){
            if(matriz[i][j] == matriz[j][i]){
                n++;
            }
        }   
    }
    if (n == linhas * colunas){
        printf("Eh simetrica\n");
    }else{
        printf("Nao eh simetrica\n");
    }
    return 0;
}