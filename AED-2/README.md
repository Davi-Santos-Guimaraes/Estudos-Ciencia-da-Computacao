# AED N2 — Insertion Sort Paralelo na Nuvem

 Este projeto foi desenvolvido para a disciplina de **Arquitetura de Computadores II** da **PUC Goiás** .  O objetivo é analisar o impacto das dependências de dados no algoritmo *Insertion Sort*  , implementar uma versão paralela utilizando *Threads* e validar a execução em um ambiente de nuvem (**AWS**) utilizando **Docker**.

##  Descrição do Problema
 O *Insertion Sort* é um algoritmo de ordenação estritamente sequencial por natureza, o que o torna um excelente objeto de estudo para identificar hazards de dados:
*  **RAW (Read After Write):** Dependência de leitura após escrita no deslocamento dos elementos.
*  **WAR (Write After Read):** Dependência de escrita após leitura no reposicionamento do índice.
*  **WAW (Write After Write):** Múltiplas escritas na mesma posição de memória durante o loop interno.

##  Arquitetura e Tecnologias
*  **Linguagem:** Java 17.
*  **Containerização:** Docker (Imagem base: `eclipse-temurin:17-jdk`).
*  **Nuvem:** Amazon Web Services (AWS) - Instância EC2 t3.micro.
*  **Estratégia de Paralelismo:** Divisão por blocos com interpolação (*Merge final*).

##  Como Executar

### Pré-requisitos
*  Docker instalado .
* Acesso à internet para baixar a imagem base.

### 1. Clonar o Repositório
```bash
git clone [https://github.com/Davi-Santos-Guimaraes/AED-2.git](https://github.com/Davi-Santos-Guimaraes/AED-2.git)
cd AED-2
```
### 2. Construir a Imagem Docker
```bash
docker build -t aed2-contagem-tempo .
```
### 3. Executar o Container
```bash
docker run aed2-contagem-tempo
```

##  Resultados Esperados
O programa realiza a ordenação de vetores de 100k, 500k e 1M de elementos. Ao final, ele apresenta:
* Tempo de execução sequencial.
* Tempo de execução paralelo (utilizando 3 threads).
* Cálculo do Speedup (Tempo Sequencial / Tempo Paralelo).

##  Justificativa Arquitetural (Nuvem)
A escolha da instância **t3.micro** da AWS permite validar como o escalonador do sistema operacional gerencia múltiplas threads em uma arquitetura virtualizada com recursos limitados. O uso do **Docker** garante que o ambiente de execução seja idêntico ao ambiente de desenvolvimento, isolando as dependências do Java.

---
#  Como Rodar Localmente

Para garantir a reprodutibilidade dos testes e a análise de desempenho, você pode executar o projeto localmente utilizando o Docker (ambiente isolado) ou diretamente via terminal.

### Pré-requisitos
* **Git**: Para clonar o repositório.
* **Docker**: (Recomendado) Para garantir que o ambiente seja idêntico ao da nuvem.
* **Java JDK 17**: Caso opte por rodar sem o Docker.

---

### Opção 1: Utilizando Docker (Recomendado)
Esta opção utiliza o `Dockerfile` presente no repositório para criar uma imagem baseada no `eclipse-temurin:17-jdk`, isolando todas as dependências.

1. **Construir a imagem:**
   ```bash
   docker build -t insertion-sort-local .
   ```
2. **Executar o container:**
   ```bash
   docker run insertion-sort-local
### Opção 2: Utilizando Java (Diretamente)

1. **Compilar o código fonte:**
   ```bash
   javac ContagemTempo.java
   ```
2. **Executar a aplicação:**
   ```bash
   java ContagemTempo
   ```
## Integrantes
* Davi Santos Guimarães
* Antônio Alves de Carvalho Neto
* Ericles Pedro Nogueira Madureiro