
---

## 📋 Descrição Geral

Este projeto implementa um **semáforo com temporização periódica** utilizando o microcontrolador **Raspberry Pi Pico W** e a função `add_repeating_timer_ms()` do **Pico SDK**. O sistema alterna automaticamente entre os estados do semáforo (**vermelho, amarelo e verde**) a cada **3 segundos**, simulando um ciclo real de sinalização viária.



---

## 🛠 Componentes Utilizados

- **Raspberry Pi Pico W** (Microcontrolador)
- **03 LEDs individuais** (vermelho, amarelo e verde)
- **03 Resistores de 330 Ω**
- **LED RGB** (conectado aos GPIOs 11, 12 e 13, conforme o mapeamento da BitDogLab)

---

## 📂 Estrutura do Projeto

```plaintext
periodic-timer/
├── wokwi/
│   ├── diagram.json
│   └── wokwi.toml
├── .gitignore
├── CMakeLists.txt
├── LICENSE
├── main.c
├── pico_sdk_import.cmake
└── README.md
```

---

## 🚦 Funcionalidades

### 1. Ciclo do Semáforo
- **Vermelho:** Inicia com o LED vermelho aceso.
- **Amarelo:** Após 3 segundos, o LED vermelho apaga e o amarelo acende.
- **Verde:** Depois de mais 3 segundos, o LED amarelo apaga e o verde acende.
- **Repetição Contínua:** O ciclo reinicia indefinidamente.

### 2. Temporização e Monitoramento Serial
- O temporizador `add_repeating_timer_ms()` garante a troca periódica dos LEDs.
- O estado do semáforo é exibido na porta serial a cada 1 segundo para monitoramento.

### 3. Implementação com LED RGB
- Substitui os LEDs individuais por um LED RGB, reduzindo o número de componentes.
- As cores são controladas pelos GPIOs 11 (Verde), 12 (Azul) e 13 (Vermelho) na BitDogLab.

---

## 🔧 Requisitos Técnicos

- **Precisão da Temporização:** O código utiliza `add_repeating_timer_ms()` para um ciclo confiável.
- **Manipulação Eficiente dos LEDs:** Implementação da função `repeating_timer_callback()` para atualizar os LEDs.
- **Feedback Serial:** Impressão de logs no terminal a cada 1 segundo para depuração e monitoramento.
- **Estrutura de Código Organizada:** Código bem documentado e modularizado para facilitar futuras melhorias.

---

## 🚀 Instalação e Execução

### 1. Configuração do Ambiente
- Certifique-se de que o **Pico SDK** está corretamente instalado e configurado.
- Instale todas as dependências necessárias para compilar o código.

### 2. Clonando o Repositório

```bash
git clone https://github.com/brunoschumacherf/periodic-timer
cd periodic-timer
```

### 3. Compilando e Enviando o Código

```bash
mkdir build
cd build
cmake ..
make
```
---

## 🛠 Testes e Simulação

### Simulação no Wokwi
- Utilize o arquivo `diagram.json` na pasta `wokwi` para testar o funcionamento.

---

## 📝 Autor

Projeto desenvolvido por **Bruno Schumacher**.

---

