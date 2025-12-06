#include "paddle.h"
#define BOARD_WIDTH 40
static Paddle paddle;

void paddle_init() {
    // TODO: colocar el paddle centrado
    paddle.width = 6;
    paddle.x = BOARD_WIDTH / 2;
}

void paddle_update(int direction) {
    // TODO: mover el paddle según la dirección (-1 izquierda, 1 derecha)
    // Mover el centro del paddle
    paddle.x += direction;

    // Para que no se salga del tablero
    int half = paddle.width / 2;

    if (paddle.x - half <= 1) {
        paddle.x = half + 1;
    }
    if (paddle.x + half >= BOARD_WIDTH - 2) {
        paddle.x = BOARD_WIDTH - half - 2;
    }
}

Paddle* paddle_get() {
    return &paddle;
}
