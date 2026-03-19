# Plan de Desarrollo: Mod para Pokémon FireRed (GBA)

## Resumen del proyecto

**Objetivo principal:** Crear un mod funcional que modifique al menos un room (mapa/sala) de Pokémon Rojo Fuego, aprendiendo programación orientada a videojuegos en el proceso.

**Perfil del desarrollador:** Principiante, trabajando solo, con ganas de aprender.

**Duración estimada total:** 4 a 8 meses (ritmo de 5-10 horas semanales).

---

## Visión general de las fases

| Fase | Nombre | Duración estimada | Resultado |
|------|--------|-------------------|-----------|
| 1 | Fundamentos | 3-4 semanas | Entender C básico y la arquitectura GBA |
| 2 | Herramientas de ROM hacking | 2-3 semanas | Editar mapas y datos con herramientas visuales |
| 3 | Scripting con XSE | 3-4 semanas | Crear eventos y diálogos personalizados |
| 4 | Programación con la descompilación | 6-8 semanas | Modificar lógica del juego con C real |
| 5 | Proyecto final | 4-6 semanas | Room personalizado y completo |

---

## Fase 1: Fundamentos (semanas 1-4)

### ¿Qué aprender?

- **Lenguaje C**: variables, tipos de datos, condicionales, bucles, funciones, punteros básicos.
- **Conceptos de GBA**: resolución (240×160), paletas de colores, tiles, sprites, memoria.
- **¿Qué es una ROM?**: formato binario, offset, parches IPS/UPS.

### ¿Cómo practicar?

1. Resolver 10-15 ejercicios básicos de C (suma, factorial, Fibonacci, manejo de strings).
2. Leer el documento "GBATEK" para entender la arquitectura GBA a alto nivel.
3. Abrir la ROM de FireRed con un editor hexadecimal (HxD) y explorar sin modificar nada.

### Entregable de la fase

- Código C funcional de al menos 3 ejercicios guardado en `src/ejercicios/fase_1/`.
- Notas propias en `docs/notas/fase_1_notas.md` con lo aprendido.

---

## Fase 2: Herramientas de ROM Hacking (semanas 5-7)

### ¿Qué aprender?

- Usar **AdvanceMap** para visualizar y editar mapas de FireRed.
- Usar **NSE (Nameless Sprite Editor)** para ver sprites.
- Entender la estructura de un "room": tileset, eventos, conexiones, encuentros.

### ¿Cómo practicar?

1. Cargar la ROM en AdvanceMap y explorar el Pueblo Paleta (Bank 0, Map 0).
2. Cambiar un tile del suelo en un mapa de prueba (no en el mapa final).
3. Mover la posición de un NPC en el mapa.

### Entregable de la fase

- Captura del mapa modificado.
- ROM de prueba con al menos un cambio visual documentado en `docs/notas/fase_2_notas.md`.

---

## Fase 3: Scripting con XSE (semanas 8-11)

### ¿Qué aprender?

- Sintaxis del **lenguaje de scripting XSE** (Cross Script Editor).
- Comandos básicos: `msgbox`, `applymovement`, `giveitem`, `trainerbattle`.
- Cómo asignar un script a un NPC o a un tile del suelo.

### ¿Cómo practicar?

1. Crear un NPC que diga un diálogo personalizado.
2. Crear un objeto en el suelo que dé un ítem al jugador.
3. Crear un evento de batalla contra un entrenador creado desde cero.

### Entregable de la fase

- Archivo `.xse` con los scripts documentados, guardado en `src/scripts/fase_3/`.
- ROM de prueba con los tres eventos funcionando.

---

## Fase 4: Programación con la Descompilación de FireRed (semanas 12-19)

### ¿Qué aprender?

- Clonar y compilar el proyecto **pokefirered** (descompilación oficial en C).
- Entender la estructura de carpetas: `src/`, `include/`, `data/`, `maps/`.
- Modificar un archivo de mapa en formato `.json` o `.pory` (Poryscript).
- Compilar y probar con el emulador mGBA.

### ¿Cómo practicar?

1. Seguir la guía de instalación oficial de pokefirered.
2. Cambiar el nombre de un NPC del Pueblo Paleta en el código fuente.
3. Agregar un nuevo NPC con un script propio escrito en Poryscript.
4. Compilar la ROM y verificar el cambio en mGBA.

### Entregable de la fase

- Fork del proyecto pokefirered con los cambios en una rama propia.
- Documentación de los cambios en `docs/notas/fase_4_notas.md`.

---

## Fase 5: Proyecto Final — Room personalizado (semanas 20-25)

### Objetivo

Crear un room completamente personalizado que incluya:

- **Diseño de mapa propio** con AdvanceMap o el sistema de mapas de la descompilación.
- **Al menos 3 NPCs** con diálogos propios.
- **Un evento especial**: un ítem escondido, una batalla o un minijuego simple de texto.
- **Conexión** con un mapa existente del juego.

### Entregable final

- ROM compilada con el room funcional.
- Documentación completa en `docs/proyecto_final.md`: diseño, decisiones tomadas y aprendizajes.
- Código fuente limpio en `src/`.

---

## Reglas del proyecto

1. **Avanza una fase a la vez.** No saltes a la siguiente sin completar los entregables.
2. **Documenta todo.** Guarda notas de lo que no entendiste y cómo lo resolviste.
3. **Haz commits frecuentes.** Cada pequeño avance merece un commit con mensaje descriptivo.
4. **No te frustres.** Romper la ROM de prueba es parte del aprendizaje; siempre guarda backups.
5. **Busca ayuda en la comunidad.** El foro PokéCommunity y el servidor de Discord de pokefirered son excelentes recursos.
