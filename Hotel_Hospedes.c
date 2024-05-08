#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define quantidadeDeHospedesPorQuarto 3

typedef struct {
    char hospede[quantidadeDeHospedesPorQuarto][30];
    int numHospedes;
} hotel;

void inicializarHotel(hotel nomedoHotel[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        nomedoHotel[i].numHospedes = 0; 
        for(int j = 0; j < quantidadeDeHospedesPorQuarto; j++){
            nomedoHotel[i].hospede[j][0] = '\0';
        }
    }
}

int main(){









    return 0;
}