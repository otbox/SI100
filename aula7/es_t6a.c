#include <stdio.h>

int main() {
    int a = 0,b = 0;
    scanf("%d %d",&a,&b);
    int array[a][b];

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf("%d",&array[i][j]);
        }
    }

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            printf("%d ", array[j][i]);
        }
        printf("\n");
    }
}