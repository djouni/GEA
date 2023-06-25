#ifndef PECAS_H
#define PECAS_H


struct Peca {
    int id;            // Identificador único da peça.
    char nome[50];     // Nome da peça.
    char marca[50];    // Marca da peça.
    char montadora[50];// Montadora associada à peça.
    int quantidade;    // Quantidade disponível em estoque da peça.
};

/*
   Função para ler as informações das peças.
*/
void lerPecas(struct Peca *pecas, int *contador);

/*
   Função para exibir as informações das peças.
*/
void exibirPecas();

/*
   Função para criar uma nova peça.
*/
void criarPeca(struct Peca *pecas, int *contador);

/*
   Função para atualizar as informações de uma peça existente.
*/
void atualizarPeca(struct Peca *pecas, int contador);

/*
   Função para excluir uma peça existente.
*/
void excluirPeca(struct Peca *pecas, int *contador);

/*
   Função para atualizar a quantidade de uma peça específica.
*/  
void atualizarQuantidadePecas(struct Peca *pecas, int contador, int id, int quantidade);

/*
   Função que exibe um menu de opções relacionadas às peças e realiza a ação escolhida pelo usuário.
*/
void menuPecas(int opcao, struct Peca pecas[], int *contador);

/*
   Função para exibir as peças que estão abaixo do estoque mínimo.
*/
void exibirPecasAbaixoEstoqueMinimo(struct Peca *pecas, int contador);
#endif