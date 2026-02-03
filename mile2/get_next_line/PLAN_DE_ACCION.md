# 📖 Plan de Acción: Get Next Line

*Este plan está diseñado para aprender paso a paso sin quedarte estancada.*

---

## 📊 Resumen del Proyecto

**Objetivo:** Crear una función que lea una línea de un file descriptor, línea por línea.

**Prototipo:** `char *get_next_line(int fd);`

**Archivos a entregar:**
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

**Concepto clave:** Variables estáticas en C

---

## 🎯 FASE 1: Fundamentos (Día 1-2)

### ✅ Checkpoint 1.1: Entender Variables Estáticas

**Objetivo:** Comprender cómo las variables estáticas mantienen su valor entre llamadas.

**Actividad:**
1. Ve a `fase1_fundamentos/01_static_vars/`
2. Compila y ejecuta `test_static.c`
3. Modifica el código para experimentar
4. Completa los ejercicios en `ejercicio_static.c`

**Concepto:**
```c
static int variable;  // Se inicializa UNA SOLA VEZ
                      // Mantiene su valor entre llamadas
                      // Solo visible en su archivo
```

**Marca como completado cuando:**
- [ ] Entiendes por qué el contador incrementa
- [ ] Puedes explicar la diferencia entre variable local y estática
- [ ] Has completado el ejercicio

---

### ✅ Checkpoint 1.2: Función read() y File Descriptors

**Objetivo:** Dominar la lectura de archivos con `read()`.

**Actividad:**
1. Ve a `fase1_fundamentos/02_read_fd/`
2. Estudia `ejemplo_read.c`
3. Completa `ejercicio_read.c`

**Conceptos:**
```c
int fd = open("archivo.txt", O_RDONLY);  // Abre archivo
char buffer[10];
int bytes = read(fd, buffer, 10);        // Lee 10 bytes
// bytes: -1 (error), 0 (fin), >0 (bytes leídos)
close(fd);
```

**Marca como completado cuando:**
- [ ] Entiendes qué es un file descriptor
- [ ] Sabes interpretar el valor de retorno de `read()`
- [ ] Puedes leer un archivo completo en bloques

---

### ✅ Checkpoint 1.3: BUFFER_SIZE y Compilación

**Objetivo:** Entender cómo funciona el flag `-D BUFFER_SIZE`.

**Actividad:**
1. Ve a `fase1_fundamentos/03_buffer_size/`
2. Compila con diferentes BUFFER_SIZE
3. Observa el comportamiento

**Comandos:**
```bash
cc -D BUFFER_SIZE=1 test_buffer.c -o test
cc -D BUFFER_SIZE=42 test_buffer.c -o test
cc -D BUFFER_SIZE=10000 test_buffer.c -o test
```

**Marca como completado cuando:**
- [ ] Entiendes que BUFFER_SIZE determina cuántos bytes lee `read()`
- [ ] Has probado con tamaños 1, 42, y 1000
- [ ] Entiendes por qué BUFFER_SIZE=1 es el más difícil

---

## 🧩 FASE 2: Diseño del Algoritmo (Día 3-4)

### ✅ Checkpoint 2.1: El Problema a Resolver

**Actividad:**
1. Lee `fase2_algoritmo/problema.md`
2. Dibuja en papel el flujo de datos
3. Anota tus ideas

**Pregunta clave:** ¿Cómo leer línea por línea si `read()` lee en bloques?

**Respuesta:** Usar una variable estática para guardar lo que sobra.

**Ejemplo visual:**
```
Archivo: "Hola\nMundo\nAdios"
BUFFER_SIZE = 5

Lectura 1: "Hola\n"  → Devuelve "Hola\n", sobra ""
Lectura 2: "Mundo"   → Lee más: "\nAdi"
           Ahora: "Mundo\nAdi" → Devuelve "Mundo\n", sobra "Adi"
Lectura 3: Lee "os"  → Ahora "Adios" → Devuelve "Adios", sobra ""
```

**Marca como completado cuando:**
- [ ] Has dibujado el flujo en papel
- [ ] Entiendes el rol de la variable estática
- [ ] Puedes explicar el proceso a alguien más

---

### ✅ Checkpoint 2.2: Pseudocódigo

**Actividad:**
1. Ve a `fase2_algoritmo/pseudocodigo.md`
2. Completa el pseudocódigo con tus palabras
3. Revisa con los ejemplos

**Estructura básica:**
```
función get_next_line(fd):
    static backup = NULL
    
    1. Validar fd
    2. Leer y acumular hasta encontrar \n
    3. Extraer línea (con \n)
    4. Guardar resto en backup
    5. Devolver línea
```

**Marca como completado cuando:**
- [ ] Has escrito tu propio pseudocódigo
- [ ] Identificas los casos especiales (EOF, sin \n final)
- [ ] Sabes qué funciones auxiliares necesitas

---

### ✅ Checkpoint 2.3: Identificar Funciones Auxiliares

**Actividad:**
1. Lista las funciones que necesitas
2. Revisa tu libft
3. Anota qué debes copiar o crear

**Funciones necesarias:**
- `ft_strlen()` - longitud de string
- `ft_strchr()` - buscar carácter
- `ft_strjoin()` - concatenar strings
- `ft_substr()` - extraer substring
- `ft_strdup()` - duplicar string

**Marca como completado cuando:**
- [ ] Has listado todas las funciones necesarias
- [ ] Has verificado que existen en tu libft
- [ ] Sabes cómo las usarás

---

## 💻 FASE 3: Implementación (Día 5-8)

### ✅ Checkpoint 3.1: Estructura del Proyecto

**Actividad:**
1. Ve a `get_next_line/`
2. Crea los archivos base:
   - `get_next_line.h`
   - `get_next_line.c`
   - `get_next_line_utils.c`

**Contenido inicial de get_next_line.h:**
```c
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
// Añadir prototipos de funciones auxiliares

#endif
```

**Marca como completado cuando:**
- [ ] Has creado los 3 archivos
- [ ] El header tiene las inclusiones necesarias
- [ ] Compila sin errores (aunque esté vacío)

---

### ✅ Checkpoint 3.2: Funciones Auxiliares

**Actividad:**
1. Copia funciones de tu libft a `get_next_line_utils.c`
2. Ajusta si es necesario (sin libft.h)
3. Añade prototipos al header

**Funciones a implementar:**
```c
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
```

**Marca como completado cuando:**
- [ ] Las 5 funciones están implementadas
- [ ] Compilan sin errores ni warnings
- [ ] Has probado cada una individualmente

---

### ✅ Checkpoint 3.3: Función Principal - Esqueleto

**Actividad:**
1. En `get_next_line.c`, crea la estructura básica
2. Añade validaciones
3. Compila

**Código inicial:**
```c
char *get_next_line(int fd)
{
    static char *backup;
    
    // Validaciones
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    // TODO: Leer y acumular
    // TODO: Extraer línea
    // TODO: Limpiar y retornar
    
    return (NULL);
}
```

**Marca como completado cuando:**
- [ ] La función compila
- [ ] Las validaciones funcionan
- [ ] Tienes la estructura clara

---

### ✅ Checkpoint 3.4: Implementar Lectura y Acumulación

**Actividad:**
1. Implementa la función que lee y acumula
2. Maneja el caso de fin de archivo
3. Prueba con archivos simples

**Función auxiliar sugerida:**
```c
static char *read_and_accumulate(int fd, char *backup)
{
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;
    char *temp;
    
    while (!ft_strchr(backup, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        temp = backup;
        backup = ft_strjoin(backup, buffer);
        free(temp);
    }
    return (backup);
}
```

**Marca como completado cuando:**
- [ ] Lee correctamente del archivo
- [ ] Acumula en backup
- [ ] Se detiene al encontrar \n o EOF

---

### ✅ Checkpoint 3.5: Extraer Línea

**Actividad:**
1. Implementa la extracción de línea
2. Actualiza backup con el resto
3. Maneja el caso sin \n al final

**Función auxiliar sugerida:**
```c
static char *extract_line(char **backup)
{
    char *line;
    char *newline_pos;
    char *temp;
    
    if (!*backup)
        return (NULL);
    
    newline_pos = ft_strchr(*backup, '\n');
    if (newline_pos)
    {
        line = ft_substr(*backup, 0, newline_pos - *backup + 1);
        temp = ft_strdup(newline_pos + 1);
        free(*backup);
        *backup = temp;
    }
    else
    {
        line = ft_strdup(*backup);
        free(*backup);
        *backup = NULL;
    }
    return (line);
}
```

**Marca como completado cuando:**
- [ ] Extrae correctamente hasta \n (incluido)
- [ ] Guarda el resto en backup
- [ ] Maneja el EOF sin \n

---

### ✅ Checkpoint 3.6: Integración y Limpieza

**Actividad:**
1. Une todas las partes en `get_next_line()`
2. Gestiona memoria correctamente
3. Maneja todos los casos edge

**Checklist de casos:**
- [ ] Líneas normales con \n
- [ ] Última línea sin \n
- [ ] Archivo vacío
- [ ] fd inválido
- [ ] Llamadas múltiples

**Marca como completado cuando:**
- [ ] La función está completa
- [ ] No hay leaks de memoria
- [ ] Pasa validaciones básicas

---

## 🧪 FASE 4: Testing Intensivo (Día 9-10)

### ✅ Checkpoint 4.1: Tests Básicos

**Actividad:**
1. Ve a `tests/`
2. Usa `test_basic.c` con archivos de prueba
3. Verifica resultados

**Comando:**
```bash
cd tests
./compile_and_test.sh basic
```

**Archivos de prueba:**
- `test_files/simple.txt` - Líneas normales
- `test_files/empty.txt` - Archivo vacío
- `test_files/one_line.txt` - Una línea sin \n
- `test_files/long_line.txt` - Línea muy larga

**Marca como completado cuando:**
- [ ] Pasa todos los tests básicos
- [ ] Los resultados son correctos
- [ ] No hay crashes

---

### ✅ Checkpoint 4.2: Tests con Diferentes BUFFER_SIZE

**Actividad:**
1. Compila con BUFFER_SIZE=1, 10, 42, 100, 1000, 10000
2. Verifica que funciona igual en todos
3. Analiza comportamiento

**Script:**
```bash
./test_buffer_sizes.sh
```

**Casos críticos:**
- BUFFER_SIZE=1 (lee de a 1 byte)
- BUFFER_SIZE=10000 (lee todo de golpe)
- BUFFER_SIZE=longitud de línea exacta

**Marca como completado cuando:**
- [ ] Funciona con BUFFER_SIZE=1
- [ ] Funciona con BUFFER_SIZE=10000
- [ ] Sin leaks en ningún caso

---

### ✅ Checkpoint 4.3: Valgrind y Memory Leaks

**Actividad:**
1. Ejecuta valgrind en todos los tests
2. Corrige cualquier leak
3. Verifica con diferentes escenarios

**Comando:**
```bash
valgrind --leak-check=full --show-leak-kinds=all ./test
```

**Escenarios a verificar:**
- [ ] Archivo completo leído
- [ ] Interrupción a mitad (no leer todo)
- [ ] fd inválido
- [ ] Múltiples llamadas

**Marca como completado cuando:**
- [ ] 0 bytes perdidos
- [ ] 0 errores de memoria
- [ ] Todos los free() están bien

---

### ✅ Checkpoint 4.4: Tests Especiales

**Actividad:**
1. Prueba con stdin (fd=0)
2. Prueba lectura desde múltiples archivos
3. Casos edge extremos

**Tests especiales:**
- Leer de stdin (teclado)
- Líneas de 10,000 caracteres
- Archivo con 1,000 líneas
- Archivo binario (comportamiento indefinido, pero no debe crashear)

**Marca como completado cuando:**
- [ ] Funciona con stdin
- [ ] Maneja líneas muy largas
- [ ] No crashea con binarios

---

## 🎁 FASE 5: Bonus (Día 11-12) - OPCIONAL

### ✅ Checkpoint 5.1: Una Sola Variable Estática

**Objetivo:** Ya lo tienes si usaste una sola variable `static char *backup`.

**Verificación:**
- [ ] Solo hay UNA variable estática en tu código
- [ ] No usas variables globales

---

### ✅ Checkpoint 5.2: Múltiples File Descriptors

**Actividad:**
1. Copia archivos a versión bonus:
   - `get_next_line_bonus.c`
   - `get_next_line_bonus.h`
   - `get_next_line_utils_bonus.c`

2. Modifica para usar array de backups:
```c
char *get_next_line(int fd)
{
    static char *backup[MAX_FD];  // MAX_FD = 1024
    
    // Usa backup[fd] en vez de backup
}
```

**Test:**
```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);
int fd3 = open("file3.txt", O_RDONLY);

printf("%s", get_next_line(fd1));  // Línea 1 de file1
printf("%s", get_next_line(fd2));  // Línea 1 de file2
printf("%s", get_next_line(fd3));  // Línea 1 de file3
printf("%s", get_next_line(fd1));  // Línea 2 de file1
```

**Marca como completado cuando:**
- [ ] Puede leer de múltiples fd alternadamente
- [ ] No se mezclan los contenidos
- [ ] No hay leaks

---

## 📝 FASE 6: Documentación (Día 13)

### ✅ Checkpoint 6.1: README.md

**Actividad:**
1. Crea `README.md` en la raíz del proyecto
2. Incluye las secciones requeridas

**Contenido obligatorio:**
```markdown
# Get Next Line

*Este proyecto ha sido creado como parte del currículo de 42 por [tu_login].*

## Descripción
[Explica qué hace el proyecto]

## Algoritmo
[Explica tu estrategia: variable estática, acumulación, etc.]

## Instrucciones
### Compilación
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o test

### Uso
[Ejemplo de código]

## Recursos
- man read
- man open
- [Artículos consultados]
- Uso de IA: [especifica si usaste y para qué]

## Decisiones Técnicas
[Por qué elegiste tu algoritmo]
```

**Marca como completado cuando:**
- [ ] README está completo
- [ ] Incluye todas las secciones requeridas
- [ ] Explica claramente el algoritmo

---

## ✅ CHECKLIST FINAL DE ENTREGA

### Archivos Obligatorios
- [ ] `get_next_line.c`
- [ ] `get_next_line.h`
- [ ] `get_next_line_utils.c`
- [ ] `README.md`

### Archivos Bonus (opcional)
- [ ] `get_next_line_bonus.c`
- [ ] `get_next_line_bonus.h`
- [ ] `get_next_line_utils_bonus.c`

### Compilación
- [ ] Compila con `-Wall -Werror -Wextra`
- [ ] Funciona con `-D BUFFER_SIZE=n` (cualquier n)
- [ ] Sin warnings

### Funcionalidad
- [ ] Lee líneas correctamente
- [ ] Líneas con \n incluyen el \n
- [ ] Última línea sin \n funciona
- [ ] Devuelve NULL al final
- [ ] Funciona con BUFFER_SIZE=1
- [ ] Funciona con BUFFER_SIZE=10000000

### Memoria
- [ ] Sin leaks (valgrind)
- [ ] No usa variables globales
- [ ] No usa lseek
- [ ] No usa libft (directamente)

### Norminette
- [ ] Pasa la norminette en todos los archivos

### Tests
- [ ] Funciona con archivos
- [ ] Funciona con stdin
- [ ] Maneja errores correctamente

---

## 🎯 PROGRESO GLOBAL

### Días 1-2: Fundamentos
- [ ] Variables estáticas
- [ ] Función read()
- [ ] BUFFER_SIZE

### Días 3-4: Algoritmo
- [ ] Problema identificado
- [ ] Pseudocódigo escrito
- [ ] Funciones planeadas

### Días 5-8: Implementación
- [ ] Estructura creada
- [ ] Funciones auxiliares
- [ ] Función principal
- [ ] Integración completa

### Días 9-10: Testing
- [ ] Tests básicos
- [ ] Tests de BUFFER_SIZE
- [ ] Valgrind limpio
- [ ] Tests especiales

### Día 11-12: Bonus (opcional)
- [ ] Múltiples fd

### Día 13: Documentación
- [ ] README completo

---

## 💡 RECURSOS Y AYUDAS

### Comandos Útiles
```bash
# Compilar
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 *.c -o gnl

# Valgrind
valgrind --leak-check=full ./gnl test.txt

# Crear archivo de prueba
echo -e "Linea 1\nLinea 2\nLinea 3" > test.txt

# Ver archivo con caracteres especiales
cat -e test.txt

# Norminette
norminette *.c *.h
```

### Debugging
```c
// Añade temporalmente para debug
printf("DEBUG: backup = '%s'\n", backup);
printf("DEBUG: bytes_read = %d\n", bytes_read);
printf("DEBUG: buffer = '%s'\n", buffer);
```

### Preguntas para Reflexionar
1. ¿Por qué necesito una variable estática?
2. ¿Qué pasa si BUFFER_SIZE es mayor que la línea?
3. ¿Qué pasa si BUFFER_SIZE es 1?
4. ¿Cómo sé que llegué al final del archivo?
5. ¿Qué hacer con la memoria de backup al final?

---

## 🆘 ¿Te quedaste estancada?

### Si no compila:
1. Verifica includes
2. Verifica prototipos en .h
3. Verifica nombres de funciones
4. Lee el mensaje de error con calma

### Si hay leaks:
1. Cada malloc debe tener su free
2. Verifica que liberas backup al final
3. Verifica ft_strjoin (¿libera el antiguo?)
4. Usa valgrind línea por línea

### Si no lee correctamente:
1. Imprime el valor de bytes_read
2. Imprime el buffer después de read
3. Imprime backup después de acumular
4. Verifica el '\0' al final del buffer

### Si falla con BUFFER_SIZE=1:
1. Es el caso más difícil, ¡es normal!
2. Traza en papel qué pasa byte por byte
3. Verifica que no asumes que lees toda la línea de una vez

---

**¡Éxito en tu proyecto! 🚀**

*Recuerda: El proceso de aprendizaje es más importante que el resultado. No tengas miedo de experimentar y equivocarte.*
