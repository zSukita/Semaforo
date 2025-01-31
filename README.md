# Semáforo com Raspberry Pi Pico

Este projeto implementa um semáforo básico utilizando o Raspberry Pi Pico. O código gerencia três LEDs (vermelho, amarelo e verde) conectados aos pinos GPIO do Pico e alterna seus estados a cada 3 segundos por meio de um timer periódico.

## Conteúdo

- [Descrição](#descrição)
- [Pré-requisitos](#pré-requisitos)
- [Configuração do Hardware](#configuração-do-hardware)
- [Compilação e Upload](#compilação-e-upload)
- [Uso e Monitoramento](#uso-e-monitoramento)
- [Possíveis Melhorias](#possíveis-melhorias)
- [Licença](#licença)

## Descrição

O programa utiliza o SDK do Raspberry Pi Pico para:
- Configurar três pinos GPIO para controlar os LEDs.
- Definir uma máquina de estados simples (VERMELHO, AMARELO e VERDE).
- Utilizar um timer periódico para alternar os estados do semáforo a cada 3 segundos.
- Enviar informações via comunicação serial para monitorar o estado atual do semáforo.

## Pré-requisitos

- [Raspberry Pi Pico](https://www.raspberrypi.com/documentation/microcontrollers/) ou compatível.
- [SDK do Raspberry Pi Pico (C/C++)](https://github.com/raspberrypi/pico-sdk).
- Ambiente de desenvolvimento configurado para compilação com C/C++ (por exemplo, CMake, Visual Studio Code, etc.).
- Conexão com um terminal serial para visualizar as mensagens do programa (por exemplo, PuTTY, screen, minicom).

## Configuração do Hardware

1. Conecte os LEDs aos pinos GPIO do Pico:
   - **LED Vermelho:** GPIO 13
   - **LED Amarelo:** GPIO 12
   - **LED Verde:** GPIO 11

2. Verifique se os LEDs possuem resistores limitadores de corrente e estão corretamente conectados ao GND e à fonte de alimentação.

## Compilação e Upload

1. **Clone o repositório** (ou copie os arquivos do projeto) em seu ambiente de desenvolvimento:

   ```bash
   git clone https://seurepositorio.git
   cd nomedopasta
