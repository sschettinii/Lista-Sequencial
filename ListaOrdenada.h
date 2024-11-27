#ifndef LISTA_SEQUENCIAL_ORDENADA_H
#define LISTA_SEQUENCIAL_ORDENADA_H

#include <stdio.h>
#include <stdlib.h>
//#define MAX 50
#define ERRO -1
#define bool int
#define true 1
#define false 0
#define MIN_THRESHOLD 0.25

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct {
  int capacidade;
  REGISTRO* A;
  int nroElem;
} LISTA;

/**
 * @brief Inicialização da lista sequencial (a lista já está criada e é apontada pelo endereço em l).
 * @param l Ponteiro para a lista a ser inicializada.
 */
void inicializarLista(LISTA* l);

/**
 * @brief Exibição da lista sequencial.
 * @param l Ponteiro para a lista a ser exibida.
 */
void exibirLista(LISTA* l);

/**
 * @brief Retornar o tamanho da lista (número de elementos válidos).
 * @param l Ponteiro para a lista.
 * @return Número de elementos válidos na lista.
 */
int tamanho(LISTA* l);

/**
 * @brief Retornar o tamanho em bytes da lista. Não depende do número de elementos usados, pois a alocação é estática.
 * @param l Ponteiro para a lista.
 * @return Tamanho em bytes da estrutura.
 */
int tamanhoEmBytes(LISTA* l);

/**
 * @brief Retornar a chave do primeiro elemento da lista sequencial (caso haja).
 * @param l Ponteiro para a lista.
 * @return Chave do primeiro elemento ou ERRO se a lista estiver vazia.
 */
TIPOCHAVE primeiroElem(LISTA* l);

/**
 * @brief Retornar a chave do último elemento da lista sequencial (caso haja).
 * @param l Ponteiro para a lista.
 * @return Chave do último elemento ou ERRO se a lista estiver vazia.
 */
TIPOCHAVE ultimoElem(LISTA* l);

/**
 * @brief Retornar a chave do elemento na posição n da lista.
 * @param l Ponteiro para a lista.
 * @param n Índice do elemento.
 * @return Chave do elemento ou ERRO se o índice for inválido.
 */
TIPOCHAVE enesimoElem(LISTA* l, int n);

/**
 * @brief Reinicializar a estrutura da lista.
 * @param l Ponteiro para a lista a ser reinicializada.
 */
void reinicializarLista(LISTA* l);

/**
 * @brief Busca sequencial em lista ordenada ou não sem sentinela.
 * @param l Ponteiro para a lista.
 * @param ch Chave a ser buscada.
 * @return Índice do elemento encontrado ou ERRO se não encontrado.
 */
int buscaSequencial(LISTA* l, TIPOCHAVE ch);

/**
 * @brief Busca sequencial em lista com sentinela (vetor criado com MAX+1 posições).
 * @param l Ponteiro para a lista.
 * @param ch Chave a ser buscada.
 * @return Índice do elemento encontrado ou ERRO se não encontrado.
 */
int buscaSentinela(LISTA* l, TIPOCHAVE ch);

/**
 * @brief Busca sequencial em lista com sentinela (vetor criado com MAX+1 posições) considerando a lista ordenada.
 * @param l Ponteiro para a lista.
 * @param ch Chave a ser buscada.
 * @return Índice do elemento encontrado ou ERRO se não encontrado.
 */
int buscaSentinelaOrdenada(LISTA* l, TIPOCHAVE ch);

/**
 * @brief Busca binária em lista ordenada.
 * @param l Ponteiro para a lista.
 * @param ch Chave a ser buscada.
 * @return Índice do elemento encontrado ou ERRO se não encontrado.
 */
int buscaBinaria(LISTA* l, TIPOCHAVE ch);

/**
 * @brief Exclusão do elemento cuja chave seja igual a ch.
 * @param l Ponteiro para a lista.
 * @param ch Chave do elemento a ser excluído.
 * @return true se o elemento foi excluído, false caso contrário.
 */
bool excluirElemLista(LISTA* l, TIPOCHAVE ch);

/**
 * @brief Exclusão do elemento cuja chave seja igual a ch em lista ordenada.
 * @param l Ponteiro para a lista.
 * @param ch Chave do elemento a ser excluído.
 * @return true se o elemento foi excluído, false caso contrário.
 */
bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch);

/**
 * @brief Inserção em lista ordenada usando busca binária permitindo duplicação.
 * @param l Ponteiro para a lista.
 * @param reg Registro a ser inserido.
 * @return true se o elemento foi inserido, false caso contrário.
 */
bool inserirElemListaOrd(LISTA* l, REGISTRO reg);

/**
 * @brief Inserção em lista ordenada usando busca binária sem duplicação.
 * @param l Ponteiro para a lista.
 * @param reg Registro a ser inserido.
 * @return true se o elemento foi inserido, false caso contrário.
 */
bool inserirElemListaOrdSemDup(LISTA* l, REGISTRO reg);

#endif // LISTA_SEQUENCIAL_ORDENADA_H
