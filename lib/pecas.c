#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pecas.h"
#define PATH "C:/GEA/data/pecas.txt"


void lerPecas(struct Peca *pecas, int *contador)
{
    FILE *file;
    file = fopen(PATH, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int id, quantidade;
    char nome[50], marca[50], montadora[50];

    while (fscanf(file, "%d %s %s %s %d", &id, nome, marca, montadora, &quantidade) != EOF)
    {
        struct Peca peca;
        peca.id = id;
        strncpy(peca.nome, nome, sizeof(peca.nome));
        strncpy(peca.marca, marca, sizeof(peca.marca));
        strncpy(peca.montadora, montadora, sizeof(peca.montadora));
        peca.quantidade = quantidade;

        pecas[*contador] = peca;
        (*contador)++;
    }

    fclose(file);
}


void exibirPecas()
{
    FILE *file;
    file = fopen(PATH, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Lista de Pecas:\n");
    int id, quantidade;
    char nome[50], marca[50], montadora[50];
    int pecasEncontradas = 0;

    while (fscanf(file, "%d %s %s %s %d", &id, nome, marca, montadora, &quantidade) != EOF)
    {
        printf("ID: %d\n", id);
        printf("Nome: %s\n", nome);
        printf("Marca: %s\n", marca);
        printf("Montadora: %s\n", montadora);
        printf("Quantidade: %d\n", quantidade);
        printf("-------------\n");
        pecasEncontradas = 1;
    }

    fclose(file);

    if (!pecasEncontradas)
    {
        printf("Nenhuma peca cadastrada.\n");
    }
}


void criarPeca(struct Peca *pecas, int *contador)
{
    if (*contador >= 100)
    {
        printf("Nao e possivel adicionar mais pecas.\n");
        return;
    }

    FILE *file;
    file = fopen(PATH, "a+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int maxID = 0;
    struct Peca peca;
    while (fscanf(file, "%d %s %s %s %d", &peca.id, peca.nome, peca.marca, peca.montadora, &peca.quantidade) != EOF)
    {
        if (peca.id > maxID)
            maxID = peca.id;
    }

    struct Peca novaPeca;

    printf("Digite o nome da peca: ");
    scanf("%s", novaPeca.nome);

    printf("Digite a marca da peca: ");
    getchar();
    scanf("%s", novaPeca.marca);

    printf("Digite a montadora da peca: ");
    getchar();
    scanf("%s", novaPeca.montadora);

    printf("Digite a quantidade da peca: ");
    scanf("%d", &novaPeca.quantidade);

    novaPeca.id = maxID + 1;

    pecas[*contador] = novaPeca;
    (*contador)++;

    fprintf(file, "%d %s %s %s %d\n", novaPeca.id, novaPeca.nome, novaPeca.marca, novaPeca.montadora, novaPeca.quantidade);

    fclose(file);

    printf("Peca adicionada com sucesso.\n");
}

void atualizarPeca(struct Peca *pecas, int contador)
{
    int id;

    printf("Digite o ID da peca a ser atualizada: ");
    scanf("%d", &id);

    int pecaEncontrada = 0;

    for (int i = 0; i < contador; i++)
    {
        if (pecas[i].id == id)
        {
            printf("Digite o novo nome da peca: ");
            scanf("%s", pecas[i].nome);

            printf("Digite a nova marca da peca: ");
            getchar();
            scanf("%s", pecas[i].marca);

            printf("Digite a nova montadora da peca: ");
            getchar();
            scanf("%s", pecas[i].montadora);

            printf("Digite a nova quantidade da peca: ");
            scanf("%d", &pecas[i].quantidade);

            pecaEncontrada = 1;
            break;
        }
    }

    if (pecaEncontrada)
    {
        FILE *file;
        file = fopen(PATH, "w");
        if (file == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        for (int i = 0; i < contador; i++)
        {
            fprintf(file, "%d %s %s %s %d\n", pecas[i].id, pecas[i].nome, pecas[i].marca, pecas[i].montadora, pecas[i].quantidade);
        }

        fclose(file);

        printf("Peca atualizada com sucesso.\n");
    }
    else
    {
        printf("Peca com ID %d nao encontrada.\n", id);
    }
}

void excluirPeca(struct Peca *pecas, int *contador)
{
    int id;

    printf("Digite o ID da peca a ser excluida: ");
    scanf("%d", &id);

    int pecaEncontrada = 0;

    for (int i = 0; i < *contador; i++)
    {
        if (pecas[i].id == id)
        {
            for (int j = i; j < *contador - 1; j++)
            {
                pecas[j] = pecas[j + 1];
            }
            (*contador)--;
            pecaEncontrada = 1;
            break;
        }
    }

    if (pecaEncontrada)
    {
        FILE *file;
        file = fopen(PATH, "w");
        if (file == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        for (int i = 0; i < *contador; i++)
        {
            fprintf(file, "%d %s %s %s %d\n", pecas[i].id, pecas[i].nome, pecas[i].marca, pecas[i].montadora, pecas[i].quantidade);
        }

        fclose(file);

        printf("Peca excluida com sucesso.\n");
    }
    else
    {
        printf("Peca com ID %d nao encontrada.\n", id);
    }
}

void atualizarQuantidadePecas(struct Peca *pecas, int contador, int id, int quantidade) {
    int i;
    int encontrou = 0;

    for (i = 0; i < contador; i++) {
        if (pecas[i].id == id) {
            encontrou = 1;

            // Verifica se a quantidade de baixa é válida
            if (pecas[i].quantidade - quantidade < 0) {
                printf("Quantidade invalida. Nao e possivel dar baixa.\n");
                return;
            }

            pecas[i].quantidade -= quantidade;

            // Atualiza o arquivo com as novas quantidades
            FILE *file = fopen(PATH, "w");
            if (file == NULL) {
                printf("Erro ao abrir o arquivo.\n");
                return;
            }

            for (i = 0; i < contador; i++) {
                fprintf(file, "%d %s %d\n", pecas[i].id, pecas[i].nome, pecas[i].quantidade);
            }

            fclose(file);

            printf("Baixa de pecas realizada com sucesso.\n");
            break;
        }
    }

    if (!encontrou) {
        printf("Peca com ID %d nao encontrada.\n", id);
    }
}

void menuPecas(int opcao, struct Peca pecas[], int *contador)
{
    switch (opcao)
    {
    case 1:
        criarPeca(pecas, contador);
        break;
    case 2:
        exibirPecas(pecas, *contador);
        break;
    case 3:
        atualizarPeca(pecas, *contador);
        break;
    case 4:
        excluirPeca(pecas, contador);
        break;
    case 5:
        {
            int id, quantidade;

            printf("Digite o ID da peca: ");
            scanf("%d", &id);

            printf("Digite a quantidade de baixa: ");
            scanf("%d", &quantidade);

            atualizarQuantidadePecas(pecas, *contador, id, quantidade);
        }
        break;
    case 0:
        printf("Saindo do menu de pecas...\n");
        break;
    default:
        printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        break;
    }
}


