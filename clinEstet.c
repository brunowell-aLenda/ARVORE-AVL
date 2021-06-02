#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clinEstet.h"
#include "validacoes.h"
#include <windows.h>
#include <locale.h>
#include <conio.h>


struct cliente
{
    char nome[81];
    char sexo;
    char servico[81];
    int dia,mes,ano;
    int hora, minuto;
    int idade;
    int CPF;
    char atendimento[2];
    float valor_serv;
};

struct arvno
{
    Cliente* info;
    int altdir, altesq; //altura daquela sub-arvore
    ArvNo* esq;
    ArvNo* dir;
};

struct arv
{
    ArvNo* raiz;
};

/*Criando uma arvore vazia*/
Arv* arv_cria(void)
{
    Arv* a = (Arv*)malloc(sizeof(Arv));
    if(a== NULL)
    {
        printf("Memoria insuficiente,\nO programa será abortado.\n");
        exit(1);
    }
    a->raiz = NULL;
    return a;
}

//Adicionando valor aos serviços
static float valor_de_serv(char* servico)
{
    float valor;
    if(strcmp(servico,"Limpeza")==0)
    {
        valor = 50.00;
    }
    else if(strcmp(servico,"Cera")==0)
    {
        valor = 85.00;
    }
    else if(strcmp(servico,"Laser")==0)
    {
        valor = 180.00;
    }
    else if(strcmp(servico,"Pelling")==0)
    {
        valor = 68.00;
    }
    else if(strcmp(servico,"Massagem")==0)
    {
        valor = 200.00;
    }
    return valor;
}

//Criando cliente
Cliente* cria_clin(char* nome, int CPF, char sexo, int idade, char* servico, int dia, int mes, int ano, int hora, int minuto)
{

    Cliente* novo_cli = (Cliente*) malloc(sizeof(Cliente));
    if(novo_cli == NULL)
    {
        printf("Erro de alocacao de memoria.\nO Programa sera abortado.\n");
        exit(1);
    }

    strcpy(novo_cli->nome, nome);
    novo_cli->CPF = CPF;
    novo_cli->sexo = sexo;
    novo_cli->idade = idade;
    strcpy(novo_cli->servico,servico);
    novo_cli->dia = dia;
    novo_cli->mes = mes;
    novo_cli->ano = ano;
    novo_cli->hora = hora;
    novo_cli->minuto = minuto;
    novo_cli->valor_serv = valor_de_serv(novo_cli->servico);

    return novo_cli;
}

//Criando no da arvore
ArvNo* arvno_cria(Cliente* a)
{
    ArvNo* novo = (ArvNo*) malloc(sizeof(ArvNo));
    if(novo == NULL)
    {
        printf("Memoria insuficiente\n.O programa sera abortado.\n");
        exit(1);
    }

    novo->info = a;
    novo->esq = novo->dir = NULL;
    novo->altesq = novo->altdir = 0;

    return novo;
}

//Fazendo Rotação a direita
static ArvNo* RotDir(ArvNo* r)
{
    ArvNo *aux1, *aux2;
    aux1 = r->esq;
    aux2 = r->dir;
    r->esq = aux2;
    aux1->dir = r;

    // altura da esquerda for maior que a altura da direita, dessa forma, a altura da esquerda vai receber a altura +1
    if(r->esq == NULL)
    {
        r->altesq = 0;
    }
    else if(r->esq->altesq > r->esq->altdir)
    {
        r->altesq = r->esq->altesq +1;
    }
    else
    {
        r->altesq = r->esq->altdir + 1; //  vai receber a altura da direita +1
    }
    // altura da subarvore esquerda for maior que a altura dos nós da subarvore direita, dessa forma, a altura direita vai receber a esquerda +1*/
    if(aux1->dir->altesq > aux1->dir->altdir)
    {
        aux1->altdir = aux1->dir->altesq + 1;
    }
    else
    {
        aux1->altdir = aux1->dir->altdir + 1;
    }
    return aux1;
}

//Fazendo Rotação a esquerda
static ArvNo* RotEsq(ArvNo* r)
{

    ArvNo *aux1, *aux2;
    aux1 = r->dir;
    aux2 = aux1->esq;
    r->dir = aux2;
    aux1->esq = r;

    if(r->dir == NULL)
    {
        r->altdir = 0;
    }
    else if(r->dir->altesq > r->dir->altdir)
    {
        r->altdir = r->dir->altesq + 1;
    }
    else
    {
        r->altdir = r->dir->altdir + 1;
    }
    if(aux1->esq->altesq > aux1->esq->altdir)
    {
        aux1->altesq = aux1->esq->altesq + 1;
    }
    else
    {
        aux1->altesq = aux1->esq->altdir + 1;
    }

    return aux1;
}

//Fazendo balanceamento e o fator de balancemento de um nó
static ArvNo* Balanceamento(ArvNo* r)
{

    int d, df;
    d = r->altdir - r->altesq;
    if(d == 2)
    {
        df = r->dir->altdir - r->dir->altesq;
        if(df >= 0)
        {
            r = RotEsq(r);
        }
        else
        {
            r->dir = RotDir(r->dir);
            r = RotEsq(r);
        }
    }
    else if(d == -2)
    {
        df = r->esq->altdir - r->esq->altesq;
        if(df <= 0)
        {
            r = RotDir(r);
        }
        else
        {
            r->esq = RotEsq(r->esq);
            r = RotDir(r);
        }
    }
    return r;
}

//Inserindo dados e fazendo o balanceamento
static ArvNo* insere(ArvNo* r, ArvNo* no)
{
    if(r == NULL)
    {
        r = no;
        r->esq = NULL;
        r->dir = NULL;
    }
    else if(strcmp(r->info->nome,no->info->nome) > 0)
    {
        r->esq = insere(r->esq, no);
        if(r->esq->altdir > r->esq->altesq)
        {
            r->altesq = r->esq->altdir + 1;
        }
        else
        {
            r->altesq = r->esq->altesq + 1;
        }
        r = Balanceamento(r);
    }
    else
    {
        r->dir = insere(r->dir, no);

        if(r->dir->altdir < r->dir->altesq)
        {
            r->altdir = r->dir->altdir + 1;
        }
        else
        {
            r->altdir = r->dir->altesq + 1;
        }
        r = Balanceamento(r);
    }
    return r;
}

//Inserindo dados
void arv_insere(Arv* a, ArvNo* no)
{
    a->raiz = insere(a->raiz, no);
}

//Imprimir dados do cliente
void imprime_cliente(Cliente* c)
{

    printf(" NOME: %s\n CPF: %d\n SEXO: %c\n IDADE: %d\n SERVICO: %s\n DATA: %d/%d/%d\n HORARIO: %d:%d\n VALOR:%.2f\n\n------------\n", c->nome, c->CPF, c->sexo, c->idade, c->servico, c->dia, c->mes, c->ano, c->hora, c->minuto, c->valor_serv);

}

//Imprimir dados do cliente
static void imprime(ArvNo* no)
{
    if(no != NULL)
    {
        imprime(no->esq);
        imprime_cliente(no->info);
        imprime(no->dir);
    }
}

//Imprimir dados do cliente
void arv_imprime(Arv* a)
{
    imprime(a->raiz);
}

//Busca de um nome na arvore
static ArvNo* busca(ArvNo* r, char* nome)
{
    if(r == NULL)
    {
        return NULL;
    }
    else if(strcmp(r->info->nome, nome) > 0)
    {
        return busca(r->esq, nome);
    }
    else if(strcmp(r->info->nome, nome) < 0)
    {
        return busca(r->dir, nome);
    }
    else
    {
        return r;
    }
    return NULL;
}

//Busca de um nome na arvore
ArvNo* arv_busca(Arv* a, char* nome)
{
    return busca(a->raiz, nome);
}

// buscando o cliente e realizar uma novo agendamento dizendo o procedimento e o horario
void nova_consulta(ArvNo* a)
{

    if(a == NULL)
    {
        printf(" CLIENTE NAO ENCONTRADO, VERIFIQUE NOVAMENTE O NOME DO CLIENTE.\n");
    }
    else
    {
        imprime_cliente(a->info);
        char ver[1];
        printf("\nEste(a) e a pessoa que quer fazer a nova consulta - [sim] ou [nao] ?");
        scanf(" %s", ver);
        if(strcmp(ver, "sim") == 0)
        {
            printf("\n AGENDAR UMA NOVA TAREFA\n");
            printf("\n Insira o SERVICO:\n");
            scanf(" %499[^\n]",a->info->servico);
            valor_de_serv(a->info->servico);
            Camelcase(a->info->servico);
            a->info->valor_serv = valor_de_serv(a->info->servico);
            printf(" Insira o DIA/MES/ANO:\n");
            scanf("%d/%d/%d",&a->info->dia, &a->info->mes, &a->info->ano);
            printf(" Insira a HORA:MINUTO\n");
            scanf("%d:%d",&a->info->hora, &a->info->minuto);

            printf(" Agendamento Marcado!\n");

            FILE* arqconsult = fopen("clientesCadastrados/clientesCadastrados.txt", "a+");
            if(arqconsult == NULL)
            {
                printf("ERRO AO ABRIR O ARQUIVO DE SAIDA.\nO PROGRAMA SERA ABORTADO");
                exit(1);
            }

            fprintf(arqconsult,"%s\t %d\t %c\t %d\t %s\t %d/%d/%d\t %d:%d\t%.2f\n",a->info->nome, a->info->CPF, a->info->sexo, a->info->idade, a->info->servico, a->info->dia, a->info->mes,a->info->ano, a->info->hora,a->info->minuto, a->info->valor_serv);
            fclose(arqconsult);
        }
        else
        {
            printf("\nTente novamente!");

        }
    }
}

//Liberar arvore
static void libera(ArvNo* r)
{
    if(r != NULL)
    {
        libera(r->esq);
        libera(r->dir);
        free(r->info);
        free(r);
    }
}

//Liberar arvore
void arv_libera (Arv* a)
{
    libera(a->raiz);
}

//Enviar para o arquivo o cliente cadastrado
static void imprimir_cliente(ArvNo* c, FILE* clienteCadastro)
{
    if(c != NULL)
    {
        imprimir_cliente(c->esq, clienteCadastro);
        fprintf(clienteCadastro,"%s\t %d\t %c\t %d\t %s\t %d/%d/%d\t %d:%d\t%.2f\t\n",c->info->nome, c->info->CPF, c->info->sexo, c->info->idade, c->info->servico, c->info->dia, c->info->mes, c->info->ano, c->info->hora, c->info->minuto,c->info->valor_serv);
        imprimir_cliente(c->dir, clienteCadastro);
    }
}

//Enviar para o arquivo o cliente cadastrado
void arv_inserirArquivo_clienteCadastrado(Arv* a)
{

    FILE* arqCadastro = fopen("clientesCADASTRADOS/clientesCadastrados.txt","w");
    if(arqCadastro == NULL)
    {
        printf(" ERRO AO ABRIR O ARQUIVO DE SAIDA.\nO PROGRAMA SERA ABORTADO");
        exit(1);
    }
    imprimir_cliente(a->raiz,arqCadastro);
    fclose(arqCadastro);
}

//Concluir se o atendimento já foi terminado
void atendimento(ArvNo* a)
{
    if(a == NULL)
    {
        printf(" CLIENTE NAO ENCONTRADO, VERIFIQUE NOVAMENTE O NOME DO CLIENTE.\n");
    }
    else
    {
        imprime_cliente(a->info);
        char ver[4];
        printf("\nDeseja finalizar o atendimento de %s: [sim] ou [nao] ?", a->info->nome);
        scanf(" %s", ver);

        if(strcmp(ver, "sim") == 0)
        {
            printf("\n Confirmar Atendimento:\n");
            scanf(" %3[^\n]", a->info->atendimento);

            printf(" Atendimento finalizado!\n");

            FILE* atendok = fopen("AtendimentosOK/AtendimentosOK.txt", "a+");
            if(atendok == NULL)
            {
                printf("ERRO AO ABRIR O ARQUIVO DE SAIDA.\nO PROGRAMA SERA ABORTADO");
                exit(1);
            }
            fprintf(atendok,"%s\t %d\t %c\t %d\t %s\t %d/%d/%d\t %d:%d\t %.2f\t %s\t\n",a->info->nome, a->info->CPF, a->info->sexo, a->info->idade, a->info->servico, a->info->dia, a->info->mes,a->info->ano, a->info->hora,a->info->minuto, a->info->valor_serv,a->info->atendimento);

            fclose(atendok);
        }
        else
        {
            printf(" \nVoltando as opcoes");
        }
    }
}

//Trazendo dados do arquivo cliente e inserindo na arvore
void carrega_dados_clin(Arv* a)
{
    char linha[280];
    FILE* file = fopen("clientesCADASTRADOS/clientesCadastrados.txt","rt");
    if(file==NULL)
    {
        printf("Arquivo Invalido\n");
        exit(1);
    }

    while(fgets(linha, 280, file)!=NULL)
    {
        Cliente* c = (Cliente*) malloc(sizeof(Cliente));
        if(c == NULL)
        {
            printf("memoria insuficiente!");
            exit(1);
        }
        sscanf(linha, "%s\t %d\t %c\t %d\t %s\t %d/%d/%d\t %d:%d\t %f", c->nome, &c->CPF, &c->sexo, &c->idade, c->servico, &c->dia, &c->mes, &c->ano, &c->hora, &c->minuto, &c->valor_serv);
        c = cria_clin(c->nome, c->CPF, c->sexo, c->idade, c->servico, c->dia, c->mes, c->ano, c->hora, c->minuto);

        ArvNo* no = arvno_cria(c);

        arv_insere(a, no);
    }
    fseek(file, 0, SEEK_SET);
    fclose(file);
}

//Mostrar a soma total de serviços realizados
void total_servico()
{

    char nomeT[81];
    char sexoT;
    char servicoT[81];
    int diaT,mesT,anoT;
    int horaT, minutoT;
    int idadeT;
    int CPFT;
    char atend[2];

    float total;
    float soma = 0;

    FILE *tot = fopen ("AtendimentosOK/AtendimentosOK.txt", "rt");
    if(tot == NULL)
    {
        printf("arquivo invalido no total");
        exit(1);
    }

    while(fscanf(tot,"%s\t %d\t %c\t %d\t %s\t %d/%d/%d\t %d:%d\t %f\n %s\n",  nomeT, &CPFT, &sexoT, &idadeT, servicoT, &diaT, &mesT, &anoT, &horaT, &minutoT, &total, atend)!=EOF)
    {
        soma +=total;
    }
    printf("Soma total de servicos realizados: R$%.2f\n", soma);

    fseek(tot, 0, SEEK_SET);
    fclose(tot);

}

//Mostrar soma da busca de serviços
void buscar_valor_pelo_servico(char* serv)
{
    char linha[280];
    char nomeB[81];
    char sexoB;
    char servicoB[81];
    int diaB,mesB,anoB;
    int horaB, minutoB;
    int idadeB;
    int CPFB;
    char atenB[2];
    float totalB;
    float somaB = 0;

    FILE *totBus = fopen ("AtendimentosOK/AtendimentosOK.txt", "rt");
    if(totBus == NULL)
    {
        printf("arquivo invalido no total");
        exit(1);
    }
    while(fgets(linha, 280, totBus)!=NULL)
    {
        sscanf(linha,"%s\n%d\n%c\n%d\n %s\n %d/%d/%d\n %d:%d\n%f\n%s\n", nomeB, &CPFB, &sexoB, &idadeB, servicoB, &diaB, &mesB, &anoB, &horaB, &minutoB,&totalB, atenB);

        if(strcmp(serv,servicoB)==0)
        {
            somaB += valor_de_serv(serv);
        }
    }

    printf("\n Soma total dos servicos de %s realizados eh: R$%.2f\n",serv, somaB);

    fseek(totBus, 0, SEEK_SET);
    fclose(totBus);
}


//Retira o cliente quando seu atendimento é finalizado

static ArvNo* retira(ArvNo* r,char* nome)
{
    if(r == NULL)
        return NULL;
    else if(strcmp(nome, r->info->nome)<0)
    {
        r->esq = retira(r->esq, nome);
    }
    else if(strcmp(nome,r->info->nome)>0)
    {
        r->dir = retira(r->dir, nome);
    }
    else
    {
        /*achou elemento*/
        /*elemento sem filhos*/
        if(r->esq == NULL && r->dir == NULL)
        {
            free(r);
            r = NULL;
        }
        else if(r->esq==NULL)
        {
            ArvNo* t = r;
            r = r->dir;
            free(t);
        }
        else if(r->dir==NULL)
        {
            ArvNo* t = r;
            r = r->esq;
            free(t);
        }
        else
        {
            ArvNo* f = r->esq;
            while (f->dir !=NULL)
            {
                f = f->dir;
            }
            strcpy(r->info->nome, f->info->nome);
            strcpy(f->info->nome, nome);
            r->esq = retira(r->esq, nome);
        }
    }

    return r;
}

//Retira o cliente quando seu atendimento é finalizado

void aa_retira(Arv* a, char* nome)
{
    a->raiz = retira(a->raiz, nome);
}
