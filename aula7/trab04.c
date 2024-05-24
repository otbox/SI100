#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxLetras 20
#define maxPalavras 70
#define maxSetencas 20
#define maxParagrafos 10

typedef struct {
    int numLetras;
    char letras[maxLetras];
} palavras;

typedef struct {
    int numPalavras;
    int numCaracteres;
    palavras palavras[maxPalavras];
} setenca;

typedef struct {
    int numSetenca;
    setenca setenca[maxSetencas];
} paragrafo;

void separador(char pal[400], char palFormatada[20][20]) {
    int a = 0, l = 0;
    for(int m = 0; m < strlen(pal) -2; m++) {
        if(pal[m] == '\n' || pal[m] == '\0') {
            pal[m] = '\0';
            palFormatada[a][l] = '\0';
            break;
        }
        if(pal[m] == ' ' || pal[m] == '\n' || pal[m] == '\0') {
            if(l > 0) {
                palFormatada[a][l] = '\0';
                a++;
                l = 0;
            }
        } else {
            palFormatada[a][l] = pal[m];
            l++;
        }
    }
}

int ComparadorPositividade(paragrafo texto, char PalForm[20][20]) {
    int positividade = 0;
    for (int s = 0; s < texto.numSetenca; s++) {
        for (int p = 0; p < texto.setenca[s].numPalavras; p++) {
            char *palav = texto.setenca[s].palavras[p].letras;
            for (int p1 = 0; p1 < 20; p1++) {
                if (strcmp(palav, PalForm[p1]) == 0) {
                    positividade++;
                    // printf("Comparacao: '%s' | '%s'\n", palav, PalForm[p1]);
                    break; // Palavra encontrada, não precisa verificar mais
                } else {
                    // printf("Diferente: '%s' | '%s'\n", palav, PalForm[p1]);
                }
            }
        }
    }
    return positividade;
}

int ComparadorPositividadeSentenca(setenca texto, char PalForm[20][20]) {
    int positividade = 0;
    for (int p = 0; p < texto.numPalavras; p++) {
        char *palav = texto.palavras[p].letras;
        for (int p1 = 0; p1 < 20; p1++) {
            if (strcmp(palav, PalForm[p1]) == 0) {
                positividade++;
                // printf("Comparacao: '%s' | '%s'\n", palav, PalForm[p1]);
                break; // Palavra encontrada, não precisa verificar mais
            } else {
                // printf("Diferente: '%s' | '%s'\n", palav, PalForm[p1]);
            }
        }
    }
    return positividade;
}

int Num_paragrafo;

void TestadordePositividade(int posPos, int posNeg) {
    int positividade = posPos - posNeg;
    char *textoPositividade = "neutra"; // 1 positivo 0 neutro 
    if(positividade > 3){
        textoPositividade = "positiva";
    }else if(posPos > 0 && posNeg == 0){
        textoPositividade = "positiva";
    }else if(positividade < -3){
        textoPositividade = "negativa";
    }else if(posNeg > 0 && posPos == 0){
        textoPositividade = "negativa";
    }

    printf("%d Palavras positivas, %d Palavras negativas: Polaridade %s\n", posPos, posNeg, textoPositividade);
}

void Opc1 (paragrafo paragrafos[Num_paragrafo],char PalPosFormatada[20][20],char PalNegFormatada[20][20]){
    int numPalNeg = 0, numPalPos = 0;
    for(int p = 0;  p < Num_paragrafo; p++){
        numPalPos += ComparadorPositividade(paragrafos[p], PalPosFormatada); 
        numPalNeg += ComparadorPositividade(paragrafos[p], PalNegFormatada);
    }
    int positividade = numPalPos - numPalNeg;
    TestadordePositividade(numPalPos, numPalNeg);
}

void Opc2 (paragrafo paragrafos,char PalPosFormatada[20][20],char PalNegFormatada[20][20]){
    int numPalPos = ComparadorPositividade(paragrafos, PalPosFormatada); 
    int numPalNeg = ComparadorPositividade(paragrafos, PalNegFormatada);
    int positividade = numPalPos - numPalNeg;
    // printf("%d Palavras positivas, %d Palavras negativas: Polaridade %s\n", numPalNeg, numPalPos, positividade >= 0 ? "positiva" : "negativa");
    TestadordePositividade(numPalPos, numPalNeg);
}


void Opc3 (paragrafo paragrafos[Num_paragrafo], char PalPosFormatada[20][20],char PalNegFormatada[20][20]){
    setenca maiorsetenca = {0,0,0};
    for(int p= 0; p < Num_paragrafo; p++){
        for(int s = 0; s < paragrafos[p].numSetenca; s++){
            if(maiorsetenca.numCaracteres < paragrafos[p].setenca[s].numCaracteres){
                maiorsetenca = paragrafos[p].setenca[s];
            }
        }
    }
    int numPalPos = ComparadorPositividadeSentenca(maiorsetenca, PalPosFormatada);
    int numPalNeg = ComparadorPositividadeSentenca(maiorsetenca, PalNegFormatada);
    int positividade = numPalPos - numPalNeg;
    // printf("Maior setença tam: %d | %s\n",maiorsetenca.numCaracteres,  maiorsetenca.palavras[0].letras);
    // printf("%d Palavras positivas, %d Palavras negativas: Polaridade %s\n", numPalNeg, numPalPos, positividade >= 0 ? "positiva" : "negativa");
    TestadordePositividade(numPalPos, numPalNeg);
}

void Opc4 (paragrafo paragrafos[Num_paragrafo], char PalPosFormatada[20][20],char PalNegFormatada[20][20]){
    setenca menorsetenca = {0,1000000,0};
    for(int p= 0; p < Num_paragrafo; p++){
        for(int s = 0; s < paragrafos[p].numSetenca; s++){
            if(paragrafos[p].setenca[s].numCaracteres > 0){
                if(paragrafos[p].setenca[s].numCaracteres < menorsetenca.numCaracteres){
                    menorsetenca = paragrafos[p].setenca[s];
                }
            }
        }
    }
    // printf("Menor setença tam: %d | %s\n",menorsetenca.numCaracteres,  menorsetenca.palavras[1].letras);
    int numPalPos = ComparadorPositividadeSentenca(menorsetenca, PalPosFormatada);
    int numPalNeg = ComparadorPositividadeSentenca(menorsetenca, PalNegFormatada);
    int positividade = numPalPos - numPalNeg;
    // printf("Maior setença tam: %d | %s\n",menorsetenca.numCaracteres,  menorsetenca.palavras[0].letras);
    // printf("%d Palavras positivas, %d Palavras negativas: Polaridade %s\n", numPalNeg, numPalPos, positividade >= 0 ? "positiva" : "negativa");
    TestadordePositividade(numPalPos, numPalNeg);
}

void escolherOpc(paragrafo paragrafos[], char PalPosFormatada[20][20], char PalNegFormatada[20][20]) {
    int qntQuestoes;
    scanf("%d", &qntQuestoes);
    int P2Questoes[qntQuestoes];
    int ordem[qntQuestoes];
    int j = 0;

    for (int nq = 0; nq < qntQuestoes; nq++) {
        int questao = 0;
        scanf("%d", &questao);
        ordem[nq] = questao;
        if (questao == 2) {
            scanf("%d", &P2Questoes[j]);
            j++;
        }
    }

    j = 0; // Reiniciar j para acessar P2Questoes corretamente durante a execução
    for (int nq = 0; nq < qntQuestoes; nq++) {
        if (ordem[nq] == 1) {
            Opc1(paragrafos, PalPosFormatada, PalNegFormatada);
        } else if (ordem[nq] == 2) {
            Opc2(paragrafos[P2Questoes[j]], PalPosFormatada, PalNegFormatada);
            j++; // Avançar para a próxima questão específica
        } else if (ordem[nq] == 3) {
            Opc3(paragrafos, PalPosFormatada, PalNegFormatada);
        } else if (ordem[nq] == 4) {
            Opc4(paragrafos, PalPosFormatada, PalNegFormatada);
        }
    }
}

int main() {
    scanf("%d\n", &Num_paragrafo);
    paragrafo paragrafos[Num_paragrafo];
    char texto[9140] = {'\0'};
    for (int p = 0; p < Num_paragrafo; p++) {
        char texto1[9140];
        fgets(texto1, 9140, stdin);
        strcat(texto, texto1);
    }

    int s = 0, w = 0, l = 0, i = 0, p = 0, sc = 0;
    for (i = 0; i < strlen(texto); i++) {
        char ch = texto[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
        }
        if (ch == '\0') {
            break;
        }
        if (ch == '\n' && texto[i + 1] == '\0') {
            paragrafos[p].setenca[s].palavras[w].letras[l] = '\0';
            paragrafos[p].setenca[s].numPalavras = w + 1;
            paragrafos[p].numSetenca = s + 1;
            break;
        }
        if (ch == '\n') {
            paragrafos[p].setenca[s].palavras[w].letras[l] = '\0';
            paragrafos[p].setenca[s].numPalavras = w + 1;
            paragrafos[p].numSetenca = s + 1;
            p++;
            s = 0;
            w = 0;
            l = 0;
            continue;
        }
        if (ch == '.') {
            paragrafos[p].setenca[s].palavras[w].letras[l] = '\0';
            paragrafos[p].setenca[s].palavras[w].numLetras = l;
            paragrafos[p].setenca[s].numPalavras = w + 1;
            paragrafos[p].setenca[s].numCaracteres = sc;
            s++;
            sc = 0;
            w = 0;
            l = 0;
            continue;
        }
        if (ch == ' ' && texto[i + 1] != ' ') {
            paragrafos[p].setenca[s].palavras[w].letras[l] = '\0';
            paragrafos[p].setenca[s].palavras[w].numLetras = l;
            if (l != 0) {
                w++;
            }
            l = 0;
            continue;
        }
        if (ch == ',' || ch == '?' || ch == '!' || ch == '(' || ch == ')' || ch == '\'' || ch == ';' || ch == '{' || ch == '}') {
            continue;
        }
        paragrafos[p].setenca[s].palavras[w].letras[l] = ch;
        sc++;
        l++;
    }
    // for (int k = 0; k < Num_paragrafo; k++) {
    // printf("Parágrafo %d tem %d sentenças:\n", k + 1, paragrafos[k].numSetenca);
    //     for (int b = 0; b < paragrafos[k].numSetenca; b++) {
    //         printf("  Sentença %d tem %d palavras e %d caracteres:\n", b + 1, paragrafos[k].setenca[b].numPalavras, paragrafos[k].setenca[b].numCaracteres);
    //         for (int w = 0; w < paragrafos[k].setenca[b].numPalavras; w++) {
    //             printf("    Palavra %d: %s Letras: %d\n", w + 1, paragrafos[k].setenca[b].palavras[w].letras,paragrafos[k].setenca[b].palavras[w].numLetras);
    //         }
    //     }
    // }
    char PalPositivas[400];
    char PalNegativas[400];
    char PalPosFormatada[20][20];
    char PalNegFormatada[20][20];

    fgets(PalPositivas, 400, stdin);
    fgets(PalNegativas, 400, stdin);

    separador(PalPositivas, PalPosFormatada);
    separador(PalNegativas, PalNegFormatada);


    // for (int a = 0; a < 20; a++) {
    //     if (PalPosFormatada[a][0] != '\0') {
    //         printf("palPos: '%s'\n", PalPosFormatada[a]);
    //     }
    // }
    // int qntQuestoes;
    // scanf("%d", &qntQuestoes);
    
    escolherOpc(paragrafos, PalPosFormatada, PalNegFormatada);
    // Opc4(paragrafos, PalPosFormatada, PalNegFormatada);
    // int qntQuestoes;
    // int P2Questoes[qntQuestoes];
    // int ordem[qntQuestoes];
    // scanf("%d", &qntQuestoes);
    // int j = 0; 
    // for(int nq = 0; nq < qntQuestoes; nq++){
    //     int questao = 0;
    //     scanf("%d", &questao);
    //     ordem[nq] = questao;
    //     if(questao == 2){
    //         scanf(" %d", &P2Questoes[j]);
    //         j++;
    //     }
    // }
    // for(int nq = 0; nq < qntQuestoes; nq++){
    //     if(ordem[nq] == 1){
    //         Opc1(paragrafos, PalPosFormatada, PalNegFormatada);
    //         continue;
    //     }
    //     if(ordem[nq] == 2){
    //         for(int nq2 = 0; nq2 < j; nq2++){
    //             Opc2(paragrafos[nq2], PalPosFormatada, PalNegFormatada);
    //             printf("Aqui");
    //         }
    //         continue;
    //     }
    //     if(ordem[nq] == 3){
    //        Opc3(paragrafos, PalPosFormatada, PalNegFormatada);
    //     }
    //     if(ordem[nq] == 4){
    //         Opc4(paragrafos, PalPosFormatada, PalNegFormatada);
    //     }
    // }
    //     Opc1(paragrafos, PalPosFormatada, PalNegFormatada);
    //     Opc2(paragrafos[7], PalPosFormatada, PalNegFormatada);
    //     Opc3(paragrafos, PalPosFormatada, PalNegFormatada);
    return 0;
}


