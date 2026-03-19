# Fase 1: Fundamentos de C y Arquitectura GBA

## Objetivo de esta fase

Al terminar esta fase deberías poder:
- Escribir programas básicos en C (variables, funciones, punteros simples).
- Explicar con tus palabras qué es una ROM y cómo funciona la GBA.
- Abrir la ROM de FireRed en un editor hexadecimal y entender qué estás viendo.

**Duración estimada:** 3-4 semanas (5-10 horas por semana).

---

## Módulo 1.1 — Primeros pasos en C

### Conceptos a dominar

- [ ] Variables y tipos básicos: `int`, `char`, `float`
- [ ] Operadores aritméticos y de comparación
- [ ] Condicionales: `if`, `else if`, `else`
- [ ] Bucles: `for`, `while`, `do-while`
- [ ] Funciones: definición, parámetros, valor de retorno
- [ ] Arrays (arreglos)
- [ ] Strings como arrays de `char`

### Ejercicios prácticos

Crea los siguientes archivos en `src/ejercicios/fase_1/`:

#### ejercicio_01.c — Hola mundo
```c
#include <stdio.h>

int main() {
    printf("Hola, mundo del modding GBA!\n");
    return 0;
}
```

#### ejercicio_02.c — Calculadora de daño Pokémon (simplificada)
```c
#include <stdio.h>

// Fórmula simplificada de daño en juegos Pokémon:
// daño = ((2 * nivel / 5 + 2) * poder * ataque / defensa) / 50 + 2
int calcular_danio(int nivel, int poder, int ataque, int defensa) {
    return ((2 * nivel / 5 + 2) * poder * ataque / defensa) / 50 + 2;
}

int main() {
    int danio = calcular_danio(50, 90, 100, 80);
    printf("Daño calculado: %d\n", danio);
    return 0;
}
```

#### ejercicio_03.c — Inventario de ítems
```c
#include <stdio.h>

#define MAX_ITEMS 6

int main() {
    char items[MAX_ITEMS][20] = {
        "Poción", "Pokéball", "Antídoto", "", "", ""
    };
    int cantidades[MAX_ITEMS] = {3, 5, 2, 0, 0, 0};

    printf("=== Inventario ===\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (cantidades[i] > 0) {
            printf("%-15s x%d\n", items[i], cantidades[i]);
        }
    }
    return 0;
}
```

### Cómo compilar y ejecutar en tu PC

```bash
# Instalar GCC en Windows (con MinGW o WSL) / Linux / macOS
gcc ejercicio_01.c -o ejercicio_01
./ejercicio_01
```

---

## Módulo 1.2 — Tipos de datos de GBA

En GBA (y en pokefirered) se usan tipos de datos específicos definidos en `include/types.h`:

```c
typedef unsigned char      u8;   // 0 a 255
typedef unsigned short     u16;  // 0 a 65535
typedef unsigned int       u32;  // 0 a 4294967295
typedef signed char        s8;   // -128 a 127
typedef signed short       s16;  // -32768 a 32767
typedef signed int         s32;  // -2147483648 a 2147483647
typedef volatile u8        vu8;
typedef volatile u16       vu16;
typedef volatile u32       vu32;
```

**¿Por qué importa esto?**
El GBA tiene memoria limitada. Usar `u8` en lugar de `int` puede ahorrar 3 bytes por variable, lo que importa cuando tienes miles de Pokémon, ítems y mapas en memoria.

### Ejercicio 1.2 — Practica con los tipos de GBA

Crea `src/ejercicios/fase_1/ejercicio_04.c`:
```c
#include <stdio.h>

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

// Simula una "estructura de Pokémon" simplificada
typedef struct {
    u16 especie;    // ID del Pokémon (ej: 25 = Pikachu)
    u8  nivel;      // 1 a 100
    u16 ps_actual;  // Puntos de salud actuales
    u16 ps_max;     // Puntos de salud máximos
} Pokemon;

int main() {
    Pokemon mi_pikachu = {25, 50, 120, 120};

    printf("Especie: %d\n", mi_pikachu.especie);
    printf("Nivel: %d\n", mi_pikachu.nivel);
    printf("PS: %d / %d\n", mi_pikachu.ps_actual, mi_pikachu.ps_max);

    return 0;
}
```

---

## Módulo 1.3 — ¿Qué es una ROM de GBA?

### Concepto

Una ROM es un archivo binario que contiene todo el juego:
- **Código ejecutable**: instrucciones que la CPU GBA ejecuta (en ARM/Thumb).
- **Datos**: mapas, Pokémon, ítems, diálogos, gráficos, música.

El archivo `.gba` de FireRed tiene exactamente **32 MB** (33,554,432 bytes).

### Exploración con HxD

1. Descarga e instala [HxD](https://mh-nexus.de/en/hxd/).
2. Abre tu ROM de FireRed (nunca trabajes sobre el original; haz una copia primero).
3. Los primeros 192 bytes son el **header de la ROM GBA**:
   - Offset `0x000`: Punto de entrada del código (4 bytes).
   - Offset `0x004`: Logo de Nintendo (156 bytes).
   - Offset `0x0A0`: Título del juego en ASCII: "POKEMON FIRE" (12 bytes).
   - Offset `0x0AC`: Código del juego: "BPRE" para FireRed inglés (4 bytes).
   - Offset `0x0B0`: Versión del juego (1 byte).

### Actividad

1. Abre la ROM en HxD.
2. Ve a Edit → Go to offset → escribe `A0` (en hexadecimal).
3. Verifica que lees "POKEMON FIRE" en la columna de texto de la derecha.
4. Anota en tus notas: ¿qué significa el offset `0x0AC`?

---

## Módulo 1.4 — Punteros (introducción)

Los punteros son fundamentales para entender cómo el GBA accede a memoria. Aquí una introducción mínima:

```c
#include <stdio.h>

int main() {
    int vida = 100;
    int *ptr_vida = &vida;  // ptr_vida guarda la DIRECCIÓN de la variable vida

    printf("Valor de vida: %d\n", vida);
    printf("Dirección de vida: %p\n", (void*)ptr_vida);
    printf("Valor a través del puntero: %d\n", *ptr_vida);

    // Modificar el valor a través del puntero
    *ptr_vida = 50;
    printf("Vida después de modificar con puntero: %d\n", vida);

    return 0;
}
```

**Analogía con GBA:** Cuando el juego quiere saber los PS de tu Pikachu, usa un puntero que apunta a la dirección de memoria donde están guardados. Así puede leerlos y modificarlos.

---

## Entregables de la Fase 1

Al terminar esta fase, tu repositorio debe contener:

```
src/
└── ejercicios/
    └── fase_1/
        ├── ejercicio_01.c    ← Hola mundo
        ├── ejercicio_02.c    ← Calculadora de daño
        ├── ejercicio_03.c    ← Inventario de ítems
        ├── ejercicio_04.c    ← Estructura de Pokémon
        └── ejercicio_05.c    ← Ejercicio de punteros (propio)
docs/
└── notas/
    └── fase_1_notas.md       ← Tus notas personales de lo aprendido
```

## Criterios de éxito

- [x] Puedo compilar y ejecutar los 5 ejercicios sin errores.
- [x] Entiendo la diferencia entre `u8`, `u16` y `u32`.
- [x] Puedo abrir la ROM en HxD y encontrar el título del juego.
- [x] Puedo explicar qué es un puntero con mis propias palabras.

## Siguiente paso

Cuando completes todos los criterios, pasa a [Fase 2: Herramientas de ROM Hacking](fase_2_herramientas_rom_hacking.md).
