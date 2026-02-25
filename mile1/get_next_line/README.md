*Este proyecto ha sido creado como parte del currículo de 42 por <lajen-li>*

DESCRIPCIÓN

	GET NEXT LINE es un proyecto que tiene como objetivo programar una función que devuelva una línea leída desde uno o varios descriptores de archivos (fd). 
	El reto principal consiste en gestionar la lectura de datos de manera eficiente. Para esto, utilizamos una variable estática, así guardamos lo que se ha leído pero no se ha devuelto, lo que nos permite a hacer llamadas sucesivas hasta llegar al final del archivo.

INSTRUCCIONES

	Para utilizar este programa en los proyectos, se debe incluir los archivos fuentes y compilar con el flag -D BUFFER_SIZE=n, donde n es el número de bytes que deseas leer por cada llamada a read().
	Se debe tener en cuenta que este proyecto contiene el apartado BONUS, por lo tanto, cuenta con 6 archivos. 3 de ellos para el GNL normal, y 3 para el bonus (_bonus).

RECURSOS

	Los materiales utilizados para este proyecto fueron información del Guidebook 42, un video de Youtube que ayudó a la comprensión de las variables estáticas. El uso de Copilot de Github para el tratamiento de los FDs multiples para el apartado del bonus.
	Sobre el uso de IA, así como lo antes explicado, la IA ha servido como un tutor. Para la explicación de conceptos básicos y generación de main para testear las distintas posibilidades de archivos que pueda encontrar.
	Además, dicha herramienta ayudó el la elaboración de este README, con la estructura y la correción de estilo.

SOBRE EL ALGORITMO Y SU JUSTIFICACIÓN

1.- Uso de variables estáticas: Se utiliza una variable static char *, para almacenar el excedente de la lectura. De esta manera gestionamos el read si este lee más allá de un salto de línea y la guardamos para la siguiente llamada.
2.- Lectura iterativa: La fucnión lee  mientras la condición del bucle se cumpla, es decir hasta que encuentre un \n o que llegue al final del archivo.
3.- Gestión de memoria: Se ha implementqado una limpieza rigurosa mediante free() para evitar memory leaks, sobre todo cuando existan errores de lectura del archivo o cuando este haya terminado.

JUSTIFICACIÓN:
	Al usar un buffer acumulativo, se garantiza que la informaciójn no se pierda entre llamadas, además, según la parte bonus, esto programa permite manejar múltiples descriptores de archivo de forma segura e independiente.