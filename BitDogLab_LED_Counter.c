#include <stdio.h>
#include "pico/stdlib.h"
#include "numeros.h"



#define LED_PIN 7

int main()
{
    stdio_init_all();
    npInit(LED_PIN);
    

    while (1)
    {
        for (int i = 0; i <= 9; i++)
        {
            Num(i);
        }
        
    }
    
    
}
