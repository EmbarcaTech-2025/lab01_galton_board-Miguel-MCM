# Projetos de Sistemas Embarcados - EmbarcaTech 2025

Autor: **Miguel Carvalho de Medeiros**

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Brasília, 09 de Maio de 2025

---

## Projeto 1 - Galton Board Digital com BitDogLab

Este projeto implementa uma simulação digital do Galton Board para a Raspberry Pi Pico W, utilizando um display OLED para visualização. O Galton Board é um dispositivo que demonstra conceitos de probabilidade e estatística através da queda de esferas por entre pinos.

## Descrição

O projeto simula o comportamento de um Galton Board em um ambiente digital. Bolas virtuais são liberadas do topo do display OLED e descem, desviando-se aleatoriamente para a esquerda ou direita ao colidir com "pinos".  Um histograma é exibido no display, mostrando a distribuição final das bolas nas "canaletas" inferiores.


## Conteúdo

* [Descrição](#descrição)
* [Conteúdo](#conteúdo)
* [Objetivos do Projeto](#objetivos-do-projeto)
* [Lista de Materiais e Conexões](#lista-de-materiais-e-conexões)
* [Como Começar](#como-começar)
    * [Pré-requisitos](#pré-requisitos)
    * [Construindo o Projeto](#construindo-o-projeto)
    * [Realizando o Flash para a Pico](#realizando-o-flash-para-a-pico)
* [Funcionalidades](#funcionalidades)
* [Contribuindo](#contribuindo)
* [Licença](#📜-licença)

## Objetivos do Projeto

* Implementar uma simulação digital funcional do Galton Board.
* Visualizar a simulação e o histograma em tempo real em um display OLED.
* Demonstrar a distribuição estatística das "bolas" após a queda.
* Permitir a experimentação com parâmetros da simulação, como o desbalanceamento da probabilidade de desvio.

## Lista de Materiais e Conexões

| Nome          | Componente             | Pino da Pico W | Descrição da Conexão           |
|---------------|------------------------|----------------|---------------------------------|
| Display OLED  | SSD1306 12C 128x64     | GP14 (SDA) e GP15 (SCL) | Comunicação I2C para o display OLED |

* Já se assume a devida conexão de Ground e VCC para o display.

## Como Começar

Siga estas instruções para configurar o ambiente de desenvolvimento e executar o projeto no seu Raspberry Pi Pico W.

### Pré-requisitos

Certifique-se de que tem as seguintes ferramentas instaladas:

* **SDK do Raspberry Pi Pico:** O ambiente de desenvolvimento para o RP2040. Consulte o [Guia de Início Rápido do Raspberry Pi Pico](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html#getting-started) para obter instruções de instalação.
* **CMake:** Uma ferramenta de construção cross-platform.
* **Um compilador ARM GCC:** Necessário para compilar o código para o RP2040. Geralmente incluído com a SDK do Pico.
* **Python 3:** Necessário para algumas ferramentas da SDK do Pico.
* **picotool:** Uma ferramenta para interagir com o Pico (incluída na SDK).

### Construindo o Projeto

1.  Clone este repositório para a sua máquina local:

    ```bash
    git clone https://github.com/EmbarcaTech-2025/lab01_galton_board-Miguel-MCM.git
    cd lab01_galton_board-Miguel-MCM
    ```

2.  Crie um diretório de build:

    ```bash
    mkdir build
    cd build
    ```

3.  Configure o build utilizando o CMake, certificando-se de que a variável `PICO_SDK_PATH` esteja corretamente definida para o local da sua instalação da SDK do Pico:

    ```bash
    export PICO_SDK_PATH="/caminho/para/a/sua/pico-sdk"
    cmake ..
    ```

    Se estiver a usar o Windows, poderá precisar de usar uma sintaxe diferente para definir a variável de ambiente.

4.  Compile o projeto:

    ```bash
    make -j4
    ```

    Isto irá gerar os ficheiros binários necessários, incluindo o ficheiro `.uf2` que será usado para realizer o flash para a Pico.

### Realizando o Flash para a Pico

1.  Certifique-se de que o seu Raspberry Pi Pico W não está ligado ao computador.
2.  Mantenha o botão `BOOTSEL` no seu Pico pressionado enquanto o conecta ao seu computador via USB. Isto irá montar o Pico como um disco removível chamado `RPI-RP2`.
3.  Copie o ficheiro `.uf2` encontrado no diretório `build` (normalmente com o nome do projeto, ex: `galton_board.uf2`) para o disco `RPI-RP2`.
4.  O Pico irá reiniciar automaticamente e começar a executar o código.

## Funcionalidades

* Simulação da queda de "bolas" através de um Galton Board virtual.
* Visualização da posição das bolas em tempo real no display OLED.
* Geração e exibição de um histograma mostrando a distribuição final das bolas.
* Contagem do número total de bolas que caem.
* Implementação de um mecanismo para desbalancear a probabilidade de desvio das bolas.

## Contribuindo

Contribuições são bem-vindas! Se tiver alguma sugestão de melhoria, correção de bugs ou novas funcionalidades, sinta-se à vontade para abrir um "issue" ou enviar um "pull request". Por favor, siga as convenções de codificação e documentação existentes.

## 📜 Licença
[MIT License - MIT GPL-3.0.](LICENSE)