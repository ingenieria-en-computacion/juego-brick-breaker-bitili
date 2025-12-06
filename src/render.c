#include "render.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include <stdio.h>

#define BOARD_WIDTH 40
#define BOARD_HEIGHT 20
#define BRICK_START_Y 2

void render_frame() {

    // TODO:
    // 1. limpiar pantalla
    // 2. dibujar ladrillos
    // 3. dibujar pelota
    // 4. dibujar paddle
    // 5. mostrar puntaje y vidas

    int x, y;
    
    Ball *ball = ball_get();
    Paddle *paddle = paddle_get();
    Brick (*bricks)[BRICK_COLS] = bricks_get();

    // Limpiar pantalla
    printf("\033[2J\033[H");

    for (y = 0; y < BOARD_HEIGHT; y++) {
        for (x = 0; x < BOARD_WIDTH; x++) {

            /* Paredes */
            if (y == 0 || x == 0 || x == BOARD_WIDTH - 1) {
                printf("#");
                continue;
            }

            if (y >= BRICK_START_Y && y < BRICK_START_Y + BRICK_ROWS) {
                int row = y - BRICK_START_Y;
                int col = x / 4;  // cada ladrillo tiene ancho 4

                if (col < BRICK_COLS && bricks[row][col].active) {
                    // borde del ladrillo
                    if (x % 4 == 0 || x % 4 == 3)
                        printf("[");
                    else
                        printf("]");
                } else {
                    printf(" ");
                }
                continue;
            }

            // Pelota
            if (x == ball->x && y == ball->y) {
                printf("O");
                continue;
            }

            // Paddle
            if (y == BOARD_HEIGHT - 2 &&
                x >= paddle->x - paddle->width / 2 &&
                x <= paddle->x + paddle->width / 2) {
                printf("=");
                continue;
            }

            // Espacio vacío
            printf(" ");
        }

        printf("\n");
    }
}