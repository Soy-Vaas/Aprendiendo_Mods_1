# Aprendiendo_Mods_1

Proyecto personal para aprender y practicar creación de mods/scripts para Pokémon Rojo Fuego (GBA). El objetivo es avanzar paso a paso, entendiendo qué lenguaje usar, dónde leer su documentación y cómo estructurar el trabajo siendo principiante y trabajando solo.

## Qué lenguaje y recursos necesito

- **Scripting específico de Pokémon (Poryscript o XSE):** Sirve para eventos, diálogos y lógica básica.  
  - Docs: [Poryscript](https://github.com/huderlem/poryscript#readme), guías de XSE en foros de romhacking de Pokémon.
- **C básico (opcional, si usas decompilación pret/pokefirered):** Permite cambios profundos si tomas el proyecto decompilado.  
  - Docs: [K&R C](https://publications.gbdirect.co.uk//c_book/), tutoriales de C en cppreference.
- **ARM Assembly GBA (solo nociones, opcional):** Útil para entender parches y hacks.  
  - Docs: Notas de ARM7TDMI y guías de gba-dev.
- **Herramientas de romhacking GBA:** A-Map (mapas/eventos), unhexed/hex editor, compilador de scripts (poryscript-cli o XSE), emulador (mGBA/vBA) para pruebas.

## Plan de desarrollo por fases (principiante y solo)

1. **Preparar entorno**
   - Consigue una *ROM limpia* de Rojo Fuego (no la subas al repositorio; compartir ROMs con copyright sin autorización es ilegal).
   - Instala emulador (mGBA) y un editor de mapas/eventos (A-Map o similar).
   - Elige flujo de trabajo:  
     - **Ruta Scripts** (más sencilla): usar Poryscript/XSE + A-Map.  
     - **Ruta Decomp** (más compleja): usar `pret/pokefirered` (requiere devkitARM y C).

2. **Hola Mundo del mod**
   - Ruta Scripts: crea un script sencillo que muestre un diálogo al entrar a un mapa. Compílalo y vincúlalo con A-Map en un evento de personaje.  
   - Ruta Decomp: clona `pret/pokefirered`, compila, cambia un texto en un evento y vuelve a compilar la ROM resultante (archivo `.gba` modificado).

3. **Eventos interactivos**
   - Añade un NPC con diálogo condicional (por ejemplo, si tienes X medallas).
   - Prueba flags y variables para controlar estado del juego.

4. **Mapas y flujo**
   - Crea una pequeña habitación nueva o reusa una existente. Coloca entradas/salidas y warps.  
   - Ajusta paletas y tiles básicos para no romper gráficos.

5. **Combates y recompensas**
   - Añade un entrenador con equipo personalizado.  
   - Define recompensas (objeto, dinero, trigger de historia).

6. **Pulido y prueba**
   - Recorre el flujo completo en emulador, revisa que no haya softlocks.  
   - Guarda versiones incrementales del ROM y scripts para poder volver atrás.

7. **Aprendizaje continuo**
   - Lee código de otros hacks (poryscript ejemplos o scripts XSE de la comunidad).  
   - Experimenta con pequeñas mejoras: animaciones, condiciones de tiempo, puzzles simples.

## Cómo usar este repositorio

- Guarda aquí tus scripts, notas y versiones de prueba (nunca subas la ROM; ver nota legal arriba).  
- Lleva un changelog breve por cada iteración (qué evento tocaste, qué probaste).  
- Mantén los pasos pequeños y probados en emulador antes de seguir.
