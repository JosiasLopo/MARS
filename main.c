#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 50

typedef struct utilizador
{
    char nome[50];
    char email[50];
    char password[19];

} Utilizador;

typedef struct administrador
{
    Utilizador utilizador;

} Administrador;

typedef struct participante
{
    Utilizador utilizador;
    int nif;
    int idade;

} Participante;

typedef struct participante
{
    Utilizador utilizador;
    int nif;
    int idade;

}Participante;   

typedef struct inscrito                                                                                                                                                                                                      
{
    Participante participante;
    int numeroDoEvento;
    Pagamento pagamento
}Inscrito;

typedef struct pagamento
{
    int metodoPagamento;
    int montante;
} Pagamento;
void my_fgets(char texto, int n);


typedef struct inscrito
{
    Participante participante;
    int numeroDoEvento;
    Pagamento pagamento;
} Inscrito;


int login(Utilizador utilizadores, char email, char password)
{
    return 1;
}

int loginadministrador(Administrador administradores, char email, char password)
{
    return 1;
}

int loginparticipante(Participante participantes, char email, char password)
{
    return 1;
}

int registo(Utilizador *utilizadores, int n)
{
    return 1;
}

int main(int argc, char const *argv[])
{
    Administrador administradores[50];

    administradores[0].utilizador.email;
}