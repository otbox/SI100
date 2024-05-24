#include <stdio.h>
#include <string.h>
int main(){
    char palavra[80];
    char palavraIn[80];
    scanf("%s", palavra);
    int j = 0;
    for (int i = 0; i < strlen(palavra); i++) {
        if(palavra[i] < 96){palavra[i] = palavra[i] + 32;}
    }
    for(int i = strlen(palavra) - 1; i >= 0; i--){
        if (palavra[i] != '\n') {
            if(palavra[i] < 96){palavraIn[j] = palavra[i] + 32;}else{
            palavraIn[j] = palavra[i];}
            }
        j++;
    }
    // printf("%s %s", palavra, palavraIn);
    if(!strcmp(palavra, palavraIn)){
        printf("Esta palavra e um palindromo\n");
    }else{
        printf("Esta palavra nao e um palindromo\n");
    }
}