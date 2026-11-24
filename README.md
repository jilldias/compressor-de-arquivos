
# Compressor de Arquivos

<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Algorithm-RLE-blue?style=for-the-badge" alt="Run-Length Encoding">
  <img src="https://img.shields.io/badge/Status-Educational-yellow?style=for-the-badge" alt="Educational Project">
</p>

## Sobre o projeto

<div align="justify">

O **Compressor de Arquivos** é um projeto desenvolvido em linguagem C com o objetivo de implementar operações de compressão e descompressão de arquivos utilizando o algoritmo **Run-Length Encoding (RLE)**.

A aplicação identifica sequências consecutivas de bytes iguais e substitui cada sequência por uma representação composta por dois valores: a quantidade de repetições e o byte correspondente. Na descompressão, esses dados são interpretados para reconstruir o conteúdo original.

O projeto foi desenvolvido como exercício prático de programação, com foco no aprofundamento de conceitos fundamentais da linguagem C, especialmente ponteiros, manipulação de arquivos binários, operações de entrada e saída e processamento de bytes.

</div>

## Funcionalidades

- **Compressão:** identifica sequências consecutivas de bytes repetidos e armazena sua representação compactada.
- **Descompressão:** reconstrói os dados originais a partir das sequências armazenadas.
- **Manipulação de arquivos binários:** realiza leitura e escrita utilizando os modos `rb` e `wb`.
- **Limite de repetição:** representa cada sequência com até 255 ocorrências por bloco.
- **Execução via terminal:** recebe parâmetros para selecionar a operação e definir os arquivos de entrada e saída.

## Algoritmo — Run-Length Encoding (RLE)

<div align="justify">

O Run-Length Encoding é um algoritmo de compressão sem perdas (*lossless compression*), baseado na identificação de sequências consecutivas de valores idênticos.

Em vez de armazenar individualmente cada ocorrência, o algoritmo registra a quantidade de repetições seguida pelo valor correspondente.

</div>

**Exemplo conceitual:**

Sequência original:

```text
AAAAABBBCCDDDD
```

Representação RLE:

```text
5A 3B 2C 4D
```

Cada par representa a quantidade de ocorrências e o respectivo caractere.

Na implementação deste projeto, cada par é armazenado como dois bytes: primeiro a contagem e depois o byte correspondente.

<div align="justify">

O RLE é especialmente eficiente em arquivos que apresentam grandes sequências de bytes repetidos. Entretanto, arquivos com pouca repetição podem não apresentar redução de tamanho e até aumentar após a compressão.

</div>

## Tecnologias e bibliotecas

- **C:** linguagem utilizada para implementar a lógica de compressão e descompressão.
- **stdio.h:** operações de entrada e saída, leitura e escrita de arquivos.
- **string.h:** comparação de argumentos recebidos pela linha de comando.
- **GCC:** compilação do código-fonte.

### Principais funções utilizadas

| Função | Responsabilidade |
|---|---|
| `fopen()` | Abre arquivos para leitura ou escrita. |
| `fgetc()` | Lê um byte do arquivo. |
| `putc()` | Escreve um byte no arquivo. |
| `fputc()` | Escreve um byte no arquivo. |
| `fclose()` | Fecha um fluxo de arquivo. |
| `strcmp()` | Compara strings. |

## Conceitos de programação estudados

| Conceito | Aplicação |
|---|---|
| Ponteiros | Utilização de `FILE *` para manipular fluxos de arquivos. |
| Funções | Organização das operações em `compress()` e `decompress()`. |
| Estruturas de repetição | Percorrimento dos bytes e identificação de sequências. |
| Estruturas condicionais | Controle das operações e identificação de repetições. |
| Arquivos binários | Leitura e escrita de dados em formato binário. |
| Manipulação de bytes | Processamento individual dos valores do arquivo. |
| Argumentos CLI | Utilização de `argc` e `argv` para receber parâmetros. |
| Algoritmos | Aplicação de uma técnica de compressão sem perdas. |

## Como executar

### 1. Clonar o repositório

```bash
git clone https://github.com/jilldias/compressor-de-arquivos.git
```

### 2. Acessar o diretório

```bash
cd compressor-de-arquivos
```

### 3. Compilar

Utilizando o GCC:

```bash
gcc main.c -o compressor
```

### 4. Executar

A aplicação recebe três argumentos:

```bash
./compressor -c|-d input output
```

| Parâmetro | Descrição |
|---|---|
| `-c` | Executa a compressão. |
| `-d` | Executa a descompressão. |
| `input` | Arquivo de entrada. |
| `output` | Arquivo de saída. |

### Exemplos de utilização

**Comprimir um arquivo:**

```bash
./compressor -c arquivo.txt arquivo.rle
```

**Descomprimir um arquivo:**

```bash
./compressor -d arquivo.rle arquivo_recuperado.txt
```

## Estrutura da implementação

### `compress(FILE *in, FILE *out)`

Responsável pela compressão. Percorre o arquivo de entrada, identifica sequências consecutivas de bytes iguais, contabiliza suas ocorrências e grava os pares de contagem e valor no arquivo de saída.

### `decompress(FILE *in, FILE *out)`

Responsável pela descompressão. Lê os pares armazenados no arquivo comprimido e reproduz cada byte de acordo com a quantidade registrada.

### `main(int argc, char *argv[])`

Responsável pelo fluxo principal da aplicação. Recebe os argumentos da linha de comando, abre os arquivos, identifica a operação solicitada e executa a função correspondente.

## Limitações conhecidas

- O algoritmo apresenta melhor desempenho em arquivos com sequências consecutivas de bytes repetidos.
- Arquivos com pouca repetição podem aumentar de tamanho após a compressão.
- Cada bloco possui limite de 255 repetições.
- O formato não possui cabeçalho de identificação ou validação de integridade.
- A implementação ainda necessita de tratamento mais robusto para erros de leitura, escrita e arquivos incompletos.

## Melhorias futuras

- Implementar validação dos arquivos de entrada e saída.
- Adicionar tratamento de erros nas operações de leitura e escrita.
- Implementar verificação para evitar sobrescrita acidental do arquivo original.
- Criar um cabeçalho para identificação do formato comprimido.
- Exibir estatísticas de compressão e redução percentual do tamanho.
- Desenvolver testes com diferentes tipos e tamanhos de arquivos.

## Contribuição

Contribuições são bem-vindas!

1. Faça um Fork do projeto.
2. Crie uma branch para sua funcionalidade:

```bash
git checkout -b feature/nova-funcionalidade
```

3. Realize as alterações e registre um commit:

```bash
git commit -m "feat: adiciona nova funcionalidade"
```

4. Envie sua branch:

```bash
git push origin feature/nova-funcionalidade
```

5. Abra um Pull Request para análise.

## Licença

Este projeto foi desenvolvido para fins educacionais e de estudo.
