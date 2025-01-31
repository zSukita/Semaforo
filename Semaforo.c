#include <stdio.h> 
#include "pico/stdlib.h"
#include "pico/time.h"

// Definição dos GPIOs para os LEDs (ajuste conforme seu circuito)
#define LED_VERMELHO  13
#define LED_AMARELO   12
#define LED_VERDE     11

// Estados do semáforo
enum EstadoSemaforo { VERMELHO, AMARELO, VERDE };
volatile enum EstadoSemaforo estado_atual = VERMELHO;

// Timer para controle do semáforo
struct repeating_timer timer;

// Função de callback do timer
bool callback_semaforo(struct repeating_timer *t) {
    // Desliga todos os LEDs antes da transição
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    // Lógica de transição de estados
    switch(estado_atual) {
        case VERMELHO:
            gpio_put(LED_AMARELO, 1);  // Mantém amarelo ligado apenas durante transições se necessário
            estado_atual = AMARELO;
            break;
        case AMARELO:
            gpio_put(LED_VERDE, 1);
            estado_atual = VERDE;
            break;
        case VERDE:
            gpio_put(LED_VERMELHO, 1);
            estado_atual = VERMELHO;
            break;
    }
    return true;
}

int main() {
    stdio_init_all();

    // Configuração dos GPIOs
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);
    
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Inicia com LED vermelho ligado
    gpio_put(LED_VERMELHO, 1);

    // Configura o timer periódico (3000ms = 3 segundos)
    add_repeating_timer_ms(3000, callback_semaforo, NULL, &timer);

    // Loop principal para monitoramento serial
    uint64_t ultimo_tempo = 0;
    while (true) {
        uint64_t tempo_atual = time_us_64();
        
        // Atualiza a serial a cada segundo
        if (tempo_atual - ultimo_tempo >= 1000000) {
            printf("Estado do semáforo: %d\n", estado_atual);
            ultimo_tempo = tempo_atual;
        }
    }
}
