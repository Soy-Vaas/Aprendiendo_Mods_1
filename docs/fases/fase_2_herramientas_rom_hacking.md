# Fase 2: Herramientas de ROM Hacking

## Objetivo de esta fase

Al terminar esta fase deberías poder:
- Abrir la ROM de FireRed con AdvanceMap y navegar por sus mapas.
- Editar tiles, eventos y la posición de NPCs.
- Entender la estructura de un "room" (mapa/sala) en términos de datos.

**Prerrequisito:** Haber completado la Fase 1.
**Duración estimada:** 2-3 semanas.

---

## Herramientas a instalar

### AdvanceMap 1.92

Herramienta gráfica para editar mapas de juegos Pokémon GBA.

**Cómo conseguirlo:**
1. Ve a PokéCommunity: https://www.pokecommunity.com
2. Busca en el subforo "ROM Hacking Tools" el hilo de AdvanceMap.
3. Descarga `AdvanceMap1.92.rar` y extrae en una carpeta (ej: `C:\herramientas\AdvanceMap`).

**Nota:** AdvanceMap solo corre en Windows. Si usas Linux/macOS, instala Wine o usa una VM.

### HxD (editor hexadecimal)

Ya instalado en la Fase 1.

### Backup de la ROM

**IMPORTANTE:** Antes de cualquier modificación, haz copias de la ROM:
```
roms/
├── FireRed_original.gba      ← Nunca tocas este archivo
├── FireRed_prueba.gba        ← Para experimentos sin miedo
└── FireRed_mod_v1.gba        ← Tu trabajo real (cuando llegue el momento)
```

---

## Módulo 2.1 — Estructura de un room en FireRed

Un "room" o mapa en FireRed es un conjunto de datos que incluye:

| Componente | Descripción |
|-----------|-------------|
| **Tileset** | Conjunto de imágenes de 8×8 px que forman el suelo, paredes, etc. |
| **Layout (diseño)** | Cómo se ordenan los tiles para dibujar el mapa |
| **Dimensiones** | Ancho y alto del mapa en bloques (cada bloque = 2×2 tiles = 16×16 px) |
| **Eventos** | Lista de NPCs, objetos en el suelo, warps (puertas/salidas) y triggers |
| **Conexiones** | Con qué otros mapas conecta al salir por los bordes |
| **Encuentros** | Pokémon salvajes que aparecen en la hierba o el agua |
| **Script principal** | Script que se ejecuta cuando entras al mapa |
| **Música** | ID de la canción que suena en este mapa |

### Sistema de coordenadas

- **Bank (banco)**: Grupo de mapas. Ej: Bank 0 = Pueblo Paleta y sus interiores.
- **Map ID**: Número del mapa dentro del banco.
- **Coordenadas (X, Y)**: Posición en bloques dentro del mapa.

---

## Módulo 2.2 — Exploración con AdvanceMap

### Paso a paso: abrir la ROM

1. Abre AdvanceMap.
2. File → Open ROM → selecciona `FireRed_prueba.gba`.
3. En el panel izquierdo verás la lista de Banks y Maps.
4. Abre **Bank 0, Map 0** (Pueblo Paleta / Pallet Town).

### Interfaz de AdvanceMap

```
┌─────────────────────────────────────────┐
│  [Map Editor] [Event Editor] [Header]   │ ← Pestañas principales
├─────────────────────────────────────────┤
│                                         │
│   Vista del mapa del Pueblo Paleta      │
│                                         │
├────────────┬────────────────────────────┤
│ Lista de   │  Propiedades del tile/     │
│ tiles      │  evento seleccionado       │
└────────────┴────────────────────────────┘
```

### Actividad 2.2.1 — Explorar el Pueblo Paleta

1. Abre Bank 0, Map 0.
2. Identifica visualmente: el laboratorio del Prof. Oak, la casa de Ash, la casa de Gary.
3. Haz clic en la pestaña **"Events"** y observa los NPCs listados.
4. Haz clic en el sprite del Prof. Oak (un NPC) y anota sus datos:
   - Sprite ID:
   - Posición X, Y:
   - Tipo de movimiento:
   - Script que ejecuta:
5. Guarda tus notas en `docs/notas/fase_2_notas.md`.

---

## Módulo 2.3 — Editar el mapa (ejercicio práctico)

### Cambiar un tile del suelo

**Objetivo:** Cambiar un pedazo de camino por hierba alta en el Pueblo Paleta.

1. Con el mapa abierto, selecciona la pestaña **"Map"**.
2. En el panel de tiles de la derecha, busca el tile de hierba alta.
3. Haz clic izquierdo sobre un tile de camino en el mapa para reemplazarlo.
4. Guarda con File → Save Map.
5. Abre el emulador y carga la ROM modificada para ver el cambio.

> ⚠️ **Advertencia:** Cambiar tiles de comportamiento (permission/movement) puede hacer que el jugador atraviese paredes. Practica primero solo con tiles visuales.

### Mover un NPC

1. Ve a la pestaña **"Events"**.
2. Haz clic en el NPC que quieres mover.
3. Modifica los campos X e Y en el panel de propiedades.
4. Guarda y prueba en el emulador.

---

## Módulo 2.4 — Entender los permisos de movimiento

Cada tile tiene dos componentes:
1. **Apariencia visual**: qué imagen se dibuja.
2. **Permiso de movimiento**: si el jugador puede pisarlo o no.

Permisos comunes en FireRed:
| Valor | Significado |
|-------|-------------|
| `0x00` | Camino libre |
| `0x01` | Hierba alta (activa encuentros) |
| `0x0C` | Agua (surf) |
| `0xFF` | Pared/obstáculo (no se puede pasar) |

En AdvanceMap, puedes ver el mapa de permisos en View → Show Movements.

---

## Módulo 2.5 — Crear un nuevo mapa vacío

1. File → New Map.
2. Elige dimensiones: 20×15 bloques (tamaño de ciudad pequeña).
3. Elige el tileset: usa el de "Pallet Town" para empezar.
4. Guarda el mapa en un banco vacío.

Este será el "room" que modificarás en las fases siguientes.

---

## Entregables de la Fase 2

```
roms/
├── FireRed_original.gba
└── FireRed_fase2_v1.gba     ← ROM con los cambios de esta fase
docs/
└── notas/
    └── fase_2_notas.md      ← Capturas, observaciones y aprendizajes
```

El archivo `fase_2_notas.md` debe incluir:
- Datos del NPC del Prof. Oak que anotaste.
- Una captura (descripción textual o imagen embebida) del mapa modificado.
- Al menos 2 cosas que no funcionaron como esperabas y cómo las resolviste.

## Criterios de éxito

- [x] Puedo navegar entre mapas en AdvanceMap sin perderme.
- [x] Cambié al menos un tile visual en el mapa de prueba.
- [x] Moví al menos un NPC a una nueva posición.
- [x] Creé un mapa nuevo vacío.
- [x] La ROM modificada carga correctamente en el emulador.

## Siguiente paso

Cuando completes todos los criterios, pasa a [Fase 3: Scripting con XSE](fase_3_scripting_xse.md).
