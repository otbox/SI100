#include <stdio.h>
#include <string.h>
int main(){
    char palavra[80];
    fgets(palavra,80,stdin);
    for(int i = strlen(palavra) - 1; i >= 0; i--){
        if (palavra[i] != '\n') printf("%c", palavra[i]);
    }
    printf("\n");
}