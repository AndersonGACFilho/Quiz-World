#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include "Quiz.c"
int main()
{
    ApontadorDescritor d;
    FILE* arquivo;
    arquivo=fopen("bank.txt", "r");
    CriarListaVazia(&d);
    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    if (d == NULL)
    {
        printf("Erro ao criar a lista de questoes!");
        return 1;
    }
    Questao q;
    char texto[250];
    while (fgets(texto, 250, arquivo) != NULL)
    {
        q.questao = (char*)malloc(sizeof(char) * strlen(texto) + 1);
        strcpy(q.questao, texto);
        fgets(texto, 250, arquivo);
        q.a = (char*)malloc(sizeof(char) * strlen(texto) + 1);
        strcpy(q.a, texto);
        fgets(texto, 250, arquivo);
        q.b = (char*)malloc(sizeof(char) * strlen(texto) + 1);
        strcpy(q.b, texto);
        fgets(texto, 250, arquivo);
        q.c = (char*)malloc(sizeof(char) * strlen(texto) + 1);
        strcpy(q.c, texto);
        fgets(texto, 250, arquivo);
        q.d = (char*)malloc(sizeof(char) *strlen(texto) + 1);
        strcpy(q.d, texto);
        q.resposta=fgetc(arquivo);
        fgetc(arquivo);
        q.dificuldade=fgetc(arquivo);
        fgetc(arquivo);
        InserirQuestao(&d, &q);
    }
    fclose(arquivo);
    Menu(&d);
    arquivo=fopen("bank.txt", "w");
    if(arquivo == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    ApontadorQuestao aux=d->prim;
    EscreverArquivo(&d,arquivo);
    fclose(arquivo);
    LiberarLista(&d);
    getchar();
    return 0;
}
