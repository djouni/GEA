#include <stdio.h>
#include <stdlib.h>
#include "C:/GEA/include/users.h"
#include "C:/GEA/include/client.h"
#include "C:/GEA/include/pecas.h"
#include "C:/GEA/include/config.h"

int main()
{
    struct Usuario usuarios[100];
    struct Peca pecas[100];
    int admin, opcao = 0, opcaoUsr = 0, contador = 0;

    lerUsuarios(usuarios, &contador);
    lerPecas(pecas, &contador);

    admin = login(usuarios, contador);

    if (admin)
    {
        do
        {
            menuAdminOptions();
            scanf("%d", &opcao);

            if (opcao == -1)
                break;

            if (opcao == 8)
            {
                menuUsersOptions();
                scanf("%d", &opcaoUsr);
                menuUsers(opcaoUsr, usuarios, &contador);
            }
            else if (opcao == 7)
            {
                alterarConfig();
            }
            else
            {
                menuPecas(opcao, pecas, &contador);
            }

        } while (opcao != -1);
    }
    else
    {
        do
        {
            menuUserOptions();
            scanf("%d", &opcao);
            if (opcao == -1)
                break;
            menuPecas(opcao, pecas, &contador);
        } while (opcao != -1);
    }

    return 0;
}
