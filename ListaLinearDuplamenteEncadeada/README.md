# Lista Linear Duplamente Encadeada (LLDE) em C

Este repositório contém uma implementação didática de uma **Lista Linear Duplamente Encadeada (LLDE)** desenvolvida na linguagem C. Cada nó nesta estrutura armazena um valor inteiro e possui dois ponteiros: um para o próximo elemento e outro para o elemento anterior, permitindo o percurso bidirecional de forma eficiente.

## 📂 Estrutura do Projeto

O projeto está organizado nos seguintes arquivos:

* **`ListaLinearDE.h`**: Arquivo de cabeçalho contendo a definição das estruturas (`TNo` e `Tllde`) e os protótipos de todas as funções disponíveis.
* **`ListaLinearDE.c`**: Implementação das funções de manipulação da estrutura de dados.
* **`main.c`**: Código de teste que exemplifica operações de inserção, exibição, consulta e remoção de elementos.

---

## 🛠️ Especificação das Estruturas e Funções

### Estruturas de Dados

```c
// Estrutura que representa cada nó da lista
typedef struct No {
    struct No* anterior;
    int dado;
    struct No* proximo;
} TNo;

// Estrutura de controle da lista
typedef struct llde {
    int tamanho;
    TNo* inicio;
    TNo* fim;
} Tllde;
