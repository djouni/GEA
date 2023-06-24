#include <stdio.h>
#include <stdlib.h>
#include "../include/users.h" 
#include "../lib/users.c"

int main() {
    struct Usuario usuarios[100];
    int contador = 0, i;

    for(i=0;i<4;i++){
        criarUsuario(usuarios, &contador);
    }
    
    exibirUsuarios();
    atualizarUsuario(usuarios, contador);
    exibirUsuarios();
    excluirUsuario(usuarios, &contador);
    exibirUsuarios();

    return 0;
}
