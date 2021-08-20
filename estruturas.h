#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct caixa{
	int codigo;
	char nome[100];
    char cpf[13];
	struct caixa *daFrente;
	struct caixa *deTras;
}tipoCaixa;

typedef struct fila{
	int quantidade;
	int contadorDeCodigo;
	tipoCaixa *primeiro;
	tipoCaixa *ultimo;
}tipoFila;

typedef struct lista{
    int quantidade;
    tipoCaixa *primeiro;
    tipoCaixa *ultimo;
}tipoLista;

tipoLista *iniciaLista();
tipoFila * iniciaFila();

void preencheCliente(tipoCaixa *clienteNovo, int codigo);
void exibiUmCliente(tipoCaixa *clienteNovo);
void inserir(tipoFila *fila);
void inserirNaLista(tipoLista *lista, tipoCaixa *clienteTemporario);
void atender(tipoFila *fila, tipoLista *lista);
void exibirAtendidos(tipoLista *lista);
void limparLista(tipoLista *lista);