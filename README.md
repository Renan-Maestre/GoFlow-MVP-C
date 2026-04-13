<img width=100% src="https://capsule-render.vercel.app/api?type=waving&height=150&color=36BCF7FF&section=header&fontSize=-2" alt="header"/> 

# 🚀 GoFlow - Sistema de Gestão de Filas


O **GoFlow** é uma solução inteligente para gerenciamento de atendimento em centros de saúde, desenvolvida como parte do Projeto Integrador da **Rede de Ensino Doctum**. O sistema automatiza a emissão de senhas, organiza a fila por prioridade legal e permite a consulta em tempo real do status de atendimento.

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C (Padrão ISO C11)
* **Arquitetura:** Modular (Separação de responsabilidades em arquivos `.c` e `.h`)
* **Metodologia:** Ágil (Scrum/Sprint)
* **Ambiente de Desenvolvimento:** Dev-C++ / VS Code

## 📁 Estrutura do Projeto

O projeto é dividido em módulos para garantir um código limpo (Clean Code) e facilitar a manutenção:

* `main.c`: Ponto de entrada do sistema e gerenciamento do menu principal.
* `totem.c`: Lógica de geração de tickets, gerenciamento da fila e consulta de status.
* `totem.h`: Definição da `struct Ticket` e protótipos das funções.

## ⚙️ Funcionalidades

1.  **Totem de Autoatendimento:** Emissão de senhas Normais e Preferenciais com captura automática de horário.
2.  **Painel de Gestão:** Chamada de senhas respeitando a prioridade legal (Preferenciais sempre no topo).
3.  **Consulta de Ticket:** Interface para o cliente verificar se sua senha está "Aguardando" ou "Em Atendimento".
4.  **Sistema de Estados:** Gerenciamento dinâmico de status dos tickets em memória.

## 🚀 Como Executar

Para compilar o projeto no Dev-C++:

1.  Crie um novo projeto do tipo **Console Application (C Project)**.
2.  Adicione os arquivos `main.c`, `totem.c` e `totem.h` ao projeto.
3.  Vá em **Compiler Options** e adicione o parâmetro `-std=c11`.
4.  Pressione `F11` para compilar e rodar.

## 👥 Equipe de Desenvolvimento

Este projeto é fruto da colaboração do grupo:
* **Renan Maestre** (Desenvolvedor Full Stack)
* Rafael, Chrystian, João Vitor Ferreira, Sibelly, Thallyson, João Victor Pierrout, Thales Rezende Assis, Thales de Castro e Weslley.

---
*Este projeto segue os princípios de SOLID e Clean Architecture para garantir escalabilidade e robustez.*

<img width=100% src="https://capsule-render.vercel.app/api?type=waving&height=150&color=36BCF7FF&section=footer&fontSize=-2" alt="footer"/>