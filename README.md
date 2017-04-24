# Keno

## Sobre o jogo

<p>   Keno é um jogo comumente encontrado em casinos e é semelhante a um bingo. O jogador escolhe até 15 números entre 1 e 80.

A casa então sorteia 20 números aleatoriamente e o pagamento é feito de acordo com a quantidade de acertos.</p>

## Como executar

| #       | Descrição           | Comando  |
| :------------- |:-------------| :-----|
| 1      | Compilar | ```$ make``` |
| 2      | Executar   | ```$ ./build/keno_game <arquivo_da_aposta>``` |

## Possíveis erros

```console
Arquivo inválido! Por favor, tente novamente
```
<br>
Arquivos inválidos não serão lidos pelo jogo. Um arquivo é considerado ilegível se possuir número de linhas diferente de 3.


``` A aposta não é um valor válido, por favor, aposte entre R$ 1,00 - 10.000,00  ```<br>
Os valores da aposta, ou seja, a primeira linha do arquivo lido, deve estar entre 1 e 10000 reais para ser considerado uma aposta válida.

## Autoria

Desenvolvido por Gabriel Araújo de Souze (<gabriel_feg@hotmail.com >) e Mayra Dantas de Azevedo (<mayradazevedo@gmail.com >)

2017.1

&copy; IMD/UFRN 2017.
