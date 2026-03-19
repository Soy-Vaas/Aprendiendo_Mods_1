/* Ejercicio 05 - Punteros: modificar estadísticas en memoria
 * Fase 1: Fundamentos de C
 * Objetivo: comprender cómo los punteros permiten modificar datos,
 *           al igual que el juego modifica los PS del Pokémon en RAM.
 */
#include <stdio.h>

typedef unsigned short u16;

typedef struct {
    u16 ps_actual;
    u16 ps_max;
} Salud;

/* Simula recibir daño: resta puntos a través de un puntero */
void recibir_danio(Salud *salud, u16 danio) {
    if (danio >= salud->ps_actual) {
        salud->ps_actual = 0; /* no puede bajar de 0 */
    } else {
        salud->ps_actual -= danio;
    }
}

/* Simula usar una Poción: recupera 20 PS sin superar el máximo */
void usar_pocion(Salud *salud) {
    salud->ps_actual += 20;
    if (salud->ps_actual > salud->ps_max) {
        salud->ps_actual = salud->ps_max;
    }
    printf("Usaste una Pocion! PS ahora: %d/%d\n",
           salud->ps_actual, salud->ps_max);
}

int main() {
    Salud pikachu = {120, 120};

    printf("PS iniciales: %d/%d\n", pikachu.ps_actual, pikachu.ps_max);

    recibir_danio(&pikachu, 45);
    printf("Tras recibir 45 de danio: %d/%d\n", pikachu.ps_actual, pikachu.ps_max);

    usar_pocion(&pikachu);

    recibir_danio(&pikachu, 200); /* golpe que lo deja en 0 */
    printf("Tras recibir 200 de danio: %d/%d\n", pikachu.ps_actual, pikachu.ps_max);

    return 0;
}
