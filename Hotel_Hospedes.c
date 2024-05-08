#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define quantidadeDeHospedesPorQuarto 3

typedef struct {
    char hospede[quantidadeDeHospedesPorQuarto][30];
    int numHospedes;
} hotel;

void inicializarHotel(hotel nomedoHotel[], int tamanho) {// tamanho vai receber o valor de quantidadeDEquartos(30)
    for (int i = 0; i < tamanho; i++) {
        nomedoHotel[i].numHospedes = 0; 
        for(int j = 0; j < quantidadeDeHospedesPorQuarto; j++){
            nomedoHotel[i].hospede[j][0] = '\0';
        }
    }
}

void inserirHospede(hotel nomedoHotel[], int numeroDoQuarto) {//numeroDoQuarto recebe valor do quarto que o hospede foi inserido
    if (nomedoHotel[numeroDoQuarto - 1].numHospedes < quantidadeDeHospedesPorQuarto) {//-1 pois quando o usuario digita um numero, ele pega a posição anterior. pois começa de 0
        printf("Digite o nome do hóspede: ");
        getchar();
        fgets(nomedoHotel[numeroDoQuarto - 1].hospede[nomedoHotel[numeroDoQuarto - 1].numHospedes], sizeof(nomedoHotel[numeroDoQuarto - 1].hospede[0]), stdin);
        nomedoHotel[numeroDoQuarto - 1].hospede[nomedoHotel[numeroDoQuarto - 1].numHospedes][strcspn(nomedoHotel[numeroDoQuarto - 1].hospede[nomedoHotel[numeroDoQuarto - 1].numHospedes], "\n")] = '\0';
        nomedoHotel[numeroDoQuarto - 1].numHospedes++;
        printf("Hóspede cadastrado com sucesso!\n");
    } else {
        printf("Limite de Hóspedes já atingido para este quarto.\n");
    }
}   
int main(){









    return 0;
}