#include "analisador.h"

int main()
{
    //Instrução para analise
    char instrucao[] ="int variavel = 0;";
    char lexema[100];
    lex(instrucao,lexema);

    return 0;
}
