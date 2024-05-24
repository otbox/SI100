#include <stdio.h>

int verificarVitoria(int jogadores[]){
    int JogadorVencedor = 0;
    for(int verificador = 0; verificador < 4; verificador++){
        if(jogadores[JogadorVencedor] > jogadores[verificador]){
            JogadorVencedor = verificador;
        }
    }
    return JogadorVencedor;
}

int verificacao (int jogadores[]){   
    for(int verificador = 0; verificador < 4; verificador++){
       if(jogadores[verificador] >= 100) {
            char jogadorChar[4] = {'A','B','C','D'};
            printf("Vencedor: jogador %c; Ultimo Lugar: jogador %c\n",jogadorChar[verificarVitoria(jogadores)],jogadorChar[verificador]);
            return 0;
        }    
    }      
    return 1; 
}

int main() {
    int jogadoresCartas[4] = {0,0,0,0};
    int jogadores[4] = {0,0,0,0};
    int jogando = 1;
    //for de verificador  
    while(jogando == 1){
        scanf("%d %d %d %d",&jogadoresCartas[0], &jogadoresCartas[1], &jogadoresCartas[2], &jogadoresCartas[3]);
        for (int y = 0; y < 4; y++){
            int copas = 0; 
            int damaEspadas = 0;
            for(int x = 0; x < jogadoresCartas[y]; x++){
                char naipe = 'a'; 
                int numero = 0;
                scanf("%d-%c", &numero, &naipe);
                // printf("%d-%c ",numero, naipe);
                if(naipe == 'C'){
                    // printf("%c", naipe);
                    jogadores[y]++;
                    copas++;
                }
                if((damaEspadas == 1) && (copas ==13)){
                    jogadores[y] -= 26;
                    damaEspadas = 0;
                    for(int z = 0; z < 4; z++){
                        if(z != y){
                            jogadores[z] += 26;
                        }
                    }
                    //  printf("All win");
                }else if((naipe == 'E')&& (numero == 12)){
                    //  printf("dama de espadas");
                    jogadores[y] += 13;
                    damaEspadas++;
                }
            }
            //  printf("Jogador %d: %d\n", y, jogadores[y]);
        }
        printf("A: %d B: %d C: %d D: %d\n", jogadores[0],jogadores[1],jogadores[2],jogadores[3]);
        //verificação de placar  
        jogando = verificacao(jogadores);
    }    
    return 0;
}
