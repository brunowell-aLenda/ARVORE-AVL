#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include "clinEstet.h"
#include "validacoes.h"
#include <ctype.h>
#include <conio.h>

#define SENHA 1234567890


int main()
{
    //setlocale(LC_ALL, "Portuguese");

    system("color E");


    int controlMENU;
    int controlCASE0,controlCASE1, controlCASE2, controlCASE3, controlCASE5;
    int senha;
    char nome[81];
    char sexo;
    char servico[81];
    int idade;
    int hora, minuto;
    int CPF;
    int dia, mes, ano;


    printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
    printf("\t\t\t³                        BEM VINDO(A)                        ³\n");
    printf("\t\t\t³                  DIWEL CLINICA DE ESTETICA                 ³\n");
    printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

    printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
    printf("\t\t\t³                        ---CREDITOS---                      ³\n");
    printf("\t\t\t³    Trabalho para a dis. de Alg. e Estruturas de Dados 2    ³\n");
    printf("\t\t\t³    Desenvolvido por: Bruno Wellington e Dimona Laquis      ³\n");
    printf("\t\t\t³         Rio grande do Norte, Maio de 2021, 3 Periodo       ³\n");
    printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

    printf("\n");
    printf("\n");
    printf("Por favor, insira a senha: ");
    scanf("%i",&senha);
    system("cls");

    Arv* arvore = arv_cria();
    carrega_dados_clin(arvore);
    if(senha==SENHA)
    {



        system("title CLINICA DE ESTETICA");
        do
        {



            printf("\n");
            printf("\n");
            printf("\n");

            int aux;
            printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
            printf("\t\t\t³               1- Servicos Ofertado           ³\n");
            printf("\t\t\t³               2- Cliente                     ³\n");
            printf("\t\t\t³               3- Agendamento                 ³\n");
            printf("\t\t\t³               4- Atendimento                 ³\n");
            printf("\t\t\t³               5- Balanco diario              ³\n");
            printf("\t\t\t³               6- Sair do Sistema             ³\n");
            printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
            printf(" \n Digite sua opcao: ");
            scanf(" %d", &controlMENU);
            system("cls");

            setbuf(stdin, NULL);

            switch(controlMENU)
            {
            case 1:
                do
                {
                    printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                    printf("\t\t\t³              [1] - Conheca nossos Servicos                 ³\n");
                    printf("\t\t\t³              [2] - Menu Inicial                            ³\n");
                    printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                    printf(" \n Digite sua opcao: ");
                    scanf(" %d", &aux);

                    system("cls");
                    if(aux == 1)
                    {
                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³        DIWEL CLINICA DE ESTETICA - SERVICOS OFERTADOS      ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³                      Limpeza: R$ 50,00                     ³\n");
                        printf("\t\t\t³                      Depilacao a cera: R$ 85,00            ³\n");
                        printf("\t\t\t³                      Depilacao a laser: R$ 180,00          ³\n");
                        printf("\t\t\t³                      Pelling: R$ 68,00                     ³\n");
                        printf("\t\t\t³                      Massagem: R$ 200,00                   ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³              [1] - Voltar para as opcoes                   ³\n");
                        printf("\t\t\t³              [2] - Menu Inicial                            ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf(" \n Digite sua opcao: ");
                        scanf(" %d",&controlCASE0);

                        if(controlCASE0 == 2)
                        {
                            aux = 3;
                            controlCASE0 = aux;
                        }
                        system("cls");
                    }
                    else
                    {
                        break;
                    }
                }
                while(controlCASE0 != 3);
                break;

            case 2:
                do
                {
                    printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                    printf("\t\t\t³              [1] - Cadastrar novo cliente                  ³\n");
                    printf("\t\t\t³              [2] - Buscar cliente                          ³\n");
                    printf("\t\t\t³              [3] - Impressao da lista de cliente           ³\n");
                    printf("\t\t\t³              [4] - Arquivar dados Cadastrados              ³\n");
                    printf("\t\t\t³              [5] - Menu Inicial                            ³\n");
                    printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                    printf(" \n Digite sua opcao: ");
                    scanf(" %d", &aux);
                    system("cls");
                    if(aux == 1)
                    {
                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³                    CADASTRANDO NOVO CLIENTE                ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf(" Informe seu Nome:\n");
                        //scanf(" %s", nome);
                        strcpy(nome, Camelcase(String()));

                        printf(" Informe seu CPF(sem tracos e ponto):\n");
                        //scanf("%d",&CPF);
                        CPF = Inteiro_CPF();

                        printf(" Informe seu Sexo:\n");
                        //scanf(" %s", sexo);
                        sexo = Valida_Sexo();

                        printf(" Informe sua Idade:\n");
                        //scanf("%d", &idade);
                        idade = Inteiro();

                        printf(" Informe o servico que vai fazer:\n");
                        //scanf(" %s", servico);
                        strcpy(servico, Camelcase(String()));

                        printf(" Informe a data no formato dia/mes/ano que vai realizar o servico:\n");
                        scanf(" %d/%d/%d", &dia, &mes, &ano);

                        printf(" Informe a hora:minuto que vai realizar o servico:\n");
                        scanf(" %d:%d", &hora, &minuto);

                        arv_insere(arvore,arvno_cria(cria_clin(nome, CPF, sexo, idade,servico, dia,mes,ano,hora,minuto)));
                        printf("\n CADASTRO EFETUADO COM SUCESSO.\n\n");


                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³              [1] - Voltar para as opcoes                   ³\n");
                        printf("\t\t\t³              [2] - Menu Inicial                            ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf(" \n Digite sua opcao: ");
                        scanf(" %d",&controlCASE1);
                        if(controlCASE1 == 2)
                        {
                            aux = 4;
                            controlCASE1 = aux;
                        }
                        system("cls");
                    }
                    else if(aux == 2)
                    {
                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³                BUSCA DE CLIENTES CADASTRADOS               ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        setbuf(stdin, NULL);
                        char bus[81];
                        printf("\n DIGITE O NOME DO CLIENTE: ");
                        gets(bus);

                        ArvNo* buscar = arv_busca(arvore, Camelcase(bus));

                        if(buscar)
                        {
                            printf(" O(A) Cliente %s esta aqui !\n",bus);
                        }
                        else
                        {
                            printf(" O(A) Cliente %s nao esta aqui. TENTE NOVAMENTE OU VEJA NA IMPRESSAO SE ESTA\n", bus);
                        }

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³              [1] - Voltar para as opcoes                   ³\n");
                        printf("\t\t\t³              [2] - Menu Inicial                            ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf(" \nDigite sua opcao: ");
                        scanf(" %d",&controlCASE1);
                        if(controlCASE1 == 2)
                        {
                            aux = 4;
                            controlCASE1 = aux;
                        }
                        system("cls");
                    }
                    else if(aux == 3)
                    {

                        setbuf(stdin, NULL);
                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³            IMPRESSAO DOS DADOS CADASTRADOS.                ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        arv_imprime(arvore);

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³              [1] - Voltar para as opcoes                   ³\n");
                        printf("\t\t\t³              [2] - Menu Inicial                            ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf(" \nDigite sua opcao: ");
                        scanf(" %d",&controlCASE1);
                        if(controlCASE1 == 3)
                        {
                            aux = 4;
                            controlCASE1 = aux;
                        }
                        system("cls");
                    }
                    else if(aux == 4)
                    {

                        setbuf(stdin, NULL);

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³            ENVIAR DADOS PARA O ARQUIVO.                    ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");


                        arv_inserirArquivo_clienteCadastrado(arvore);
                        printf("Dados inseridos no arquivo\n");
                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³              [1] - Voltar para as opcoes                   ³\n");
                        printf("\t\t\t³              [2] - Menu Inicial                            ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf(" \nDigite sua opcao: ");
                        scanf(" %d",&controlCASE1);
                        if(controlCASE1 == 1)
                        {
                            aux = 4;
                            controlCASE1 = aux;
                        }
                        system("cls");
                    }
                    else if(aux == 5)
                    {
                        // VOLTA AO MENU INICIAL
                        break;
                    }
                }
                while((controlCASE1 != 5 && controlCASE1 != 1) || aux != 5);
                system("cls");
                break;

            case 3:
                do
                {

                    printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                    printf("\t\t\t³              [1] - Realizar novos Agendamento              ³\n");
                    printf("\t\t\t³              [2] - Clientes Agendados                      ³\n");
                    printf("\t\t\t³              [3] - Menu Inicial                            ³\n");
                    printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                    printf(" \n\nDigite sua opcao: ");
                    scanf(" %d",&aux);
                    printf("\n");
                    if(aux == 1)
                    {
                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³                           NOVO AGENDAMENTO                 ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                        printf("\n DIGITE O NOME DO CLIENTE: ");
                        scanf(" %120[^\n]", nome);
                        nova_consulta(arv_busca(arvore,Camelcase(nome)));
                        Sleep(2000);

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³              [1] - Voltar para as opcoes                   ³\n");
                        printf("\t\t\t³              [2] - Menu Inicial                            ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf(" \nDigite sua opcao: ");
                        scanf(" %d",&controlCASE1);
                        if(controlCASE1 == 2)
                        {
                            aux = 4;
                            controlCASE1 = aux;
                        }
                        system("cls");
                    }
                    else if(aux == 2)
                    {
                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³                       CLIENTES AGENDADOS                   ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                        setbuf(stdin, NULL);

                        char linha[280];
                        char nomeA[81];
                        char sexoA;
                        char servicoA[81];
                        int diaA,mesA,anoA;
                        int horaA, minutoA;
                        int idadeA;
                        int CPFA;
                        float valor_servA;

                        FILE* fp = fopen("clientesCadastrados/clientesCadastrados.txt","rt");
                        if(fp == NULL)
                        {
                            printf("Arquivo Invalido\n");
                            exit(1);
                        }

                        while(fgets(linha, 280, fp) != NULL)
                        {
                            sscanf(linha, "%s\n  %d\n %c\n %d\n %s\n %d/%d/%d\n %d:%d\n %f\n", nomeA, &CPFA, &sexoA, &idadeA, servicoA, &diaA, &mesA, &anoA, &horaA, &minutoA,&valor_servA);
                            printf(" NOME: %s\n CPF: %d\n SEXO: %c\n IDADE: %d\n SERVICO: %s\n DIA: %d/%d/%d\n HORARIO: %d:%d\n VALOR: %.2f\n-----------\n", nomeA, CPFA, sexoA, idadeA, servicoA, diaA, mesA, anoA, horaA, minutoA, valor_servA);
                        }

                        fclose(fp);

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³              [1] - Voltar para as opcoes                   ³\n");
                        printf("\t\t\t³              [2] - Menu Inicial                            ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf(" \nDigite sua opcao: ");
                        scanf(" %d",&controlCASE2);
                        if(controlCASE2 == 2)
                        {
                            aux = 4;
                            controlCASE2 = aux;
                        }
                        system("cls");
                    }
                    else
                    {
                        //Ir para o menu Inicial
                        break;
                    }
                }
                while((controlCASE2 != 4 && controlCASE2 != 1) || aux != 4);
                system("cls");
                break;

            case 4:
                do
                {
                    printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                    printf("\t\t\t³              [1] - Confirmar Atendimento                   ³\n");
                    printf("\t\t\t³              [2] - Mostrar Atendimento finalizados         ³\n");
                    printf("\t\t\t³              [3] - Menu Inicial                            ³\n");
                    printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                    printf(" \nDigite sua opcao: ");
                    scanf(" %d", &aux);

                    if(aux == 1)
                    {
                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³                      CONFIRMANDO O ATENDIMENTO             ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                        printf("\n DIGITE O NOME DO CLIENTE: ");
                        scanf(" %120[^\n]", nome);

                        atendimento(arv_busca(arvore,Camelcase(nome)));
                        aa_retira(arvore, nome);
                        arv_inserirArquivo_clienteCadastrado(arvore);
                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³              [1] - Voltar para as opcoes                   ³\n");
                        printf("\t\t\t³              [2] - Menu Inicial                            ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf(" \nDigite sua opcao: ");
                        scanf(" %d",&controlCASE3);
                        if(controlCASE3 == 2)
                        {
                            aux = 4;
                            controlCASE3 = aux;
                        }
                        system("cls");
                    }
                    else if(aux == 2)
                    {
                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³                CLIENTES ATENDIDOS E FINALIZADOS            ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        setbuf(stdin, NULL);

                        char linha[280];
                        char nomeO[81];
                        char sexoO;
                        char servicoO[81];
                        int diaO,mesO,anoO;
                        int horaO, minutoO;
                        int idadeO;
                        int CPFA;
                        float valor;
                        char atendimentoO[2];

                        FILE* ok = fopen("AtendimentosOK/AtendimentosOK.txt","rt");
                        if(ok == NULL)
                        {
                            printf("Arquivo Invalido\n");
                            exit(1);
                        }

                        while(fgets(linha, 280, ok) != NULL)
                        {
                            sscanf(linha, "%s\n %d\n %c\n %d\n %s\n %d/%d/%d\n %d:%d\n %f\n %s\n", nomeO, &CPFA, &sexoO, &idadeO, servicoO, &diaO, &mesO, &anoO, &horaO, &minutoO, &valor, atendimentoO);
                            printf(" NOME: %s\n CPF: %d\n SEXO: %c\n IDADE: %d\n SERVICO: %s\n DIA: %d/%d/%d\n HORARIO: %d:%d\n VALOR: %.2f\n ATENDIDO: %s\n\n-------------\n", nomeO, CPFA, sexoO, idadeO, servicoO, diaO, mesO, anoO, horaO, minutoO,valor,atendimentoO);
                        }


                        fclose(ok);

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³              [1] - Voltar para as opcoes                   ³\n");
                        printf("\t\t\t³              [2] - Menu Inicial                            ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf(" \nDigite sua opcao: ");
                        scanf(" %d",&controlCASE3);
                        if(controlCASE3 == 2)
                        {
                            aux = 4;
                            controlCASE3 = aux;
                        }
                        system("cls");
                    }
                    else
                    {
                        // VOLTA AO MENU INICIAL
                        break;
                    }
                }
                while((controlCASE3 != 4 && controlCASE3 != 1) || aux != 4);
                system("cls");
                break;

            case 5:
                do
                {

                    printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                    printf("\t\t\t³              [1] - Buscar valor total do balanco por servico           ³\n");
                    printf("\t\t\t³              [2] - Imprimir balanco diario                             ³\n");
                    printf("\t\t\t³              [3] - Menu Inicial                                        ³\n");
                    printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                    printf(" \n Digite sua opcao: ");
                    scanf(" %d", &aux);

                    if(aux == 1)
                    {
                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³                        BUSCA DE VALOR PELO SERVICO                   ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");


                        printf(" INFORME O SERVICO: ");
                        char serv[21];
                        strcpy(serv, Camelcase(String()));
                        buscar_valor_pelo_servico(Camelcase(serv));

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³              [1] - Voltar para as opcoes                   ³\n");
                        printf("\t\t\t³              [2] - Menu Inicial                            ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf(" \nDigite sua opcao: ");
                        scanf(" %d",&controlCASE5);
                        if(controlCASE5 == 2)
                        {
                            aux = 4;
                            controlCASE5 = aux;
                        }
                        system("cls");
                    }
                    else if(aux == 2)
                    {
                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³                       VALOR TOTAL DO SERVICOS                        ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        setbuf(stdin, NULL);
                        printf("\n");
                        total_servico();

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                        printf("\t\t\t³              [1] - Voltar para as opcoes                   ³\n");
                        printf("\t\t\t³              [2] - Menu Inicial                            ³\n");
                        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                        printf(" \nDigite sua opcao: ");
                        scanf(" %d",&controlCASE5);
                        if(controlCASE5 == 2)
                        {
                            aux = 4;
                            controlCASE5 = aux;
                        }
                        system("cls");
                    }
                    else
                    {
                        // VOLTA AO MENU INICIAL
                        break;
                    }
                }
                while((controlCASE5 != 4 && controlCASE5 != 1) || aux != 4);
                system("cls");
                break;

            case 6:
                printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                printf("\t\t\t³       OBRIGADO POR FAZER PARTE DA NOSSA CLINICA DE ESTETICA          ³\n");
                printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                Sleep(2000);
                system("cls");
                printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                printf("\t\t\t³                 O SISTEMA ESTA SENDO FINALIZADO                      ³\n");
                printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                Sleep(2000);
                system("cls");
                printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                printf("\t\t\t³                           ATE MAIS!                                  ³\n");
                printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

                arv_libera(arvore);

                Sleep(2000);
                system("cls");
                break;

            default:
                printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                printf("\t\t\t³                  OPCAO INVALIDA, TENTE NOVAMENTE!                      ³\n");
                printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                Sleep(2000);
                system("cls");
            }
        }
        while(controlMENU != 6);
        system("cls");
    }
    else
    {
        printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
        printf("\t\t\t³              SENHA INCORRETA! O SISTEMA VAI SER DESLIGADO              ³\n");
        printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
        Sleep(2000);
        system("cls");
    }

    return 0;
}
