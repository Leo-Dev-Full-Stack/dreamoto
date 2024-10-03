#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOTOS 1000  // Definindo um tamanho máximo para o vetor de motos

typedef struct {
    char marca[20];
    char tipo[20];
    char modelo[20];
    int qntdParcelas;
    float preco;
} moto;

int main() {
    FILE *arquivoMoto;
    int i = 0;
    float valorParcela;
    moto motos[MAX_MOTOS];  // Criando um vetor de motos

    arquivoMoto = fopen("motosPesquisadas.txt", "a");

    if (arquivoMoto == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 1;  // Retornamos um código de erro
    } else {
        while (i < MAX_MOTOS) {  // Permitir cadastro de múltiplas motos
            printf("Digite a marca da moto: ");
            scanf("%s", motos[i].marca);
            printf("Digite o tipo da moto: ");
            scanf("%s", motos[i].tipo);
            printf("Digite o modelo da moto: ");
            scanf("%s", motos[i].modelo);
            printf("Digite o preco da moto: ");
            scanf("%f", &motos[i].preco);
            printf("Digite a quantidade de parcelas: ");
            scanf("%d", &motos[i].qntdParcelas);

            valorParcela = motos[i].preco / motos[i].qntdParcelas;

            fprintf(arquivoMoto, "\n<-------------------!!------------------->\n\n");
            fprintf(arquivoMoto, "Marca: %s\nTipo: %s\nModelo: %s\nPreco: R$%.2f\nQuantidade de Parcelas: %d\nValor das parcelas: R$%.2f\n",
                    motos[i].marca, motos[i].tipo, motos[i].modelo, motos[i].preco, motos[i].qntdParcelas, valorParcela);

            i++;  // Avançar para a próxima moto
            
            // Pergunta se o usuário deseja cadastrar mais motos
            char continuar;
            printf("Deseja cadastrar outra moto? (s/n): ");
            scanf(" %c", &continuar);
            if (continuar != 's') {
                break;  // Se não quiser continuar, sai do loop
            }
        }
    }

    fclose(arquivoMoto);  // Fecha o arquivo ao final
    return 0;
}