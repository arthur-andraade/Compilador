import re
arquivo = open('entrada.txt','r')

tokens = {
    'int': 0,
    'char':0,
    'double': 0,
    'float': 0,
    'literal_int':0
}
variaveis = 0

expresaoParaVariavel = re.compile('[a-z]\w*')
expressaoParaDouble = re.compile('double')
expressaoParaChar = re.compile('char')
expressaoParaFloat = re.compile('float')
expressaoParaInt = re.compile('int')
expresaoParaLiteral = re.compile('\d+')

for linha in arquivo:
    resultado = expresaoParaVariavel.findall(linha)
    
    for lexema in resultado:
        identificadorVariavel = True
        for token in tokens:
            if(lexema == token):
                identificadorVariavel = False
                break
        if(identificadorVariavel):
            variaveis = variaveis + 1
            
    resultado = expressaoParaInt.findall(linha)
    tokens['int'] = len(resultado) + tokens['int']

    resultado = expressaoParaChar.findall(linha)
    tokens['char'] = len(resultado) + tokens['char']

    resultado = expressaoParaDouble.findall(linha)
    tokens['double'] = len(resultado) + tokens['double']

    resultado = expressaoParaFloat.findall(linha)
    tokens['float'] = len(resultado) + tokens['float'] 

    resultado = expresaoParaLiteral.findall(linha)
    tokens['literal_int'] = len(resultado) + tokens['literal_int']

print(tokens)
print(variaveis)
arquivo.close()