#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define SUCESSO 1
#define FALHA 0

typedef struct Questao* ApontadorQuestao;
typedef struct Descritor* ApontadorDescritor;
typedef struct Questao{
    int numero_questao;
    char *questao; 
    char *a; 
    char *b; 
    char *c; 
    char *d; 
    char resposta;
    char dificuldade;
    ApontadorQuestao prox;
    ApontadorQuestao ant;
}Questao;

typedef struct Descritor{
    ApontadorQuestao prim;
    int numeros_questoes;
    ApontadorQuestao ult;
}Descritor;

typedef struct Player{
    int score;
    int PerguntasAcertadas;
    int PerguntasErradas;
}Player;
int CriarListaVazia(ApontadorDescritor *d);
int InserirInicio(ApontadorDescritor *d, Questao *questao);
int InserirQuestao(ApontadorDescritor *d, Questao *questao);
int ApagarQuestao(ApontadorDescritor *d, int numero_questao);
int ProcurarQuestaoDificuldade(ApontadorDescritor *d);
int ProcurarQuestaoTrecho(ApontadorDescritor *d);
int AlterarQuestao(ApontadorDescritor *d);
int MostrarQuestao(ApontadorQuestao q);

int MostrarQuestoes(ApontadorDescritor  *d);

int LiberarLista(ApontadorDescritor *d);
void EscreverArquivo(ApontadorDescritor *d, FILE *f);

int Menu(ApontadorDescritor *d);
void Quiz(ApontadorDescritor *d,Player *player);

int QuestaoQuiz(ApontadorDescritor *d, int numero_questao, Player *player);

int tamanho(int n);
