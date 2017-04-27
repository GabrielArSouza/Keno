# Keno

## Sobre o jogo

<p>Keno é um jogo comumente encontrado em casinos e é semelhante a um bingo. O jogador escolhe até 15 números entre 1 e 80 e seu ganho é proporcional ao número de acertos.

A casa sorteia 20 números aleatoriamente e o pagamento é feito de acordo com a tabela de pagamentos, que é gerada a partir do número de apostas. Por exemplo, para 3 números, o pagamento segue a seguinte tabela:</p>

| Acertos     | Fator multiplicador           |
| :------------- |:-------------|
| 0      | 0 |
| 1      | 1   | 
| 2      | 2   |
| 3      | 16   |

## Como executar

| #       | Descrição           | Comando  |
| :------------- |:-------------| :-----|
| 1      | Compilar | ```$ make``` |
| 2      | Executar   | ```$ ./build/keno_game <arquivo_da_aposta>``` |

Durante o jogo, para passar de uma rodada para outra basta pressionar a tecla ENTER.

## Como fazer uma aposta

1º Crie um arquivo .txt (ou edite os criados na pasta data);<br/>
2º Edite o arquivo com os dados da sua posta;<br/>

Uma arquivo com aposta válida deve ser escrito da forma:

**<Valor_da_aposta>** ( Número real entre 1 - 10.000 )<br/>
**<Quantidade_de_rodadas>** ( Número natural entre 1 - 10 )<br/>
**<Números_que_se_deseja_apostar>** ( No máximo 15 números naturais, separados por um espaço e entre 1 - 80 )<br/>

#### Exemplo de aposta
```
5000 
5
1 5 9 20 12 45 77 22 54
```

<p>Nessa aposta, o jogador ta entrando com R$5000.00, distribuindo essa valor em 5 rodadas e apostando os números da última linha.
Se o arquivo conter números fora do intervalo 1 - 80, eles serão desconsiderados, caso algum campo não contenha valores aceitados pelo
jogo, alguns erros podem ser exibidos, estes podem ser conferidos na sessão abaixo. </p> 

## Possíveis erros

```Arquivo inválido! Por favor, tente novamente.```

Arquivos inválidos não serão lidos pelo jogo. Um arquivo é considerado ilegível se possuir número de linhas diferente de 3.


```A aposta não é um valor válido! Por favor, aposte entre R$ 1,00 - 10.000,00.``` 

O valor da aposta, ou seja, a primeira linha do arquivo lido, deve estar entre 1 e 10000 reais para ser considerado uma aposta válida.



```O número de rodadas não é válido! Por favor, aposte entre 1 - 10 rodadas.``` 

A segunda linha do arquivo, que representa o número de rodadas, deve conter um número que está entre 1 e 10 reais para ser considerada como uma aposta válida.



```O número de números apostados é inválido! Por favor, aposte ente 1 - 15 números.``` 

Para ser considerada como uma aposta válida, a terceira linha do arquivo deve conter de 1 a 15 números, sendo estes os números que o jogador quer apostar.

## Autoria

Desenvolvido por Gabriel Araújo de Souza (<gabriel_feg@hotmail.com >) e Mayra Dantas de Azevedo (<mayradazevedo@gmail.com >)

2017.1

&copy; IMD/UFRN 2017.
