# Simulador de Associatividade Adaptativa
Esse programa é um simulador de acesso à memória cache que recebe como entrada os endereços a serem acessados (no formato Hexadecimal). A partir da entrada, ele fará a busca de todos os endereços na cache, utilizando um dos 3  tipos de mapeamento (Direto, Parcialmente Associativo ou Totalmente Associativo). Se a palavra não for encontrada (houver um *miss*), o contador de *miss* será atualizado e a palavra será escrita na cache.


## Troca do tipo de mapeamento
Cada vez que a taxa de *miss* for maior que **X%** (em que X é um percentual definido pelo usuário), o tipo de mapeamento deve ser alterado.

Para este programa, o ciclo dos tipos de mapeamento é:

&rarr; **Direto** &rarr; **Parcialmente Associativo** (com a memória dividida em 4 blocos) &rarr; **Totalmente Associativo** &rarr;

## Compilação e Execução
Para compilar esse programa, tudo o que você precisa fazer é digitar:
```shell
make clean
make
```

E para executá-lo:
```shell
./bin/memory_mapping arquivo_com_endereços taxa_maxima_de_miss [tamanho_da_cache]
```

Onde o `arquivo_com_endereços` representa um arquivo com todos os endereços a serem buscados pelo programa (um por linha), a `taxa_maxima_de_miss` é o percentual (em ponto flutuate) que definirá a troca do tipo de mapeamento e o `tamanho_da_cache` é um parâmetro opcional para definir o tamanho da memória cache (no mínimo 4 posições), caso não seja informado, ele assumirá um valor padrão de 16 posições.

### Exemplo de um arquivo de entrada válido
>input.dat

```
0x0E
0xED
0x39
0x39
0xAF
0x34
0x3F
0x39
0xED
0x3F
0x45
0x13
0x3F
0xAF
```

## Autor
Esse projeto foi desenvolvido por **Elton de Souza Vieira**
 - [GitHub](https://github.com/eltonvs)
 - [Webpage](http://www.eltonviana.com)
