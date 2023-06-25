#ifndef CLIENT_H
#define CLIENT_H
#include "users.h"

/* 
    Função para limpar a tela do console. Usando comandos específicos do sistema operacional.
*/
void clear(); 

/* 
    Função para realizar o login de um usuário, recebe estruturas de Usuário e o contador do número de 
    usuários e retorna um inteiro indicando o índice do usuário logado ou -1 em caso de falha no login.
*/
int login(struct Usuario *usuarios, int contador); 

/*
   Função para CRUD de usuários.
*/
void menuUsersOptions();

/*
   Função que exibe o menu de opções disponíveis para usuários comuns.
*/
void menuUserOptions();

/*
   Função que exibe o menu de opções disponíveis para um administrador.
*/
void menuAdminOptions();

/*
   Função para pausar a execução e aguardar uma ação do usuário.
*/
void wait_action();

/*
   Função para exibir o logo do programa.
*/
void logo();

#endif  
