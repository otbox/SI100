#include <stdio.h>

int main () {
    for (int x = 0; x <= 10; x++){
        int a = 0;
        scanf("%d", &a);

        if (a % 2 == 0) {
            printf("Este numero é par\n");
        }else {
            printf("é Impar\n");
        }       
    }
    return 0;
}