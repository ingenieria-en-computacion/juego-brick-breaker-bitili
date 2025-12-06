#include "brick.h"

static Brick bricks[BRICK_ROWS][BRICK_COLS];

void bricks_init() {
    // TODO: Inicializar todos los ladrillos como activos
    int i, j;

    for (i = 0; i < BRICK_ROWS; i++) {
        for (j = 0; j < BRICK_COLS; j++) {
            bricks[i][j].active = 1;
        }
    }
}

Brick (*bricks_get())[BRICK_COLS] {
    return bricks;
}

void brick_destroy(int row, int col) {
    // TODO: Marcar un ladrillo como destruido
    if (row < 0 || row >= BRICK_ROWS) return;
    if (col < 0 || col >= BRICK_COLS) return;

    bricks[row][col].active = 0;
}
