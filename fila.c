#include"estruturas.h"

tipoFila * iniciaFila(){
	tipoFila *fila;
	fila= (tipoFila *)malloc(sizeof(tipoFila));
	fila->quantidade= 0;
	fila->contadorDeCodigo= 1;
	fila->primeiro= NULL;
	fila->ultimo= NULL;
	return fila;
}

tipoLista *iniciaLista(){
    tipoLista *lista;
    lista= (tipoLista *)malloc(sizeof(tipoLista));
    lista->quantidade= 0;
    lista->primeiro= NULL;
    lista->ultimo= NULL;
    return lista;
}

void preencheCliente(tipoCaixa *clienteNovo, int codigo){
	clienteNovo->codigo= codigo;

	printf("Informe o nome do cliente: ");
    fflush(stdin);
    fgets(clienteNovo->nome, 100, stdin);

    printf("Informe o CPF do cliente: ");
    fflush(stdin);
    fgets(clienteNovo->cpf, 13, stdin);
}

void exibiUmCliente(tipoCaixa *clienteNovo){
	printf("\n---------------------------------------\n");
	printf("Codigo  =    %d\n",clienteNovo->codigo);
	printf("Nome    =    %s\n",clienteNovo->nome);
    printf("CPF     =    %s\n",clienteNovo->cpf);
	printf("---------------------------------------\n");
}

void inserir(tipoFila *fila){
    if(fila->quantidade > 10){
        printf("A fila estiver cheia, voltem depois.\n");
        return;
    }
	tipoCaixa *clienteNovo;
	clienteNovo= (tipoCaixa *)malloc(sizeof(tipoCaixa));
	preencheCliente(clienteNovo,fila->contadorDeCodigo);

	if(fila->primeiro == NULL){
		fila->primeiro= clienteNovo;
		fila->ultimo= clienteNovo;
		clienteNovo->deTras= NULL;
		clienteNovo->daFrente= NULL;
	}
	else{
		clienteNovo->daFrente= fila->ultimo;
		fila->ultimo->deTras= clienteNovo;
		clienteNovo->deTras= NULL;
		fila->ultimo= clienteNovo;
	}
	fila->quantidade++;
	fila->contadorDeCodigo++;
}

void inserirNaLista(tipoLista *lista, tipoCaixa *clienteTemporario){
    clienteTemporario->daFrente= NULL;

    if(lista->quantidade == 0){
        lista->primeiro= clienteTemporario;
        clienteTemporario->deTras= NULL;
    }
    else{
        lista->ultimo->daFrente= clienteTemporario;
        clienteTemporario->deTras= lista->ultimo;
    }
    lista->ultimo= clienteTemporario;
    lista->quantidade++;
}

void atender(tipoFila *fila, tipoLista *lista){
    if(fila->primeiro == NULL){
		printf("Fila vazia!\n");
		return;
	}
	if(fila->quantidade == 1){
        fila->primeiro->nome[strlen(fila->primeiro->nome) - 1] = '\0';
        fila->primeiro->cpf[strlen(fila->primeiro->cpf) - 1] = '\0';
        printf("== Atendendo o cliente ==\nNome= %s\nCPF= %s\n",fila->primeiro->nome, fila->primeiro->cpf);
		inserirNaLista(lista, fila->primeiro);
		fila->primeiro= NULL;
		fila->ultimo= NULL;
		fila->quantidade--;
		return;
	}
	if(fila->quantidade > 1){
		tipoCaixa *primeiroDaFila;
		tipoCaixa *segundoDaFila;

		primeiroDaFila= fila->primeiro;
		segundoDaFila= primeiroDaFila->deTras;
		segundoDaFila= fila->primeiro->deTras;
		
        primeiroDaFila->nome[strlen(primeiroDaFila->nome) - 1]= '\0';
        primeiroDaFila->cpf[strlen(primeiroDaFila->cpf) - 1]= '\0';
        printf("== Atendendo o cliente ==\nNome= %s\nCPF= %s\n",primeiroDaFila->nome, primeiroDaFila->cpf);
		inserirNaLista(lista, primeiroDaFila);
		segundoDaFila->daFrente = NULL;
		fila->primeiro= segundoDaFila;
		fila->quantidade--;
	}
}

void exibirAtendidos(tipoLista *lista){
    if(lista->quantidade == 0){
        printf("A lista esta vazia!\n");
        return;
    }
    tipoCaixa *clienteTemporario;
    clienteTemporario= lista->primeiro;
    while(clienteTemporario != NULL){
        exibiUmCliente(clienteTemporario);
        clienteTemporario= clienteTemporario->daFrente;
    }
}

void limparLista(tipoLista *lista){
    if(lista->quantidade == 0){
        printf("A lista esta vazia!\n");
        return;
    }
    printf("A lista foi limpa!\n");
    tipoCaixa *clienteTemporario;
    clienteTemporario= lista->primeiro;
    while(clienteTemporario != NULL){
        free(clienteTemporario);
        clienteTemporario= clienteTemporario->daFrente;
        lista->quantidade--;
    }
    return;
}