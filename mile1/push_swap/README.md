*Este proyecto ha sido creado como parte del currículo de 42 por lajen-li, cscaroni.*

## DESCRIPCIÓN

Push Swap es un algoritmo de ordenamiento eficiente que ordena una serie de números enteros utilizando dos stacks (pilas A y B) y un conjunto limitado de operaciones permitidas.

Objetivo: Ordenar los números del stack A en orden ascendente utilizando el mínimo número de operaciones posible, demostrando optimización algorítmica y manejo eficiente de estructuras de datos.

### Características principales

Múltiples estrategias de sorting: Implementa cuatro algoritmos diferentes adaptados a diferentes tamaños y complejidades de entrada

-  Simple (O(n²)): Para ordenamientos básicos
-  Medium (O(n√n)): Algoritmo de chunks para mejor rendimiento
-  Complex (O(n log n)): Algoritmo turco (Turk)
-  Adaptive: Selecciona automáticamente la mejor estrategia según el nivel de desorden

**Operaciones limitadas:** Push, Rotate, Reverse Rotate y Swap en ambos stacks

Análisis de rendimiento: Incluye herramientas de benchmarking para evaluar la eficiencia de cada estrategia

Manejo robusto de errores: Validación completa de entrada y detección de números duplicados

Este proyecto combina teoría algorítmica con implementación práctica en C, optimizando el balance entre complejidad temporal y número de operaciones

## INSTRUCCIONES

### Compilación 

Para compilar el proyecto, ejecuta en el terminal desde la raíz del proyecto:

```bash
make
```
Este comando compilará automáticamente la librería libft y el ejecutable principal push_swap.

### Elementos disponibles

- make o make all — Compila el proyecto completo
- make clean — Elimina los archivos objeto (.o)
- make fclean — Elimina los archivos objeto y el ejecutable
- make re — Recompila el proyecto desde cero

### Ejecución

El programa ordena un conjunto de números enteros utilizando dos stacks. La sintaxis básica es:

./push_swap [flags] [números]

**Ejemplo básico**

```bash
./push_swap 4 67 3 87 23
```
### Opciones de Estrategia

Puedes especificar qué algoritmo de ordenamiento deseas utilizar añadiendo cualquiera de las siguientes flags al final de la entrada:

| Opción | Descripción | Complejidad |
| :--- | :--- | :--- |
| `--simple` | Algoritmo básico de selección | $O(n^2)$ |
| `--medium` | Algoritmo con chunks | $O(n\sqrt{n})$ |
| `--complex` | Algoritmo Turkey optimizado | $O(n \log n)$ |
| `--adaptive` | Selecciona automáticamente la mejor estrategia | Automático |

**Ejemplo:**

```bash
./push_swap 5 2 8 1 9 --complex
```

Si no especificas una estrategia, se utiliza `--adaptive` por defecto.

Análisis de Rendimiento
Añade la flag --bench para ver un reporte detallado del número de operaciones realizadas:

```bash
./push_swap 4 67 3 87 23 --bench --adaptive
```
**El reporte mostrará:**

- Número total de operaciones (moves)
- Desglose por tipo de operación (push, rotate, swap, etc.)
- Nivel de desorden de la entrada
- Estrategia utilizada

### Validación
El programa incluye validación automática para:

- [x] Números duplicados (genera error)
- [x] Argumentos no numéricos (genera error)
- [x] Números fuera del rango de long (genera error)
- [✓] Detección automática si los números ya están ordenados

En caso de error, verás el mensaje: **Error**

## RECURSOS

### Referencias y herramientas utilizadas

### Visualizer de Push Swap: 
https://push-swap42-visualizer.vercel.app/

Se utilizó para visualizar movimientos, validar secuencias de operaciones y detectar ineficiencias en el ordenamiento.

### Generador de números aleatorios: 
https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php

Se empleó para crear casos de prueba variados (pequeños, medianos y grandes), incluyendo entradas desordenadas para pruebas de rendimiento.

### Interacciones pair to pair (peer learning):
Se realizaron sesiones de revisión entre compañeros para discutir estrategias, detectar errores lógicos y contrastar decisiones de implementación.

### Uso de IA en el proyecto
La IA se utilizó como herramienta de apoyo técnico y documental, especialmente en:

- `Debugging:` ayuda para analizar errores, proponer hipótesis de fallo y sugerir rutas de corrección.
- `Explicaciones técnicas:` soporte para comprender y reforzar el uso y manejo de listas doblemente enlazadas (estructura de nodos, punteros prev/next, inserciones, extracciones y rotaciones).
- `Redacción supervisada de este documento:` mejora de claridad, organización y estilo del README, manteniendo validación y criterio final humano.

La implementación, pruebas y validación final del comportamiento del programa fueron realizadas por el equipo, es decir, el proceso del desarrollo de codigo ha sido el mismo para cada integrante.