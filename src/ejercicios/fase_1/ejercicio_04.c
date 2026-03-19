/* Ejercicio 04 - Estructura de Pokémon con tipos de GBA
 * Fase 1: Fundamentos de C
 * Objetivo: practicar structs y los tipos u8/u16/u32 usados en pokefirered.
 */
#include <stdio.h>

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* Estructura simplificada de un Pokémon en batalla */
typedef struct {
    u16 especie;     /* ID del Pokémon: 25 = Pikachu, 1 = Bulbasaur, etc. */
    u8  nivel;       /* 1 a 100 */
    u16 ps_actual;   /* Puntos de salud actuales */
    u16 ps_max;      /* Puntos de salud máximos */
    u16 ataque;
    u16 defensa;
    u16 velocidad;
} Pokemon;

void mostrar_pokemon(const Pokemon *p) {
    printf("Especie #%d  Nv.%d\n", p->especie, p->nivel);
    printf("  PS: %d / %d\n", p->ps_actual, p->ps_max);
    printf("  Atk: %d  Def: %d  Vel: %d\n", p->ataque, p->defensa, p->velocidad);
}

int main() {
    Pokemon pikachu = {25, 50, 120, 120, 75, 50, 110};
    Pokemon bulbasaur = {1, 45, 130, 130, 65, 75, 55};

    printf("=== Equipo ===\n");
    mostrar_pokemon(&pikachu);
    printf("\n");
    mostrar_pokemon(&bulbasaur);

    return 0;
}
