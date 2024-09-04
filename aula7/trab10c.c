#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){

    typedef struct {
        char nome[110];
        int ra;
        float p1;
        float p2;
    } aluno;

    int nalunos;
    scanf("%d", &nalunos);
    getchar();
    aluno* alunos = (aluno*)malloc(nalunos * sizeof(aluno));  

    for(int i = 0; i < nalunos; i++){
        fgets(alunos[i].nome,110,stdin); 
        int len = strlen(alunos[i].nome);
        alunos[i].nome[len-1] = '\0';
        scanf("%d",&alunos[i].ra); 
        scanf("%f",&alunos[i].p1); 
        scanf("%f",&alunos[i].p2); 
        getchar();
    }
    for(int i = 0; i < nalunos; i++){
        float media = (alunos[i].p1 + alunos[i].p2)/2;
        printf("%d\t%s\t%.2f\n", alunos[i].ra,alunos[i].nome, media);
    }
}
