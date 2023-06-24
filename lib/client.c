#include <stdio.h>
#include <string.h>
#include "../include/client.h"
#include "../include/users.h"

int login(struct Usuario *usuarios, int contador)
{
    char usuario[50], senha[10];
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
            printf("Usuário ou senha inválidos. Tente novamente!\n");
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

void menuAdminOptions()
{
    printf("Selecione uma opcao:\n");
    printf("[1] Cadastrar nova peca\n");
    printf("[2] Listar estoque\n");
    printf("[3] Exibir pecas abaixo do estoque\n");
    printf("[4] Baixa de peca\n");
    printf("[5] Pecas por montadora\n");
    printf("[6] Configuracao\n");
    printf("[7] Usuarios\n");
    printf("[0] Sair\n");
}

void menuUserOptions()
{
    printf("Selecione uma opcao:\n");
    printf("[1] Cadastrar nova peca\n");
    printf("[2] Listar estoque\n");
    printf("[3] Exibir pecas abaixo do estoque\n");
    printf("[4] Excluir pecas\n");
    printf("[5] Baixa de peca\n");
    printf("[5] Pecas por montadora\n");
    printf("[0] Sair\n");
}


