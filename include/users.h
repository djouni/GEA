#ifndef USERS_H
#define USERS_H

struct Usuario
{
    int id;
    char nome[50];
    char senha[10];
    int cargo;
};


void exibirUsuarios();
void criarUsuario(struct Usuario *usuarios, int *contador);
void atualizarUsuario(struct Usuario *usuarios, int contador);
void excluirUsuario(struct Usuario *usuarios, int *contador);
void menuUsers(int opcao, struct Usuario usuarios[], int *contador);
void lerUsuarios(struct Usuario *usuarios, int *contador);

#endif
