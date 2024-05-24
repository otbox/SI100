#include <stdio.h>

int main () {
    int a = 0;
    scanf("%d", &a);

    if (a % 2 == 0) {
        printf("Este numero é par");
    }else {
        printf("é Impar");
    }
    return 0;
}