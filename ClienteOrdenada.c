// main.c
#include "ListaOrdenada.h"

int main() {
  /*LISTA lista;
  REGISTRO reg;

  // Inicializar a lista
  inicializarLista(&lista);

  // Exibir lista vazia
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  // Inserir elementos na lista
  reg.chave = 9;
  inserirElemListaOrd(&lista, reg);
  reg.chave = 3;
  inserirElemListaOrd(&lista, reg);
  reg.chave = 4;
  inserirElemListaOrd(&lista, reg);
  reg.chave = 1;
  inserirElemListaOrd(&lista, reg);
  reg.chave = 12;
  inserirElemListaOrd(&lista, reg);

  // Exibir lista após inserções
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  // Buscar um elemento na lista
  int pos = buscaSequencial(&lista, 4);
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n", pos);
  
  pos = buscaBinaria(&lista, 4);
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n", pos);
  
  pos = buscaSentinela(&lista, 4);
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n", pos);

  // Excluir alguns elementos da lista
  if (excluirElemLista(&lista, 4)) printf("Exclusao bem sucedida: 4.\n");
  if (excluirElemLista(&lista, 8)) printf("Exclusao bem sucedida: 8 (não existe na lista).\n");
  if (excluirElemLista(&lista, 9)) printf("Exclusao bem sucedida: 9.\n");

  // Exibir lista após exclusões
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  // Reinicializar a lista
  reinicializarLista(&lista);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));*/

  // Inicializar a lista
    LISTA lista;
    inicializarLista(&lista);

    // Adicionar elementos para atingir a capacidade máxima e testar listIsFull
    printf("Inserindo elementos...\n");
    for (int i = 0; i < 55; i++) { // Excede a capacidade inicial (50)
        REGISTRO reg;
        reg.chave = i;
        if (!inserirElemListaOrd(&lista, reg)) {
            printf("Falha ao inserir elemento: %d\n", i);
        } else {
            printf("Inserido: %d\n", reg.chave);
        }
    }
    exibirLista(&lista);

    // Remover elementos para atingir o limiar mínimo e testar lessThanTreshold
    printf("\nRemovendo elementos...\n");
    for (int i = 0; i < 45; i++) { // Reduz a lista para bem abaixo da capacidade inicial
        if (!excluirElemLista(&lista, i)) {
            printf("Falha ao remover elemento: %d\n", i);
        } else {
            printf("Removido: %d\n", i);
        }
    }
    exibirLista(&lista);

    // Exibir informações sobre a lista
    printf("\nCapacidade atual: %d\n", lista.capacidade);
    printf("Número de elementos: %d\n", lista.nroElem);

    return 0;

  return 0;
}
