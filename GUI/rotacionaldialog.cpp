#include "rotacionaldialog.h"
#include "ui_rotacionaldialog.h"
#include <QMessageBox>
#include "globals.h"
#include <mainwindow.h>

#include <string>
#include <sstream>

RotacionalDialog::RotacionalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RotacionalDialog)
{
    ui->setupUi(this);
    ui->orientacion_neg->setEnabled(editando == MOTOR);
    ui->orientacion_pos->setEnabled(editando == MOTOR);
}

RotacionalDialog::~RotacionalDialog()
{
    delete ui;
}

/**
 *  Guarda los datos ingresados por el form de rotacional.
 *  Guarda bool x_selected, y_selected o z_selected dependiendo de que coordenada es la que se va a editar
 *  Y float ángulo el ángulo a editar
 *  Además guarda la variable "editar" con la información si se está editando el motor o un conector.
 */
void RotacionalDialog::on_buttonBox_accepted()
{
    float angulo =  ui->anguloText->text().toFloat();
    int selected = 0;
    int orientacion = 0;

    if(ui->rot_x->isChecked()){
        selected = EJE_X;
     }
     else if(ui->rot_y->isChecked()){
        selected = EJE_Y;
     }else{
        selected = EJE_Z;
     }

    if(editando == MOTOR){
        if(ui->orientacion_pos->isChecked())
            orientacion = 1;
        if(ui->orientacion_neg->isChecked())
            orientacion = 0;
    }

    if(tipo_edicion == CREANDO){ // se está creando un vector
        if(editando == MOTOR){
            SComponentes componente = { MOTOR_ROT, 0,0,0, selected, angulo , orientacion};
            componentes.push_back(componente);
        }else{
            SComponentes componente = { CONECTO_ROT, 0,0,0, selected, angulo , orientacion};
            componentes.push_back(componente);
       }
    }else{ // Se está modificando un vector
         int posicion = tipo_edicion;
         componentes[posicion].eje = selected;
         componentes[posicion].angulo = angulo;
    }
}
