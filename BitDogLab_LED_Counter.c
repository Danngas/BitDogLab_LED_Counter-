#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "numeros.h"

#define LED_PIN 7
#define PIN_LED_RED 12

void blink_red(u_int32_t LED_PIN_blik); // funcao para piscar o led
int main()
{
    stdio_init_all();
    npInit(LED_PIN);

    gpio_init(PIN_LED_RED);              // Inicializa o pino do LED
    gpio_set_dir(PIN_LED_RED, GPIO_OUT); // Configura o pino como saída

    while (1)
    {
        blink_red(PIN_LED_RED);
        Num(0);


    }
}

void blink_red(u_int32_t LED_PIN_blik)
{
    gpio_put(LED_PIN_blik, !gpio_get(LED_PIN_blik));
    sleep_ms(200); // does nothing
}