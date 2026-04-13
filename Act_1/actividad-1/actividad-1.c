#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int x = 0;
/**
 * @brief Programa principal
*/
int main(void) {
  // Inicializo el USB
  stdio_init_all();
  cyw43_arch_init();

  // Mensaje por USB
  printf("\nHola mundo!\n");

  while (true) {
    // Prendo LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    // Mensaje por USB
    printf("fiesta\n");
    // Demora
    sleep_ms(1000);
    x = x + 1;
    printf("encendido %d\n", x);
    // Apago LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    // Mensaje por USB
    printf("sin fiesta\n");
    // Demora
    sleep_ms(1000);
    printf("apagado %d\n", x);
  }
  return 0;
}