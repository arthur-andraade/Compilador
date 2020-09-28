%option noyywrap

%{
#include <stdio.h>
int numero_de_linhas = 0;
%}

PALAVRA_RESERVADA	"and"|"array"|"begin"|"case"|"const"|"div"|"do"|"downto"|"else"|"file"|"for"|"forward"|"function"|"goto"|"if"|"in"|"label"|"main"|"mod"|"nil"|"not"|"of"|"or"|"packed"|"procedure"|"program"|"record"|"repeat"|"set"|"then"|"to"|"type"|"until"|"var"|"while"|"with"
IDENTIFICADORES_PADRAO "abs"|"arctan"|"boolean"|"char"|"chr"|"cos"|"dispose"|"eof"|"eoln"|"exp"|"false"|"get"|"input"|"integer"|"ln"|"maxint"|"new"|"odd"|"ord"|"output"|"page"|"pred"|"put"|"read"|"readln"|"real"|"reset"|"rewrite"|"round"|"sin"|"sqr"|"sqrt"|"succ"|"text"|"true"|"trunc"|"write"|"writeln"
SIMBOLOS_ESPECIAIS "+"|"-"|"/"|"*"|"<"|">"|"["|"]"|"."|","|":="|":"|";"|"("|")"|"<>"|"<="|">="|".."|"^"
SIMBOLOS_ESPECIAIS_FORA_DO_PADRAO "~"|"&"|"|"|"!"|"#"|"%"
PALAVRA_RESERVADAS_FORA_DO_PADRAO "define"|"extern"|"external"|"module"|"otherwise"|"private"|"public"|"static"|"univ"
IDENTIFICADORES_PREDECLARADOS_FORA_DO_PADRAO	"FALSE"|"TRUE"|"addr"|"alf"|"append"|"argc"|"argv"|"arshft"|"asl"|"asr"|"assert"|"bell"|"card"|"clock"|"close"|"concat"|"date"|"discard"|"double"|"exit"|"expo"|"filesize"|"firstof"|"flush"|"getenv"|"getfile"|"halt"|"in_range"|"index"|"integer16"|"integer32"|"intset"|"land"|"lastof"|"length"|"linelimit"|"lnot"|"longreal"|"lor"|"lshft"|"lsl"|"lsr"|"max"|"maxchar"|"message"|"min"|"minchar"|"minint"|"next"|"null"|"open"|"pack"|"random"|"remove"|"return"|"rshft"|"seed"|"seek"|"shortreal"|"single"|"sizeof"|"stlimit"|"stradd"|"string"|"substr"|"sysclock"|"tab"|"tell"|"time"|"trace"|"trim"|"univ_ptr"|"unpack"|"varying"|"wallclock"|"xor"
%%

{PALAVRA_RESERVADA} 	{printf("PALAVRA RESERVADA ENCONTRADA [%s]\n", yytext);}
{IDENTIFICADORES_PADRAO} 	{printf("IDENTIFICADOR PADRAO ENCONTRADO [%s]\n", yytext);}
{SIMBOLOS_ESPECIAIS} 	{printf("SIMBOLO ESPECIAL ENCONTRADO [%s]\n", yytext);}
{SIMBOLOS_ESPECIAIS_FORA_DO_PADRAO} 	{printf("SIMBOLO ESPECIAL FORA DO PADRAO ENCONTRADO  [%s]\n", yytext);}
{PALAVRA_RESERVADAS_FORA_DO_PADRAO} {printf("PALAVRA RESERVADA FORA DO PADRAO ENCONTRADO [%s]\n", yytext);}
{IDENTIFICADORES_PREDECLARADOS_FORA_DO_PADRAO} { printf("IDENTIFICADOR PREDECLARADO FORA DO PADRAO ENCONTRADO [%s] \n", yytext);}

\n   {numero_de_linhas++;}
.     /* Ignora character*/

<<EOF>> {
            printf("\nNumero de linhas analisados %d", numero_de_linhas);
            exit(0);
        }

%%

int main(int argc, char **argv){

    if(argc < 2){
		printf("ATENCAO\n\tUso:./exercicio2 <entrada.txt>\n");
		exit(1);
	}
	else{
		yyin = fopen(argv[1],"r");
		if(yyin == NULL) {
			printf("Erro ao abrir arquivo [%s]\n",argv[1]);
			exit(1);
		}
		
		yylex();
		
	}
}