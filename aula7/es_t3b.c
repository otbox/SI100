#include <stdio.h>

int main () {
    int dd = 0;
    int mm = 0;
    int yyyy = 0;
    scanf("%d/%d/%d", &dd, &mm, &yyyy);

    if ((mm <= 0)||(mm > 12)){
        printf("Mes invalido\n");
        return 0;
    }
    char* meses[] = {"", "janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    
    printf("%d de %s de %d\n", dd, meses[mm], yyyy);
    return 0;
}