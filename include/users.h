#ifndef USERS_H
#define USERS_H

struct Usuario {
    int id;           // Identificador único do usuário.
    char nome[50];    // Nome do usuário.
    char senha[10];   // Senha do usuário.
    int cargo;        // Cargo do usuário.
};

/*
    Função para exibir uma lista com os usuarios ativos.
*/
void exibirUsuarios();

/*
    Função para criar novos usuários.
*/
void criarUsuario(struct Usuario *usuarios, int *contador);

/*
    Função para editar e atualizar usuários.
*/
void atualizarUsuario(struct Usuario *usuarios, int contador);

/*
    Função para excluir usuários atraves do id.
*/
void excluirUsuario(struct Usuario *usuarios, int *contador);

/*
    
*/
void menuUsers(int opcao, struct Usuario usuarios[], int *contador);

/*
    Função para ler as informações dos usuários.
*/
void lerUsuarios(struct Usuario *usuarios, int *contador);

#endif
