#include "menu.h"
#include <stdio.h>

// TODO: El estudiante debe completar el menú
void menu_show() {
    printf("\n======== BRICK BREAKER ========\n");
    printf("1) Jugar\n");
    printf("2) Instrucciones\n");
    printf("3) Salir\n");    
    printf("Seleccione una opción: ");
}

int menu_get_option() {
    int opt;
    scanf("%d", &opt);
    // TODO: Completar la lectura de la opción. 
    scanf("%d", &opt);
    return opt;
}
