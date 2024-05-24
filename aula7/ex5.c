#include <ctype.h>
#include <stdio.h>

int main () {
    char a;
    scanf("%c", &a);

    printf("%c\n", toupper(a));
    return 0;
}