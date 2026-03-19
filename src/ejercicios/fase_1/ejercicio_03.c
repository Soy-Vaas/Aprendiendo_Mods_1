/* Ejercicio 03 - Inventario de ítems
 * Fase 1: Fundamentos de C
 * Objetivo: practicar arrays y estructuras de control.
 */
#include <stdio.h>

#define MAX_ITEMS 6

int main() {
    char items[MAX_ITEMS][20] = {
        "Pocion", "Pokeball", "Antidoto", "", "", ""
    };
    int cantidades[MAX_ITEMS] = {3, 5, 2, 0, 0, 0};

    printf("=== Inventario ===\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (cantidades[i] > 0) {
            printf("%-15s x%d\n", items[i], cantidades[i]);
        }
    }

    /* Total de ítems */
    int total = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        total += cantidades[i];
    }
    printf("------------------\n");
    printf("Total de objetos: %d\n", total);

    return 0;
}
