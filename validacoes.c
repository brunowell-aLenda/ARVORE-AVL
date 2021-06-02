#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h> // BIBLIOTECA DE COLOCAR A PRIMEIRA LETRA MAISCULA
#include "validacoes.h"


void limpa_buffer(void){
    int valorLido; /* valorLido deve ser int! */
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

int Inteiro_CPF(void){
    int umInt, nValoresLidos;
    nValoresLidos = scanf(" %d", &umInt);
    while ((nValoresLidos == 0) || (umInt < 0)) { //Nenhum inteiro foi lido
        limpa_buffer();
        printf("  ENTRADA INCORRETA. DIGITE UM VALOR INTEIRO(sem traços e pontos): ");
        nValoresLidos = scanf(" %d", &umInt);
    }
    limpa_buffer();
    return umInt;
}

int Inteiro(void) {
    int umInt, nValoresLidos;
    nValoresLidos = scanf(" %d", &umInt);
    while ((nValoresLidos == 0) || (umInt < 0)) { //Nenhum inteiro foi lido
        limpa_buffer();
        printf(" ENTRADA INCORRETA. DIGITE UM VALOR INTEIRO: ");
        nValoresLidos = scanf(" %d", &umInt);
    }
    limpa_buffer();
    return umInt;
}

char* String(void) {
    char aux[121];
    scanf(" %120[^\n]", aux);
    int n = strlen(aux);
    char* string = (char*) malloc((n+1)*sizeof(char));
    strcpy(string, aux);
    int i = 0;
    while(string[i] != '\0'){
        if(isdigit(string[i])||(ispunct(string[i]))){
            printf("\n  ENTRADA INCORRETA. DIGITE SOMENTE CARACTERES: ");
            return String();
        }
        i++;
    }
    return string;
}

static char* recebe(){
    char* valor = (char*) malloc(10*sizeof(char));
    int i = 0;
    scanf(" %9[^\n]", valor);
    while(valor[i] != '\0'){
        if(valor[i] == ','){
            valor[i] = ':';
            break;
        }
        i++;
    }
    return valor;
}

float LeFloat(void) {
    float umFloat;
    int nValoresLidos;
    nValoresLidos = sscanf(recebe()," %f", &umFloat);
    while ((nValoresLidos == 0) || (umFloat < 0)) { //Nenhum inteiro foi lido
        limpa_buffer();
        printf(" ENTRADA INCORRETA. DIGITE UM VALOR REAL: ");
        nValoresLidos = sscanf(recebe()," %f", &umFloat);
    }
    limpa_buffer();
    return umFloat;
}

char* Camelcase(char* strings){//Colocar a primeira letra maiscula
	int i = 0;
	while(strings[i] != '\0'){

		if(strings[0] != ' '){
			strings[0] = toupper(strings[0]);
		}
		if(strings[i-1] == ' ' && strings[i-1] != '\0'){
			strings[i] = toupper(strings[i]);
		}else{
			strings[i] = tolower(strings[i]);
		}
		i++;
	}
	return strings;
}

char Valida_Sexo(void){
    int nlidos;
    char sexo;
    nlidos = scanf(" %c", &sexo);
    sexo = toupper(sexo);
    while((nlidos != 0) && ((sexo != 'M') && (sexo != 'F'))){
        limpa_buffer();
        printf(" INFORME APENAS O CARACTERE M OU F: ");
        nlidos = scanf(" %c", &sexo);
        sexo = toupper(sexo);
    }
    limpa_buffer();
    return sexo;
}
