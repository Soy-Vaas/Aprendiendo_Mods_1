/* Ejercicio 02 - Calculadora de daño Pokémon (simplificada)
 * Fase 1: Fundamentos de C
 * Fórmula simplificada:
 *   daño = ((2 * nivel / 5 + 2) * poder * ataque / defensa) / 50 + 2
 */
#include <stdio.h>

int calcular_danio(int nivel, int poder, int ataque, int defensa) {
    return ((2 * nivel / 5 + 2) * poder * ataque / defensa) / 50 + 2;
}

int main() {
    int danio = calcular_danio(50, 90, 100, 80);
    printf("Danio calculado (nivel 50, poder 90, atk 100, def 80): %d\n", danio);

    /* Prueba con distintos niveles */
    printf("Nivel 10: %d\n", calcular_danio(10, 90, 100, 80));
    printf("Nivel 50: %d\n", calcular_danio(50, 90, 100, 80));
    printf("Nivel 100: %d\n", calcular_danio(100, 90, 100, 80));

    return 0;
}
