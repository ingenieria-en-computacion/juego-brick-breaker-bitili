#include "input.h"
#include "library_compat.h"

int input_update() {
    // TODO:
    // Leer teclas 'a' y 'd', regresar -1 o 1
    // Si no se presiona nada, regresar 0
    char c;

if (!kbhit()) {
    return 0;
}

int ch = getch();

    if (ch == 'a' || ch == 'A') {
        return -1; // izquierda
    }
    if (ch == 'd' || ch == 'D') {
        return 1; // derecha
    }

    return 0;
}
