#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAGRAPHS 10
#define MAX_SENTENCES 20
#define MAX_WORDS 70
#define MAX_LETTERS 20
#define MAX_INPUT 9040

typedef struct {
    char letters[MAX_LETTERS];
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int word_count;
} Sentence;

typedef struct {
    Sentence sentences[MAX_SENTENCES];
    int sentence_count;
} Paragraph;

typedef struct {
    Paragraph paragraphs[MAX_PARAGRAPHS];
    int paragraph_count;
} Text;

void segment_text(char *input, Text *text) {
    int p_index = 0, s_index = 0, w_index = 0, l_index = 0;

    text->paragraph_count = 0;
    text->paragraphs[p_index].sentence_count = 0;
    text->paragraphs[p_index].sentences[s_index].word_count = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\n' && input[i+1] == '\n') { // New paragraph
            p_index++;
            s_index = 0;
            w_index = 0;
            l_index = 0;
            text->paragraph_count++;
            text->paragraphs[p_index].sentence_count = 0;
            text->paragraphs[p_index].sentences[s_index].word_count = 0;
            i++;
        } else if (input[i] == '.' || input[i] == '!' || input[i] == '?') { // New sentence
            if (l_index > 0) { // Finish the last word
                text->paragraphs[p_index].sentences[s_index].words[w_index].letters[l_index] = '\0';
                text->paragraphs[p_index].sentences[s_index].word_count++;
                w_index++;
                l_index = 0;
            }
            s_index++;
            w_index = 0;
            text->paragraphs[p_index].sentence_count++;
            text->paragraphs[p_index].sentences[s_index].word_count = 0;
        } else if (isspace(input[i])) { // New word
            if (l_index > 0) { // Finish the last word
                text->paragraphs[p_index].sentences[s_index].words[w_index].letters[l_index] = '\0';
                text->paragraphs[p_index].sentences[s_index].word_count++;
                w_index++;
                l_index = 0;
            }
        } else if (isalpha(input[i])) { // New letter
            text->paragraphs[p_index].sentences[s_index].words[w_index].letters[l_index++] = input[i];
        }
    }
}

void print_text(Text *text) {
    for (int i = 0; i < text->paragraph_count; i++) {
        printf("Paragraph %d:\n", i+1);
        for (int j = 0; j < text->paragraphs[i].sentence_count; j++) {
            printf("  Sentence %d:\n", j+1);
            for (int k = 0; k < text->paragraphs[i].sentences[j].word_count; k++) {
                printf("    Word %d: %s\n", k+1, text->paragraphs[i].sentences[j].words[k].letters);
            }
        }
    }
}

int main() {
    char input[MAX_INPUT];
    Text text;

    printf("Enter the number of paragraphs (max %d): ", MAX_PARAGRAPHS);
    int num_paragraphs;
    scanf("%d", &num_paragraphs);
    getchar(); // to consume the newline character

    printf("Enter the text:\n");
    fgets(input, MAX_INPUT, stdin);

    segment_text(input, &text);
    print_text(&text);

    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define maxLetras 20;
// #define maxPalavras 70;
// #define maxSetencas 20;
// #define maxParagrafos 10;
// typedef struct{
//     int numLetras;
//     char letras[20]; 
// }palavras;

// typedef struct{
//     int numPalavras;
//     palavras palavras[70];
// }setenca;

// typedef struct{
//     int numSetenca;
//     setenca setenca[20];
// }paragrafo; 

// int main() {
//     int Num_paragrafo;
//     scanf("%d\n", &Num_paragrafo);
//     paragrafo paragrafos[Num_paragrafo];
//     char texto[9040] = {'\0'};
//     for(int p = 0; p < Num_paragrafo; p++){
//         char texto1[9040];
//         fgets(texto1,9040, stdin);
//         strcat(texto, texto1);
//     }
//     // printf("%s", texto);

//     int s = 0, w = 0, l = 0, i = 0, p = 0;
//     for(int i = 0; i < 9040; i++){
//         if(texto[i] >= 'A' && texto[i] <= 'Z'){
//             paragrafos[p].setenca[s].palavras[w].letras[l] = texto[i] + 32;
//         }else{
//             paragrafos[p].setenca[s].palavras[w].letras[l] = texto[i];
//         }
//         if (texto[i] == '\0') {
//         break;  
//       }
//       if (texto[i] == '\n') {
//         paragrafos[p].setenca[s].palavras[w].letras[l] = '\0';
//         p++;
//         paragrafos[p].numSetenca = s;
//         s = 0;
//         w = 0;
//         l = 0;
//         continue;
//       } else if (texto[i] == '.') {
//         paragrafos[p].setenca[s].palavras[w].letras[l] = '\0';
//         s++;
//         paragrafos[p].setenca[s].numPalavras = w;
//         paragrafos[p].setenca[s].palavras[w].numLetras = l;
//         w = 0;
//         l = 0;
//         continue;
//       } else if (texto[i] == ' ' && texto[i + 1] != ' ') {
//         paragrafos[p].setenca[s].palavras[w].letras[l] = '\0';
//         paragrafos[p].setenca[s].palavras[w].numLetras = l;
//         if(l != 0) {w++;}
//         l = 0;
//         continue;
//       } else {
//         l++;
//       }
//     }
//     // printf("%s", paragrafos[1].setenca[1].palavras[1].letras);
    
//     for (int k = 0; k < Num_paragrafo; k++) {
//     printf("Parágrafo %d tem %d sentenças:\n", k + 1, paragrafos[k].numSetenca);
//         for (int b = 0; b < paragrafos[k].numSetenca; b++) {
//             printf("  Sentença %d tem %d palavras:\n", b + 1, paragrafos[k].setenca[b].numPalavras);
//             for (int w = 0; w < paragrafos[k].setenca[b].numPalavras; w++) {
//                 printf("    Palavra %d: %s Letras: %d\n", w + 1, paragrafos[k].setenca[b].palavras[w].letras,paragrafos[k].setenca[b].palavras[w].numLetras);
//             }
//         }
//     }
    
    

//     return 0;
// }