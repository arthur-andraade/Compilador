#include "analisador.h"
#include <stdlib.h>
#include<stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

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


int lex(char *instrucao, char *lexema){

    int contador = 0;
    int tamanhoLexema = 0;
    classeCaractares analiseCaracter;

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
            return pesquisa(lexema);
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
            return 1;
            break;

        //Default
        default:
            return 0;
            break;
    }
}




