Motion Structure es una aplicación que busca ayudar al movimiento de estructuras motorizadas.

El problema que buscamos solucionar viene dado principalmente por las múltiples configuraciones posibles que pueden tener las estructuras motorizadas. Realizar el estudio cinemático y, posteriormente, la programación para cada configuración en particular es bastante complejo.

Motion structure soporta las componentes de tipo motor (sean estos translacionales o rotacionales) y conectores (también translacionales o rotacionales).




Instalación del proyecto:
========================

El proyecto requiere primero la instalación de las librerías armadillo:

```
$ sudo apt-get install armadillo
```
En caso que no le sirva la linea anterior buscar isntrucciones en http://arma.sourceforge.net/ 

una vez instalado armadillo y dentro de esta carpeta se debe compilar.

```
$ make
```
Con esto está listo para usarse el programa.


Ejecución del programa de muestra.
=================================

Antes de poder realizar la ejecución de muestra primero de debe descargar el Simulador VREP que es el usado para esta muestra.

Vrep está habilitado gratuitamente para licencia educacional y se puede encontrar en http://www.coppeliarobotics.com/

Para la ejecución del programa de muestra se tienen los siguentes archivos:

```
carpeta experiment:
	- brazo.cpp: Corresponde al experimento en el cual se mueve un brazo hecho en el simulador VREP.
	- vrep_scene.ttt: Es una escena en el simulador VREP lista para su uso con el programa de pruebas.
carpeta config:
	-brazo_vrep.txt: Posee la configuracion de la estructura robótica ya realizada en la interfaz de usuario.
```


ejecución
---------

primero se debe abrir vrep y cargar la escena que está en la carpeta experiment, pasos:

1) abrir vrep: puede abrirse desde terminal con ./vrep.sh sin la necesidad de la instalación de vrep en el sistema.
2) Dentro de vrep:
	2.1) File -> open scene -> buscar la escena que está en la carpeta experiments de motion_structure.


Luego desde un terminal situado en la carpeta motion_structure ejecutar:

```
$ make brazo
$ make runBrazo
```

Seguir los pasos que serán impresos por terminal.


Interfaz de usuario
===================

El objetivo de la interfaz de usuario es facilitar al programador la creación de una estructura nueva.


Instalación interfaz de usuario
-------------------------------

Primero es necesario que Instale Qt Creator, las instrucciones de instalación las puede encontrar en http://qt-project.org/.

Dentro de Qt debe hacer lo siguiente:
 File->Open file or proyect -> buscar el .pro que está dentro de la carpeta GUI de motion_structure.

y hacer click en run en Qt.  