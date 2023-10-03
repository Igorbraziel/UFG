dados = dict()
funcionario = list()

qtd = int(input())

mediaIdade = mediaFilhos = k1 = k2 = k3 = k4 = 0

while qtd > 0:
    dados['matricula'] = int(input())
    dados['idade'] = int(input())
    dados['numFilhos'] = int(input())
    dados['sexo'] = str(input()).upper()
    dados['salário'] = float(input())
    mediaIdade += dados['idade']
    mediaFilhos += dados['numFilhos']
    funcionario.append(dados.copy())
    dados.clear()
    qtd -= 1

mediaIdade /= len(funcionario)
mediaFilhos /= len(funcionario)

for p in funcionario:
    if p['idade'] > mediaIdade and p['salário'] > 3600:
        k1 += 1
    if p['sexo'] == 'F' and p['numFilhos'] > mediaFilhos:
        k2 += 1
    if p['sexo'] == 'M' and p['numFilhos'] > mediaFilhos:
        k3 += 1
    if p['idade'] > 47 and p['salário'] / (p['numFilhos'] + 1) < 2400:
        k4 += 1

print(k1, k2, k3, k4)
    
