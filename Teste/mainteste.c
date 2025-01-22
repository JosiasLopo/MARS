#include <stdio.h>
// #include <stdlib.h>
#include <string.h>
// #include <qrencode.h> // Biblioteca libqrencode

#define MAX_EVENTOS 100
#define MAX_TAMANHO_NOME 50
#define MAX_UTILIZADORES 50
#define MAX_TAMANHO_PASSWORD 20
#define MAX_EMAIL 50
#define MAX_DATA 15
#define MAX_LOCAL 30
#define MAX_ESPERA 20

typedef struct evento {
  char nomeEv[MAX_TAMANHO_NOME];
  char data[MAX_DATA];
  char DetalhesEvento[150];
  float preco;
  char local[MAX_LOCAL];
  char oradores[MAX_TAMANHO_NOME];
  int totalinscritos;
  int maxinscritos;
} Evento;

typedef struct pagamento {
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

typedef struct inscricao {
  Utilizador utilizador;
  int numEvento;
  Pagamento pagamento;
} Inscricao;

typedef struct filaEspera {
  Inscricao fila[MAX_ESPERA];
  int inicio;
  int fim;
  int tamanho;
} FilaEspera;

int menuLogin(Utilizador utilizadores[], int numUtilizadores,
              Utilizador *utilizadorAtual, int *MainMenuCounter) {
  printf("Insira o nome: ");
  scanf("%s", utilizadorAtual->nome);
  printf("Insira a password: ");
  scanf("%s", utilizadorAtual->password);
  for (int userCode = 0; userCode < numUtilizadores; userCode++) {
    if (strcmp(utilizadores[userCode].nome, utilizadorAtual->nome) == 0 &&
        strcmp(utilizadores[userCode].password, utilizadorAtual->password) ==
            0) {
      printf("Login bem-sucedido.\n");
      *MainMenuCounter = 1;
      *utilizadorAtual = utilizadores[userCode]; // Atualiza utilizadorAtual
      return userCode; // Retorna o índice do usuário
    }
  }
  printf("Palavra-passe ou nome incorretos.\n");
  return -1;
}

int menuSignUp(Utilizador utilizadores[], int *numUtilizadores,
               Utilizador *utilizadorAtual) {
  Utilizador novoUtilizador;
  printf("Insira nome: ");
  scanf(" %[^\n]", novoUtilizador.nome);
  printf("Insira uma password: ");
  scanf("%s", novoUtilizador.password);
  printf("Insira o seu email: ");
  scanf("%s", novoUtilizador.email);
  printf("Insira a idade: ");
  scanf("%d", &novoUtilizador.idade);
  printf("Insira o nif: ");
  scanf("%d", &novoUtilizador.nif);

  novoUtilizador.codAdmin = 0;

  utilizadores[*numUtilizadores] = novoUtilizador;
  *utilizadorAtual = novoUtilizador; // Atualiza utilizadorAtual
  (*numUtilizadores)++;

  printf("Registro bem-sucedido.\n");
  return 1;
}
void adminPredefinido(Utilizador utilizadores[], int *numUtilizadores) {
  Utilizador admin;
  strcpy(admin.nome, "admin");        // Nome do administrador
  strcpy(admin.password, "admin123"); // Senha do administrador
  strcpy(admin.email, "admin@admin.com");
  admin.idade = 30;
  admin.nif = 123456789;
  admin.codAdmin = 1; // Definir como administrador

  utilizadores[*numUtilizadores] = admin;
  (*numUtilizadores)++;
}
/*void criarQRcode(Evento evento, Utilizador inscrito) {
    // Criando uma string com as informações do evento e do inscrito
    char info[300];
    snprintf(info, sizeof(info),
             "Evento: %s\nData: %s\nLocal: %s\nPreço: %.2f\nInscrito: %s\nEmail:
%s", evento.nomeEv, evento.data, evento.local, evento.preco, inscrito.nome,
inscrito.email);

    printf("Gerando QR Code com os seguintes dados:\n%s\n", info);

    // Gerar QR Code com a libqrencode
    QRcode qrcode = QRcode_encodeString(info, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Erro ao gerar o QR Code\n");
        return;
    }

    // Imprimindo o QR Code no console
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            printf(qrcode->data[y qrcode->width + x] & 1 ? "██" : "  ");
        }
        printf("\n");
    }

    // Liberar a memória do QR Code
    QRcode_free(qrcode);
}
*/
void criarEvento(Evento eventos[], int *numEventos) {
  if (*numEventos >= MAX_EVENTOS) {
    printf("Número máximo de eventos atingido.\n");
    return;
  }

  //Q1 - LINHA 155

  Evento novoEvento;
  printf("Insira o nome do evento: ");
  scanf(" %[^\n]", novoEvento.nomeEv);

  printf("Insira a data do evento (dd/mm/yyyy)/(hora:min) : ");
  scanf("%s", novoEvento.data);

  printf("Insira os detalhes do evento: ");
  scanf(" %[^\n]",
        novoEvento.DetalhesEvento); // Permite ler strings com espaços

  printf("Insira o local (sala) do evento: ");
  scanf(" %[^\n]", novoEvento.local);

  printf("Insira o nome do orador: ");
  scanf(" %[^\n]", novoEvento.oradores);

  // fgets(novoEvento.oradores, MAX_TAMANHO_NOME, std----);
  // novoEvento.oradores[strc----(novoEvento.oradores, "\n")] = '\0';


  //Q1 - LINHA 172
  do {
    printf("Insira o preço do evento: ");
    scanf("%f", &novoEvento.preco);
    if (novoEvento.preco < 0) {
      printf("Preço inválido! Tente novamente.\n");
    }
  } while (novoEvento.preco < 0);

  printf("Insira o número máximo de inscritos: ");
  scanf("%d", &novoEvento.maxinscritos);
  if (novoEvento.maxinscritos <= 0) {
    printf("Número máximo de inscritos inválido! Operação cancelada.\n");
    return;
  }

  novoEvento.totalinscritos = 0;
  eventos[*numEventos] = novoEvento;
  (*numEventos)++;

  printf("Evento criado com sucesso!\n");
  printf(
      "Nome: %s\nData: %s\nLocal: %s\nPreço: %.2f\nMáximo de Inscritos: %d\n",
      novoEvento.nomeEv, novoEvento.data, novoEvento.local, novoEvento.preco,
      novoEvento.maxinscritos);
}
void editarEvento(int numerodoEvento, int *numEventos, Evento eventos[]) {
  printf("Insira o número do evento para editar: ");
  scanf("%d", &numerodoEvento);
  if (numerodoEvento < 0 || numerodoEvento >= *numEventos) {
    printf("Esse evento não existe.\n");
    return;
  }

  printf("Insira o novo nome: ");
  scanf(" %[^\n]", eventos[numerodoEvento].nomeEv);
  printf("Insira a nova data do evento, (dd/mm/yyyy)/(hora:min): ");
  scanf("%s", eventos[numerodoEvento].data);
  printf("Insira os novos detalhes do evento: ");
  scanf(" %[^\n]", eventos[numerodoEvento].DetalhesEvento);
  printf("Insira o novo local (sala) pretendido:");
  scanf(" %[^\n]", eventos[numerodoEvento].local);
  printf("Insira o novo orador: ");
  scanf(" %[^\n]", eventos[numerodoEvento].oradores);
  printf("Insira o novo preco pretendido:");
  scanf("%f", &eventos[numerodoEvento].preco);
  if (eventos[numerodoEvento].preco < 0) {
    printf("Preço inválido! Operação cancelada.\n");
    return;
  }

  int novoLimite; // aqui a função verifica a possivilidade de ao mudar a
                  // quantidade de pessoas que podem se increver, se n se altera
                  // para menos do que as que ja estao inscritas.
  printf("Insira o novo limite máximo de inscritos (o atual é de: %d): ",
         eventos[numerodoEvento].maxinscritos);
  scanf("%d", &novoLimite);
  if (novoLimite < eventos[numerodoEvento].totalinscritos) {
    printf("O novo limite não pode ser menor que o número atual de inscritos "
           "(%d).\n",
           eventos[numerodoEvento].totalinscritos);
  } else {
    eventos[numerodoEvento].maxinscritos = novoLimite;
    printf("Limite de inscritos atualizado para %d.\n", novoLimite);
  }
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

void pesquisarEventoPorIndice(Evento eventos[], int *numEventos, char *nome) {

  for (int i = 0; i < *numEventos; i++) {
    if (strcmp(eventos[i].nomeEv, nome) == 0) {
      printf("Evento %d:\n", i);
      printf("  Nome: %s\n", eventos[i].nomeEv);
      printf("  Data e Hora: %s\n", eventos[i].data);
      printf("  Local (sala): %s\n", eventos[i].local);
      printf("  Orador: %s\n", eventos[i].oradores);
      printf("  Preço: %.2f euros.\n", eventos[i].preco);
      printf("  Detalhes: %s\n", eventos[i].DetalhesEvento);
      printf("  Inscritos: %d / %d\n", eventos[i].totalinscritos,
             eventos[i].maxinscritos);
      printf("-------------------------\n");
    } else {
      printf("Evento com o nome '%s' não encontrado.\n", nome);
    }
  }
}

void listarEventos(Evento eventos[], int *numEventos) {
  if (*numEventos == 0) {
    printf("Nenhum evento disponível.\n");
    return;
  }

  printf("Lista de Eventos:\n");
  printf("=========================================================\n");
  for (int i = 0; i < *numEventos; i++) {
    printf("Evento %d:\n", i);
    printf("  Nome: %s\n", eventos[i].nomeEv);
    printf("  Data e Hora, (dd/mm/yyyy)/(hora:min): %s\n", eventos[i].data);
    printf("  Local (sala): %s\n", eventos[i].local);
    printf("  Preço: %.2f euros.\n", eventos[i].preco);
    printf("  Detalhes: %s\n", eventos[i].DetalhesEvento);
    printf("  Orador: %s\n", eventos[i].oradores);
    printf("  Inscritos: %d / %d\n", eventos[i].totalinscritos,
           eventos[i].maxinscritos);
    printf("---------------------------------------------------------\n");
  }
}

void adicionarFilaEspera(FilaEspera *fila, Inscricao inscrito) {
  if (fila->tamanho < MAX_ESPERA) {
    fila->fila[fila->fim] = inscrito;
    fila->fim = (fila->fim + 1) % MAX_ESPERA;
    fila->tamanho++;
    printf("Inscrito ' %s' adicionado à fila de espera.\n",
           inscrito.utilizador.nome);
  } else {
    printf("Fila de espera cheia! Não é possível adicionar '%s'.\n",
           inscrito.utilizador.nome);
  }
}

//Q2 LINHA 334

void inscreverNoEvento(Evento eventos[], int numEventos,
                       Utilizador utilizadorAtual, Inscricao inscricoes[],
                       int *numInscricoes, FilaEspera *fila,
                       Inscricao inscrito) {
  if (numEventos == 0) {
    printf("Não há eventos disponíveis para inscrição.\n");
    return;
  }

  listarEventos(eventos, &numEventos);

  int numeroDoEvento;
  printf("Insira o número do evento para se inscrever: ");
  scanf("%d", &numeroDoEvento);

  if (numeroDoEvento < 0 || numeroDoEvento >= numEventos) {
    printf("Número do evento inválido.\n");
    return;
  }

  //Q2 - LINHA 334
  Evento *evento = &eventos[numeroDoEvento];
  if (evento->totalinscritos >= evento->maxinscritos) {
  printf("O evento já atingiu o número máximo de inscritos.\n");
        
  FilaEspera filaEspera;
  // Adicionar à fila de espera
  adicionarFilaEspera(&filaEspera, inscrito);
  printf("Você foi adicionado à fila de espera.\n");

  return;
  }

  {
    Inscricao novaInscricao;
    novaInscricao.utilizador = utilizadorAtual;
    novaInscricao.numEvento = numeroDoEvento;

    printf("Insira o método de pagamento (1 - Cartão, 2 - Transferência): ");
    scanf("%d", &novaInscricao.pagamento.metodoPagamento);
    if (novaInscricao.pagamento.metodoPagamento != 1 &&
        novaInscricao.pagamento.metodoPagamento != 2) {
      printf("Método de pagamento inválido.\n");
      return;
    }

    novaInscricao.pagamento.montante = eventos[numeroDoEvento].preco;
    inscricoes[(*numInscricoes)++] = novaInscricao;
    eventos[numeroDoEvento].totalinscritos++; // Contagem de inscritos no evento

    printf("Inscrição realizada com sucesso no evento: %s\n",
           eventos[numeroDoEvento].nomeEv);
  }
}

void listarInscritos(Evento evento, Inscricao inscricoes[], int *numEventos,
                     int numerodoEvento, Evento eventos[]) {
  printf("insira o numero do evento para mostrar os incritos:");
  scanf("%d", &numerodoEvento);
  if (numerodoEvento < 0 || numerodoEvento >= *numEventos) {
    printf("Esse evento não existe.\n");
    return;
  }

  if (evento.totalinscritos == 0) {
    printf("Nenhum inscrito neste evento!\n");
    return;
  }

  printf("\nLista de Inscritos no Evento ' %s' (em ordem alfabética):\n",
         evento.nomeEv);
  for (int idInscrito = 0; idInscrito < eventos[numerodoEvento].totalinscritos;
       idInscrito++) {
    printf("========================================\n");
    printf("ID do utilizador [%d].\n", idInscrito);
    printf("Nome: %s\n", inscricoes[idInscrito].utilizador.nome);
    printf("NIF: %d\n", inscricoes[idInscrito].utilizador.nif);
    printf("Email: %s\n", inscricoes[idInscrito].utilizador.email);
    printf("Idade: %d\n", inscricoes[idInscrito].utilizador.idade);
    printf("----------------------------------------\n");
  }
}


//Q2 - LINHA 394 E 411
int removerFilaEspera(FilaEspera *fila, Inscricao *removido) {

  int booleano;
  if (fila->tamanho > 0) {
    // Remove o elemento na posição 'inicio'
    *removido = fila->fila[fila->inicio];
    fila->inicio++; // Avança o índice 'inicio'
    fila->tamanho--;

    // Verifica se 'inicio' ultrapassou o limite do array
    if (fila->inicio == MAX_ESPERA) {
      fila->inicio = 0; // Reseta para 0 se atingir o final
    }

    booleano = 1;
    return booleano;
  } else {
    booleano = 0;
    return booleano;
  }
}


void desinscreverEventoUsuario(Evento eventos[], int numEventos,
                               Utilizador utilizadorAtual,
                               Inscricao inscricoes[], int *numInscricoes,
                               FilaEspera *fila) {
  if (numEventos == 0) {
    printf("Não há eventos disponíveis.\n");
    return;
  }

  printf("Eventos nos quais você está inscrito:\n");
  int eventosInscrito = 0;
  for (int i = 0; i < *numInscricoes; i++) {
    if (strcmp(inscricoes[i].utilizador.nome, utilizadorAtual.nome) == 0) {
      printf("Evento %d: %s\n", inscricoes[i].numEvento,
             eventos[inscricoes[i].numEvento].nomeEv);
      eventosInscrito++;
    }
  }

  if (eventosInscrito == 0) {
    printf("Você não está inscrito em nenhum evento.\n");
    return;
  }

  int numeroDoEvento;
  printf("Insira o número do evento para se desinscrever: ");
  scanf("%d", &numeroDoEvento);

  if (numeroDoEvento < 0 || numeroDoEvento >= numEventos) {
    printf("Número do evento inválido.\n");
    return;
  }

  int inscricaoEncontrada = -1;
  for (int i = 0; i < *numInscricoes; i++) {
    if (strcmp(inscricoes[i].utilizador.nome, utilizadorAtual.nome) == 0 &&
        inscricoes[i].numEvento == numeroDoEvento) {
      inscricaoEncontrada = i;
      break;
    }
  }

  if (inscricaoEncontrada == -1) {
    printf("Você não está inscrito no evento ' %s'.\n",
           eventos[numeroDoEvento].nomeEv);
    return;
  }

  printf("Removendo inscrição do evento '%s'.\n",
         eventos[numeroDoEvento].nomeEv);
  printf("Você foi desinscrito com sucesso do evento ' %s'.\n",
         eventos[numeroDoEvento].nomeEv);
  // Remove a inscrição movendo as seguintes
  for (int i = inscricaoEncontrada; i < *numInscricoes - 1; i++) {
    inscricoes[i] = inscricoes[i + 1];
  }
  (*numInscricoes)--;
  eventos[numeroDoEvento].totalinscritos--;

  // Gerenciar a fila de espera
  if (fila->tamanho > 0) {
    Inscricao novoInscrito;
    int res = removerFilaEspera(fila, &novoInscrito);

    if (novoInscrito.utilizador.nome[0] !=
        '\0') { // Verifica se a remoção foi válida
      novoInscrito.numEvento = numeroDoEvento;
      inscricoes[*numInscricoes] = novoInscrito;
      (*numInscricoes)++;
      eventos[numeroDoEvento].totalinscritos++;
      printf("Vaga liberada! ' %s' foi inscrito automaticamente no evento ' "
             "%s'.\n",
             novoInscrito.utilizador.nome, eventos[numeroDoEvento].nomeEv);
    }
  }
}

void totalEventos(Evento eventos[], int *numEventos) {
  printf("Total de eventos: %d\n", *numEventos);
}

void numeroMedioInscritosEventos(Evento eventos[], int *numEventos) {
  if (*numEventos == 0) {
    printf("Nenhum evento disponível.\n");
    return;
  }

  int totalInscritos = 0;
  for (int i = 0; i < *numEventos; i++) {
    totalInscritos += eventos[i].totalinscritos;
  }

  float media = (float)totalInscritos / *numEventos;
  printf("O numero médio de inscritos por evento: %.2f\n", media);
}

//Q1 - LINHA 529
float capacidadeMediaEventos(Evento eventos[], int *numEventos, float media) {

  if (*numEventos == 0) {
    return 0;
  }

  int totalCapacidade = 0;
  for (int i = 0; i < *numEventos; i++) {
    totalCapacidade += eventos[i].maxinscritos;
  }

  media = (float)totalCapacidade / *numEventos;
  //printf("Capacidade média de eventos: %.2f\n", media);
  return media;
}

void eventosComMaiorNumeroInscritos(Evento eventos[], int *numEventos) {
  if (*numEventos == 0) {
    printf("Nenhum evento disponível.\n");
    return;
  }

  int maiorNumeroInscritos = 0;
  for (int i = 0; i < *numEventos; i++) {
    if (eventos[i].totalinscritos > maiorNumeroInscritos) {
      maiorNumeroInscritos = eventos[i].totalinscritos;
    }
  }

  printf("Eventos com o maior número de inscritos:\n");
  for (int i = 0; i < *numEventos; i++) {
    if (eventos[i].totalinscritos == maiorNumeroInscritos) {
      printf("Evento %d: %s\n", i, eventos[i].nomeEv);
    }
  }
}

void eventosComCapacidadeMaxima(Evento eventos[], int *numEventos) {
  if (*numEventos == 0) {
    printf("Nenhum evento disponível.\n");
    return;
  }

  printf("Eventos com capacidade máxima de inscritos:\n");
  for (int i = 0; i < *numEventos; i++) {
    if (eventos[i].totalinscritos == eventos[i].maxinscritos) {
      printf("Evento %d: %s\n", i, eventos[i].nomeEv);
    }
  }
}

void totalReceitas(Evento eventos[], int *numEventos) {
  if (*numEventos == 0) {
    printf("Nenhum evento disponível.\n");
    return;
  }

  float totalReceitas = 0;
  for (int i = 0; i < *numEventos; i++) {
    totalReceitas += eventos[i].preco * eventos[i].totalinscritos;
  }

  printf("Total de receitas: %.2f euros.\n", totalReceitas);
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

int paginaEstatisticas(Evento eventos[], int *numEventos) {
  int choice;
  float media;
  printf("1. Total de eventos\n");
  printf("2. Número médio de inscritos por evento\n");
  printf("3. Capacidade média de eventos\n");
  printf("4. Eventos com o maior número de inscritos\n");
  printf("5. Eventos com capacidade máxima\n");
  printf("6. Total de receitas\n");
  printf("0. Sair\n");
  printf("Insira a sua opção: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    totalEventos(eventos, numEventos);
    break;
  case 2:
    numeroMedioInscritosEventos(eventos, numEventos);
    break;
  case 3:
    capacidadeMediaEventos(eventos, numEventos, media);
    printf("Capacidade média de eventos: %.2f\n", media); //float media
    break;
  case 4:
    eventosComMaiorNumeroInscritos(eventos, numEventos);
    break;
  case 5:
    eventosComCapacidadeMaxima(eventos, numEventos);
    break;
  case 6:
    totalReceitas(eventos, numEventos);
    break;
  case 0:
    printf("Saindo da página de estatísticas.\n");
    return 0;
  default:
    printf("Opção inválida.\n");
    break;
  }

  return 1;
}

int menuHomeAdmin(Evento eventos[], int *numEventos, int *numeroDoEvento,
                  Utilizador utilizadores[], int *numUtilizadores,
                  Utilizador utilizadorAtual, Inscricao inscricoes[],
                  int *numInscricoes, FilaEspera *fila) {
  int choice;

  printf(
      "1. Criar Evento                           6. Para Listar os eventos\n");
  printf("2. Editar Evento                          7. Para pesquisar os "
         "eventos\n");
  printf("3. Eliminar Evento                        8. Para se inscrever no "
         "evento\n");
  printf("4. Pagina de estatisticas                 9. Para se desinscrever no "
         "evento\n");
  printf("5. Pagina de avaliações                   10. Para listar inscritos "
         "no evento\n\n");
  printf("0 Sair ->\n\n");
  printf("Insira a sua opcção: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    criarEvento(eventos, numEventos);
    break;
  case 2:

    editarEvento(*numeroDoEvento, numEventos, eventos);
    break;
  case 3:
    printf("Insira o número do evento para deletar: ");
    scanf("%d", numeroDoEvento);
    deleteEvent(eventos, numEventos, *numeroDoEvento);
    break;
  case 4:
    paginaEstatisticas(eventos, numEventos);
    break;

  case 5:
    // criarQRcode(eventos[*numeroDoEvento],
    // inscricoes[*numInscricoes].utilizador);
    break;

  case 6:
    listarEventos(eventos, numEventos);
    break;

  case 7: {
    int indice;
    printf("Insira o indice do evento que deseja pesquisar (0 a %d): ",
           *numEventos - 1);
    scanf("%d", &indice);
    pesquisarEventoPorIndice(eventos, numEventos,
                             eventos[indice].nomeEv); // Usa nomeEv do struct

    break;
  }

  case 8:
    inscreverNoEvento(eventos, *numEventos, utilizadorAtual, inscricoes,
                      numInscricoes, fila, inscricoes[*numInscricoes]);
    break;

  case 9:
    desinscreverEventoUsuario(eventos, *numEventos, utilizadorAtual, inscricoes,
                              numInscricoes, fila);
    break;

  case 10:
    listarInscritos(eventos[*numeroDoEvento], inscricoes, numEventos,
                    *numeroDoEvento, eventos);
    break;

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
                 Utilizador utilizadorAtual, Inscricao inscricoes[],
                 int *numInscricoes) {
  int choice;

  printf("1. Para listar os eventos\n");
  printf("2. Para se inscrever no evento\n");
  printf("3. Para se desinscrever no evento\n");
  printf("4. Pagina de avaliações\n");
  printf("5. Sair\n");
  printf("Insira a sua opcção: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    listarEventos(eventos, numEventos);
    break;
  case 2:
    inscreverNoEvento(eventos, *numEventos, utilizadorAtual, inscricoes,
                      numInscricoes);
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
  Inscricao inscricoes[MAX_UTILIZADORES];
  int numInscricoes = 0;

  int numeroDoEvento;
  Utilizador utilizadores[MAX_EVENTOS];
  Evento eventos[MAX_EVENTOS];
  int numUtilizadores = 0;
  int numEventos = 0;
  Utilizador utilizadorAtual;
  utilizadorAtual.codAdmin = 0;
  adminPredefinido(utilizadores, &numUtilizadores);
  numUtilizadores = 1;
  Welcome();

  int login = 0;
  int userLogged = 0;
  int MainMenuCounter = 0;
  int choice = 0;

  while (MainMenuCounter == 0) {
    menuStart(&choice);
    switch (choice) {
    case 1:
      if (menuLogin(utilizadores, numUtilizadores, &utilizadorAtual,
                    &MainMenuCounter) != -1) {
        userLogged = 1; // Marcando o usuário como autenticado
      }
      break;
    case 2:
      menuSignUp(utilizadores, &numUtilizadores, &utilizadorAtual);
      MainMenuCounter = 1; // Diretamente para o menu após registro
      break;
    case 3:
      printf("Saindo do programa.\n");
      return 0;
    default:
      printf("Escolha inválida\n");
      break;
    }
  }

  while (MainMenuCounter == 1) {
    if (utilizadorAtual.codAdmin) {
      if (!menuHomeAdmin(eventos, &numEventos, &numeroDoEvento, utilizadores,
                         &numUtilizadores, utilizadorAtual, inscricoes,
                         &numInscricoes, NULL))
        MainMenuCounter = 0;
    } else {
      if (!menuHomeUser(eventos, &numEventos, &numeroDoEvento, utilizadores,
                        &numUtilizadores, utilizadorAtual, inscricoes,
                        &numInscricoes))
        MainMenuCounter = 0;
    }
  }
  return 0;
}