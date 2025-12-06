#include <stdio.h>
#include "game.h"
#include "score.h"
#include "menu.h"

int main() {

  menu_show();
    int opcion = menu_get_option();

     switch (opcion) {

        case 1:
            game_init();
            game_loop_step();
            break;

        case 2:
            printf("\n=== INSTRUCCIONES ===\n");
            printf("Usa 'A' para mover a la izquierda\n");
            printf("Usa 'D' para mover a la derecha\n");
            printf("Evita que la pelota caiga\n");
            printf("Destruye todos los ladrillos!\n\n");
            break;

        case 3:
            printf("Saliendo del juego...\n");
            return 0;

        default:
            printf("Opción no válida\n");
            break;
    }
    // Inicializa el sistema de puntajes y crea el archivo si no existe.
    // TODO: Se debe completar esta función en score.c
    score_init("scores.txt");

    // Inicializa el juego (carga ladrillos, posiciones iniciales, etc.)
    game_init();

    // Bucle principal del juego.
    // TODO: Debe llamar a: input_update(), game_update(), render_frame().
    // Se implementa en game.c
    while (!game_is_over()) {
        game_loop_step();
    }

    // Guarda la puntuación del jugador al final del juego
    // se implementa score_save()
    score_save("scores.txt");
      printf("Juego terminado.\n");

    return 0;
}
