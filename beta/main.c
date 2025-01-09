#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

#define MAX_EVENTOS 100
#define MAX_TAMANHO_NOME_EVENTO 20
#define MAX_TAMANHO_NOME 50
#define MAX_TAMANHO_PASSWORD 20
#define MAX_UTILIZADORES 50
#define MAX_EMAIL 50
#define MAX_NIF 9
#define MAX_IDADE 3

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
  int nif[MAX_NIF];
  char email[MAX_EMAIL];
  char password[MAX_TAMANHO_PASSWORD];
  int idade[MAX_IDADE];
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
void infoVerification(){}

int menuLogin(Utilizador utilizadores[], int numUtilizadores, Utilizador utilizadorAtual, int *MainMenuCounter) {
  printf("Insira o nome: ");
  scanf("%s", utilizadorAtual.nome);
  printf("Insira a password: ");
  scanf("%s", utilizadorAtual.password);
  for (int userCode = 0; userCode < numUtilizadores; userCode++) {
    if (strcmp(utilizadores[userCode].nome, utilizadorAtual.nome) == 0 &&
        strcmp(utilizadores[userCode].password, utilizadorAtual.password) == 0) {
            printf("Login bem sucedido.\n");
            *MainMenuCounter = 1;
      return userCode; // manda a localização do utilizador atual no array
    }
  }
    printf("Palavra-passe ou nome incorretos.\n");
  return 0;
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

  return 1;
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
      menuStart(&choice);
      switch (choice) {
        case 1:
          menuLogin(utilizadores, numUtilizadores, utilizadorAtual, &MainMenuCounter);
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

  return 0;
}