#include <stdio.h>
#include <string.h>

#define MAX_EVENTOS 100
#define MAX_TAMANHO_NOME_EVENTO 20
#define MAX_TAMANHO_NOME 50
#define MAX_TAMANHO_PASSWORD 20
#define MAX_UTILIZADORES 50
#define MAX_EMAIL 50
#define MAX_NIF 9
#define MAX_IDADE 3
#define MAX_DATA 15
#define MAX_PREÇO 15

typedef struct evento {
  char nomeEv[MAX_TAMANHO_NOME];
  int data[MAX_DATA];
  char DetalhesEvento[150];
  float preco[MAX_PREÇO];
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

int menuLogin(Utilizador utilizadores[], int numUtilizadores,
              Utilizador utilizadorAtual, int *MainMenuCounter) {
  printf("Insira o nome: ");
  scanf("%s", utilizadorAtual.nome);
  printf("Insira a password: ");
  scanf("%s", utilizadorAtual.password);
  for (int userCode = 0; userCode < numUtilizadores; userCode++) {
    if (strcmp(utilizadores[userCode].nome, utilizadorAtual.nome) == 0 &&
        strcmp(utilizadores[userCode].password, utilizadorAtual.password) ==
            0) {
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
  printf("Insira a idade: ");
  scanf("%d", novoUtilizador.idade);
  printf("Insira o nif: ");
  scanf("%d", novoUtilizador.nif);

  novoUtilizador.codAdmin = 0;

  utilizadores[(*numUtilizadores)++] = novoUtilizador;
  printf("Registration successful.\n");

  return 1;
}

void criarEvento(Evento eventos[], int *numEventos) {
  if (*numEventos >= MAX_EVENTOS) {
    printf("Numero máximo de eventos atingido.\n");
    return;
  } else {

    Evento novoEvento;
    printf("Insira o nome do evento: ");
    scanf("%s", novoEvento.nomeEv);
    printf("Insira a data do evento (ddmmaaaa): ");
    scanf("%d", novoEvento.data);
    printf("Insira os detalhes do evento: ");
    scanf("%s", novoEvento.DetalhesEvento);
    printf("Insira o preco que pretende: ");
    scanf("%f", novoEvento.preco);
    printf("Evento criado com sucesso, com o numero de evento %d.\n", *numEventos  );
    eventos[(*numEventos)++] = novoEvento;
    
  }
}

void editarEvento(int numeroDoEvento, int *numEventos, Evento eventos[]) {
  if (numeroDoEvento < 0 || numeroDoEvento >= *numEventos) {
    printf("Esse evento não existe.\n");
    return;
  }

  printf("Insira o novo nome: ");
  scanf("%s", eventos[numeroDoEvento].nomeEv);
  printf("Insira a nova data do evento: ");
  scanf("%d", eventos[numeroDoEvento].data);
  printf("Insira os novos detalhes do evento: ");
  scanf("%s", eventos[numeroDoEvento].DetalhesEvento);
  printf("Insira o novo preco pretendido: ");
  scanf("%f", &eventos[numeroDoEvento].preco[0]);
  printf("Evento editado com sucesso.\n");
}

void deleteEvent(Evento eventos[], int *numEventos, int numeroDoEvento) {
  if (numeroDoEvento < 0 || numeroDoEvento >= *numEventos) {
    printf("Esse evento nao existe.\n");
    return;
  }

  for (int i = numeroDoEvento; i < *numEventos - 1; i++) {
    eventos[i] = eventos[i + 1];
  }
  (*numEventos)--;
  printf("Evento eliminado com sucesso.\n");
}

void pesquisarEventoPorNome(Evento eventos[], int *numEventos, char *nome) {
  int encontrado = 0;

  for (int i = 0; i < *numEventos; i++) {
    if (strcmp(eventos[i].nomeEv, nome) == 0) {
      printf("Evento encontrado:\n");
      printf("Nome do evento: %s\n", eventos[i].nomeEv);
      printf("Data: %d\n", eventos[i].data);
      printf("Detalhes do evento: %s\n", eventos[i].DetalhesEvento);
      printf("Preço: %.2f\n", eventos[i].preco[0]);
      printf("-------------------------\n");
      encontrado = 1;
    }
  }

  if (!encontrado) {
    printf("Evento com o nome '%s' não encontrado.\n", nome);
  }
}

void listarEventos(Evento eventos[], int *numEventos) {
  if (*numEventos == 0) {
    printf("Nenhum evento registrado.\n");
    return;
  }

  printf("Lista de eventos:\n");
  for (int i = 0; i < *numEventos; i++) {
    printf("Evento %d:\n", i + 1);
    printf("Nome do evento: %s\n", eventos[i].nomeEv);
    printf("Data: %d\n", eventos[i].data);
    printf("Detalhes do evento: %s\n", eventos[i].DetalhesEvento);
    printf("Preço: %.2f\n", eventos[i].preco[0]);
    printf("-------------------------\n");
  }
}

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

int menuStart(int *choice) {
  printf("|1 - Login\n");
  printf("|2 - Registar\n");
  printf("|3 - Sair\n");
  printf("Escolha: ");
  scanf("%d", choice);
  return *choice;
}

int menuHomeAdmin(Evento eventos[], int *numEventos, int *numeroDoEvento,
                  Utilizador utilizadores[], int *numUtilizadores,
                  Utilizador *utilizadorAtual) {
  int choice;

  printf(
      "1. Criar Evento                           6. Para Listar os eventos\n");
  printf("2. Editar Evento                          7. Para verificar os "
         "eventos\n");
  printf("3. Eliminar Evento                        8. Para se inscrever no "
         "evento\n");
  printf("4. Pagina de estatisticas                 9. Para se desinscrever no "
         "evento\n");
  printf(
      "5. Pagina de avaliações                   10. Pagina de avaliações\n\n");
  printf("0 Sair ->");
  printf("Insira a sua opcção: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    criarEvento(eventos, numEventos);
    break;
  case 2:
    printf("Insira o número do evento para editar: ");
    scanf("%d", numeroDoEvento);
    editarEvento(*numeroDoEvento, numEventos, eventos);
    break;
  case 3:
    printf("Insira o número do evento para deletar: ");
    scanf("%d", numeroDoEvento);
    deleteEvent(eventos, numEventos, *numeroDoEvento);
    break;
  case 4:
    return 0;

  case 5:
    return 0;

  case 6:
    listarEventos(eventos, numEventos);
    return 0;

  case 7: {
    int indice;
    printf("Insira o índice do evento que deseja pesquisar (0 a %d): ",
           *numEventos - 1);
    scanf("%d", &indice);

    if (indice >= 0 && indice < *numEventos) {
      pesquisarEventoPorNome(eventos, numEventos,
                             eventos[indice].nomeEv); // Usa nomeEv do struct
    } else {
      printf("Índice inválido.\n");
    }
    return 0;
  }

  case 8:
    return 0;

  case 9:
    return 0;

  case 10:
    return 0;

  case 0:
    printf("Saindo do menu administrador.\n");
    return 0;

  default:
    printf("Opção inválida.\n");
    break;
  }

  return 1;
}

int menuHomeUser(Evento eventos[], int *numEventos, int *numeroDoEvento,
                 Utilizador utilizadores[], int *numUtilizadores,
                 Utilizador *utilizadorAtual) {
  int choice;

  printf("1. Para verificar os eventos\n");
  printf("2. Para se inscrever no evento\n");
  printf("3. Para se desinscrever no evento\n");
  printf("4. Pagina de avaliações\n");
  printf("5. Sair\n");
  printf("Insira a sua opcção: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    printf("Eventos disponíveis:\n");
    for (int i = 0; i < *numEventos; i++) {
      printf("%d - %s\n", i, eventos[i].nomeEv);
    }
    break;
  case 2:
    printf("Insira o número do evento para se inscrever: ");
    scanf("%d", numeroDoEvento);
    printf("Inscrição realizada no evento: %s\n",
           eventos[*numeroDoEvento].nomeEv);
    break;
  case 3:
    printf("Insira o número do evento para se desinscrever: ");
    scanf("%d", numeroDoEvento);
    printf("Desinscrição realizada do evento: %s\n",
           eventos[*numeroDoEvento].nomeEv);
    break;
  case 4:
    printf("Página de avaliações (em desenvolvimento).\n");
    break;
  case 5:
    printf("Saindo do menu usuário.\n");
    return 0;
  default:
    printf("Opção inválida.\n");
    break;
  }
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
  int choice = 0;

  while (MainMenuCounter == 0) {
    menuStart(&choice);
    switch (choice) {
    case 1:
      menuLogin(utilizadores, numUtilizadores, utilizadorAtual,
                &MainMenuCounter);
      break;
    case 2:
      menuSignUp(utilizadores, &numUtilizadores);
      break;
    default:
      printf("Escolha invalida\n");
      break;
    }
  }

  while (MainMenuCounter == 1) {
    if (utilizadorAtual.codAdmin) {
      if (!menuHomeAdmin(eventos, &numEventos, &numeroDoEvento, utilizadores,
                         &numUtilizadores, &utilizadorAtual))
        MainMenuCounter = 0;
    } else {
      if (!menuHomeUser(eventos, &numEventos, &numeroDoEvento, utilizadores,
                        &numUtilizadores, &utilizadorAtual))
        MainMenuCounter = 0;
    }
  }

  return 0;
}
