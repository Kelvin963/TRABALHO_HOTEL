#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define quantidadeDEQuartos 30
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
        fgets(nomedoHotel[numeroDoQuarto - 1].hospede[nomedoHotel[numeroDoQuarto - 1].numHospedes], sizeof(nomedoHotel[numeroDoQuarto - 1].hospede[0]), stdin);//le o nome
        nomedoHotel[numeroDoQuarto - 1].hospede[nomedoHotel[numeroDoQuarto - 1].numHospedes][strcspn(nomedoHotel[numeroDoQuarto - 1].hospede[nomedoHotel[numeroDoQuarto - 1].numHospedes], "\n")] = '\0';//retira o caractere \n
        nomedoHotel[numeroDoQuarto - 1].numHospedes++;//adiciona um no numero de hospede para manter a consistencia do codigo
        printf("Hóspede cadastrado com sucesso!\n");
    } else {
        printf("Limite de Hóspedes já atingido para este quarto.\n");
    }
}   

void listarHospedes(hotel nomedoHotel[]) {
    printf("Lista de hospedes por quarto:\n");
    for (int i = 0; i < quantidadeDEQuartos; i++) {//percorrer todos os quartos
        if (nomedoHotel[i].numHospedes > 0) {            
            printf("Quarto %d:\n", i + 1);
//Ordenar os nomes dos hóspedes diretamente no vetor do quarto usando bubble sort
            for(int j = 0; j < nomedoHotel[i].numHospedes - 1; j++){
                for(int k = 0; k < nomedoHotel[i].numHospedes - j - 1; k++){
                    if (strcmp (nomedoHotel[i].hospede[k], nomedoHotel[i].hospede[k+1]) > 0){
                        char temporario[30];
                        strcpy(temporario, nomedoHotel[i].hospede[k]);
                        strcpy(nomedoHotel[i].hospede[k], nomedoHotel[i].hospede[k+1]);
                        strcpy(nomedoHotel[i].hospede[k+1], temporario);
                    }
                }
            }

            for(int j = 0; j < nomedoHotel[i].numHospedes; j++){
                printf("- %s \n",nomedoHotel[i].hospede[j]);
            }
        }
    }
    system("pause");
    system("cls");
}
void buscarHospede(hotel nomedoHotel[]) {
    char nome[50];
    printf("Digite o nome do hóspede a ser buscado: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < quantidadeDEQuartos; i++) {
        for(int j = 0; j < quantidadeDeHospedesPorQuarto; j++){
            if (strcmp(nomedoHotel[i].hospede[j], nome) == 0) {
                printf("%s está no quarto %d.\n", nome, i + 1);
                return;
            }
        }
    }

    printf("%s não encontrado.\n", nome);
    system("pause");
    system("cls");
}
int main(){









    return 0;
}