#include "ball.h"
#define BOARD_WIDTH 40
#define BOARD_HEIGHT 20
static Ball ball;

void ball_init() {
    // TODO: posicionar la pelota al centro y darle velocidad inicial
    ball.x = BOARD_WIDTH / 2;
    ball.y = BOARD_HEIGHT / 2;
    ball.dx = 1;
    ball.dy = -1;
}

void ball_update() {
    // TODO: mover la pelota y actualizar colisiones generales
    // Mover la pelotita
    ball.x += ball.dx;
    ball.y += ball.dy;

    // Rebote paredes
    if (ball.x <= 1 || ball.x >= BOARD_WIDTH - 2) {
        ball.dx *= -1;
    }

    // Rebote techo
    if (ball.y <= 1) {
        ball.dy *= -1;
    }
}

Ball* ball_get() {
    return &ball;
}
