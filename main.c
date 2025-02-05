#include "pico/stdlib.h"
#include <stdio.h>

#define RED_LED 11
#define YELLOW_LED 12
#define GREEN_LED 13

// Callback do temporizador que alterna entre os estados do semáforo
bool repeating_timer_callback(struct repeating_timer *t) {
    static int state = 0;  // Estado atual do semáforo (0 = vermelho, 1 = amarelo, 2 = verde)

    // Desliga todos os LEDs antes de ligar o próximo
    gpio_put(RED_LED, 0);
    gpio_put(YELLOW_LED, 0);
    gpio_put(GREEN_LED, 0);

    state = (state + 1) % 3;  // Avança para o próximo estado de forma cíclica

    switch (state) {
        case 0:
            gpio_put(RED_LED, 1);  // Liga o LED vermelho
            printf("RED light ON\n");
            break;
        case 1:
            gpio_put(YELLOW_LED, 1);  // Liga o LED amarelo
            printf("YELLOW light ON\n");
            break;
        case 2:
            gpio_put(GREEN_LED, 1);  // Liga o LED verde
            printf("GREEN light ON\n");
            break;
    }

    return true;  // Mantém o temporizador ativo para continuar repetindo
}

int main() {
    stdio_init_all();  // Inicializa a comunicação serial para exibir mensagens no console

    // Configura os pinos dos LEDs como saída
    gpio_init(RED_LED);
    gpio_init(YELLOW_LED);
    gpio_init(GREEN_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_set_dir(YELLOW_LED, GPIO_OUT);
    gpio_set_dir(GREEN_LED, GPIO_OUT);

    // Inicializa o semáforo com o LED vermelho ligado
    gpio_put(RED_LED, 1);
    gpio_put(YELLOW_LED, 0);
    gpio_put(GREEN_LED, 0);
    printf("TRAFFIC LIGHT SYSTEM STARTED\n");
    printf("RED light ON\n");

    struct repeating_timer timer;
    // Configura o temporizador para alternar o estado do semáforo a cada 3 segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Simula um relógio que exibe o tempo no console
    uint32_t hours = 0, minutes = 0, seconds = 0;

    while (1) {
        seconds++;  // Incrementa os segundos a cada iteração

        if (seconds >= 60) {  // Se atingir 60 segundos, incrementa os minutos
            seconds = 0;
            minutes++;
            if (minutes >= 60) {  // Se atingir 60 minutos, incrementa as horas
                minutes = 0;
                hours = (hours + 1) % 24;  // Limita as horas a 24 para simular um relógio de 24h
            }
        }

        // Exibe o tempo atual formatado como HH:MM:SS
        printf("Time: %02lu:%02lu:%02lu\n", hours, minutes, seconds);
        sleep_ms(1000);  // Aguarda 1 segundo antes de atualizar novamente
    }

    return 0;
}
