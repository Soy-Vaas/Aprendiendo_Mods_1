# Fase 5: Proyecto Final — Room Personalizado

## Objetivo de esta fase

Crear un room completamente personalizado e integrado en Pokémon FireRed, aplicando todo lo aprendido en las fases anteriores.

**Prerrequisito:** Haber completado las Fases 1 a 4.
**Duración estimada:** 4-6 semanas.

---

## Diseño del room

Antes de programar nada, diseña tu room en papel o en un editor de texto:

### Plantilla de diseño

```
docs/notas/diseno_room_final.md
```

Incluye:
1. **Nombre del mapa**: ej. "Cueva del Eco"
2. **Dimensiones**: ej. 20×15 bloques
3. **Tileset**: el que mejor se adapte al ambiente
4. **Descripción del ambiente**: ¿Es una cueva? ¿Una ciudad? ¿Un edificio?
5. **Lista de NPCs**: nombre, posición, qué dicen, si bloquean algo
6. **Eventos especiales**: ítems ocultos, batallas, cutscenes
7. **Conexión con el mundo**: ¿A qué mapa existente conecta?
8. **Pokémon salvajes**: si tiene hierba/agua, ¿qué Pokémon aparecen?

### Ejemplo de diseño

```
Nombre: La Cabaña del Viejo Lobo
Dimensiones: 12×10 bloques (interior pequeño)
Tileset: Interior de casa

NPCs:
1. Viejo Lobo (x:5, y:4): dice un misterio sobre el mapa oculto
2. Gato (x:2, y:7): solo dice "Miau" sin importar cuántas veces lo hablas
3. Mago (x:9, y:3): te da TM01 si le respondes correctamente una pregunta

Eventos:
- Tile (x:6, y:8): libro en el suelo → al pisarlo muestra un poema
- Cofre (x:10, y:2): contiene PP Máximo, se puede abrir solo una vez (flag)

Conexión: Entra desde Pueblo Paleta (x:10, y:1 en el mapa de Pueblo Paleta)
```

---

## Paso a paso: construir el room

### Etapa 1 — Crear el mapa base (semana 1-2)

1. En AdvanceMap (o usando la descompilación), crea un nuevo mapa con las dimensiones diseñadas.
2. Elige el tileset apropiado.
3. Dibuja el diseño: suelo, paredes, muebles (si es interior), decoraciones.
4. Configura los permisos de movimiento (qué tiles se pueden pisar).
5. Crea el warp de entrada (la puerta que conecta con el mundo exterior).
6. Compila y verifica visualmente en mGBA.

### Etapa 2 — Agregar los NPCs (semana 2-3)

Para cada NPC de tu diseño:

1. Agrega el NPC en `map.json` con su posición y tipo de movimiento.
2. Escribe su script en `scripts.pory` usando Poryscript.
3. Compila y prueba cada NPC individualmente.

**Checklist de cada NPC:**
- [ ] Aparece en la posición correcta.
- [ ] Su sprite se ve bien y hace el movimiento esperado.
- [ ] Su diálogo se muestra correctamente.
- [ ] Si tiene lógica (flags, ítems), funciona sin bugs.

### Etapa 3 — Agregar los eventos especiales (semana 3-4)

Para cada evento especial:

1. Si es un ítem oculto: usa `setvar` + `checkflag` + `finditem`.
2. Si es un cofre: crea el script con `checkflag`, `setflag` y `giveitem`.
3. Si es una batalla de entrenador: usa `trainerbattle` con un entrenador definido en `src/data/trainers.h`.

### Etapa 4 — Conectar con el mundo (semana 4-5)

1. En AdvanceMap, abre el mapa de Pueblo Paleta.
2. Agrega una puerta que lleve a tu nuevo room.
3. Configura los warps: ida (Pueblo Paleta → tu room) y vuelta (tu room → Pueblo Paleta).
4. Prueba que entrar y salir funciona correctamente.

### Etapa 5 — Pulido y testing final (semana 5-6)

1. Juega tu room completo desde cero.
2. Busca bugs: ¿algún NPC se queda atascado? ¿Algún script no termina bien?
3. Revisa los textos: ortografía, coherencia, longitud de líneas (máx ~30 caracteres por línea).
4. Pide a alguien de confianza que pruebe tu room sin explicarle nada.

---

## Estructura final del proyecto

```
(tu fork de pokefirered)/
├── maps/
│   ├── PalletTown/
│   │   └── map.json         ← Modificado para incluir la entrada a tu room
│   └── CabanaViejoLobo/     ← Tu room personalizado
│       ├── map.json
│       └── scripts.pory
├── src/
│   └── data/
│       └── trainers.h       ← Si agregaste un entrenador personalizado

(este repositorio)/
├── docs/
│   ├── proyecto_final.md    ← Documentación completa del room
│   └── notas/
│       └── diseno_room_final.md
└── src/
    └── scripts/
        └── fase_5/
            └── *.pory       ← Copia de los scripts (para referencia)
```

---

## Documentación del proyecto final

Crea `docs/proyecto_final.md` con:

### Sección 1: Descripción del room
- Qué es y para qué sirve narrativamente.
- Capturas de pantalla o descripción visual.

### Sección 2: Decisiones de diseño
- ¿Por qué elegiste ese tileset?
- ¿Por qué ese tamaño de mapa?
- ¿Qué problemas encontraste y cómo los resolviste?

### Sección 3: Aprendizajes
- ¿Qué fue lo más difícil?
- ¿Qué harías diferente la próxima vez?
- ¿Qué quieres aprender después?

### Sección 4: Código destacado
- Copia el script de Poryscript más complejo que hayas escrito.
- Explica cómo funciona línea por línea.

---

## Criterios de éxito del proyecto final

- [x] El room tiene un diseño coherente y visualmente limpio.
- [x] Tiene al menos 3 NPCs con diálogos únicos.
- [x] Tiene al menos 1 evento especial (ítem, cofre, o batalla).
- [x] Está conectado con el mundo original del juego.
- [x] No tiene bugs críticos (el juego no se congela ni crashea).
- [x] El código está en Git con historial de commits.
- [x] Tengo `docs/proyecto_final.md` escrito.

---

## ¿Qué sigue después de esta fase?

Una vez que completes el proyecto final, tienes varias opciones para seguir aprendiendo:

### Siguiente nivel A — Mecánicas de juego

Modifica la lógica del juego en C:
- Cambiar la fórmula de experiencia ganada.
- Agregar un nuevo tipo de Pokémon.
- Crear un movimiento nuevo.

**Recurso:** Estudia `src/battle_main.c` y `src/pokemon.c` en pokefirered.

### Siguiente nivel B — Gráficos personalizados

Crea tus propios sprites para NPCs y Pokémon:
- Herramienta: **Aseprite** o **GraphicsGale** para pixel art.
- Proceso: dibujar → exportar en paleta GBA (15 colores) → importar con herramientas de pokefirered.

### Siguiente nivel C — Ensamblador ARM

Aprende ensamblador para optimizar rutinas o acceder a partes del código que no están en C:
- **Recurso:** ARM Architecture Reference Manual (ARM ARMv4T).
- **Aplicación:** Escribir rutinas de "hacks ASM" que patches directamente la ROM.

### Siguiente nivel D — Crear un ROM hack completo

Con todo lo aprendido, podrías planear un ROM hack más ambicioso: una historia nueva, regiones nuevas, Pokémon originales.

---

¡Felicitaciones por llegar hasta aquí! 🎉

Crear este room significa que pasaste de no saber nada a modificar el código fuente de un videojuego de Game Boy Advance. Eso es un logro real.
