# Recursos y Documentación

## Lenguajes que necesitas aprender

### 1. C (lenguaje principal)

**¿Por qué C?**
La ROM de Pokémon FireRed fue compilada originalmente en C. El proyecto de descompilación [`pokefirered`](https://github.com/pret/pokefirered) reconstruyó el código fuente completo en C, lo que permite modificarlo y recompilarlo. Aprender C te da acceso total al juego.

**Nivel requerido:** Básico-intermedio.
- Variables, tipos (`int`, `u8`, `u16`, `u32`), operadores.
- Condicionales (`if`/`else`/`switch`).
- Bucles (`for`, `while`).
- Funciones y paso de parámetros.
- Punteros (al menos conceptos básicos: qué es una dirección de memoria).
- Estructuras (`struct`).

**Recursos para aprender C:**
| Recurso | Tipo | Idioma | Link |
|---------|------|--------|------|
| CS50x de Harvard | Curso gratuito | Inglés/subtítulos ES | https://cs50.harvard.edu/x |
| "El lenguaje de programación C" (Kernighan & Ritchie) | Libro clásico | Inglés | Disponible en librerías |
| Learn-C.org | Tutorial interactivo | Inglés | https://www.learn-c.org |
| Programiz C Tutorial | Tutorial | Inglés | https://www.programiz.com/c-programming |
| minicurso C en español | YouTube | Español | Busca "C desde cero español" en YouTube |

---

### 2. XSE / Scripting de FireRed (scripting de eventos)

**¿Qué es?**
XSE (Cross Script Editor) es un lenguaje de scripting específico para juegos de Pokémon GBA. Permite crear diálogos, dar ítems, activar batallas y controlar eventos del juego sin necesidad de programar en C.

**Nivel requerido:** Básico.
- Aprender los comandos más usados (`msgbox`, `giveitem`, `applymovement`, `end`, `return`).
- Entender el sistema de variables y flags del juego.

**Recursos para XSE:**
| Recurso | Tipo | Link |
|---------|------|------|
| Documentación oficial de comandos XSE | Referencia | Incluida en el programa XSE al descargarlo |
| Tutorial XSE en PokéCommunity | Foro/Tutorial | https://www.pokecommunity.com (busca "XSE tutorial") |
| Bulbapedia - Script commands | Wiki | https://bulbapedia.bulbagarden.net/wiki/Appendix:FireRed_and_LeafGreen_script_commands |

---

### 3. Poryscript (opcional, mejora XSE)

**¿Qué es?**
Poryscript es un lenguaje de scripting moderno que se compila a los scripts nativos de GBA. Se usa en la descompilación de pokefirered y es más legible que el XSE clásico.

**Recursos:**
| Recurso | Tipo | Link |
|---------|------|------|
| Repositorio oficial de Poryscript | GitHub | https://github.com/huderlem/poryscript |
| Documentación de Poryscript | README del repositorio | Mismo link de arriba |

---

### 4. Ensamblador ARM/Thumb (avanzado, opcional)

**¿Qué es?**
El GBA usa un procesador ARM7TDMI. Algunas partes del juego están escritas en ensamblador. No es necesario para el proyecto básico, pero es útil para hacks avanzados.

**Recursos:**
| Recurso | Tipo | Link |
|---------|------|------|
| ARM Developer Documentation | Referencia oficial | https://developer.arm.com/documentation |
| Tutorial de ASM hacking en PokéCommunity | Foro | https://www.pokecommunity.com |
| GBATEK (arquitectura GBA completa) | Referencia técnica | https://problemkaputt.de/gbatek.htm |

---

## Herramientas necesarias

### Herramientas de ROM Hacking (Fase 2-3)

| Herramienta | Uso | Link de descarga |
|-------------|-----|-----------------|
| **AdvanceMap 1.92** | Editor visual de mapas GBA | https://www.pokecommunity.com (busca "AdvanceMap") |
| **XSE (Cross Script Editor)** | Editor de scripts de eventos | https://www.pokecommunity.com (busca "XSE download") |
| **NSE (Nameless Sprite Editor)** | Editar sprites de NPCs | Foro PokéCommunity |
| **HxD** | Editor hexadecimal (para explorar la ROM) | https://mh-nexus.de/en/hxd/ |
| **Lunar IPS** | Aplicar parches IPS a la ROM | Busca "Lunar IPS download" |

### Herramientas de desarrollo (Fase 4)

| Herramienta | Uso | Link |
|-------------|-----|------|
| **Git** | Control de versiones | https://git-scm.com |
| **devkitARM** | Compilador de C para GBA | https://devkitpro.org |
| **mGBA** | Emulador GBA con herramientas de debug | https://mgba.io |
| **VS Code** | Editor de código | https://code.visualstudio.com |
| **Python 3** | Requerido por el sistema de compilación de pokefirered | https://www.python.org |

### Repositorio principal

| Recurso | Descripción | Link |
|---------|-------------|------|
| **pokefirered** | Descompilación completa de FireRed en C | https://github.com/pret/pokefirered |
| **pret wiki** | Guías de instalación y desarrollo | https://github.com/pret/pokefirered/wiki |
| **poryscript** | Compilador de scripts modernos | https://github.com/huderlem/poryscript |

---

## Comunidades donde pedir ayuda

| Comunidad | Plataforma | Enfoque |
|-----------|-----------|---------|
| PokéCommunity ROM Hacking | Foro | ROM hacking general, XSE, AdvanceMap |
| pret Discord | Discord | Descompilación, C, pokefirered |
| r/PokemonROMhacks | Reddit | Preguntas generales |
| GitHub Issues de pokefirered | GitHub | Problemas de compilación |

---

## Arquitectura de Pokémon FireRed (referencia rápida)

```
ROM de FireRed (32 MB)
├── Código ejecutable (C compilado → ARM/Thumb)
├── Datos de mapas (tileset, eventos, NPCs, conexiones)
├── Scripts de eventos (diálogos, ítems, batallas)
├── Datos de Pokémon (estadísticas, movimientos, evoluciones)
├── Sprites y gráficos (comprimidos con LZ77)
└── Música y efectos de sonido (formato GB/GBA)
```

**Tipos de memoria en GBA:**
- `EWRAM` (0x02000000): RAM externa, 256 KB — datos de juego en tiempo real.
- `IWRAM` (0x03000000): RAM interna, 32 KB — código y stack de alta velocidad.
- `ROM` (0x08000000): La ROM del juego, solo lectura durante ejecución.
- `SRAM/Flash` (0x0E000000): La memoria de guardado.

---

## Glosario básico

| Término | Significado |
|---------|-------------|
| **ROM** | Read-Only Memory; el archivo del juego (`.gba`) |
| **Offset** | Posición en bytes dentro del archivo ROM |
| **Tileset** | Conjunto de imágenes pequeñas (tiles 8×8 px) que forman el mapa |
| **Tile** | Bloque gráfico de 8×8 píxeles |
| **Flag** | Variable binaria (0 o 1) que el juego usa para recordar eventos |
| **Variable** | Valor numérico que el juego usa internamente |
| **Script** | Secuencia de comandos que define el comportamiento de un evento |
| **Overworld** | El mapa del mundo donde camina el jugador |
| **Bank** | Grupo de mapas relacionados en la ROM |
| **IPS/UPS** | Formato de parche para distribuir ROMs modificadas |
| **Decomp** | Abreviación de "descompilación"; proyecto que reconstruyó el código fuente original |
