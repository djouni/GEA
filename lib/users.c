/**
 * Esse arquivo é responsável por armazenar toda a lógica referente as funções de usuário, sendo mais especifico ao CRUD de usuário.
 * Os usuários serão identificados pelo atributo cargo, sendo 1 para usuários administradores e 0 para os demais usuários.
 * Abaixo segue uma explicação sobre como cada função presente neste arquivo funciona.
 * 
 * - exibirUsuarios(): Essa função lê o arquivo users.txt que contém as informações dos usuários e exibe na tela o ID, nome e cargo de cada usuário.
 * 
 * - criarUsuario(struct Usuario *usuarios, int *contador): Essa função permite criar um novo usuário. Ela solicita ao usuário que digite o nome, 
 * senha e cargo do usuário. O novo usuário é adicionado ao array de usuários e também é registrado no arquivo users.txt.
 * 
 * atualizarUsuario(struct Usuario *usuarios, int contador): Essa função permite atualizar as informações de um usuário existente. 
 * O usuário é identificado pelo ID. Ela solicita ao usuário que digite o ID do usuário a ser atualizado e, em seguida, 
 * solicita o novo nome, senha e cargo. As informações atualizadas são registradas tanto no array de usuários quanto no arquivo users.txt.
 * 
 * excluirUsuario(struct Usuario *usuarios, int *contador): Essa função permite excluir um usuário existente. 
 * O usuário é identificado pelo ID. Ela solicita ao usuário que digite o ID do usuário a ser excluído. 
 * O usuário correspondente é removido do array de usuários e também é atualizado o arquivo users.txt para refletir as alterações.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/users.h"
#define PATH "C:/GEA/data/users.txt"


void exibirUsuarios()
{
    FILE *file;
    file = fopen(PATH, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Lista de Usuarios:\n");
    int id, cargo;
    char nome[50], senha[10];
    int usuariosEncontrados = 0; 

    while (fscanf(file, "%d %s %s %d", &id, nome, senha, &cargo) != EOF)
    {
        printf("ID: %d\n", id);
        printf("Nome: %s\n", nome);
        printf("Cargo: %s\n", cargo == 1 ? "Administrador" : "Usuario Comum");
        printf("-------------\n");
        usuariosEncontrados = 1; 
    }

    fclose(file);

    if (!usuariosEncontrados)
    {
        printf("Nenhum usuario cadastrado.\n");
    }
}


void criarUsuario(struct Usuario *usuarios, int *contador)
{
    if (*contador >= 100)
    {
        printf("Nao e possivel adicionar mais usuarios.\n");
        return;
    }

    FILE *file;
    file = fopen(PATH, "a+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Ler os usuários existentes do arquivo e encontrar o ID máximo, para que assim nenhum id seja repetido
    int maxID = 0;
    struct Usuario usuario;
    while (fscanf(file, "%d %s %s %d", &usuario.id, usuario.nome, usuario.senha, &usuario.cargo) != EOF)
    {
        if (usuario.id > maxID)
            maxID = usuario.id;
    }

    struct Usuario novoUsuario;

    printf("Digite o nome do usuario: ");
    scanf("%s", novoUsuario.nome);

    printf("Digite a senha do usuario: ");
    getchar();
    scanf("%s", novoUsuario.senha);

    printf("Digite o cargo do usuario (0 - Normal, 1 - Administrador): ");
    getchar();
    scanf("%d", &novoUsuario.cargo);

    novoUsuario.id = maxID + 1;

    usuarios[*contador] = novoUsuario;
    (*contador)++;

    fprintf(file, "%d %s %s %d\n", novoUsuario.id, novoUsuario.nome, novoUsuario.senha, novoUsuario.cargo);

    fclose(file);

    printf("Usuario adicionado com sucesso.\n");
}



void atualizarUsuario(struct Usuario *usuarios, int contador)
{
    int id;

    printf("Digite o ID do usuario a ser atualizado: ");
    scanf("%d", &id);

    int usuarioEncontrado = 0;

    for (int i = 0; i < contador; i++)
    {
        if (usuarios[i].id == id)
        {
            printf("Digite o novo nome do usuario: ");
            scanf("%s", usuarios[i].nome);

            printf("Digite a nova senha do usuario: ");
            getchar();
            scanf("%s", usuarios[i].senha);

            printf("Digite o novo cargo do usuario (0 - Normal, 1 - Administrador): ");
            getchar();
            scanf("%d", &usuarios[i].cargo);

            usuarioEncontrado = 1;
            break;
        }
    }

    if (usuarioEncontrado)
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
            fprintf(file, "%d %s %s %d\n", usuarios[i].id, usuarios[i].nome, usuarios[i].senha, usuarios[i].cargo);
        }

        fclose(file);

        printf("Usuario atualizado com sucesso.\n");
    }
    else
    {
        printf("Usuario com ID %d nao encontrado.\n", id);
    }
}

void excluirUsuario(struct Usuario *usuarios, int *contador)
{
    int id;

    printf("Digite o ID do usuario a ser excluido: ");
    scanf("%d", &id);

    int usuarioEncontrado = 0;

    for (int i = 0; i < *contador; i++)
    {
        if (usuarios[i].id == id)
        {

            for (int j = i; j < *contador - 1; j++)
            {
                usuarios[j] = usuarios[j + 1];
            }
            (*contador)--;
            usuarioEncontrado = 1;
            break;
        }
    }

    if (usuarioEncontrado)
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
            fprintf(file, "%d %s %s %d\n", usuarios[i].id, usuarios[i].nome, usuarios[i].senha, usuarios[i].cargo);
        }

        fclose(file);

        printf("Usuario excluido com sucesso.\n");
    }
    else
    {
        printf("Usuario com ID %d nao encontrado.\n", id);
    }
}