#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <vector>

//Constantes para ver si se está editando un motor o un conector
#define MOTOR 1
#define CONECTOR 2

//Constante para ver si se está editando o modificando una variable
#define CREANDO -1

//Constantes para definir los ejes coordenados
#define EJE_X 1
#define EJE_Y 2
#define EJE_Z 3

//Constantes para definir el tipo de componentes
#define MOTOR_ROT 1
#define CONECTO_ROT 2
#define MOTOR_TRANS 3
#define CONECTOR_TRANS 4

//Estructura principal para el guardado de las componentes (posteriormente para usar como vector)
struct SComponentes {
  int tipo; // Motor o conector, translacional o rotacional.
  //Para tipo translacionales
  float x;
  float y;
  float z;
  //Para tipo rotacionales
  int eje;
  float angulo;
  //para motores
  int orientacion;
};

//Variables de estado globales
extern int editando;
extern int tipo_edicion;
//Vector global con las componentes
extern std::vector<SComponentes> componentes;

//Declaración de funciones.
void printComponentes(const std::vector<SComponentes> &vect);
using namespace std;
string returnStringArchivo(const vector<SComponentes> &vect);
using namespace std;
string returnComponentes(const std::vector<SComponentes> &vect, int count);
#endif // GLOBALS_H
