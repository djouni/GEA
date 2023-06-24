#ifndef PECAS_H
#define PECAS_H

struct Peca {
    int id;
    char nome[50];
    char marca[50];
    char montadora[50];
    int quantidade;
};

void lerPecas(struct Peca *pecas, int *contador);
void exibirPecas();
void criarPeca(struct Peca *pecas, int *contador);
void atualizarPeca(struct Peca *pecas, int contador);
void excluirPeca(struct Peca *pecas, int *contador);
void atualizarQuantidadePecas(struct Peca *pecas, int contador, int id, int quantidade);
void menuPecas(int opcao, struct Peca pecas[], int *contador);



#endif