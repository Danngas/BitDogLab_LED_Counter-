# BitDogLab LED Counter  

## 📌 Descrição  

O **BitDogLab LED Counter** é um projeto desenvolvido para explorar o uso de **interrupções (IRQ)** em microcontroladores RP2040. Ele utiliza **botões físicos** para controlar a exibição de números em uma **matriz de LEDs WS2812**, implementando **debouncing via software** e manipulação de **LEDs RGB comuns**.  

### 🛠 Construído com  
- **Microcontrolador:** RP2040 (Placa BitDogLab)  
- **Linguagem:** C/C++  
- **Frameworks:** Pico SDK  
- **Componentes:** LEDs WS2812, LED RGB, botões físicos  

### 🎯 Por que foi construído?  
Este projeto foi criado para consolidar conceitos sobre **interrupções em microcontroladores**, controle de LEDs endereçáveis e **debouncing de botões**, aplicando boas práticas de programação embarcada.  

---

## 📁 Estrutura do Projeto  

O programa foi organizado da seguinte forma:  

### 🔹 Arquivos principais  

- `BitDogLab_LED_Counter.c` – **Programa principal**, responsável pela lógica central do sistema.  
- `matrizled.c` – **Configuração e controle** da matriz de LEDs WS2812.  
- `numeros.h` – **Modelos dos números de 0 a 9** para exibição na matriz de LEDs.  

### 🛠 Arquivos auxiliares  

- `ws2818b.pio` – **Código PIO** para controle eficiente dos LEDs WS2812.  
- `wokwi.toml` – **Configuração do projeto** para simulação no Wokwi.  
- `diagram.json` – **Diagrama de conexão** dos componentes.  
- `CMakeLists.txt` – **Configuração do CMake** para compilação do projeto.  

---

## 🚀 Funcionalidades  

- Piscar contínuo do LED vermelho do **LED RGB**.  
- Contagem de **0 a 9** exibida na matriz de LEDs WS2812.  
- Controle da contagem via **botões com interrupções (IRQ)**.  
- Implementação de **debouncing via software** para evitar acionamentos falsos.  

---

## 🎥 Demonstração  

Um vídeo demonstrando o funcionamento do projeto está disponível, onde são explicadas suas principais funcionalidades e execução na **placa BitDogLab**.  

---

## ⚙️ Instruções para Execução do Projeto  

### 📌 Requisitos  

- **Placa compatível:** BitDogLab (RP2040)  
- **Ambiente de desenvolvimento:**  
  - [Pico SDK](https://github.com/raspberrypi/pico-sdk) instalado e configurado  
  - Compilador **ARM GCC**  
  - Ferramenta **CMake**  
  - Interface serial para upload do código  

### 🚀 Passos para Compilação e Upload  

1. **Clonar o repositório**  
   ```sh
   git clone https://github.com/Danngas/BitDogLab_LED_Counter-.git
   cd BitDogLab_LED_Counter

2. **Configurar e compilar o projeto**  

``mkdir build && cd build``
``cmake ..``
``make``

3. **Transferir o firmware para a placa**

Conectar a placa BitDogLab ao computador
Copiar o arquivo .uf2 gerado para o drive da placa
4. **Testar o projeto**

Pressionar os botões físicos para alterar a exibição dos números
Observar os efeitos de LED

## 📜 Licença  

Este projeto está sob a licença MIT. Sinta-se à vontade para utilizá-lo e modificá-lo conforme necessário.  
