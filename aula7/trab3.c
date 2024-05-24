#include <stdio.h>

void testar(int a, int b, int imgSource[a][b][3]) {
    //Sim isto funciona 
    for(int i = 0;  i < a; i++){
            for(int j = 0; j < b; j++){
                printf("%d %d %d ", imgSource[i][j][0],imgSource[i][j][1],imgSource[i][j][2]);
            }
        printf("\n");
        }
}

void testar2(int a, int MatrixCores[a][5]) {
    //Sim isto funciona 
    for(int i = 0;  i < a; i++){
                printf("%d %d %d %d %d\n", MatrixCores[i][0],MatrixCores[i][1],
                MatrixCores[i][2],MatrixCores[i][3],MatrixCores[i][4]);
        }
    // printf("\n");
}

void comprimirMatriz(int rows, int column, int imgSource[rows][column][3], int MatrixCores[rows][5],int MPixel[5])
{
    for(int i = 0;  i < rows; i++){
        for(int j = 0; j < column; j++){
            if(imgSource[i][j][0] == 255 && imgSource[i][j][1] == 255){ // 255 255 0
                MatrixCores[i][4]++;
                MPixel[4]++;
            }
            else if (imgSource[i][j][0] == 255 && imgSource[i][j][1] != 255) { // 255 0 0
                MatrixCores[i][1]++;
                MPixel[1]++;
            }
            else if (imgSource[i][j][1] == 255) { // 0 255 0
                MatrixCores[i][2]++;
                MPixel[2]++;
            }
            else if (imgSource[i][j][2] == 255) { // 0 0 255
                MatrixCores[i][3]++;
                MPixel[3]++;
            }else{
                MatrixCores[i][0]++; // 0 0 0
                MPixel[0]++;
            }
        
        }
    }
}

void ModificarMatriz (int rows, int column, int imgSource[rows][column][3]) {
    imgSource[rows][column][0] = 0;
    imgSource[rows][column][1] = 0;
    imgSource[rows][column][2] = 0;
}

int main () {
    int rows,column;
    scanf("P3 %d %d 255", &rows,&column);
    int imgSource[rows][column][3];
    for(int i = 0;  i < rows; i++){
        for(int j = 0; j < column; j++){
            scanf("%d %d %d", &imgSource[i][j][0],&imgSource[i][j][1],&imgSource[i][j][2]);
        }
    }

    // testar( rows,  column, imgSource);
    int MatrixCores[rows][5];
    //Inicializador para 0
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 5; j++) {
            MatrixCores[i][j] = 0;
        }
    }
    //Verificador de Cores 
    int MPixel[5]; //Array para somar a coluna inteira
    comprimirMatriz(rows, column, imgSource, MatrixCores, MPixel);
    // testar( rows,  column, imgSource);
    testar2(rows, MatrixCores);
    //Descomprimir
    // for(int k = 0; k < 5; k++){
    //    MPixel[k] = 0; 
    // }
    // //printf("Babi %d\n",MatrixCores[0][0]);
    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < rows; j++){
    //         // printf("Somando %d + %d\n",MPixel[i],MatrixCores[j][i]);
    //         MPixel[i] += MatrixCores[j][i];
    //     }
    // }
    // printf("\n");
    // for(int i = 0; i < 5; i++){
    //     printf("%d ", MPixel[i]);
    // }
    // printf("\n");
    //AAAAAA
    //Sistema para indentificação de Empates e quais forao 
    int MEmpate[5] = {0};
    int Empate = 0;
    int MCor[2]; // Demonstra a [0] a cor que foi mais repetida e [1] a quantidade de vezes 
    //Verificar o maior numero de vezes que uma cor apareceu
    for(int i = 0; i < 5; i++){
        if(MCor[1] < MPixel[i]){
            MCor[0] = i;
            MCor[1] = MPixel[i];
        }
    }
    //Verificar se esse o maior numero de cores aconteceu novamente
    for(int i = 0; i < 5; i++){
        if(MCor[1] == MPixel[i]){
            MEmpate[i] = 1;
            Empate++;
    }}

    printf("\n%d %d Empate:%d\n MEmpate %d %d %d %d %d\n", MCor[0], MCor[1], Empate, MEmpate[0],MEmpate[1],MEmpate[2],MEmpate[3],MEmpate[4]);
    if(Empate == 1){
        for(int i = 0;  i < rows; i++){
            for(int j = 0; j < column; j++){
                if(imgSource[i][j][0] == imgSource[i][j][1] && imgSource[i][j][0] == 255 && MCor[0] == 4){
                    imgSource[i][j][0] = 0;
                    imgSource[i][j][1] = 0;
                    imgSource[i][j][2] = 0;
                }
                else if (imgSource[i][j][0] == 255 && MCor[0] == 1 && imgSource[i][j][1] != 255) {
                    imgSource[i][j][0] = 0;
                    imgSource[i][j][1] = 0;
                    imgSource[i][j][2] = 0;
                }
                else if (imgSource[i][j][1] == 255 && MCor[0] == 2 && imgSource[i][j][0] != 255 && imgSource[i][j][2] != 255) {
                    imgSource[i][j][0] = 0;
                    imgSource[i][j][1] = 0;
                    imgSource[i][j][2] = 0;
                }
                else if (imgSource[i][j][2] == 255 && MCor[0] == 3 && imgSource[i][j][1] != 255 && imgSource[i][j][0] != 255) {
                    imgSource[i][j][0] = 0;
                    imgSource[i][j][1] = 0;
                    imgSource[i][j][2] = 0;
                }else{
                    imgSource[i][j][0] = 255;
                    imgSource[i][j][1] = 255;
                    imgSource[i][j][2] = 255;
                }
            }
        }
    }else if (Empate < 5){
        for(int i = 0;  i < rows; i++){
            for(int j = 0; j < column; j++){
                if(imgSource[i][j][0] == imgSource[i][j][1] && imgSource[i][j][0] == 255 && MEmpate[4]){
                    // printf("Xablau4");
                    continue;
                }
                else if (imgSource[i][j][0] == 255 && imgSource[i][j][1] != 255 && MEmpate[1]) {
                    //  printf("Xablau1");
                    continue;
                }
                else if (imgSource[i][j][1] == 255 && MEmpate[2] && imgSource[i][j][0] != 255 && imgSource[i][j][2] != 255) {
                    // printf("Xablau2");
                    continue;
                }
                else if (imgSource[i][j][2] == 255 && MEmpate[3] && imgSource[i][j][1] != 255 && imgSource[i][j][0] != 255) {
                    // printf("Xablau3");
                    continue;
                }else if(imgSource[i][j][2] != 255 && imgSource[i][j][1] != 255 && imgSource[i][j][0] != 255 && MEmpate[0]){
                    // printf("Xablau0");
                    continue;
                }
                else{
                    imgSource[i][j][0] = 255;
                    imgSource[i][j][1] = 255;
                    imgSource[i][j][2] = 255;
                    // printf("xablau");
                }
            }
        }
    }else if (Empate == 5){

    }
    testar( rows,  column, imgSource);

}