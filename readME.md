# Implementação da Lista Ordenada em C

Este documento detalha a implementação de uma lista ordenada em C, com foco nas funções de inserção e remoção, além de explicar o uso das funções que ajustam dinamicamente o tamanho da lista.

## Funções de Inserção

### `inserirElemListaOrd`
Essa função insere elementos na lista mantendo a ordem crescente com base na chave.

#### Passos da Implementação:
1. **Verificação de Capacidade**: Antes de inserir, a função verifica se a lista está cheia, chamando `listIsFull` para aumentar sua capacidade, se necessário.
2. **Busca da Posição**: Encontra a posição correta para inserir o novo elemento, mantendo a ordem da lista.
3. **Deslocamento e Inserção**: Move os elementos posteriores para abrir espaço e insere o novo registro na posição encontrada.

#### Relação com `listIsFull`
Ao atingir a capacidade máxima, a função chama `listIsFull` para dobrar a capacidade da lista, permitindo que a inserção seja realizada sem interrupções.

## Funções de Remoção

### `excluirElemListaOrd`
Essa função remove um elemento da lista com base em sua chave.

#### Passos da Implementação:
1. **Busca do Elemento**: Localiza a posição do elemento a ser removido usando busca binária.
2. **Deslocamento**: Após localizar o elemento, desloca os elementos posteriores para preencher o espaço vazio.
3. **Ajuste de Capacidade**: Chama `lessThanTreshold` para reduzir a capacidade da lista caso o número de elementos caia abaixo do limite mínimo.

#### Relação com `lessThanTreshold`
Se o número de elementos na lista for menor ou igual a 25% da capacidade total, a função reduz a capacidade para evitar desperdício de memória.

## Funções de Ajuste Dinâmico

### `listIsFull`
Essa função é chamada quando a capacidade máxima da lista é atingida.

#### Funcionamento:
1. **Realoação de Memória**: Duplica a capacidade da lista usando `realloc`.
2. **Atualização de Metadados**: Ajusta o valor de capacidade para refletir o novo limite.
3. **Mensagem Informativa**: Exibe uma mensagem indicando que a capacidade foi aumentada.

```c
void listIsFull(LISTA* l) {
  if (l->capacidade == l->nroElem) {
    l->A = realloc(l->A, l->capacidade * 2 * sizeof(REGISTRO));
    l->capacidade *= 2;
    printf("\nA lista atingiu sua capacidade máxima. CAPACIDADE AUMENTADA\n");
  }
}
```

### `lessThanTreshold`
Essa função é chamada quando o número de elementos na lista fica muito abaixo da capacidade total.

#### Funcionamento:
1. **Verificação de Limite**: Se o número de elementos for menor ou igual a 25% da capacidade, reduz o tamanho da lista.
2. **Realoação de Memória**: Usa `realloc` para ajustar a capacidade para metade do tamanho atual.
3. **Atualização de Metadados**: Ajusta o valor de capacidade para refletir o novo limite.
4. **Mensagem Informativa**: Exibe uma mensagem indicando que a capacidade foi reduzida.

```c
void lessThanTreshold(LISTA* l) {
  if (l->nroElem <= l->capacidade * MIN_THRESHOLD) {
    l->A = realloc(l->A, l->capacidade * 0.5 * sizeof(REGISTRO));
    l->capacidade *= 0.5;
    printf("\nA lista atingiu sua capacidade mínima. CAPACIDADE REDUZIDA\n");
  }
}
```
# Instruções para Utilizar o Makefile com Target `ted`

Para usar o `Makefile` com o target `ted`, siga estas etapas:

1. **Verifique se o `Makefile` está no diretório do projeto.**  
   O `Makefile` deve ter um target `ted` configurado.

2. **Abra o terminal no diretório do projeto.**

3. **Execute o comando:**
   ```bash
   make ted
   ```

    Isso irá compilar o código.
4. **Para executar basta executar o comando:**
   ```bash
   ./ted
