#include "analisador.h"
#include <stdlib.h>
#include<stdio.h>
#include <ctype.h>
#include <string.h>

//Tokens 
int pesquisa(char *lexema){

    if( strncmp(lexema,"int",3) == 0){
        //TIPO_INT
        return 2;
    }else if (strncmp(lexema,"char",4) == 0)
    {
        //TIPO_CHAR
        return 3;
    }else if(strncmp(lexema,"float",5) == 0){
        //TIPO_FLOAT
        return 4;
    }else{
        //Identificador
        return 5;
    }
}

classeCaractares obtemCaracter(char c){
    
    //Auxiliar
    classeCaractares analiseCaracter;

    if(isdigit(c)){
        analiseCaracter.classe = 'd';
    }else if(isalpha(c)){
        analiseCaracter.classe = 'l';
    }else{
        analiseCaracter.classe = 'n';
    }
    return analiseCaracter;
}


void lex(char *instrucao, char *lexema){

    int contador = 0;
    int tamanhoLexema = 0;
    classeCaractares analiseCaracter;
    int tamanhoInstrucao = strlen(instrucao);

    
    while(contador < tamanhoInstrucao){

        
        analiseCaracter = obtemCaracter(instrucao[contador]);

        switch (analiseCaracter.classe)
        {
            
            //Letra
            case 'l':
                
                //Adicionando caracter
                lexema[tamanhoLexema] = instrucao[contador];
                tamanhoLexema++;
                contador++;
                analiseCaracter = obtemCaracter(instrucao[contador]);

                while (analiseCaracter.classe == 'l' || analiseCaracter.classe == 'd')
                {
                    //Adicionando caracter
                    lexema[tamanhoLexema] = instrucao[contador];
                    tamanhoLexema++;
                    contador++;
        
                    analiseCaracter = obtemCaracter(instrucao[contador]);
                }
                
                printf("token --> %d \n", pesquisa(lexema));
                reiniciaLexema(&tamanhoLexema, lexema);
                break;

            //Digito
            case 'd':
                
                lexema[tamanhoLexema] = instrucao[contador];
                tamanhoLexema++;
                contador++;
                analiseCaracter = obtemCaracter(instrucao[contador]);
                
                while (analiseCaracter.classe == 'd')
                {
                    //Adicionando caracter
                    lexema[tamanhoLexema] = instrucao[contador];
                    tamanhoLexema++;
                    contador++;
                    analiseCaracter = obtemCaracter(instrucao[contador]);
                }

                //LIT_INT
                printf("token --> %d \n", 1);
                reiniciaLexema(&tamanhoLexema, lexema);
                break;

            //Default tokens não determinados "espaço, atribuição, operadores aritmetricos, etc"
            default:
                printf("token --> %d \n", 0);
                contador++;
                break;
        }
    }
}

void reiniciaLexema(int* tamanho, char*lexema){
   int contador = 0;
   while (contador < *tamanho )
   {    
       lexema[contador] = '\0';
       contador++;
   }
    *tamanho = 0;
}


