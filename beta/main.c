#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTOS 100
#define MAX_TAMANHO_NOME_EVENTO 20
#define MAX_TAMANHO_NOME 50
#define MAX_TAMANHO_PASSWORD 20
#define MAX_UTILIZADORES 50
#define MAX_EMAIL 50

typedef struct evento {
  char nomeEv[MAX_TAMANHO_NOME];
  int data;
  char DetalhesEvento[150];
  float preco;
} Evento;

typedef struct pagamento {
  int dataPagamento;
  int metodoPagamento;
  int montante;
} Pagamento;

typedef struct utilizador {
  char nome[MAX_TAMANHO_NOME];
  int nif;
  char email[MAX_EMAIL];
  char password[MAX_TAMANHO_PASSWORD];
  int idade;
  int codAdmin;
} Utilizador;

typedef struct inscrição {
  Utilizador utilizador;
  int numeroDoEvento;
  Pagamento pagamento;
} Inscrição;

// fim das estruturas

void Welcome() {
  printf("██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗\n");
  printf("██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝\n");
  printf("██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗  \n");
  printf("██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝  \n");
  printf("╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗\n");
  printf(" ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝\n");
  printf("                                                              \n");
  printf("████████╗ ██████╗     ███╗   ███╗ █████╗ ██████╗ ███████╗██╗\n");
  printf("╚══██╔══╝██╔═══██╗    ████╗ ████║██╔══██╗██╔══██╗██╔════╝██║\n");
  printf("   ██║   ██║   ██║    ██╔████╔██║███████║██████╔╝███████╗██║\n");
  printf("   ██║   ██║   ██║    ██║╚██╔╝██║██╔══██║██╔══██╗╚════██║╚═╝\n");
  printf("   ██║   ╚██████╔╝    ██║ ╚═╝ ██║██║  ██║██║  ██║███████║██╗\n");
  printf("   ╚═╝    ╚═════╝     ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝\n");
  printf("\n");
  printf("    ╔═══════════════════════════════════════════════╗\n");
  printf("    ║                NFI PROJECT #1                 ║\n");
  printf("    ║  Coordinates: 168.192.02.4 - Your Terminal    ║\n");
  printf("    ║  Event Software                               ║\n");
  printf("    ╚═══════════════════════════════════════════════╝\n");
  printf("\n");
}
// inicialização finalizada
// inicio das funções
int menuStart(int *choice) {
  printf("|1 - Login\n");
  printf("|2 - Registar\n");
  printf("|3 - Sair\n");
  printf("Escolha: ");
  scanf("%d", choice);
  return *choice;
}

int menuLogin(Utilizador utilizadores[], int numUtilizadores,
              Utilizador utilizadorAtual) {
  printf("Insira o nome: ");
  scanf("%s", utilizadorAtual.nome);
  printf("Insira a password: ");
  scanf("%s", utilizadorAtual.password);
  for (int i = 0; i < numUtilizadores; i++) {
    if (strcmp(utilizadores[i].nome, utilizadorAtual.nome) == 0 &&
        strcmp(utilizadores[i].password, utilizadorAtual.password) == 0) {
      return i; // manda a localização do utilizador atual no array
    }
  }

  return -1;
}

int menuSignUp(Utilizador utilizadores[], int *numUtilizadores) {

  Utilizador novoUtilizador;
  printf("Insira nome: ");
  scanf("%s", novoUtilizador.nome);
  printf("Insira uma password: ");
  scanf("%s", novoUtilizador.password);
  printf("Insira o seu email: ");
  scanf("%s", novoUtilizador.email);
  printf("Insira a idade");
  scanf("%d", novoUtilizador.idade);
  printf("Insira o nif:");
  scanf("%d", novoUtilizador.nif);
  novoUtilizador.codAdmin = 0;

  utilizadores[(*numUtilizadores)++] = novoUtilizador;
  printf("Registration successful.\n");
}

int main() {
  int numeroDoEvento;
  Utilizador utilizadores[MAX_EVENTOS];
  Evento eventos[MAX_EVENTOS];
  int numUtilizadores = 0;
  int numEventos = 0;
  Utilizador utilizadorAtual;
  utilizadorAtual.codAdmin = 0;

  Welcome();

  int login = 0;
  int userLogged = 0;
  int MainMenuCounter = 0;
  int *autorizationLayerPass = 0;
  int choice = 0;

  while (MainMenuCounter == 0) {
    if (login == 0) {
      menuStart(&choice);
      switch (choice) {
        case 1:
          menuLogin(utilizadores, numUtilizadores, utilizadorAtual);
          login = 1;
          break;
        case 2:
          menuSignUp(utilizadores, &numUtilizadores);
          break;
        case 3:
          return 0;
          break;
        default:
          printf("Escolha invalida\n");
          break;
      }
    }
  }

  return 0;
}