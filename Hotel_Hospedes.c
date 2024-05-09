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

void inserirHospede(hotel nomedoHotel[], int numeroDoQuarto) {//numeroDoQuarto tem o valor de "quantidadeDEQuartos"
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
//letras tem um valor como se fossem números na lógica de programação em c, de acordo com a tabela ASCII.
            for(int j = 0; j < nomedoHotel[i].numHospedes - 1; j++){
                for(int k = 0; k < nomedoHotel[i].numHospedes - j - 1; k++){
                    if (strcmp (nomedoHotel[i].hospede[k], nomedoHotel[i].hospede[k+1]) > 0){
                        char temporario[30];
                        strcpy(temporario, nomedoHotel[i].hospede[k]);//hospede[K] para temporario
                        strcpy(nomedoHotel[i].hospede[k], nomedoHotel[i].hospede[k+1]);// hospede[K+1] para hospede [K]
                        strcpy(nomedoHotel[i].hospede[k+1], temporario);//temporario para hospede[K+1]
                    }
                }
            }

            for(int j = 0; j < nomedoHotel[i].numHospedes; j++){
                printf("- %s \n",nomedoHotel[i].hospede[j]); //imprimir a lista ordenada
            }
        }
    }
    system("pause");
    system("cls");
}

void buscarHospede(hotel nomedoHotel[]) {
    char nome[50];
    printf("Digite o nome do hóspede a ser buscado: ");
    getchar();//limpa buffer de entrada
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';//atribui valor nulo ao caractere de nova linha

    for (int i = 0; i < quantidadeDEQuartos; i++) {//percorre os quartos
        for(int j = 0; j < quantidadeDeHospedesPorQuarto; j++){//percorre os hospedes por quarto
            if (strcmp(nomedoHotel[i].hospede[j], nome) == 0) {//compara se o hospede buscado está em algum quarto
                printf("%s está no quarto %d.\n", nome, i + 1);
                return;
            }
        }
    }

    printf("%s não encontrado.\n", nome);//se o if nao rodar, pula pro printf
    system("pause");
    system("cls");
}

void editarHospede(hotel nomedoHotel[]) { 
    char nome[50];
    printf("Digite o número do quarto a ser editado: ");
    int numeroDoQuarto;
    scanf("%d", &numeroDoQuarto);//ler a entrada para saber o numero do quarto a ser editado

    if (numeroDoQuarto >= 1 && numeroDoQuarto <= quantidadeDEQuartos) { //entre 1 e 30
        printf("Digite o nome do hospede a ser editado:");
            getchar();
            fgets(nome, sizeof(nome), stdin);//ler o nome digitado para comparação
            nome[strcspn(nome, "\n")] = '\0';//anular o "\n"

            int encontrado = 0;
            for(int i = 0; i < quantidadeDeHospedesPorQuarto; i++){
                if(strcmp(nomedoHotel[numeroDoQuarto - 1].hospede[i], nome) == 0) {//comparar o nome de cada hospede com o "nome" inserido
                    encontrado = 1;
                    printf("Digite o novo nome do hospede: ");
                    fgets(nomedoHotel[numeroDoQuarto - 1].hospede[i], sizeof(nomedoHotel[numeroDoQuarto - 1].hospede[i]), stdin);
                    nomedoHotel[numeroDoQuarto - 1].hospede[i][strcspn(nomedoHotel[numeroDoQuarto - 1].hospede[i], "\n")] = '\0';
                    printf("Hospede editado com sucesso! \n");
                    break;
                //se achar o hospede, o programa vai pedir um novo nome para o mesmo local e encerrará o programa para evitar loop infinito
                }
            }
            if(encontrado == 0){
                printf("Hospede nao encontrado no quarto. \n");

            }else{  
                printf("Numero de quarto invalido");

            }
    }
            
    system("pause");
    system("cls");
}

void removerHospede(hotel nomedoHotel[]) {
    char nome[50];
    printf("Digite o nome do hospede a ser removido: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int quartoEncontrado = -1;

    for(int i = 0; i < quantidadeDEQuartos; i++){               //lê os quartos
        for(int j = 0; j < quantidadeDeHospedesPorQuarto; j++){ // lê os hospedes de cada quarto lido
            if(strcmp(nomedoHotel[i].hospede[j], nome) == 0){   //comparar
                quartoEncontrado = i;
                nomedoHotel[i].hospede[j][0] = '\0';            //remove hospede
                nomedoHotel[i].numHospedes--;                   //decrementa numero de hospedes

                for(int k = j; k < quantidadeDeHospedesPorQuarto - 1; k++){//reorganiza os hospedes do quarto
                    strcpy(nomedoHotel[i].hospede[k], nomedoHotel[i].hospede[k + 1]);//o codigo vai organizar a partir do que removeu e ocorrerá o break, assim o codigo nao ficará em loop
                }
                nomedoHotel[i].hospede[quantidadeDeHospedesPorQuarto - 1][0] = '\0';//Essa linha remove o primeiro caractere da string do último hóspede armazenado em um determinado quarto.
                break;  
            }
        }
        if(quartoEncontrado != -1){
            break;
        }
    }
    
    if(quartoEncontrado == -1){
        printf("%s Nao encontrado em nenhum quarto. \n", nome);
    }else{
        printf("Hospede removido com sucesso! \n");
    }

    system("pause");
    system("cls");
}

void quartosDisponiveis(hotel nomedoHotel[]) {
    printf("Quartos Disponíveis: \n");
    for (int i = 0; i < quantidadeDEQuartos; i++) {//30 quartos
        
            if(nomedoHotel[i].numHospedes == 0) { //verifica se tem um valor dentro de cada quarto
                printf("QUARTO 0%d: ( )\n", i + 1);
            }else{
                printf("QUARTO 0%d: (x)\n", i + 1);//i + 1 pois a posição do quarto começa de 0 e vai até 29
            }
                    
    }
    printf("\n");
    system("pause");
    system("cls");
}

void gerartxt(hotel nomedoHotel[]) {
    FILE *ponteiroarq;
    ponteiroarq = fopen("C:\\Users\\Public\\ListaDeHospede", "w"); // W cria um novo arquivo no destino

    for (int i = 0; i < 30; i++) {
        for(int j = 0; j < quantidadeDeHospedesPorQuarto; j++){ //percorrer hospedes
            if (nomedoHotel[i].hospede[j][0] != '\0') {
                fprintf(ponteiroarq,"Quarto %d: %s\n", i + 1, nomedoHotel[i].hospede[j]);//escreve no arquivo
            }
        }
    }
    fclose(ponteiroarq);
    printf("Arquivo Gerado com sucessos\n");
    system("pause");
  
}
int main(){










    return 0;
}