#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/config.h"
#include "../include/client.h"
#define PATH "C:/GEA/data/config.txt"

void alterarConfig()
{
    clear();
    logo();
    int novoEstoqueMinimo;

    printf("----- CONFIGURACAO DE ESTOQUE -----\n\n");
    printf("Digite o novo estoque minimo do sistema: ");
    scanf("%d", &novoEstoqueMinimo);

    FILE *file;
    file = fopen(PATH, "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(file, "%d\n", novoEstoqueMinimo);

    fclose(file);

    printf("Estoque minimo do sistema atualizado com sucesso.\n");
    wait_action();
}

int obterEstoqueMinimo()
{
    FILE *file;
    file = fopen(PATH, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 0; // Valor padrão a ser retornado em caso de erro
    }

    int estoqueMinimo;

    if (fscanf(file, "%d", &estoqueMinimo) != 1)
    {
        printf("Erro ao ler o valor do arquivo.\n");
        fclose(file);
        return 0; // Valor padrão a ser retornado em caso de erro de leitura
    }

    fclose(file);

    return estoqueMinimo;
}
