#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"Quiz.h"
int CriarListaVazia(ApontadorDescritor *d)
{
    (*d)=(ApontadorDescritor)malloc(sizeof(Descritor));
    if(*d==NULL)
    {
        printf("ERRO");
        exit(1);
    }
    (*d)->numeros_questoes=0;
    (*d)->prim=(ApontadorQuestao)NULL;
    (*d)->ult=(ApontadorQuestao)NULL;
    return(SUCESSO);
}
int InserirInicio(ApontadorDescritor *d, Questao *questao)
{
    ApontadorQuestao q;
    q=(ApontadorQuestao)malloc(sizeof(Questao));
    int i;
    if(q==NULL)
    {
        printf("ERRO");
        exit(1);
    }
    (*d)->numeros_questoes++;
    q->numero_questao=1;
    q->questao=(char*)malloc(sizeof(char)*strlen((*questao).questao)+1);
    strcpy(q->questao, (*questao).questao);
    q->a=(char*)malloc(sizeof(char)*strlen((*questao).a)+1);
    strcpy(q->a, (*questao).a);
    q->b=(char*)malloc(sizeof(char)*strlen((*questao).b)+1);
    strcpy(q->b, (*questao).b);
    q->c=(char*)malloc(sizeof(char)*strlen((*questao).c)+1);
    strcpy(q->c, (*questao).c);
    q->d=(char*)malloc(sizeof(char)*strlen((*questao).d)+1);
    strcpy(q->d, (*questao).d);
    q->resposta=(*questao).resposta;
    q->dificuldade=(*questao).dificuldade;    
    q->ant=(ApontadorQuestao)NULL;
    q->prox=(*d)->prim;
    if((*d)->numeros_questoes==1)
    {
        (*d)->prim=q;
        (*d)->ult=q;
    }else
    {
        (*d)->prim->ant=q;
        (*d)->prim=q;
    }
    free((*questao).a);
    free((*questao).b);
    free((*questao).c);
    free((*questao).d);
    free((*questao).questao);
    if((*d)->numeros_questoes>1)
    {
        ApontadorQuestao r=(*d)->prim->prox;
        while(r!=NULL)
        {
            r->numero_questao++;
            r=r->prox;
        }
    }
    return SUCESSO;
}
int InserirQuestao(ApontadorDescritor *d, Questao *questao)
{
    ApontadorQuestao q,r;
    q=(ApontadorQuestao)malloc(sizeof(Questao));
    if(q==NULL)
    {
        printf("ERRO");
        exit(1);
    }
    
    if((*d)->numeros_questoes==0||(*questao).dificuldade=='F')
    {
        return(InserirInicio(d,questao));
    }
    else if (questao->dificuldade=='D')
    {
        (*d)->numeros_questoes++;
        q->numero_questao=(*d)->numeros_questoes;
        q->questao = (char*)malloc(sizeof(char) * strlen((*questao).questao) + 1);
        strcpy(q->questao, (*questao).questao);
        q->a = (char*)malloc(sizeof(char) * strlen((*questao).a) + 1);
        strcpy(q->a, (*questao).a);
        q->b = (char*)malloc(sizeof(char) * strlen((*questao).b) + 1);
        strcpy(q->b, (*questao).b);
        q->c = (char*)malloc(sizeof(char) * strlen((*questao).c) + 1);
        strcpy(q->c, (*questao).c);
        q->d = (char*)malloc(sizeof(char) * strlen((*questao).d) + 1);
        strcpy(q->d, (*questao).d);
        q->resposta=(*questao).resposta;
        q->dificuldade=(*questao).dificuldade;
        q->ant=(*d)->ult;
        q->prox=(ApontadorQuestao)NULL;
        (*d)->ult->prox=q;
        (*d)->ult=q;
        free((*questao).a);
        free((*questao).b);
        free((*questao).c);
        free((*questao).d);
        free((*questao).questao);
    }else{
        if((*d)->prim->dificuldade=='D')
        {
            return(InserirInicio(d,questao));
        }
        else if((*d)->ult->dificuldade=='D')
        {
            r=(*d)->prim;
            while (r->prox->dificuldade!='D')
            {
                r=r->prox;
            }
            q->numero_questao=r->prox->numero_questao;
            q->questao = (char*)malloc(sizeof(char) * strlen((*questao).questao) + 1);
            strcpy(q->questao, (*questao).questao);
            q->a = (char*)malloc(sizeof(char) * strlen((*questao).a) + 1);
            strcpy(q->a, (*questao).a);
            q->b = (char*)malloc(sizeof(char) * strlen((*questao).b) + 1);
            strcpy(q->b, (*questao).b);
            q->c = (char*)malloc(sizeof(char) * strlen((*questao).c) + 1);
            strcpy(q->c, (*questao).c);
            q->d = (char*)malloc(sizeof(char) * strlen((*questao).d) + 1);
            strcpy(q->d, (*questao).d);
            q->resposta=(*questao).resposta;
            q->dificuldade=(*questao).dificuldade;
            q->ant=r;
            q->prox=r->prox;
            r->prox->ant=q;
            r->prox=q;
            free((*questao).a);
            free((*questao).b);
            free((*questao).c);
            free((*questao).d);
            free((*questao).questao);
            ApontadorQuestao r=q->prox;
            while(r!=NULL)
            {
                r->numero_questao++;
                r=r->prox;
            }
        }
        else{
            (*d)->numeros_questoes++;
            q->numero_questao=(*d)->numeros_questoes;
            q->questao = (char*)malloc(sizeof(char) * strlen((*questao).questao) + 1);
            strcpy(q->questao, (*questao).questao);
            q->a = (char*)malloc(sizeof(char) * strlen((*questao).a) + 1);
            strcpy(q->a, (*questao).a);
            q->b = (char*)malloc(sizeof(char) * strlen((*questao).b) + 1);
            strcpy(q->b, (*questao).b);
            q->c = (char*)malloc(sizeof(char) * strlen((*questao).c) + 1);
            strcpy(q->c, (*questao).c);
            q->d = (char*)malloc(sizeof(char) * strlen((*questao).d) + 1);
            strcpy(q->d, (*questao).d);
            q->resposta=(*questao).resposta;
            q->dificuldade=(*questao).dificuldade;
            q->ant=(*d)->ult;
            q->prox=(ApontadorQuestao)NULL;
            (*d)->ult->prox=q;
            (*d)->ult=q;
            free((*questao).a);
            free((*questao).b);
            free((*questao).c);
            free((*questao).d);
            free((*questao).questao);
        }
    }
    return SUCESSO;
}
int ApagarQuestao(ApontadorDescritor *d, int numero_questao)
{
    getchar();
    if((*d)->prim==NULL)
    {
        printf("Nao ha questao para apagar!!\n");
        return(1);
    }
    int i;
    char controle;
    ApontadorQuestao q=(*d)->prim,aux;
    if((*d)->numeros_questoes==1&&numero_questao==1)
    {
        (*d)->numeros_questoes=0;
        (*d)->prim=(ApontadorQuestao)NULL;
        (*d)->ult=(ApontadorQuestao)NULL;
        printf("\n");
        for ( i = 0; i < 120; i++)
        {
            printf("-");
        }
        if(q->dificuldade=='F')
            printf("\n\n%d: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Facil\n\n",q->numero_questao,q->questao,q->a,q->b,q->c,q->d,q->resposta);
        else if(q->dificuldade=='M')
            printf("\n\n%d: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Medio\n\n",q->numero_questao,q->questao,q->a,q->b,q->c,q->d,q->resposta);
        else if(q->dificuldade=='D')
            printf("\n\n%d: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Dificil\n\n",q->numero_questao,q->questao,q->a,q->b,q->c,q->d,q->resposta);
        for ( i = 0; i < 120; i++)
        {
            printf("-");
        }
        printf("\n\n");
        printf("Deseja apaga-la(S/N)?\n");
        scanf("%c",&controle);
        if(controle=='S'||controle=='s')
        {   
            free(q->questao);
            free(q->a);
            free(q->b);
            free(q->c);
            free(q->d);
            free(q);
        }
        return 1;
    }
    if(numero_questao>(*d)->numeros_questoes)
    {
        printf("Questao nao existentente!!\n");
        return 0;
    }else if(numero_questao<1)
    {
        printf("Numero incompativel\n");
        return 0;
    }else if(numero_questao==(*d)->numeros_questoes)    
        q=(*d)->ult;
    else if(numero_questao/(*d)->numeros_questoes*100<=50)
    {
        q=(*d)->prim;
        while (q->numero_questao!=numero_questao)
        {
            q=q->prox;
        }
    }else if(numero_questao/(*d)->numeros_questoes*100>50)
    {
        q=(*d)->ult;
        while (q->numero_questao!=numero_questao)
        {
            q=q->ant;
        }
    } 
    printf("\n");
    for ( i = 0; i < 120; i++)
    {
        printf("-");
    }
    if(q->dificuldade=='F')
        printf("\n\n%d: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Facil\n\n",q->numero_questao,q->questao,q->a,q->b,q->c,q->d,q->resposta);
    else if(q->dificuldade=='M')
        printf("\n\n%d: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Medio\n\n",q->numero_questao,q->questao,q->a,q->b,q->c,q->d,q->resposta);
    else if(q->dificuldade=='D')
        printf("\n\n%d: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Dificil\n\n",q->numero_questao,q->questao,q->a,q->b,q->c,q->d,q->resposta);
    for ( i = 0; i < 120; i++)
    {
        printf("-");
    }
    printf("\n\n");
    printf("Deseja apaga-la(S/N)?\n");
    scanf("%c",&controle);
    if(controle=='S'||controle=='s')
    {
        if(numero_questao>1&&numero_questao<(*d)->numeros_questoes)
        {
            while (q->resposta!=numero_questao)
            {
                q=q->prox;
            }            
            q->ant->prox=q->prox;
            q->prox->ant=q->ant;
            aux=q->prox;
        }
        else if(numero_questao==1)
        {
            q->prox->ant=(ApontadorQuestao)NULL;
            (*d)->prim=q->prox;
            aux=q->prox;
        }
        else if(numero_questao==(*d)->numeros_questoes)
        {
            q->ant->prox=(ApontadorQuestao)NULL;
            (*d)->ult=q->ant;
            aux=NULL;
        }
        while(aux!=NULL)
        {
            aux->numero_questao--;
            aux=aux->prox;
        }
        free(q->questao);
        free(q->a);
        free(q->b);
        free(q->c);
        free(q->d);
        free(q);
        (*d)->numeros_questoes--;
    }
    return 1;
}
int MostrarQuestoes(ApontadorDescritor  *d)
{
    ApontadorQuestao q=(*d)->prim;
    int i;
    if((*d)->prim==NULL)
    {
        printf("Nao ha questao!!\n");
        return(1);
    }
    for ( i = 0; i < 120; i++)
    {
        printf("-");
    }
    
    while(q!=NULL)
    {
        if(q->dificuldade=='F')
            printf("\n\n%d: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Facil\n\n",q->numero_questao,q->questao,q->a,q->b,q->c,q->d,q->resposta);
        else if(q->dificuldade=='M')
            printf("\n\n%d: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Medio\n\n",q->numero_questao,q->questao,q->a,q->b,q->c,q->d,q->resposta);
        else if(q->dificuldade=='D')
            printf("\n\n%d: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Dificil\n\n",q->numero_questao,q->questao,q->a,q->b,q->c,q->d,q->resposta);
        for ( i = 0; i < 120; i++)
        {
            printf("-");
        }
        q=q->prox;
    }
}
int LiberarLista(ApontadorDescritor *d)
{
    ApontadorQuestao q=(*d)->prim,r;
    while(q!=NULL)
    {
        free(q->questao);
        free(q->a);
        free(q->b);
        free(q->c);
        free(q->d);
        r=q;
        q=q->prox;
        free(r);
    }
    free(*d);
    return 0;
}
int Menu(ApontadorDescritor *d)
{
    char texto[250],S_N;
    int controle=1,i;
    Questao q;
    while (controle)
    {
        system("cls");
        for(i=0;i<120;i++)
        {
            printf("-");
        }
        printf("\n");
        for(i=0;i<57;i++)
        {
            printf(" ");
        }
        printf("EDITOR");
        printf("\n");
        for(i=0;i<120;i++)
        {
            printf("-");
        }
        printf("Aperte 0 para terminar o programa.\n");
        printf("Aperte 1 para inserir uma nova questao.\n");
        printf("Aperte 2 para remover alguma questao.\n");
        printf("Aperte 3 para procurar questoes por palavras ou trechos da questao.\n");
        printf("Aperte 4 para alterar alguma questao.\n");
        printf("Aperte 5 para procurar questoes por dificuldade.\n");
        printf("Aperte 6 para mostrar todas as questoes.\n-> ");
        scanf("%d",&controle);
        printf("\n\n\n");
        switch (controle)
        {
        case 1:
            for(i=0;i<120;i++)
            {
                printf("-");
            }
            printf("\n");
            for(i=0;i<53;i++)
            {
                printf(" ");
            }
            printf("CRIAR  QUESTAO");
            printf("\n");
            for(i=0;i<120;i++)
            {
                printf("-");
            }
            getchar();
            printf("Digite a questao: ");
            scanf("%[^\n]",texto);
            for (i = 0; texto[i]!='\0'; i++)
            {
            }
            texto[i]='\n';
            if(i<250)
                texto[i+1]='\0';
            getchar();
            q.questao=(char*)malloc(sizeof(char)*strlen(texto)+1);
            strcpy(q.questao,texto);
            printf("Digite a alternativa A: ");
            scanf("%[^\n]",texto);
            for (i = 0; texto[i]!='\0'; i++)
            {
            }
            texto[i]='\n';
            if(i<250)
                texto[i+1]='\0';
            q.a=(char*)malloc(sizeof(char)*strlen(texto)+1);
            strcpy(q.a,texto);
            getchar();
            printf("Digite a alternativa B: ");
            scanf("%[^\n]",texto);
            for (i = 0; texto[i]!='\0'; i++)
            {
            }
            texto[i]='\n';
            if(i<250)
                texto[i+1]='\0';
            getchar();
            q.b=(char*)malloc(sizeof(char)*strlen(texto)+1);
            strcpy(q.b,texto);
            printf("Digite a alternativa C: ");
            scanf("%[^\n]",texto);
            for (i = 0; texto[i]!='\0'; i++)
            {
            }
            texto[i]='\n';
            if(i<250)
                texto[i+1]='\0';
            getchar();
            q.c=(char*)malloc(sizeof(char)*strlen(texto)+1);
            strcpy(q.c,texto);
            printf("Digite a alternativa D: ");
            scanf("%[^\n]",texto);
            for (i = 0; texto[i]!='\0'; i++)
            {
            }
            texto[i]='\n';
            if(i<250)
                texto[i+1]='\0';
            getchar();
            q.d=(char*)malloc(sizeof(char)*strlen(texto)+1);
            strcpy(q.d,texto);
            printf("Digite a alternativa correta, em maiusculo: ");
            scanf("%c",&q.resposta);
            
            while(q.resposta<65||q.resposta>68)
            {
                printf("\n");
                for (i = 0; i < 49; i++)
                {
                    printf(" ");
                }
                printf("Alternativa Invalida!\n");
                for (i = 0; i < 51; i++)
                {
                    printf(" ");
                }
                getchar();
                printf("Digite Novamente\n");
                printf("Digite a alternativa correta, em maiusculo: ");
                scanf("%c",&q.resposta);
            }
            getchar();
            printf("\n");
            printf("Digite F para facil.\nDigite M para medio.\nDigite D para dificil.\n-> ");
            scanf("%c",&q.dificuldade);
            while(q.dificuldade!='D'&&q.dificuldade!='M'&&q.dificuldade!='F')
            {
                printf("\n");
                for ( i = 0; i < 49; i++)
                {
                    printf(" ");
                }
                printf("Dificuldade Invalida!\n");
                for ( i = 0; i < 51; i++)
                {
                    printf(" ");
                }
                printf("Digite novamente!\n");
                printf("Digite F para facil.\nDigite M para medio.\nDigite D para dificil.\n-> ");
                getchar();
                scanf("%c",&q.dificuldade);
            }
            printf("\n");
            for ( i = 0; i < 120; i++)
            {
                printf("-");
            }
            if(q.dificuldade=='F')
                printf("\n\nEnunciado: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Facil\n\n",q.questao,q.a,q.b,q.c,q.d,q.resposta);
            else if(q.dificuldade=='M')
                printf("\n\nEnunciado: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Medio\n\n",q.questao,q.a,q.b,q.c,q.d,q.resposta);
            else if(q.dificuldade=='D')
                printf("\n\nEnunciado: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Dificil\n\n",q.questao,q.a,q.b,q.c,q.d,q.resposta);

            for ( i = 0; i < 120; i++)
            {
                printf("-");
            }
            printf("\n\n");
            getchar();
            printf("Deseja inseri-la(S/N)?\n");
            scanf("%c",&S_N);
            (S_N=='S'||S_N=='s')?InserirQuestao(d,&q): printf("\n");
            break;
        case 2:
            for(i=0;i<120;i++)
            {
                printf("-");
            }
            printf("\n");
            for(i=0;i<52;i++)
            {
                printf(" ");
            }
            printf("REMOVER  QUESTAO");
            printf("\n");
            for(i=0;i<120;i++)
            {
                printf("-");
            }
            printf("\n");
            printf("Digite o numero da questao que deseja deletar.\n-> ");
            scanf("%d",&i);
            ApagarQuestao(d,i);
            break;
        case 3:
            for ( i = 0; i < 120; i++)
            {
                printf("-");
            }
            ProcurarQuestaoTrecho(d);
            break;
        case 4:
            AlterarQuestao(d);
            break;
        case 5:
            ProcurarQuestaoDificuldade(d);
            break;
        case 6:
            for ( i = 0; i < 120; i++)
            {
                printf("-");
            }
            printf("\n\n");
            for ( i = 0; i < 56; i++)
            {
                printf(" ");
            }
            printf("QUESTOES");
            printf("\n\n");
            MostrarQuestoes(d);
            break;
        
        case 0:
            break;
        default:
            printf("Numero Invalido!!\n");
            break;
        }
        system("pause");
    }
    return 1;
}
void EscreverArquivo(ApontadorDescritor *d, FILE *f){
    if((*d)->prim==NULL)
    {
        printf("Arquivo Vazio\n");
        system("pause");
        return;
    }
    ApontadorQuestao q=(*d)->prim;
    while(q!=NULL)
    {
        fprintf(f,"%s",q->questao);
        fprintf(f,"%s",q->a);
        fprintf(f,"%s",q->b);
        fprintf(f,"%s",q->c);
        fprintf(f,"%s",q->d);
        fprintf(f,"%c",q->resposta);
        fprintf(f,"\n");
        fprintf(f,"%c",q->dificuldade);
        fprintf(f,"\n");
        q=q->prox;
    }
    return;
}
void Quiz(ApontadorDescritor *d,Player *player)
{
    int i;
    printf("\n");
    for(int i=0;i<120;i++)
    {
        printf("-");
    }
    printf("\n\n");
    for(int i=0;i<43;i++)
    {
        printf(" ");
    }
    printf("BEM VINDO AO MUNDO DOS QUIZES!!!\n");
    printf("\n");
    for(int i=0;i<120;i++)
    {
        printf("-");
    }
    printf("\n\n");
    player->PerguntasAcertadas=0;
    player->score=0;
    player->PerguntasErradas=0;
    int questao_atual;
    srand(time(NULL));
    while((*d)->numeros_questoes)
    {
        questao_atual=(rand()%(*d)->numeros_questoes)+1;
        QuestaoQuiz(d,questao_atual,player);
    }
    for(i=0;i<120;i++)
    {
        printf("-");
    }
    printf("\n\n");
    for(i=0;i<44;i++)
    {
        printf(" ");
    }
    printf("Que pena as perguntas acabaram\n"); 
    for(int i=0;i<(120-tamanho(player->score)-28)/2;i++)
    {
        printf(" ");
    }
    printf("Sua Pontuacao final foi: %d\n\n",player->score);
    for(i=0;i<(120-tamanho(player->PerguntasAcertadas)-tamanho(player->PerguntasErradas)-22)/2;i++)
    {
        printf(" ");
    }
    printf("Voce acertou  %d de %d!\n\n",player->PerguntasAcertadas,player->PerguntasErradas+player->PerguntasAcertadas);
    for(int i=0;i<48;i++)
    {
        printf(" ");
    }
    printf("Obrigado por jogar :D\n\n");
    for(int i=0;i<120;i++)
    {
        printf("-");
    }
    system("pause");
}
int QuestaoQuiz(ApontadorDescritor *d, int numero_questao, Player *player)
{
    int i;
    ApontadorQuestao q;
    char AlternativaCorreta;
    if((float)numero_questao/(float)(*d)->numeros_questoes<=0.5)
    {
        q=(*d)->prim;
        while (q->numero_questao!=numero_questao&&q->prox!=NULL)
        {
        q=q->prox;
        }
    }else{
        q=(*d)->ult;
        while (q->numero_questao!=numero_questao&&q->ant!=NULL)
        {
            q=q->ant;
        }
    } 
    if(q==NULL)
    {
        printf("Falha");
        return 0;
    }printf("\n");
    for (i = 0; i < 120; i++)
    {
        printf("-");
    }
    printf("\n");
    if(player->score!=0)
    {
        printf("\n");
    }
    for(i=0;i<120-tamanho(player->score)-10;i++)
    {
        printf(" ");
    }
    printf("SCORE:%d\n",player->score);
    printf(" %d-",player->PerguntasAcertadas+1);
    for (i = 0; i < (120-strlen(q->questao))/2-3; i++)
    {
        printf(" ");
    }
    printf("%s",q->questao);
    printf("\n\n");
    for (i = 0; i < 120; i++)
    {
        printf("-");
    }
    printf("\n\n");
    printf(" A: %s",q->a);
    printf(" B: %s",q->b);
    printf(" C: %s",q->c);
    printf(" D: %s",q->d);
    printf("Digite a alternativa correta, em maiusculo: ");
    scanf("%c",&AlternativaCorreta);
    while(AlternativaCorreta<65||AlternativaCorreta>68)
    {
        printf("\n");
        for (i = 0; i < 49; i++)
        {
            printf(" ");
        }
        printf("Alternativa Invalida!\n");
        for (i = 0; i < 51; i++)
        {
            printf(" ");
        }
        printf("Digite Novamente\n");
        getchar();
        printf("Digite a alternativa correta, em maiusculo: ");
        scanf("%c",&AlternativaCorreta);
    }
    printf("\n");
    for (i = 0; i < 120; i++)
    {
        printf("-");
    }

    if(AlternativaCorreta==q->resposta)
    {
        player->PerguntasAcertadas++;
        for (i = 0; i < 120; i++)
        {
            printf("-");
        }
        printf("\n");
        if(player->score!=0)
            printf("\n");
        for (i = 0; i < 44; i++)
        {
            printf(" ");
        }
        printf("PARABENS VOCE ACERTOU!!    +10 pontos\n\n");
        player->score+=10;
        for (i = 0; i < 120; i++)
        {
            printf("-");
        }
    }else{
        player->PerguntasErradas++;
        for (i = 0; i < 120; i++)
        {
            printf("-");
        }
        printf("\n\n");
        for (i = 0; i < 49; i++)
        {
            printf(" ");
        }
        printf("Que pena voce errou.\n");
        for (i = 0; i < 55; i++)
        {
            printf(" ");
        }
        printf(" -5 pontos\n\n");
        player->score-=5;
        for (i = 0; i < 120; i++)
        {
            printf("-");
        }
        printf("\n\n");
    }

    if(q==(*d)->prim)
    {
        if ((*d)->numeros_questoes == 1) {
            (*d)->prim = (ApontadorQuestao) NULL;
            (*d)->ult = (ApontadorQuestao) NULL;
        } 
        else {
            (*d)->prim = q->prox;
            ((*d)->prim)->ant = (ApontadorQuestao) NULL;
        }
    }else if(q==(*d)->ult)
    {
        (*d)->ult=q->ant;
        (*d)->ult->prox=(ApontadorQuestao)NULL;
    }else{
        q->ant->prox=q->prox;
        q->prox->ant=q->ant;
    }
    free(q->questao);
    free(q->a);
    free(q->b);
    free(q->c);
    free(q->d);
    free(q);
    system("pause");
    getchar();
    (*d)->numeros_questoes--;
}
int tamanho(int n)
{
    int i;
    for(i=1;n>9;i++)
    {
        n/=10;
    }
    return i;
}
int AlterarQuestao(ApontadorDescritor *d)
{
    int i,numero_questao;
    ApontadorQuestao r=(*d)->prim;
    system("cls");
    for ( i = 0; i < 120; i++)
    {
        printf("-");
    }
    printf("\n\n");
    for ( i = 0; i < 55; i++)
    {
        printf(" ");
    }
    printf("ALTERADOR\n\n");
    for ( i = 0; i < 120; i++)
    {
        printf("-");
    }
    printf("Digite o numero da questao que deseja alterar.\n");
    printf("-> ");
    scanf("%d",&numero_questao);
    if(numero_questao>(*d)->numeros_questoes)
    {
        system("cls");
        for ( i = 0; i < 120; i++)
        {
            printf("-");
        }
        printf("\n\n");
        for ( i = 0; i < 57; i++)
        {
            printf(" ");
        }
        printf("ERRO !\n");
        for ( i = 0; i < 46; i++)
        {
            printf(" ");
        }
        printf("QUESTAO NAO IDENTIFICADA !\n\n");
        for ( i = 0; i < 120; i++)
        {
            printf("-");
        }
        printf("\n\n");
        return FALHA;
    }
    while(r->numero_questao!=numero_questao&&r!=(ApontadorQuestao)NULL)
    {
        r=r->prox;
    }
    MostrarQuestao(r);
    for ( i = 0; i < 120; i++)
    {
        printf("-");
    }
    MostrarQuestao(r);
    for ( i = 0; i < 120; i++)
    {
        printf("-");
    }
    char aux[255];
    getchar();
    printf("\nDigite Questao para alterar o enunciado.\nDigite A para alterar a alternativa A.\n");
    printf("\nDigite B para alterar a alternativa B.\nDigite C para alterar a alternativa C.\n");
    printf("\nDigite D para alterar a alternativa D.\nDigite Alternativa para alterar a alternativa correta.\n");   
    printf("\nDigite Dificuldade para alterar a dificuldade da questao.\n"); 
    scanf("%[^\n]",aux);
    if(aux[0]=='Q'||aux[0]=='q')
    {
        getchar();
        printf("\nDigite qual é o enunciado correto:\n");
        scanf("%[^\n]",aux);
        free(r->questao);
        r->questao=(char*)malloc((sizeof(char)*strlen(aux))+1);
        strcpy(r->questao,aux); 
        r->questao[strlen(r->questao)-1]='\n';
    }
    else if(aux[0]=='A'||aux[0]=='a')
    {
        if(strlen(aux)==1){
            getchar();
            printf("\nDigite o qual é a alternativa correta:\n");
            scanf("%[^\n]",aux);
            free(r->a);
            r->a=(char*)malloc((sizeof(char)*strlen(aux))+1);
            strcpy(r->a,aux); 
            r->a[strlen(r->a)-1]='\n';
        }
        else{
            getchar();
            printf("\nDigite qual a alterativa correta:\n");
            scanf("%c",&aux[0]);
            r->resposta=aux[0];
            while(r->resposta<65||r->resposta>68)
            {
                printf("\n");
                getchar();
                for (i = 0; i < 49; i++)
                {
                    printf(" ");
                }
                printf("Alternativa Invalida!\n");
                for (i = 0; i < 51; i++)
                {
                    printf(" ");
                }
                printf("Digite Novamente\n");
                printf("Digite a alternativa correta novamente, em maiusculo: ");
                scanf("%c",&r->resposta);
            }
        }
    }
    else if(aux[0]=='B'||aux[0]=='b')
    {
        getchar();
        printf("\nDigite qual a alterativa corrigida:\n");
        scanf("%[^\n]",aux);
        free(r->b);
        r->b=(char*)malloc((sizeof(char)*strlen(aux))+1);
        strcpy(r->b,aux);
        r->b[strlen(r->b)-1]='\n';
    }
    else if(aux[0]=='C'||aux[0]=='c')
    {
        getchar();
        printf("\nDigite qual a alterativa corrigida:\n");
        scanf("%[^\n]",aux); 
        free(r->c);
        r->c=(char*)malloc((sizeof(char)*strlen(aux))+1);
        strcpy(r->c,aux); 
        r->c[strlen(r->c)-1]='\n';
    }
    else if(aux[0]=='D'||aux[0]=='d')
    {
        if(strlen(aux)==1)
        {
            getchar();
            printf("\nDigite qual a alterativa corrigida:\n");
            scanf("%[^\n]",aux);
            free(r->d);
            r->d=(char*)malloc((sizeof(char)*strlen(aux))+1);
            strcpy(r->d,aux);
            r->d[strlen(r->d)-1]='\n';
        }
        else{
            getchar();
            printf("\n\nDigite F para facil\nDigite M para medio\nDigite D para dificil:\n-> ");
            scanf("%c",&aux[0]);
            r->dificuldade=aux[0];
            while(r->dificuldade!='D'&&r->dificuldade!='M'&&r->dificuldade!='F')
            {
                printf("\n");
                for ( i = 0; i < 49; i++)
                {
                    printf(" ");
                }
                printf("Dificuldade Invalida!\n");
                for ( i = 0; i < 51; i++)
                {
                    printf(" ");
                }
                printf("Digite novamente!\n");
                printf("Digite F para facil.\nDigite M para medio.\nDigite D para dificil.\n-> ");
                getchar();
                scanf("%c",&r->dificuldade);
            }
        }
    }
    MostrarQuestao(r);
    return SUCESSO;
}
int ProcurarQuestaoTrecho(ApontadorDescritor *d)
{
    system("cls");
    int i,j,aux1,aux2,aux3;
    ApontadorQuestao q=(*d)->prim;
    for(i=0;i<120;i++)
    {
        printf("-");
    }
    printf("\n\n");
    for(i=0;i<48;i++)
    {
        printf(" ");
    }
    printf("PESQUISADOR POR TRECHOS");
    printf("\n\n");
    for(i=0;i<120;i++)
    {
        printf("-");
    }
    char trecho[255];
    printf("Digite o trecho a qual deseja procurar:\n");
    printf("-> ");
    getchar();
    scanf("%[^\n]",trecho);
    while(q!=(ApontadorQuestao)NULL)
    {
        aux1=strlen(q->questao);
        aux2=strlen(trecho);
        aux3=0;
        for ( i = 0; i < aux1; i++)
        {
            for ( j = 0; j < aux2&&i+j<aux1&&trecho[j]==q->questao[i+j]; j++)
            {
            }
            if(j==aux2)
            {
                MostrarQuestao(q);
                aux3=1;
                break;
            }
        }
        if(aux3!=1)
        {
            aux1=strlen(q->a);
            for ( i = 0; i < aux1; i++)
            {
                for ( j = 0; j < aux2&&i+j<aux1&&trecho[j]==q->a[i+j]; j++)
                {
                }
                if(j==aux2)
                {
                    MostrarQuestao(q);
                    aux3=1;
                    break;
                }
            }
        }
        if(aux3!=1)
        {
            aux1=strlen(q->b);
            for ( i = 0; i < aux1; i++)
            {
                for ( j = 0; j < aux2&&i+j<aux1&&trecho[j]==q->b[i+j]; j++)
                {
                }
                if(j==aux2)
                {
                    MostrarQuestao(q);
                    aux3=1;
                    break;
                }
            }
        }
        if(aux3!=1)
        {
            aux1=strlen(q->c);
            for ( i = 0; i < aux1; i++)
            {
                for ( j = 0; j < aux2&&i+j<aux1&&trecho[j]==q->c[i+j]; j++)
                {
                }
                if(j==aux2)
                {
                    MostrarQuestao(q);
                    aux3=1;
                    break;
                }
            }
        }
        if(aux3!=1)
        {
            aux1=strlen(q->d);
            for ( i = 0; i < aux1; i++)
            {
                for ( j = 0; j < aux2&&i+j<aux1&&trecho[j]==q->d[i+j]; j++)
                {
                }
                if(j==aux2)
                {
                    MostrarQuestao(q);
                    aux3=1;
                    break;
                }
            }
        }
        q=q->prox;
    }
}
int MostrarQuestao(ApontadorQuestao q)
{
    int i;
    printf("\n");
    for ( i = 0; i < 120; i++)
    {
        printf("-");
    }
    if(q->dificuldade=='F')
        printf("\n\n%d: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Facil\n\n",q->numero_questao,q->questao,q->a,q->b,q->c,q->d,q->resposta);
    else if(q->dificuldade=='M')
        printf("\n\n%d: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Medio\n\n",q->numero_questao,q->questao,q->a,q->b,q->c,q->d,q->resposta);
    else if(q->dificuldade=='D')
        printf("\n\n%d: %s\n\nA: %s\nB: %s\nC: %s\nD: %s\nAlternativa Correta: %c\nDificuldade: Dificil\n\n",q->numero_questao,q->questao,q->a,q->b,q->c,q->d,q->resposta);
    for ( i = 0; i < 120; i++)
    {
        printf("-");
    }
    return SUCESSO;
}
int ProcurarQuestaoDificuldade(ApontadorDescritor *d)
{
    ApontadorQuestao r;
    system("cls");
    int i;
    for ( i = 0; i < 120; i++)
    {
        printf("-");
    }
    printf("\n\n");
    for (i = 0; i < 42; i++)
    {
        printf(" ");
    }
    printf("PROCURANDO QUESTOES POR DIFICULDADE\n");
    printf("\n");
    for ( i = 0; i < 120; i++)
    {
        printf("-");
    }
    char dificuldade;
    printf("Digite F para facil\nDigite M para medio\nDigite D para dificil\n-> ");
    getchar();
    scanf("%c",&dificuldade);
    while(dificuldade!='D'&&dificuldade!='M'&&dificuldade!='F')
    {
        printf("\n");
        for ( i = 0; i < 49; i++)
        {
            printf(" ");
        }
        printf("Dificuldade Invalida!\n");
        for ( i = 0; i < 51; i++)
        {
            printf(" ");
        }
        printf("Digite novamente!\n");
        printf("Digite F para facil.\nDigite M para medio.\nDigite D para dificil.\n-> ");
        getchar();
        scanf("%c",&dificuldade);
    }
    r=(*d)->prim;
    while(r!=NULL)
    {
        if(r->dificuldade==dificuldade)
        {
            MostrarQuestao(r);
        }
        r=r->prox;
    }
}