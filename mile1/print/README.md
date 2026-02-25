*Este proyecto ha sido creado como parte del currículo de 42 por @lajen-li*

DESCRIPCIÓN: 
	Este proyecto tiene como objetivo recreaar la función printf de la librería de C. Al establecerla, esta implementación debe ser capaz de procesar una cadena de formato y devolver una salida formateada; para esto se debe tener en cuenta los diversos tipos de datos de forma dinámica.
	Durante el proceso, se profundizó en el uso de las "funciones variádicas", además de situaciones especiales que se debieron tener en cuenta para replicar el comportamiento original de la función del sistema.

	De este modo, el proyecto total consta de un archivo con la función principal "ft_printf.c" y otros archivos con funciones de apoyo, uno encargado de las especificaciones numéricas "ft_print_num.c" y otra encargada de la impresión mediante 'write' para las funciones no numéricas "ft_print_utils.c".

INSTRUCCIONES:
	El presente proyecto tiene un Makefile que compila la libería libftprintf.a. Para esto hay que tener en cuenta los siguientes comandos:

	> make: Compila los archivos fuente y genera la libería.
	> make clean: Elimina los archivos objetos (.o).
	> make fclean: Elimina los objetos y el archivo de la librería.
	> make re: Realiza una recompilación completa.

	Para usar ft_printf en un programa, se necesita incluir el encabezado en el código principal y enlazar la libería durante la compilación.
	Inclusión del header:
	 
	 	#include "ft_printf.h"
	El programa compila vinculando la libería estática:
	
	cc main.c -L. -lfprintf -o mi programa

RECURSOS:
	Para este proyecto se consultaron las isguientes referencias:

	-Man de Printf (referencia proncipal, sobre todo para ver los valores de retorno y la gestión de errores)
	-Gitbook 42 (por Lura @thebrisly)
	-Manual de instrucciones de 42 sobre el proyecto.
	-Documentación de starg.h. (Para entender sobre las funciones variádicas y el uso de las macros: va_start, va_arg, va_copy y va_end.)

	Sobre el uso de Inteligencia artificial:

	En este proyecto se ha integrado el uso de Gemini y Copilot enfocado en la asistencia de aprendizaje. El uso de estas herramientas ayudó en la aclaración de conceptos como las funciones varíadicas, las macros, los especificadores de formato, etc.

	La IA se usó también para la elaboración de la estructura de este apartado. Un apoyo para poner en orden las ideas y mantener una coherencia y una cohesión adecuada.

	En resumen, la IA se ha utilizado como un tutor para entender la técnica, mientas que la lógica del código quedó bajo la responsabilidad de la autora.

EXPLICACIÓN Y JUSTIFICACIÓN:
	Se ha implementado un algoritmo de realizando un parsing. El algoritmo recorre la cadena 'format' carácter a carácter. Si el carácter no es %, se envía directamente al buffer de salida.
	Sin embargo, cuando se detecta un %, el algoritmo entra a una función que identifica al especificador de formato (c, s, p, d, i, u, x, X, %).

	Se eligió esta vía por su eficiencia en memoria y una simplicidad en el bucle del código. Así pues, la función se vuelve ligera, rápida e ideal para sistemas en donde los recursos son limitados.
