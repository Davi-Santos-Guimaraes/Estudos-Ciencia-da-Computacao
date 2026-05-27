# exercicio-structfuncoes-c
Exercício de revisão sobre structs, funções e passagem de parâmetros em C.

Aqui está um plano para criar um exercício de revisão sobre os conceitos de struct,
funções, e passagem de parâmetros por valor e por referência na linguagem C. O
exercício será armazenado em um repositório no GitHub.
1. Estrutura do Exercício
Objetivo
O objetivo do exercício é reforçar os seguintes conceitos:
1. Criação e uso de structs.
2. Implementação de funções para manipular dados.
3. Diferença entre passagem de parâmetros por valor e por referência.
Enunciado do Exercício
Crie um programa em C que gerencie as informações de estudantes. O programa deve
permitir:
1. Inserir dados de um estudante (nome, idade e nota).
2. Atualizar a nota de um estudante.
3. Mostrar as informações de um estudante.
Detalhes:
1. Use uma struct chamada Estudante que contenha:
o Nome (string com no máximo 50 caracteres),
o Idade (inteiro),
o Nota (float).
2. Crie as seguintes funções:
o void inserirDados(Estudante *e): Insere os dados de um estudante.
(passagem por referência)
o void atualizarNota(Estudante *e, float novaNota): Atualiza a
nota de um estudante. (passagem por referência)
o void mostrarDados(Estudante e): Mostra os dados de um estudante.
(passagem por valor)
Regras:
 Utilize as funções para manipular a struct, evitando o uso direto das variáveis da
struct no main.
 Crie exemplos no main para testar o funcionamento do programa. 
