#include "globals.h"
#include <sstream>

int editando = 1; //Guarda el valor de cuál es el tipo de componente que se está editando (translacional o rotacional)
int elementos = 0;
int tipo_edicion = CREANDO; //Guarda el estado del sistema para ver si se está agregando una componente nueva o se está editando una (en caso de que se esté editando esta sería el ID de la componente)

std::vector<SComponentes> componentes;

using namespace std;
void printComponentes(const vector<SComponentes> &vect)
{
    string nombre_tipo = "";
    string eje = "";
    if(vect.empty())
        cout << "\nNo hay elementos en el vector";
    else
        for(int count = 0; count < (int) vect.size(); count++){
            //Obtener el tipo de de componente que es (en palabras)
            if(vect[count].tipo == MOTOR_ROT)
                nombre_tipo = "Motor rotacional";
            else if(vect[count].tipo == CONECTO_ROT)
                nombre_tipo = "Conector rotacional";
            else if(vect[count].tipo == MOTOR_TRANS)
                nombre_tipo = "Motor translacional";
            else
                nombre_tipo = "Conector translacional";

            if((vect[count].tipo == MOTOR_ROT)||(vect[count].tipo == CONECTO_ROT)){
                if(vect[count].eje == EJE_X)
                    eje = "X";
                else if(vect[count].eje == EJE_Y)
                    eje = "Y";
                else
                    eje = "Z;";

                cout << "\nTipo: " << nombre_tipo << "\nEje:: " << eje << "\nAngulo: " << vect[count].angulo << "°" << endl;
            }else{
                cout << "\nTipo: " << nombre_tipo << "\nT(x,y,z): (" << vect[count].x << "," << vect[count].y << "," << vect[count].z << ")" << endl;
            }
        }
    cout << endl;
}

using namespace std;
string returnComponentes(const vector<SComponentes> &vect, int count)
{
    string nombre_tipo = "";
    string eje = "";
    string out = "";
    std::stringstream ss;

    if(vect.empty())
        return "";
    else{
            if(vect[count].tipo == MOTOR_ROT)
                nombre_tipo = "Motor rotacional";
            else if(vect[count].tipo == CONECTO_ROT)
                nombre_tipo = "Conector rotacional";
            else if(vect[count].tipo == MOTOR_TRANS)
                nombre_tipo = "Motor translacional   ";
            else
                nombre_tipo = "Conector translacional";

            out.append("#");

            //Esta es la mejor transformación de int a str que pude hacer :/
            std::stringstream ss;
            ss << count +1 ;
            std::string count_str = ss.str();

            out.append(count_str);
            out.append(" ");
            out.append(nombre_tipo);
            out.append(" ");
            ss.str("");

            if((vect[count].tipo == MOTOR_ROT)||(vect[count].tipo == CONECTO_ROT)){
                //Caso rotacional
                if(vect[count].eje == 1) //EJE_X
                    eje = "x";
                else if(vect[count].eje == 2) //EJE_Y
                    eje = "y";
                else
                    eje = "z";

                out.append("Eje: ");
                out.append(eje);
                out.append(" - Angulo:");

                ss << vect[count].angulo;
                std::string angle_str = ss.str();
                ss.str("");

                out.append(angle_str); //vect[count].angulo
                out.append("°");
            }else{// Caso translacional
                out.append("T(x,y,z): (");

                ss << vect[count].x;
                std::string x_str = ss.str();
                ss.str("");

                out.append(x_str);
                out.append(",");

                ss << vect[count].y;
                std::string y_str = ss.str();
                ss.str("");

                out.append(y_str);
                out.append(",");

                ss << vect[count].z;
                std::string z_str = ss.str();
                ss.str("");

                out.append(z_str); //vect[count].z
                out.append(")");
            }
    }
    return out;
}

/**
 *  Retorna un string con la información de los componentes para poner en el archivo de salida (de uso interno).
 */
using namespace std;
string returnStringArchivo(const vector<SComponentes> &vect)
{
    string out = "";
    std::stringstream ss;
    int size=vect.size(); //Guardar el tamaño del vector en la primera línea
    ss << size;
    std::string size_str = ss.str();
    out.append(size_str);
    out.append("\n");
    ss.str("");

    for(int count = 0; count < (int) vect.size(); count++){
        ss << vect[count].tipo;
        std::string tipo_str = ss.str();
        out.append(tipo_str);
        out.append(" ");
        ss.str("");
        if((vect[count].tipo == MOTOR_ROT)||(vect[count].tipo == MOTOR_TRANS)){
             ss << vect[count].orientacion;
             std::string orie = ss.str();
             out.append(orie);
             out.append(" ");
             ss.str("");
        }
        if((vect[count].tipo == MOTOR_ROT)||(vect[count].tipo == CONECTO_ROT)){
            ss << vect[count].eje;
            std::string eje_str = ss.str();
            out.append(eje_str);
            out.append(" ");
            ss.str("");

            ss << vect[count].angulo;
            std::string angulo_str = ss.str();
            out.append(angulo_str);
            out.append("\n");
            ss.str("");
        }else{// Caso translacional
            ss << vect[count].x;
            std::string x_str = ss.str();
            out.append(x_str);
            out.append(" ");
            ss.str("");

            ss << vect[count].y;
            std::string y_str = ss.str();
            out.append(y_str);
            out.append(" ");
            ss.str("");

            ss << vect[count].z;
            std::string z_str = ss.str();
            out.append(z_str);
            out.append("\n");
            ss.str("");
        }
    }
    return out;
}
