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


    printf("\t\t\t������������������������������������������������������������Ŀ\n");
    printf("\t\t\t�                        BEM VINDO(A)                        �\n");
    printf("\t\t\t�                  DIWEL CLINICA DE ESTETICA                 �\n");
    printf("\t\t\t��������������������������������������������������������������\n");

    printf("\t\t\t������������������������������������������������������������Ŀ\n");
    printf("\t\t\t�                        ---CREDITOS---                      �\n");
    printf("\t\t\t�    Trabalho para a dis. de Alg. e Estruturas de Dados 2    �\n");
    printf("\t\t\t�    Desenvolvido por: Bruno Wellington e Dimona Laquis      �\n");
    printf("\t\t\t�         Rio grande do Norte, Maio de 2021, 3 Periodo       �\n");
    printf("\t\t\t��������������������������������������������������������������\n");

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
            printf("\t\t\t����������������������������������������������Ŀ\n");
            printf("\t\t\t�               1- Servicos Ofertado           �\n");
            printf("\t\t\t�               2- Cliente                     �\n");
            printf("\t\t\t�               3- Agendamento                 �\n");
            printf("\t\t\t�               4- Atendimento                 �\n");
            printf("\t\t\t�               5- Balanco diario              �\n");
            printf("\t\t\t�               6- Sair do Sistema             �\n");
            printf("\t\t\t������������������������������������������������\n");
            printf(" \n Digite sua opcao: ");
            scanf(" %d", &controlMENU);
            system("cls");

            setbuf(stdin, NULL);

            switch(controlMENU)
            {
            case 1:
                do
                {
                    printf("\t\t\t������������������������������������������������������������Ŀ\n");
                    printf("\t\t\t�              [1] - Conheca nossos Servicos                 �\n");
                    printf("\t\t\t�              [2] - Menu Inicial                            �\n");
                    printf("\t\t\t��������������������������������������������������������������\n");

                    printf(" \n Digite sua opcao: ");
                    scanf(" %d", &aux);

                    system("cls");
                    if(aux == 1)
                    {
                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�        DIWEL CLINICA DE ESTETICA - SERVICOS OFERTADOS      �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�                      Limpeza: R$ 50,00                     �\n");
                        printf("\t\t\t�                      Depilacao a cera: R$ 85,00            �\n");
                        printf("\t\t\t�                      Depilacao a laser: R$ 180,00          �\n");
                        printf("\t\t\t�                      Pelling: R$ 68,00                     �\n");
                        printf("\t\t\t�                      Massagem: R$ 200,00                   �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�              [1] - Voltar para as opcoes                   �\n");
                        printf("\t\t\t�              [2] - Menu Inicial                            �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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
                    printf("\t\t\t������������������������������������������������������������Ŀ\n");
                    printf("\t\t\t�              [1] - Cadastrar novo cliente                  �\n");
                    printf("\t\t\t�              [2] - Buscar cliente                          �\n");
                    printf("\t\t\t�              [3] - Impressao da lista de cliente           �\n");
                    printf("\t\t\t�              [4] - Arquivar dados Cadastrados              �\n");
                    printf("\t\t\t�              [5] - Menu Inicial                            �\n");
                    printf("\t\t\t��������������������������������������������������������������\n");

                    printf(" \n Digite sua opcao: ");
                    scanf(" %d", &aux);
                    system("cls");
                    if(aux == 1)
                    {
                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�                    CADASTRANDO NOVO CLIENTE                �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�              [1] - Voltar para as opcoes                   �\n");
                        printf("\t\t\t�              [2] - Menu Inicial                            �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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
                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�                BUSCA DE CLIENTES CADASTRADOS               �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�              [1] - Voltar para as opcoes                   �\n");
                        printf("\t\t\t�              [2] - Menu Inicial                            �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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
                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�            IMPRESSAO DOS DADOS CADASTRADOS.                �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

                        arv_imprime(arvore);

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�              [1] - Voltar para as opcoes                   �\n");
                        printf("\t\t\t�              [2] - Menu Inicial                            �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�            ENVIAR DADOS PARA O ARQUIVO.                    �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");


                        arv_inserirArquivo_clienteCadastrado(arvore);
                        printf("Dados inseridos no arquivo\n");
                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�              [1] - Voltar para as opcoes                   �\n");
                        printf("\t\t\t�              [2] - Menu Inicial                            �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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

                    printf("\t\t\t������������������������������������������������������������Ŀ\n");
                    printf("\t\t\t�              [1] - Realizar novos Agendamento              �\n");
                    printf("\t\t\t�              [2] - Clientes Agendados                      �\n");
                    printf("\t\t\t�              [3] - Menu Inicial                            �\n");
                    printf("\t\t\t��������������������������������������������������������������\n");
                    printf(" \n\nDigite sua opcao: ");
                    scanf(" %d",&aux);
                    printf("\n");
                    if(aux == 1)
                    {
                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�                           NOVO AGENDAMENTO                 �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");
                        printf("\n DIGITE O NOME DO CLIENTE: ");
                        scanf(" %120[^\n]", nome);
                        nova_consulta(arv_busca(arvore,Camelcase(nome)));
                        Sleep(2000);

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�              [1] - Voltar para as opcoes                   �\n");
                        printf("\t\t\t�              [2] - Menu Inicial                            �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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
                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�                       CLIENTES AGENDADOS                   �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");
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

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�              [1] - Voltar para as opcoes                   �\n");
                        printf("\t\t\t�              [2] - Menu Inicial                            �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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
                    printf("\t\t\t������������������������������������������������������������Ŀ\n");
                    printf("\t\t\t�              [1] - Confirmar Atendimento                   �\n");
                    printf("\t\t\t�              [2] - Mostrar Atendimento finalizados         �\n");
                    printf("\t\t\t�              [3] - Menu Inicial                            �\n");
                    printf("\t\t\t��������������������������������������������������������������\n");
                    printf(" \nDigite sua opcao: ");
                    scanf(" %d", &aux);

                    if(aux == 1)
                    {
                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�                      CONFIRMANDO O ATENDIMENTO             �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");
                        printf("\n DIGITE O NOME DO CLIENTE: ");
                        scanf(" %120[^\n]", nome);

                        atendimento(arv_busca(arvore,Camelcase(nome)));
                        aa_retira(arvore, nome);
                        arv_inserirArquivo_clienteCadastrado(arvore);
                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�              [1] - Voltar para as opcoes                   �\n");
                        printf("\t\t\t�              [2] - Menu Inicial                            �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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
                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�                CLIENTES ATENDIDOS E FINALIZADOS            �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�              [1] - Voltar para as opcoes                   �\n");
                        printf("\t\t\t�              [2] - Menu Inicial                            �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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

                    printf("\t\t\t������������������������������������������������������������������������Ŀ\n");
                    printf("\t\t\t�              [1] - Buscar valor total do balanco por servico           �\n");
                    printf("\t\t\t�              [2] - Imprimir balanco diario                             �\n");
                    printf("\t\t\t�              [3] - Menu Inicial                                        �\n");
                    printf("\t\t\t��������������������������������������������������������������������������\n");
                    printf(" \n Digite sua opcao: ");
                    scanf(" %d", &aux);

                    if(aux == 1)
                    {
                        printf("\t\t\t����������������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�                        BUSCA DE VALOR PELO SERVICO                   �\n");
                        printf("\t\t\t������������������������������������������������������������������������\n");


                        printf(" INFORME O SERVICO: ");
                        char serv[21];
                        strcpy(serv, Camelcase(String()));
                        buscar_valor_pelo_servico(Camelcase(serv));

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�              [1] - Voltar para as opcoes                   �\n");
                        printf("\t\t\t�              [2] - Menu Inicial                            �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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
                        printf("\t\t\t����������������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�                       VALOR TOTAL DO SERVICOS                        �\n");
                        printf("\t\t\t������������������������������������������������������������������������\n");

                        setbuf(stdin, NULL);
                        printf("\n");
                        total_servico();

                        printf("\n");
                        printf("\n");
                        printf("\n");

                        printf("\t\t\t������������������������������������������������������������Ŀ\n");
                        printf("\t\t\t�              [1] - Voltar para as opcoes                   �\n");
                        printf("\t\t\t�              [2] - Menu Inicial                            �\n");
                        printf("\t\t\t��������������������������������������������������������������\n");

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
                printf("\t\t\t����������������������������������������������������������������������Ŀ\n");
                printf("\t\t\t�       OBRIGADO POR FAZER PARTE DA NOSSA CLINICA DE ESTETICA          �\n");
                printf("\t\t\t������������������������������������������������������������������������\n");
                Sleep(2000);
                system("cls");
                printf("\t\t\t����������������������������������������������������������������������Ŀ\n");
                printf("\t\t\t�                 O SISTEMA ESTA SENDO FINALIZADO                      �\n");
                printf("\t\t\t������������������������������������������������������������������������\n");
                Sleep(2000);
                system("cls");
                printf("\t\t\t����������������������������������������������������������������������Ŀ\n");
                printf("\t\t\t�                           ATE MAIS!                                  �\n");
                printf("\t\t\t������������������������������������������������������������������������\n");

                arv_libera(arvore);

                Sleep(2000);
                system("cls");
                break;

            default:
                printf("\t\t\t������������������������������������������������������������������������Ŀ\n");
                printf("\t\t\t�                  OPCAO INVALIDA, TENTE NOVAMENTE!                      �\n");
                printf("\t\t\t��������������������������������������������������������������������������\n");
                Sleep(2000);
                system("cls");
            }
        }
        while(controlMENU != 6);
        system("cls");
    }
    else
    {
        printf("\t\t\t������������������������������������������������������������������������Ŀ\n");
        printf("\t\t\t�              SENHA INCORRETA! O SISTEMA VAI SER DESLIGADO              �\n");
        printf("\t\t\t��������������������������������������������������������������������������\n");
        Sleep(2000);
        system("cls");
    }

    return 0;
}
