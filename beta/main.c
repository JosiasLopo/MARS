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
#define MAX_DATA 15
#define MAX_PREÇO 15

typedef struct evento
{
  char nomeEv[MAX_TAMANHO_NOME];
  int data[MAX_DATA];
  char DetalhesEvento[150];
  float preco[MAX_PREÇO];
} Evento;

typedef struct pagamento
{
  int dataPagamento;
  int metodoPagamento;
  int montante;
} Pagamento;

typedef struct utilizador
{
  char nome[MAX_TAMANHO_NOME];
  int nif[MAX_NIF];
  char email[MAX_EMAIL];
  char password[MAX_TAMANHO_PASSWORD];
  int idade[MAX_IDADE];
  int codAdmin;
} Utilizador;

typedef struct inscrição
{
  Utilizador utilizador;
  int numeroDoEvento;
  Pagamento pagamento;
} Inscrição;

int menuLogin(Utilizador utilizadores[], int numUtilizadores,
              Utilizador utilizadorAtual, int *MainMenuCounter)
{
  printf("Insira o nome: ");
  scanf("%s", utilizadorAtual.nome);
  printf("Insira a password: ");
  scanf("%s", utilizadorAtual.password);
  for (int userCode = 0; userCode < numUtilizadores; userCode++)
  {
    if (strcmp(utilizadores[userCode].nome, utilizadorAtual.nome) == 0 &&
        strcmp(utilizadores[userCode].password, utilizadorAtual.password) ==
            0)
    {
      printf("Login bem sucedido.\n");
      *MainMenuCounter = 1;
      return userCode; // manda a localização do utilizador atual no array
    }
  }
  printf("Palavra-passe ou nome incorretos.\n");
  return 0;
}

int menuSignUp(Utilizador utilizadores[], int *numUtilizadores)
{

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

void criarEvento(Evento eventos[], int *numEventos)
{
  if (*numEventos >= MAX_EVENTOS)
  {
    printf("Numero máximo de eventos atingido.\n");
    return;
  }
  else
  {

    Evento novoEvento;
    printf("Insira o nome do evento: ");
    scanf("%s", novoEvento.nomeEv);
    printf("Insira a data do evento: ");
    scanf("%d", novoEvento.data);
    printf("Insira os detalhes do evento: ");
    scanf("%s", novoEvento.DetalhesEvento);
    printf("Insira o preco que pretende:");
    scanf("%f", novoEvento.preco);

    eventos[(*numEventos)++] = novoEvento;
    printf("Evento criado com sucesso, com o numero de evento %d.\n",
           eventos[*numEventos]);
  }
}

void editarEvento(int numerodoEvento, int *numEventos, Evento eventos[])
{
  if (numerodoEvento < 0 || numerodoEvento >= numEventos)
  {
    printf("Esse evento não existe.\n");
    return;
  }

  printf("Insira o novo nome: ");
  scanf("%s", eventos[numerodoEvento].nomeEv);
  printf("Insira a nova data do evento: ");
  scanf("%c", eventos[numerodoEvento].data);
  printf("Insira os novos detalhes do evento: ");
  scanf("%s", eventos[numerodoEvento].DetalhesEvento);
  printf("Insira o novo preco pretendido:");
  scanf("%d", eventos[numerodoEvento].preco);
  printf("Evento editado com sucesso.\n");
}

void deleteEvent(Evento eventos[], int *numEventos, int numeroDoEvento)
{
  if (numeroDoEvento < 0 || numeroDoEvento >= *numEventos)
  {
    printf("Esse evento nao existe.\n");
    return;
  }

  for (int i = numeroDoEvento; i < *numEventos - 1; i++)
  {
    eventos[i] = eventos[i + 1];
  }
  (*numEventos)--;
  printf("Evento eliminado com sucesso.\n");
}

// fim das estruturas

void Welcome()
{
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
int menuStart(int *choice)
{
  printf("|1 - Login\n");
  printf("|2 - Registar\n");
  printf("|3 - Sair\n");
  printf("Escolha: ");
  scanf("%d", choice);
  return *choice;
}

int menuHomeAdmin()
{
  int choice2;
  Utilizador utilizadorAtual;

  // if (utilizadorAtual.codAdmin) {
  printf("1. Criar Evento                           1. Para verificar os eventos\n");
  printf("2. Editar Evento                          2. Para se inscrever no evento\n");
  printf("3. Eliminar Evento                        3. Para se desinscrever no evento\n");
  printf("4. Pagina de estatisticas                 4. Pagina de avaliações\n");
  printf("5. Pagina de avaliações                           \n\n");
  printf("10 Sair ->");
  printf("Insira a sua opcção: ");
  scanf("%d", choice2);

  switch (choice2)
  {
  case 1:
    criarEvento(evento, &numEvents);
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 10:
    break;
  }
}

int menuHomeUser()
{
  int choice;
  printf("1. Para verificar os eventos");
  printf("2. Para se inscrever no evento");
  printf("3. Para se desinscrever no evento");
  printf("4. Pagina de avaliações");
  printf("5. Exit\n");
  printf("Insira a sua opcção: ");
  scanf("%d", choice);

  switch (choice)
  {
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  default:
    break;
  }
}

/*void infoVerification(Utilizador utilizadores[], int numUtilizadores,
Utilizador novoUtilizador) { for (int userCode = 0; userCode <
numUtilizadores; userCode++) { if (strcmp(utilizadores[userCode].nome,
novoUtilizador.nome) == 0) { printf("O nome que colocou já está a ser
usado"); return
    }
    if ((utilizadores[userCode].nif == novoUtilizador.nif)) {
      printf("O nif que colocou já está a ser usado");
    }
    if (strcmp(utilizadores[userCode].email, novoUtilizador.email) == 0) {
      printf("O nome que colocou já está a ser usado");
    }
  }
}*/

int main()
{

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

  while (MainMenuCounter == 0)
  {
    menuStart(&choice);
    switch (choice)
    {
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

  while (MainMenuCounter == 1)
  {
    Utilizador utilizadorAtual;
    if (utilizadorAtual.codAdmin)
    {
      menuHomeAdmin();
    }
    else
    {
      menuHomeUser();
    }
  }
}
