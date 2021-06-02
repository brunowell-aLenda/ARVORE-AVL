#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct cliente Cliente;
typedef struct arvno ArvNo;
typedef struct arv Arv;

Arv* arv_cria(void);

ArvNo* arvno_cria(Cliente* a);

Cliente* cria_clin(char* nome, int CPF, char sexo, int idade, char* servico, int dia, int mes, int ano, int hora, int minuto);

void arv_insere(Arv* a, ArvNo* no);  // inserir dados na arvore *

void arv_imprime(Arv* a); // imprimir a arvore completa

void imprime_cliente(Cliente* a); // imprimir a arvore mas setando a informação que deseja *

ArvNo* arv_busca(Arv* a, char* nome); // buscar cliente na arvore *

void nova_consulta(ArvNo* no);  // realizar uma novo agendamento dizendo o procedimento e o horario *


void arv_inserirArquivo_clienteCadastrado(Arv* a); // inserir todos os clientes cadastrados no arquivo *

void atendimento(ArvNo* a);// realizar A CONFIRMAÇÃO DA consulta dizendo DIZENDO SE JÁ CONCLUIU *

void carrega_dados_clin(Arv* a); //carrega dados do cliente *

void total_servico(); //Mostrar a soma total de serviços realizados*

void buscar_valor_pelo_servico(char* serv); //Mostrar soma da busca de serviços*

void arv_libera (Arv* a); // liberar  arvore

void aa_retira(Arv* a, char* nome); // retirada dos clientes *


#endif // CLIENTE_H_INCLUDED
