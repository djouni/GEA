#include <stdio.h>
#include <stdlib.h>
#include "C:/GEA/include/users.h"
#include "C:/GEA/include/client.h" 
#include "C:/GEA/include/pecas.h"  

// int main()
// {
//     struct Usuario usuarios[100];
//     int admin, contador = 0;
//     lerUsuarios(usuarios, &contador);

//     admin = login(usuarios, contador);

//     if(admin){
//         menuAdminOptions();
//     }
//     else{
//         menuUserOptions();
//     }

//     return 0;
// }

int main() {
    struct Peca pecas[100];
    int contador = 0;
    int op;

    lerPecas(pecas, &contador);
    menuUserOptions();
   
    scanf("%d", &op);
    menuPecas(op, pecas, &contador);
    

    

    // for(i=0; i<3; i++){
    //     criarPeca(pecas, &contador);
    // }

    // exibirPecas();
    // atualizarPeca(pecas, contador);
    // exibirPecas();
    // excluirPeca(pecas, &contador);
    // exibirPecas();

    return 0;
}