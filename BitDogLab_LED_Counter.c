#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "numeros.h"

// Definição dos pinos de LED e botões
#define LED_PIN 7
#define PIN_LED_RED 13
#define BUTTON_A 5
#define BUTTON_B 6

#define flag 999             // Valor padrão para indicar que nenhum botão foi pressionado
int AUXBUTON = flag;         // Variável auxiliar para armazenar qual botão foi pressionado
static int numero_atual = 5; // Variável que armazena o número atualmente exibido na matriz de LEDs

static volatile uint32_t last_time = 0; // Variável auxiliar para controle de debounce

void blink_red(u_int32_t LED_PIN_blik);                   // Protótipo da função que faz o LED vermelho piscar
static void gpio_irq_handler(uint gpio, uint32_t events); // Protótipo da função de interrupção dos botões

int main()
{
    stdio_init_all(); // Inicializa a comunicação serial
    npInit(LED_PIN);  // Inicializa a matriz de LEDs (função externa)

    // Configuração do LED vermelho
    gpio_init(PIN_LED_RED);              // Inicializa o pino do LED vermelho
    gpio_set_dir(PIN_LED_RED, GPIO_OUT); // Define o pino como saída

    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN); // Configura o pino como entrada
    gpio_pull_up(BUTTON_A);          // Habilita o pull-up interno

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN); // Configura o pino como entrada
    gpio_pull_up(BUTTON_B);          // Habilita o pull-up interno

    // Configuração das interrupções dos botões para detecção de borda de descida
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    Num(numero_atual); // Exibe o número inicial 5 na matriz de LEDs

    while (1)
    {
        blink_red(PIN_LED_RED); // Faz o LED vermelho piscar continuamente

        // Verifica se o botão A foi pressionado e ainda não atingiu o valor máximo (9)
        if (AUXBUTON == 0 && numero_atual < 9)
        {
            numero_atual = numero_atual + 1; // Incrementa o número exibido
            Num(numero_atual);               // Atualiza a matriz de LEDs com o novo número
            AUXBUTON = flag;                 // Reseta a variável para evitar incrementos repetidos
        }
        // Verifica se o botão B foi pressionado e ainda não atingiu o valor mínimo (0)
        else if (AUXBUTON == 1 && numero_atual > 0)
        {
            numero_atual = numero_atual - 1; // Decrementa o número exibido
            Num(numero_atual);               // Atualiza a matriz de LEDs com o novo número
            AUXBUTON = flag;                 // Reseta a variável para evitar decrementos repetidos
        }
    }
}

// Função que faz o LED vermelho piscar continuamente
void blink_red(u_int32_t LED_PIN_blik)
{
    gpio_put(LED_PIN_blik, !gpio_get(LED_PIN_blik)); // Alterna o estado do LED
    sleep_ms(200);                                   // Aguarda 200ms antes da próxima mudança
}

// Função de interrupção chamada quando um botão é pressionado
void gpio_irq_handler(uint gpio, uint32_t events)
{
    // Obtém o tempo atual em microssegundos
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    // Verifica se passou tempo suficiente desde o último evento (200ms de debounce)
    if (current_time - last_time > 200000)
    {
         printf("Interrupção ocorreu no pino %d, no evento %d\n", gpio, events);
        last_time = current_time; // Atualiza o tempo do último evento

        // Verifica qual botão foi pressionado e define o valor de AUXBUTON
        if (gpio == BUTTON_A)
        {
            AUXBUTON = 0; // Define que o botão A foi pressionado (incremento)
        }
        else if (gpio == BUTTON_B)
        {
            AUXBUTON = 1; // Define que o botão B foi pressionado (decremento)
        }
    }
}
