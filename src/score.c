#include "score.h"
#include <stdio.h>

static int score = 0;

void score_init(const char *filename) {
    // TODO: Crear archivo si no existe o cargar mejores puntajes
     FILE *f;

    score = 0;

    f = fopen(filename, "a");
    if (f != NULL) {
        fclose(f);
    }
}

void score_add(int points) {
    // TODO: sumar puntos al puntaje actual
    score += points;
}

int score_get() {
    return score;
}

void score_save(const char *filename) {
    // TODO: guardar puntaje final del jugador en el archivo
    FILE *f = fopen(filename, "a");

    if (f == NULL) return;

    fprintf(f, "Puntaje final: %d\n", score);
    fclose(f);
}
