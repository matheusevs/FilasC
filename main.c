#include"estruturas.h"

int main(void){

    int opcao;

    tipoFila *fila;
    tipoLista *lista;

    fila= iniciaFila();
    lista= iniciaLista();

    do{
        printf("\n ========== Escolha uma das opcoes ==========");
		printf("\n | 1) Gerar senha para um cliente novo      |");
        printf("\n | 2) Atender cliente                       |");
		printf("\n | 3) Listar clientes ja atendidos          |");
        printf("\n | 4) Limpar lista de clientes ja atendidos |");
		printf("\n | 5) Sair                                  |");
        printf("\n ============================================\n");
        printf("\n>> ");
		scanf("%d", &opcao);

        switch(opcao){
            case 1:
            sleep(1);
            system("cls");
            inserir(fila);
            system("pause");
            system("cls");
            break;

            case 2:
            sleep(1);
            system("cls");
            atender(fila, lista);
            system("pause");
            system("cls");
            break;

            case 3:
            sleep(1);
            system("cls");
            exibirAtendidos(lista);
            system("pause");
            system("cls");
            break;

            case 4:
            sleep(1);
            system("cls");
            limparLista(lista);
            system("pause");
            system("cls");
            break;

            case 5:
            sleep(1);
            system("cls");
            printf("Programa encerrado!\n");
            system("pause");
            break;

			default:
			printf("Opcao invalida!");
            sleep(1);
            system("cls");
			break;
        }
        system("cls");
    }while(opcao != 5);

    return 0;
}