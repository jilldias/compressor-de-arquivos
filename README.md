
# File Compressor — Compressão de Arquivos em C

<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Compression-RLE-blue?style=for-the-badge" alt="RLE">
  <img src="https://img.shields.io/badge/Status-Study%20Project-yellow?style=for-the-badge" alt="Study Project">
</p>

## Sobre o projeto

<div align="justify">

Este projeto consiste em um programa de compressão e descompressão de arquivos desenvolvido em linguagem C, utilizando o algoritmo **Run-Length Encoding (RLE)**.

O objetivo principal é explorar conceitos fundamentais da linguagem C, especialmente manipulação de ponteiros, operações de entrada e saída (I/O), leitura e escrita de arquivos binários e processamento de dados.

A implementação realiza a compressão identificando sequências consecutivas de bytes iguais e armazenando cada sequência como um par de valores: a quantidade de repetições e o byte correspondente.

</div>

## Funcionalidades

- **Compressão de arquivos:** identifica sequências consecutivas de bytes iguais e representa cada sequência por um par de valores.
- **Descompressão de arquivos:** interpreta os pares armazenados e reconstrói os dados originais.
- **Manipulação binária:** utiliza os modos `rb` e `wb` para leitura e escrita de arquivos binários.
- **Limite de sequência:** cada bloco de repetição possui no máximo 255 ocorrências.
- **Interface via terminal:** recebe parâmetros para definir a operação, o arquivo de entrada e o arquivo de saída.

## Algoritmo utilizado — Run-Length Encoding (RLE)

<div align="justify">

O Run-Length Encoding é um algoritmo de compressão sem perdas (*lossless compression*) que substitui sequências consecutivas de valores repetidos por uma representação composta pela quantidade de repetições e pelo valor correspondente.

Por exemplo, uma sequência de dados como:

</div>

```text
AAAAABBBCCDDDD
```

É representada conceitualmente por:

```text
5A 3B 2C 4D
```

Cada par representa:

| Elemento | Significado |
|---|---|
| `5` | Quantidade de repetições |
| `A` | Byte repetido |
| `3` | Quantidade de repetições |
| `B` | Byte repetido |

<div align="justify">

O algoritmo é particularmente eficiente quando os arquivos possuem grandes sequências de bytes repetidos. Entretanto, arquivos com muitos valores diferentes ou poucas repetições podem não apresentar redução de tamanho.

</div>

## Tecnologias e recursos

- **Linguagem C:** implementação da lógica de compressão e descompressão.
- **stdio.h:** manipulação de arquivos por meio de `FILE`, `fopen`, `fgetc`, `putc`, `fputc` e `fclose`.
- **string.h:** comparação de argumentos recebidos pela linha de comando com `strcmp`.
- **Ponteiros de arquivo:** utilização de `FILE *` para controlar os fluxos de entrada e saída.
- **Argumentos de linha de comando:** utilização de `argc` e `argv` para receber parâmetros externos.

## Conceitos de programação estudados

| Conceito | Aplicação no projeto |
|---|---|
| Ponteiros | Manipulação dos fluxos de arquivos com `FILE *`. |
| Estruturas de repetição | Percorrer os bytes e identificar sequências repetidas. |
| Estruturas condicionais | Controlar as operações de compressão e descompressão. |
| Funções | Separação das responsabilidades em `compress()` e `decompress()`. |
| Arquivos binários | Leitura e escrita de dados sem interpretação textual. |
| Manipulação de bytes | Processamento individual dos valores armazenados nos arquivos. |
| Argumentos CLI | Definição da operação e dos caminhos dos arquivos. |
| Algoritmos | Implementação de uma estratégia de compressão sem perdas. |

## Como executar

### 1. Clonar o repositório

```bash
git clone https://github.com/jilldias/file-compressor.git
```

### 2. Acessar o diretório

```bash
cd file-compressor
```

### 3. Compilar

Com GCC:

```bash
gcc main.c -o compressor
```

### 4. Executar

O programa recebe três argumentos:

```bash
./compressor -c input output
```

| Parâmetro | Descrição |
|---|---|
| `-c` | Executa a compressão. |
| `-d` | Executa a descompressão. |
| `input` | Caminho do arquivo de entrada. |
| `output` | Caminho do arquivo de saída. |

### Exemplos

**Comprimir um arquivo:**

```bash
./compressor -c arquivo.txt arquivo.rle
```

**Descomprimir um arquivo:**

```bash
./compressor -d arquivo.rle arquivo_recuperado.txt
```

## Estrutura da implementação

### `compress()`

Responsável por percorrer o arquivo de entrada, identificar sequências consecutivas de bytes iguais e gravar os pares quantidade/byte no arquivo de saída.

### `decompress()`

Responsável por interpretar os pares armazenados no arquivo comprimido e reconstruir a sequência original, repetindo cada byte conforme a quantidade registrada.

### `main()`

Responsável por interpretar os argumentos da linha de comando, abrir os arquivos, selecionar a operação e encerrar os fluxos de entrada e saída.

## Limitações conhecidas

- O algoritmo RLE apresenta melhor desempenho em arquivos com sequências consecutivas de bytes repetidos.
- Arquivos sem repetições podem aumentar de tamanho após a compressão.
- O formato utiliza um byte para representar a quantidade de repetições, limitando cada bloco a 255 ocorrências.
- A implementação atual não possui cabeçalho ou mecanismo de validação do formato do arquivo comprimido.
- A implementação ainda precisa de tratamento mais robusto para falhas de leitura, escrita e abertura de arquivos.

## Possíveis melhorias

- Implementar validação dos arquivos de entrada e saída.
- Verificar erros durante as operações de leitura e escrita.
- Impedir situações em que os caminhos de entrada e saída sejam iguais.
- Criar um cabeçalho para identificar o formato dos arquivos comprimidos.
- Implementar estatísticas de compressão, incluindo tamanho original, tamanho comprimido e percentual de redução.
- Adicionar testes com arquivos de diferentes formatos e tamanhos.

## Contribuição

Contribuições são bem-vindas!

1. Faça um Fork do projeto.
2. Crie uma branch para sua implementação:

   ```bash
   git checkout -b feature/nova-funcionalidade
   ```

3. Realize as alterações e faça commit:

   ```bash
   git commit -m "feat: adiciona nova funcionalidade"
   ```

4. Envie as alterações:

   ```bash
   git push origin feature/nova-funcionalidade
   ```

5. Abra um Pull Request para análise.

## Licença

Este projeto foi desenvolvido para fins educacionais e de estudo.
