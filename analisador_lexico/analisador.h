#ifndef ANALISADOR_H
#define ANALISADOR_H


// LETRA - DIGITO
typedef struct classeCaractares{
    char classe;
} classeCaractares;

//Assinaturas das funções
int pesquisa(char *lexema);
classeCaractares obtemCaracter(char c);
void acrescentaCararacter(char *lexema, char caracter, int *tamanhoLexema);
int lex(char *instrucao, char *lexema);

#endif

