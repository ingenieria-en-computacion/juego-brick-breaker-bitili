#include "game.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "render.h"
#include "input.h"
#include "score.h"

// Aquí pueden declararse variables globales del estado del juego.
// Los estudiantes deben completar esto.
static int game_over = 0;

void game_init() {
    // TODO: Inicializar paddle, pelota, matriz de ladrillos, puntaje, vidas, etc.
}

void game_loop_step() {
    
    // TODO:
    // 1. Leer entrada con input_update()
    // 2. Actualizar pelota, paddle y colisiones
    // 3. Verificar si la pelota cae → restar vida
    // 4. Llamar a render_frame()
}

int game_is_over() {
    // TODO: retornar si el juego terminó
    return game_over;
}
