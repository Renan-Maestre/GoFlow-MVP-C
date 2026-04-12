#include <stdio.h>
#include <string.h>
#include <time.h>
#include "totem.h"

#define MAX_TICKETS 100

Ticket fila[MAX_TICKETS];
int contadorTickets = 0;

void gerarTicket(int opcao) {
    if (contadorTickets >= MAX_TICKETS) {
        printf("\nFila cheia!\n");
        return;
    }

    Ticket novo;
    novo.id = contadorTickets + 1;
    novo.status = 0;
    
    if (opcao == 1) {
        strcpy(novo.tipo, "PREFERENCIAL");
    } else {
        strcpy(novo.tipo, "NORMAL");
    }

    // Pegando a hora atual (opcional, mas relevante)
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(novo.hora, "%02d:%02d", tm.tm_hour, tm.tm_min);

    // Salva na "fila"
    fila[contadorTickets] = novo;
    contadorTickets++;

    // Exibe para o usuário
    printf("\n==============================");
    printf("\n   TICKET GERADO COM SUCESSO  ");
    printf("\n   Senha: %d", novo.id);
    printf("\n   Tipo: %s", novo.tipo);
    printf("\n   Horario: %s", novo.hora);
    printf("\n==============================\n");
    printf("\nPressione Enter para continuar...");
    getchar(); getchar(); 
}


void consultarTicket() {
    int senhaBusca;
    int encontrado = 0;
    int i;

    limparTela();
    printf("=== CONSULTAR TICKET ===\n");
    printf("Digite o numero da sua senha: ");
    scanf("%d", &senhaBusca);

    for ( i = 0; i < contadorTickets; i++) {
        if (fila[i].id == senhaBusca) {
            encontrado = 1;
            printf("\n--- Informacoes do Ticket ---");
            printf("\nID: %d", fila[i].id);
            printf("\nTipo: %s", fila[i].tipo);
            printf("\nHorario: %s", fila[i].hora);
            
            // Lógica de Status
            printf("\nStatus: ");
            if (fila[i].status == 0) printf("AGUARDANDO na fila...");
            else if (fila[i].status == 1) printf("EM ATENDIMENTO (Va ao guiche)");
            else printf("FINALIZADO");
            
            printf("\n-----------------------------\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nTicket nao encontrado ou inexistente!\n");
    }

    printf("\nPressione Enter para voltar...");
    getchar(); getchar();
}


// No arquivo totem.c

void listarFila() {
    int i;
    printf("\n--- FILA DE ESPERA (Prioridade: Preferencial) ---\n");
    
    // Primeiro listamos os Preferenciais que estão aguardando (status 0)
    for (i = 0; i < contadorTickets; i++) {
        if (fila[i].status == 0 && strcmp(fila[i].tipo, "PREFERENCIAL") == 0) {
            printf("[%d] %s - %s\n", fila[i].id, fila[i].tipo, fila[i].hora);
        }
    }
    
    // Depois listamos os Normais que estão aguardando (status 0)
    for (i = 0; i < contadorTickets; i++) {
        if (fila[i].status == 0 && strcmp(fila[i].tipo, "NORMAL") == 0) {
            printf("[%d] %s - %s\n", fila[i].id, fila[i].tipo, fila[i].hora);
        }
    }
    printf("-------------------------------------------------\n");
}

void chamarProximo() {
    int i;
    int indiceEncontrado = -1;

    // Busca o primeiro PREFERENCIAL com status 0
    for (i = 0; i < contadorTickets; i++) {
        if (fila[i].status == 0 && strcmp(fila[i].tipo, "PREFERENCIAL") == 0) {
            indiceEncontrado = i;
            break;
        }
    }

    // Se não achou preferencial, busca o primeiro NORMAL com status 0
    if (indiceEncontrado == -1) {
        for (i = 0; i < contadorTickets; i++) {
            if (fila[i].status == 0 && strcmp(fila[i].tipo, "NORMAL") == 0) {
                indiceEncontrado = i;
                break;
            }
        }
    }

    if (indiceEncontrado != -1) {
        fila[indiceEncontrado].status = 1; // Muda para "Em Atendimento"
        printf("\n>>> CHAMANDO SENHA: %d (%s) <<<", fila[indiceEncontrado].id, fila[indiceEncontrado].tipo);
        printf("\nStatus atualizado para: EM ATENDIMENTO\n");
    } else {
        printf("\nNao ha ninguem aguardando na fila.\n");
    }
    
    printf("\nPressione Enter para continuar...");
    getchar(); getchar();
}

void menuGestao() {
    int opcao = 0;
    while (opcao != 3) {
        limparTela();
        printf("=== PAINEL DE GESTAO ===\n");
        listarFila(); // Exibe a lista ordenada antes das opções
        printf("\n1. Chamar Proximo");
        printf("\n2. Atualizar Lista");
        printf("\n3. Voltar");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            chamarProximo();
        }
    }
}

void menuTotem() {
    int opcao = 0;
    while (opcao != 3) {
        limparTela();
        printf("=== ATENDIMENTO TOTEM ===\n");
        printf("1. Senha Preferencial\n");
        printf("2. Senha Normal\n");
        printf("3. Voltar ao Menu Principal\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1 || opcao == 2) {
            gerarTicket(opcao);
        }
    }
}
