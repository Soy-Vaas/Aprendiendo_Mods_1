# Fase 4: Programación con la Descompilación de FireRed

## Objetivo de esta fase

Al terminar esta fase deberías poder:
- Clonar, configurar y compilar el proyecto pokefirered.
- Modificar datos de un mapa editando archivos de código fuente en C y Poryscript.
- Agregar un nuevo NPC con script propio usando el sistema de la descompilación.
- Compilar la ROM modificada y probarla en mGBA.

**Prerrequisito:** Haber completado la Fase 3.
**Duración estimada:** 6-8 semanas.

---

## ¿Qué es la descompilación de pokefirered?

El proyecto **pret/pokefirered** es una reconstrucción completa del código fuente original de Pokémon FireRed en C y ensamblador ARM. El código fue descompilado y organizado de forma que, al compilarlo, produce una ROM bit-a-bit idéntica al juego original.

Esto significa que puedes:
- **Leer el código real del juego** y entender cómo funciona todo.
- **Modificar cualquier cosa**: mecánicas, datos, mapas, scripts.
- **Compilar** tu versión modificada como si fuera el juego original.

---

## Módulo 4.1 — Instalación del entorno

### Requisitos

| Herramienta | Propósito |
|-------------|-----------|
| **Git** | Clonar el repositorio |
| **devkitARM** | Compilador de C para procesadores ARM (GBA) |
| **Python 3** | Scripts de compilación |
| **mGBA** | Emulador para probar la ROM |

### Instalación en Windows (usando MSYS2/devkitPro)

1. **Instala devkitPro** (incluye devkitARM):
   - Ve a https://devkitpro.org/wiki/Getting_Started
   - Descarga `devkitProUpdater-3.x.x.exe` y ejecútalo.
   - Instala el paquete `gba-dev`.

2. **Instala Git**: https://git-scm.com

3. **Instala Python 3**: https://www.python.org (marca "Add to PATH" al instalar)

4. **Clona pokefirered** (desde la terminal de MSYS2):
   ```bash
   git clone https://github.com/pret/pokefirered
   cd pokefirered
   ```

5. **Intenta compilar** (primera vez toma ~10 minutos):
   ```bash
   make
   ```
   Si termina sin errores, verás `pokefirered.gba` en la carpeta raíz.

### Instalación en Linux (Ubuntu/Debian)

```bash
# Instalar dependencias
sudo apt-get install gcc git python3

# Instalar devkitARM
# Sigue las instrucciones en: https://devkitpro.org/wiki/devkitPro_pacman

# Clonar y compilar
git clone https://github.com/pret/pokefirered
cd pokefirered
make
```

---

## Módulo 4.2 — Estructura del repositorio pokefirered

```
pokefirered/
├── src/              ← Código fuente en C (.c) — la lógica del juego
├── include/          ← Headers (.h) — definiciones, constantes, tipos
├── data/             ← Datos del juego: Pokémon, ítems, movimientos, etc.
├── maps/             ← Datos de los mapas (en formato JSON/Poryscript)
│   └── PalletTown/   ← Datos del Pueblo Paleta
├── graphics/         ← Sprites y tilesets comprimidos
├── sound/            ← Música y efectos de sonido
├── tools/            ← Programas auxiliares usados al compilar
└── Makefile          ← Sistema de compilación
```

### Archivos clave para modificar mapas

```
maps/PalletTown/
├── map.json          ← Configuración del mapa (dimensiones, música, encuentros)
├── scripts.pory      ← Scripts de los NPCs en Poryscript
└── header.inc        ← Nombre y tipo del mapa
```

---

## Módulo 4.3 — Tu primer cambio: renombrar un NPC

### Cómo funciona el sistema de nombres de NPCs

En pokefirered, los textos de diálogo están en los archivos `.pory` de cada mapa, dentro del bloque del script del NPC.

1. Abre el archivo `maps/PalletTown/scripts.pory`.
2. Busca el NPC del Prof. Oak (busca "Professor Oak" o "PROF_OAK").
3. Cambia el texto de su diálogo.
4. Recompila con `make`.
5. Prueba en mGBA.

### Ejemplo de un script en Poryscript

```
script PalletTown_EventScript_ProfOak {
    msgbox(PalletTown_Text_OakIntro, MSGBOX_DEFAULT)
    end
}

text PalletTown_Text_OakIntro {
    format("¡Bienvenido al mundo de los{NEWLINE}"
           "Pokémon! Mi nombre es Oak.")
}
```

Para cambiar el texto, solo modifica la cadena entre comillas y ejecuta `make`.

---

## Módulo 4.4 — Agregar un nuevo NPC

Los NPCs de un mapa se definen en el archivo `map.json` (o en archivos `.inc` en algunos mapas). Aquí el flujo completo:

### Paso 1: Agregar el NPC en map.json

Abre `maps/PalletTown/map.json` y busca la sección `"object_events"`. Agrega una entrada:

```json
{
    "graphics_id": "OBJ_EVENT_GFX_YOUNGSTER",
    "x": 5,
    "y": 7,
    "elevation": 3,
    "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
    "movement_range_x": 0,
    "movement_range_y": 0,
    "trainer_type": "TRAINER_TYPE_NONE",
    "trainer_sight_or_berry_tree_id": 0,
    "script": "PalletTown_EventScript_MiNuevoNPC",
    "flag": "FLAG_SPECIAL_0"
}
```

### Paso 2: Crear el script en scripts.pory

Agrega al final de `maps/PalletTown/scripts.pory`:

```
script PalletTown_EventScript_MiNuevoNPC {
    msgbox(PalletTown_Text_MiNuevoNPC, MSGBOX_NPC)
    end
}

text PalletTown_Text_MiNuevoNPC {
    format("¡Este es mi primer NPC{NEWLINE}"
           "creado desde el código fuente!")
}
```

### Paso 3: Compilar y probar

```bash
make
```

Abre `pokefirered.gba` en mGBA y ve al Pueblo Paleta. Deberías ver tu nuevo NPC.

---

## Módulo 4.5 — Modificar datos de Pokémon

Los datos base de los Pokémon están en `src/data/pokemon/base_stats/`. Cada Pokémon tiene su propio archivo.

### Ejemplo: modificar las estadísticas de Pikachu

Abre `src/data/pokemon/base_stats/pikachu.h`:

```c
const struct BaseStats gBaseStats_Pikachu = {
    .baseHP        = 35,
    .baseAttack    = 55,
    .baseDefense   = 30,
    .baseSpeed     = 90,
    .baseSpAttack  = 50,
    .baseSpDefense = 40,
    // ...
};
```

Cambia `.baseSpeed` a `110` para tener un Pikachu más rápido. Luego `make` y prueba.

> ⚠️ Documenta SIEMPRE los cambios que hagas. Es fácil perder el rastro de qué modificaste.

---

## Módulo 4.6 — Trabajar con Git en tu fork

**¿Por qué usar un fork?**
Al tener tu propio fork de pokefirered, puedes hacer commits de tus cambios, volver atrás si algo se rompe, y eventualmente compartir tu mod.

```bash
# Crear una rama para tus cambios
git checkout -b mi-mod

# Después de cada cambio significativo
git add .
git commit -m "Agrega NPC personalizado en Pueblo Paleta"

# Ver el historial de cambios
git log --oneline
```

---

## Entregables de la Fase 4

```
(tu fork de pokefirered)/
├── maps/PalletTown/scripts.pory   ← Con al menos 1 NPC nuevo
├── maps/PalletTown/map.json       ← Con el NPC referenciado
└── src/data/pokemon/base_stats/   ← Con al menos 1 Pokémon modificado

docs/
└── notas/
    └── fase_4_notas.md            ← Proceso de instalación, errores y soluciones
```

## Criterios de éxito

- [x] Pude compilar pokefirered sin errores.
- [x] Cambié el diálogo de al menos un NPC existente.
- [x] Agregué un NPC nuevo con su propio script.
- [x] Modifiqué al menos una estadística de un Pokémon.
- [x] Tengo todos los cambios en commits de Git.

## Siguiente paso

Cuando completes todos los criterios, pasa a [Fase 5: Proyecto Final](fase_5_proyecto_final.md).
