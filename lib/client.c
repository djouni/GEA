#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/client.h"
#include "../include/users.h"

void clear()
{
    //    printf("\033[2J\033[H");
    system("cls");
}

void wait_action()
{
    printf("Pressione Enter para voltar ao menu...");
    getchar(); 
    getchar();
}

void logo()
{
    printf("   ____   _____      _    \n");
    printf("  / ___| | ____|    / \\   \n");
    printf(" | |  _  |  _|     / _ \\  \n");
    printf(" | |_| | | |___   / ___ \\ \n");
    printf("  \\____| |_____| /_/   \\_\\ \n\n");
}

int login(struct Usuario *usuarios, int contador)
{
    char usuario[50], senha[10];
    logo();
    printf("\t\tBem-vindo ao GEA\n\n");

    int loginValido = 0;
    int isAdmin = 0;
    while (!loginValido)
    {
        printf("Por favor, realize login\n");
        printf("Usuario: ");
        scanf("%s", usuario);

        printf("Senha: ");
        scanf("%s", senha);

        for (int i = 0; i < contador; i++)
        {
            if (strcmp(usuarios[i].nome, usuario) == 0 && strcmp(usuarios[i].senha, senha) == 0)
            {
                isAdmin = (usuarios[i].cargo == 1) ? 1 : 0;
                loginValido = 1;
                break;
            }
        }

        if (!loginValido)
        {
            printf("Usuario ou senha invalidos. Tente novamente!\n");
        }
    }

    if (isAdmin)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void menuUsersOptions()
{
    clear();
    logo();
    printf("Bem vindo ao menu de gerenciamento de usuario\n\n");
    printf("Selecione uma opcao:\n");
    printf("[1] Exibir usuarios\n");
    printf("[2] Criar usuarios\n");
    printf("[3] Atualizar usuarios\n");
    printf("[4] Excluir usuarios\n");
    printf("[0] Retornar ao menu\n");
}

void menuAdminOptions()
{
    clear();
    logo();
    printf("usuario Administrador\n\n");
    printf("Selecione uma opcao:\n");
    printf("[1] Cadastrar nova peca\n");
    printf("[2] Listar estoque\n");
    printf("[3] Atualizar estoque\n");
    printf("[4] Excluir peca do estoque\n");
    printf("[5] Dar baixa\n");
    printf("[6] Pecas abaixo do estoque:\n");
    printf("[7] Configuracao\n");
    printf("[8] Usuarios\n");
    printf("[-1] Sair\n\n");
    printf("Escolha uma opcao: ");
}

void menuUserOptions()
{
    clear();
    logo();
    printf("Selecione uma opcao:\n");
    printf("[1] Cadastrar nova peca\n");
    printf("[2] Listar estoque\n");
    printf("[3] Atualizar estoque\n");
    printf("[4] Excluir peca do estoque\n");
    printf("[5] Dar baixa\n");
    printf("[6] Pecas abaixo do estoque:\n");
    printf("[-1] Sair\n\n");
    printf("Escolha uma opcao: ");
}
