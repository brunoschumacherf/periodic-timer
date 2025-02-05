#include "pico/stdlib.h"
#include <stdio.h>

#define RED_LED 11
#define YELLOW_LED 12
#define GREEN_LED 13

bool repeating_timer_callback(struct repeating_timer *t) {
    static int state = 0;

    gpio_put(RED_LED, 0);
    gpio_put(YELLOW_LED, 0);
    gpio_put(GREEN_LED, 0);

    state = (state + 1) % 3;

    switch (state) {
        case 0:
            gpio_put(RED_LED, 1);
            printf("RED light ON\n");
            break;
        case 1:
            gpio_put(YELLOW_LED, 1);
            printf("YELLOW light ON\n");
            break;
        case 2:
            gpio_put(GREEN_LED, 1);
            printf("GREEN light ON\n");
            break;
    }

    return true;
}

int main() {
    stdio_init_all();

    gpio_init(RED_LED);
    gpio_init(YELLOW_LED);
    gpio_init(GREEN_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_set_dir(YELLOW_LED, GPIO_OUT);
    gpio_set_dir(GREEN_LED, GPIO_OUT);

    gpio_put(RED_LED, 1);
    gpio_put(YELLOW_LED, 0);
    gpio_put(GREEN_LED, 0);
    printf("TRAFFIC LIGHT SYSTEM STARTED\n");
    printf("RED light ON\n");

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    uint32_t hours = 0, minutes = 0, seconds = 0;

    while (1) {
        seconds++;
        if (seconds >= 60) {
            seconds = 0;
            minutes++;
            if (minutes >= 60) {
                minutes = 0;
                hours = (hours + 1) % 24;
            }
        }

        printf("Time: %02lu:%02lu:%02lu\n", hours, minutes, seconds);
        sleep_ms(1000);
    }

    return 0;
}
