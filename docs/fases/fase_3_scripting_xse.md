# Fase 3: Scripting con XSE

## Objetivo de esta fase

Al terminar esta fase deberías poder:
- Escribir scripts en XSE para crear diálogos, dar ítems y activar eventos.
- Asignar scripts a NPCs y tiles del suelo en AdvanceMap.
- Tener un room funcional con al menos 3 eventos personalizados.

**Prerrequisito:** Haber completado la Fase 2.
**Duración estimada:** 3-4 semanas.

---

## ¿Qué es XSE?

XSE (Cross Script Editor) es un programa que te permite escribir y compilar scripts para juegos Pokémon GBA. Los scripts controlan:

- Qué dice un NPC cuando lo hablas.
- Qué pasa cuando pisas un tile especial.
- Si una batalla comienza.
- Qué ítem recibes al abrir un cofre.
- Si una puerta se abre o se bloquea.

Los scripts se escriben en un lenguaje de alto nivel que XSE compila directamente dentro de la ROM.

---

## Módulo 3.1 — Instalación y primer script

### Instalar XSE

1. Busca "XSE download PokéCommunity" y descarga la última versión.
2. Extrae en `C:\herramientas\XSE\`.
3. Abre `XSE.exe` y selecciona tu ROM de prueba.

### Estructura básica de un script

```
#dynamic 0x800000

#org @main
  msgbox @texto MSG_NORMAL
  end

#org @texto
  = ¡Hola! Soy un NPC personalizado.
```

**Explicación línea por línea:**

| Línea | Significado |
|-------|-------------|
| `#dynamic 0x800000` | XSE busca espacio libre desde este offset para insertar el script |
| `#org @main` | Define el punto de inicio del script (etiqueta `@main`) |
| `msgbox @texto MSG_NORMAL` | Muestra un cuadro de diálogo con el texto de `@texto` |
| `end` | Termina el script y devuelve el control al jugador |
| `#org @texto` | Define la etiqueta donde está el texto del diálogo |
| `= ¡Hola! ...` | El texto a mostrar (el `=` indica que es una string) |

---

## Módulo 3.2 — Tipos de msgbox

| Constante | Comportamiento |
|-----------|----------------|
| `MSG_NORMAL` | Caja simple, el jugador presiona A para cerrar |
| `MSG_YESNO` | Muestra "¿SÍ? ¿NO?" y guarda la respuesta |
| `MSG_SIGN` | Para letreros (sin sonido de "bip" de NPC) |
| `MSG_NPC` | Caja de NPC con el retrato del personaje |

### Ejemplo: NPC con opción Sí/No

```
#dynamic 0x800000

#org @main
  msgbox @pregunta MSG_YESNO
  compare LASTRESULT 0x1
  if 0x1 goto @si
  msgbox @no MSG_NORMAL
  end

#org @si
  msgbox @respuesta_si MSG_NORMAL
  end

#org @pregunta
  = ¿Quieres recibir una Poción?

#org @no
  = ¡Está bien! ¡Hasta luego!

#org @respuesta_si
  = ¡Aquí tienes una Poción!
```

---

## Módulo 3.3 — Dar ítems al jugador

```
#dynamic 0x800000

#org @main
  checkitemspace ITEM_POTION 0x1
  compare LASTRESULT 0x0
  if 0x1 goto @bolsa_llena
  giveitem ITEM_POTION 0x1 MSG_OBTAIN
  end

#org @bolsa_llena
  msgbox @texto_lleno MSG_NORMAL
  end

#org @texto_lleno
  = No tienes espacio en la bolsa.
```

**Constantes de ítems útiles:**
| Constante | Ítem |
|-----------|------|
| `ITEM_POTION` | Poción |
| `ITEM_ANTIDOTE` | Antídoto |
| `ITEM_POKEBALL` | Pokéball |
| `ITEM_REPEL` | Repelente |
| `ITEM_ESCAPE_ROPE` | Cuerda Huida |

> Consulta la lista completa en `include/items.h` del repositorio pokefirered.

---

## Módulo 3.4 — Mover NPCs

El comando `applymovement` mueve un NPC siguiendo una secuencia de movimientos.

```
#dynamic 0x800000

#org @main
  applymovement 0xFF @movimientos
  waitmovement 0x0
  end

#org @movimientos
  #raw 0x0B  ; Camina hacia abajo 1 paso
  #raw 0x0B  ; Camina hacia abajo 1 paso
  #raw 0x11  ; Gira a la derecha
  #raw 0xFE  ; Fin de la secuencia de movimiento
```

**Códigos de movimiento comunes:**
| Código | Acción |
|--------|--------|
| `0x0A` | Caminar hacia arriba |
| `0x0B` | Caminar hacia abajo |
| `0x0C` | Caminar hacia la izquierda |
| `0x0D` | Caminar hacia la derecha |
| `0x0E` | Girar hacia arriba |
| `0x0F` | Girar hacia abajo |
| `0x10` | Girar hacia la izquierda |
| `0x11` | Girar hacia la derecha |
| `0xFE` | Fin de la secuencia |

---

## Módulo 3.5 — Flags y variables

Los **flags** son como interruptores (encendido/apagado). Se usan para recordar si ya hablaste con alguien, si ya abriste un cofre, etc.

Las **variables** guardan valores numéricos (0-65535).

```
#dynamic 0x800000

#org @main
  checkflag FLAG_COFRE_ABIERTO
  if 0x1 goto @ya_abierto
  setflag FLAG_COFRE_ABIERTO
  giveitem ITEM_REPEL 0x1 MSG_OBTAIN
  end

#org @ya_abierto
  msgbox @texto_vacio MSG_SIGN
  end

#org @texto_vacio
  = El cofre está vacío.
```

> **Flags seguros para usar en tus mods:** `0x500` a `0x5FF` (reservados para el jugador).
> No uses flags del `0x0` al `0x4FF` sin verificar que no están en uso por el juego base.

---

## Módulo 3.6 — Asignar un script a un NPC en AdvanceMap

1. Abre tu ROM en AdvanceMap.
2. Ve al mapa que quieres modificar.
3. Pestaña **"Events"** → selecciona o crea un NPC.
4. En el campo **"Script offset"**, escribe el offset donde XSE insertó tu script (XSE te lo dice al compilar).
5. Guarda y prueba en el emulador.

---

## Proyecto de la Fase 3: Mini-room con eventos

### Diseño del room

Crea un mapa pequeño (10×8 bloques) con:

1. **NPC "Mago"**: cuando lo hablas, pregunta si quieres un ítem.
   - Si dices SÍ: te da un Repelente.
   - Si dices NO: dice "¡Hasta la próxima!".

2. **NPC "Guardia"**: bloquea una puerta y solo se mueve si tienes activado un flag específico.

3. **Tile especial en el suelo**: al pisarlo, muestra un letrero con un mensaje misterioso.

### Archivos del proyecto

Guarda tus scripts en `src/scripts/fase_3/`:
```
src/
└── scripts/
    └── fase_3/
        ├── npc_mago.xse       ← Script del NPC Mago
        ├── npc_guardia.xse    ← Script del NPC Guardia
        └── tile_especial.xse  ← Script del tile del suelo
```

---

## Entregables de la Fase 3

```
src/
└── scripts/
    └── fase_3/
        ├── npc_mago.xse
        ├── npc_guardia.xse
        └── tile_especial.xse
roms/
└── FireRed_fase3_v1.gba       ← ROM con los 3 eventos funcionando
docs/
└── notas/
    └── fase_3_notas.md        ← Lo aprendido y los errores que encontraste
```

## Criterios de éxito

- [x] Tengo al menos 1 NPC con diálogo propio funcionando en el emulador.
- [x] El sistema de Sí/No funciona correctamente.
- [x] La lógica de flags impide recoger un ítem dos veces.
- [x] Mis scripts están guardados en el repositorio.

## Siguiente paso

Cuando completes todos los criterios, pasa a [Fase 4: Programación con la Descompilación](fase_4_decomp_c.md).
