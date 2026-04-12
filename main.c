#include <stdio.h>
#include <stdlib.h>
#include "totem.h"

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int opcao = 0;

    do {
        limparTela();
        printf("=== SISTEMA DE GESTAO ===\n");
        printf("1. Ir para Totem\n");
        printf("2. Ir para Gestao (Em breve)\n");
        printf("3. Ver Ticket (Em breve)\n");
        printf("4. Finalizar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuTotem();
                break;
            case 2:
            	menuGestao();
            	break;
            case 3:{
            	consultarTicket();
				break;
			}
            case 4:
                printf("Saindo...\n");
                break;
            default:
                if(opcao != 4) {
                    printf("Opcao invalida ou nao implementada.\n");
                    getchar(); getchar();
                }
                break;
        }
    } while (opcao != 4);

    return 0;
}
