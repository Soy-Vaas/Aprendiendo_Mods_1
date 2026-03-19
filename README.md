# Aprendiendo_Mods_1

Proyecto personal para aprender programación orientada a videojuegos desde cero, explorando conceptos básicos y aplicándolos en un proyecto ambicioso: **crear un mod/script para Pokémon Rojo Fuego (GBA)**.

## ¿De qué trata este proyecto?

El objetivo es aprender a modificar ROMs de Game Boy Advance, específicamente Pokémon FireRed, partiendo desde cero. Se avanza de forma gradual: primero con herramientas visuales y scripting de alto nivel, luego con el lenguaje **C** usando el proyecto de descompilación oficial, y finalmente con conceptos de **ensamblador ARM** si el nivel lo permite.

## Estructura del repositorio

```
docs/
├── plan_de_desarrollo.md          ← Hoja de ruta completa del proyecto
├── recursos_y_documentacion.md    ← Lenguajes, herramientas y links de referencia
└── fases/
    ├── fase_1_fundamentos.md      ← Fundamentos: C, GBA y ROM hacking
    ├── fase_2_herramientas_rom_hacking.md  ← Herramientas visuales (AdvanceMap, XSE)
    ├── fase_3_scripting_xse.md    ← Scripting con XSE: primer mod funcional
    ├── fase_4_decomp_c.md         ← Programación real con la descompilación de FireRed
    └── fase_5_proyecto_final.md   ← Integración: room personalizado completo
```

## Cómo usar este plan

1. Lee [`docs/plan_de_desarrollo.md`](docs/plan_de_desarrollo.md) para entender la hoja de ruta.
2. Consulta [`docs/recursos_y_documentacion.md`](docs/recursos_y_documentacion.md) para saber qué aprender y dónde.
3. Avanza fase a fase siguiendo los archivos en `docs/fases/`.
4. Usa este repositorio para guardar tu código, scripts y notas a medida que avanzas.

## Objetivo de aprendizaje

- Reforzar el pensamiento lógico y algorítmico.
- Aprender **C** en un contexto real y entretenido.
- Entender cómo funcionan los videojuegos por dentro (memoria, lógica de eventos, gráficos en GBA).
- Completar un mod funcional que modifique al menos un room de Pokémon FireRed.
