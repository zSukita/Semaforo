# Semáforo com Raspberry Pi Pico

Este é um projeto de controle de semáforo usando o microcontrolador **Raspberry Pi Pico**. O programa alterna entre os estados **vermelho**, **amarelo** e **verde** em intervalos de tempo pré-definidos, utilizando LEDs conectados aos GPIOs do Pico.

---

## 💻 Requisitos de Hardware

1. **Raspberry Pi Pico**
2. **3 LEDs** (vermelho, amarelo e verde)
3. **Resistores** (330Ω para cada LED)
4. **Jumpers** e **protoboard** para conexões
5. **Cabos USB** para alimentação e programação

---

## 🛠 Montagem do Circuito

Conecte os LEDs aos GPIOs da seguinte forma:

| Cor do LED      | Pino GPIO | Resistor |
|------------------|-----------|----------|
| Vermelho        | 13        | 330Ω     |
| Amarelo         | 12        | 330Ω     |
| Verde           | 11        | 330Ω     |

1. Conecte o **ânodo** (perna longa) de cada LED ao pino GPIO correspondente.
2. Conecte o **cátodo** (perna curta) de cada LED ao resistor de 220Ω.
3. Conecte o outro terminal do resistor ao **GND** (terra) do Pico.

---

## 📄 Instruções de Uso

### 1. Configuração do Ambiente
- Certifique-se de que o SDK do Raspberry Pi Pico (pico-sdk) está instalado e configurado no seu sistema.
- Configure o ambiente de desenvolvimento (recomenda-se o uso do **Visual Studio Code** com a extensão **Pico C/C++ SDK**).

### 2. Compilação e Upload
1. Clone o repositório do projeto ou crie um novo.
2. Compile o código usando o `CMake`. No terminal, navegue até a pasta do projeto e execute:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
3. Conecte o Raspberry Pi Pico ao computador no modo **BOOTSEL** (segure o botão BOOTSEL ao conectar o USB).
4. Copie o arquivo `.uf2` gerado na pasta `build` para o Pico (ele será reconhecido como um drive USB).

### 3. Execução do Programa
Após o upload, o programa será executado automaticamente. O semáforo alternará entre os estados a cada **3 segundos**, e o estado atual será exibido na serial.

---

## 🚦 Funcionamento do Programa

1. **Estado inicial**: O LED vermelho é ligado.
2. A cada **3 segundos**, o semáforo alterna os estados na seguinte sequência:
   - Vermelho → Amarelo
   - Amarelo → Verde
   - Verde → Vermelho
3. O estado atual é impresso na serial a cada **1 segundo**.

---

## 🔧 Personalização

- Para alterar o tempo de cada estado, modifique o valor `3000` (em milissegundos) na função `add_repeating_timer_ms` no código.
- Para adicionar uma lógica diferente de transição entre estados, ajuste a função `callback_semaforo`.

---

## ⚠️ Considerações Finais

- Certifique-se de que os LEDs estejam conectados corretamente e com os resistores apropriados para evitar danos ao Pico.
- Este projeto é um exemplo básico e pode ser expandido para incluir mais funcionalidades, como botões de pedestre ou controle remoto.

---

😊 **Divirta-se explorando e expandindo este projeto!**
