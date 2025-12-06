#include "game.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "render.h"
#include "input.h"
#include "score.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define BOARD_HEIGHT 20
// Aquí pueden declararse variables globales del estado del juego.
// Los estudiantes deben completar esto.
static int game_over = 0;

void game_init() {
    // TODO: Inicializar paddle, pelota, matriz de ladrillos, puntaje, vidas, etc.
    game_over = 0;

    paddle_init();
    ball_init();
    bricks_init();
}

void game_loop_step() {
    
    // TODO:
    // 1. Leer entrada con input_update()
    // 2. Actualizar pelota, paddle y colisiones
    // 3. Verificar si la pelota cae → restar vida
    // 4. Llamar a render_frame()

    int direction;
    int i, j;
    int bricks_left = 0;

    Ball *ball = ball_get();
    Paddle *paddle = paddle_get();
    Brick (*bricks)[BRICK_COLS] = bricks_get();

    // 1. Entrada
    direction = input_update();

    // 2. Actualizar paddle y pelota
    paddle_update(direction);
    ball_update();

    // 3. Colisión de la pelotita con el paddle
    if (
        ball->y == BOARD_HEIGHT - 3 &&
        ball->x >= paddle->x - paddle->width / 2 &&
        ball->x <= paddle->x + paddle->width / 2
    ) {
        ball->dy = -1;
        ball->dx = (ball->x < paddle->x ? -1 : 1);
    }

    // 4. Colisión de la pelota con los ladrillos
    for (i = 0; i < BRICK_ROWS; i++) {
        for (j = 0; j < BRICK_COLS; j++) {
            if (bricks[i][j].active) {
                int brick_y = 2 + i;
                int brick_x_start = j * 4;
                int brick_x_end = brick_x_start + 3;

                if (
                    ball->y == brick_y &&
                    ball->x >= brick_x_start &&
                    ball->x <= brick_x_end
                ) {
                    brick_destroy(i, j);
                    ball->dy *= -1;
                    score_add(10);
                } if (bricks[i][j].active) {
                     int brick_y = 2 + i;
                     int brick_x_start = j * 4;
                     int brick_x_end = brick_x_start + 3;

                if (
                     ball->y == brick_y &&
                     ball->x >= brick_x_start &&
                     ball->x <= brick_x_end
                ) {
                    brick_destroy(i, j);
                    ball->dy *= -1;
                    score_add(10);
                }else {
                    bricks_left++;
                }
            }
        }
    }

    // 5. iiii, se le cayó la pelota y perdió
    if (ball->y >= BOARD_HEIGHT - 1) {
        game_over = 1;
    }

    // 6. Victoria
    if (bricks_left == 0) {
        game_over = 1;
    }

    // 7. Render
    render_frame();

        #ifdef _WIN32
    Sleep(60);
    #else
    usleep(60000); // Para Linux
    #endif
}}

int game_is_over() {
    // TODO: retornar si el juego terminó
    return game_over;
}
