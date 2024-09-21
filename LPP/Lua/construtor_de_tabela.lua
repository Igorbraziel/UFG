days = {'SEG','TER','QUA','QUI','SEX'}
person = {'Pedro'; 25; true; {}}


--Podemos usar variáveis na criação de uma tabela
nome = 'Pedro'
idade = 25
socio = true
endereco = {}
-- pack
person = {idade, nome, endereco, socio}
print(person[1])
print(person[2])
print(person[3])
print(person[4])


--Podemos informar o índice explicitamente na criação das tabelas
days = {
[2] = 'TER',
[3] = 'QUA',
[5] = 'SEX',
[1] = 'SEG',
[4] = 'QUI',
}

person = {
['nome'] = 'Pedro',
['idade'] = 24+1,
['socio'] = true,
['endereco'] = {
['rua'] = 'Rua 123',
['cep'] = '37362-392',
},
}