#ifndef TOTEM_H
#define TOTEM_H

typedef struct {
    int id;
    char tipo[20];
    char hora[10]; // Ex: "14:30"
    int status; // 0: Aguardando, 1: Em Atendimento, 2: Finalizado
} Ticket;

// Prot?tipos
void menuTotem();
void gerarTicket(int tipo);
void limparTela();
void consultarTicket();
void menuGestao();


#endif

