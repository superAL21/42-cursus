*Este proyecto ha sido creado como parte del currículo de 42 por <lajen-li>.*

Descripción:

	Este proyecto se titula Libft.h y es parte de la primera etapa del common core de 42. El objetivo principal es crear una biblioteca de funcione en lenguaje C. Algunas funciones sacadas directamente del manual y otras funciones modificadas con el fin de obtener un resultado que ayude a los siguientes proyectos. El mayor reto es reconstruir dichas funciones desde cero para entender cómo funcionan por dentro.

	Dentro del proyecto se trabajó la lógica de las funciones, así como la gestión dinámica de la memoroa (malloc y free), manipulación de punteros, desbordamiento, conversiones y el manejo de los distintos tipos de datos que nos podemos encontrar a lo largo de las diferentes funciones.

Instrucciones:

	Para compilar y utilizar esta libería es necesario el compilador gcc y la herramienta make instalados en un entorno basado en el sistema Unix (Linux o macOS).

	El proyecto incluye un archivo Makefile que se encarga de gestionar eficientemente la compilación. Así pues, para generar la libería, clona el repositorio y ejecuta uno de los siguientes comando en la terminal:

	make			(Complia los archivos fuente y genera la libería estática libft.a)

	make clean		(Elimina todos los archivos objeto (.o))

	make fclean 	(Ejecuta clean y además elimina el archivo lifbt.a)

	make re			(Realiza fclean seguido de un make para compilar todo desde cero)

	Para incluir esta libería en tu proyecto:

	-Incluye el encabezado en tu archivo de código fuente:

	#include "libft.h"

	-Compila tu programa vinculando la librería estática:

	cc main.c -L. -lft -o mi_programa

Recursos:

	Para este proyecto se han consultado las siguientes referencias:

	-Man pages (Manuales de Linux)

	-Manual de instrucciones de 42 sobre proyecto.

	Sobre el uso de Inteligencia Artificial:

	En este proyecto se ha integrado el uso de Gemini enfocado en la asistencia al aprendizaje. Sobre todo para la aclaración de conceptos complejos commo el manejo de los punteros dobles, el funcionamiento de las listas enlazadas, el desbordamiento, el tratamiento de los int y el cuidado por los número min y máx, el casteo, entre otros.

	En alguna ocación se utilizó la reducir el número de líneas prestablecidas según la norma de 42 o incluso para Debugging.

	También se extrajo una estructura para la elaboración de este apartado. Una especie de guía para poner las ideas en orden y no deja nada de lado.

	En resumen, la IA se ha utilizado como un tutor para entender la técnica, mientras que la lógica quedó bajo la responsabildiad de la autora.

Sobre la libería:

-Manipulación de Memoria:
	Estas funciones operan sobre la meoria para darle eficiencia a los programas en C.
	>Gestión:	 	ft_memset, ft_bzero, ft_calloc.
	>Movimiento: 	ft_memcpy, ft_memmove.
	>Búsqueda:		ft_memchr, ft_memcmp.

-Procesamiento de Strings:
	Las funciones clásicas para manejar string.h, con enfoque a seguridad para evitar desbordamientos de búfer (overflow).
	>Seguridad:		ft_strlcpy y ft_strlcat.
	>Análisis:		ft_strlen, ft_strchr, ft_strnstr.

-Transformación y Creación:
	Funciones que no existen en la libc pero son herramientas potenciales para futuros proyectos de 42.
	ft_split y ft_itoa

-Estructura de Listas enlazadas:
	El manejo de nodos y punteros auto-referenciados. Ayuda con las limitaciones que traen los arrays estáticos.

Este proyecto está escrito con lenguaje C y sigue La norme de 42, lo que implica una estructura limpia y específica, además de contar con funciones de no más de 25 líneas, mantener un orden, la utilización de asignaciones adecuadas, entre otras cuestiones.