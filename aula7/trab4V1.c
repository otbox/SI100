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
} palavra;

typedef struct {
    int numPalavras;
    int numCaracteres;
    palavra palavras[maxPalavras];
} sentenca;

typedef struct {
    int numSentencas;
    sentenca sentencas[maxSetencas];
} paragrafo;

void separador(char pal[400], char palFormatada[20][20]) {
    int a = 0, l = 0;
    for (int m = 0; m < strlen(pal); m++) {
        if (pal[m] == '\n' || pal[m] == '\0') {
            palFormatada[a][l] = '\0';
            break;
        }
        if (pal[m] == ' ' || pal[m] == '\n' || pal[m] == '\0') {
            if (l > 0) {
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
    int positividade1 = 0;
    for (int s = 0; s < texto.numSentencas; s++) {
        for (int p = 0; p < texto.sentencas[s].numPalavras; p++) {
            char *palav = texto.sentencas[s].palavras[p].letras;
            for (int p1 = 0; p1 < 20; p1++) {
                if (strcmp(palav, PalForm[p1]) == 0) {
                    positividade1++;
                    break;
                }
            }
        }
    }
    return positividade1;
}

int ComparadorPositividadeSentenca(sentenca texto, char PalForm[20][20]) {
    int positividade1 = 0;
    for (int p = 0; p < texto.numPalavras; p++) {
        char *palav = texto.palavras[p].letras;
        for (int p1 = 0; p1 < 20; p1++) {
            if (strcmp(palav, PalForm[p1]) == 0) {
                positividade1++;
                break;
            }
        }
    }
    return positividade1;
}

void TestadordePositividade(int posPos, int posNeg) {
    int positividade1 = posPos - posNeg;
    char *textoPositividade = "neutra";
    if (positividade1 > 3) {
        textoPositividade = "positiva";
    } else if (posPos > 0 && posNeg == 0) {
        textoPositividade = "positiva";
    } else if (positividade1 < -3) {
        textoPositividade = "negativa";
    } else if (posNeg > 0 && posPos == 0) {
        textoPositividade = "negativa";
    }

    printf("%d Palavras positivas, %d Palavras negativas: Polaridade %s\n", posPos, posNeg, textoPositividade);
}

void Opc1(paragrafo *paragrafos, int Num_paragrafo, char PalPosFormatada[20][20], char PalNegFormatada[20][20]) {
    int numPalNeg = 0, numPalPos = 0;
    for (int p = 0; p < Num_paragrafo; p++) {
        numPalPos += ComparadorPositividade(paragrafos[p], PalPosFormatada);
        numPalNeg += ComparadorPositividade(paragrafos[p], PalNegFormatada);
    }
    TestadordePositividade(numPalPos, numPalNeg);
}

void Opc2(paragrafo paragrafos, char PalPosFormatada[20][20], char PalNegFormatada[20][20]) {
    int numPalPos = ComparadorPositividade(paragrafos, PalPosFormatada);
    int numPalNeg = ComparadorPositividade(paragrafos, PalNegFormatada);
    TestadordePositividade(numPalPos, numPalNeg);
}

void Opc3(paragrafo *paragrafos, int Num_paragrafo, char PalPosFormatada[20][20], char PalNegFormatada[20][20]) {
    sentenca maiorsentenca = {0, 0, 0};
    for (int p = 0; p < Num_paragrafo; p++) {
        for (int s = 0; s < paragrafos[p].numSentencas; s++) {
            if (maiorsentenca.numCaracteres < paragrafos[p].sentencas[s].numCaracteres) {
                maiorsentenca = paragrafos[p].sentencas[s];
            }
        }
    }
    int numPalPos = ComparadorPositividadeSentenca(maiorsentenca, PalPosFormatada);
    int numPalNeg = ComparadorPositividadeSentenca(maiorsentenca, PalNegFormatada);
    printf("Maior setença tam: %d | %s\n", maiorsentenca.numCaracteres, maiorsentenca.palavras[0].letras);
    TestadordePositividade(numPalPos, numPalNeg);
}

void Opc4(paragrafo *paragrafos, int Num_paragrafo, char PalPosFormatada[20][20], char PalNegFormatada[20][20]) {
    sentenca menorsentenca = {0, 1000000, 0};
    for (int p = 0; p < Num_paragrafo; p++) {
        for (int s = 0; s < paragrafos[p].numSentencas; s++) {
            if (paragrafos[p].sentencas[s].numCaracteres > 0) {
                if (paragrafos[p].sentencas[s].numCaracteres < menorsentenca.numCaracteres) {
                    menorsentenca = paragrafos[p].sentencas[s];
                }
            }
        }
    }
    int numPalPos = ComparadorPositividadeSentenca(menorsentenca, PalPosFormatada);
    int numPalNeg = ComparadorPositividadeSentenca(menorsentenca, PalNegFormatada);
    printf("Menor setença tam: %d | %s\n", menorsentenca.numCaracteres, menorsentenca.palavras[0].letras);
    TestadordePositividade(numPalPos, numPalNeg);
}

void escolherOpc(paragrafo *paragrafos, int Num_paragrafo, char PalPosFormatada[20][20], char PalNegFormatada[20][20]) {
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
            Opc1(paragrafos, Num_paragrafo, PalPosFormatada, PalNegFormatada);
        } else if (ordem[nq] == 2) {
            Opc2(paragrafos[P2Questoes[j]], PalPosFormatada, PalNegFormatada);
            j++; // Avançar para a próxima questão específica
        } else if (ordem[nq] == 3) {
            Opc3(paragrafos, Num_paragrafo, PalPosFormatada, PalNegFormatada);
        } else if (ordem[nq] == 4) {
            Opc4(paragrafos, Num_paragrafo, PalPosFormatada, PalNegFormatada);
        }
    }
}

int main() {
    int Num_paragrafo;
    scanf("%d\n", &Num_paragrafo);
    paragrafo *paragrafos = malloc(Num_paragrafo * sizeof(paragrafo));
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
            paragrafos[p].sentencas[s].palavras[w].letras[l] = '\0';
            paragrafos[p].sentencas[s].numPalavras = w + 1;
            paragrafos[p].numSentencas = s + 1;
            break;
        }
        if (ch == '\n') {
            paragrafos[p].sentencas[s].palavras[w].letras[l] = '\0';
            paragrafos[p].sentencas[s].numPalavras = w + 1;
            paragrafos[p].numSentencas = s + 1;
            p++;
            s = 0;
            w = 0;
            l = 0;
            continue;
        }
        if (ch == '.') {
            paragrafos[p].sentencas[s].palavras[w].letras[l] = '\0';
            paragrafos[p].sentencas[s].palavras[w].numLetras = l;
            paragrafos[p].sentencas[s].numPalavras = w + 1;
            paragrafos[p].sentencas[s].numCaracteres = sc;
            s++;
            sc = 0;
            w = 0;
            l = 0;
            continue;
        }
        if (ch == ' ' && texto[i + 1] != ' ') {
            paragrafos[p].sentencas[s].palavras[w].letras[l] = '\0';
            paragrafos[p].sentencas[s].palavras[w].numLetras = l;
            if (l != 0) {
                w++;
            }
            l = 0;
            continue;
        }
        if (ch == ',' || ch == '?' || ch == '!' || ch == '(' || ch == ')' || ch == '\'' || ch == ';' || ch == '{' || ch == '}') {
            continue;
        }
        paragrafos[p].sentencas[s].palavras[w].letras[l] = ch;
        sc++;
        l++;
    }

    char PalPositivas[400];
    char PalNegativas[400];
    char PalPosFormatada[20][20];
    char PalNegFormatada[20][20];

    fgets(PalPositivas, 400, stdin);
    fgets(PalNegativas, 400, stdin);

    separador(PalPositivas, PalPosFormatada);
    separador(PalNegativas, PalNegFormatada);

    escolherOpc(paragrafos, Num_paragrafo, PalPosFormatada, PalNegFormatada);

    free(paragrafos);
    return 0;
}
