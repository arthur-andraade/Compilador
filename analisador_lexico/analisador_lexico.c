#include <stdlib.h>
#include <stdio.h>
#include "analisador.h"
#include <string.h>
#include <ctype.h>

int main()
{
    
    char instrucao[] ="14";
    char lexema[100];
    int token = 0;
    token = lex(instrucao,lexema);

    printf("tokens --> %d", token);
    return 0;
}
