#include "translacionaldialog.h"
#include "ui_translacionaldialog.h"
#include "globals.h"
#include "mainwindow.h"
#include <QMessageBox>

TranslacionalDialog::TranslacionalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TranslacionalDialog)
{
    ui->setupUi(this);
    ui->orientacion_neg->setEnabled(editando == MOTOR);
    ui->orientacion_pos->setEnabled(editando == MOTOR);
}

TranslacionalDialog::~TranslacionalDialog()
{
    delete ui;
}

void TranslacionalDialog::on_buttonBox_accepted()
{
     float x = ui->xText->text().toFloat();
     float y = ui->yText->text().toFloat();
     float z = ui->zText->text().toFloat();
     int orientacion = 0;

     if(editando == MOTOR){
         if(ui->orientacion_pos->isChecked())
             orientacion = 1;
         if(ui->orientacion_neg->isChecked())
             orientacion = 0;
     }

     if(tipo_edicion == CREANDO){ // se está creando un vector
        if(editando == MOTOR){
             SComponentes componente = { MOTOR_TRANS, x,y,z, 0, 0, orientacion };
            componentes.push_back(componente);
        }else{
             SComponentes componente = { CONECTOR_TRANS, x,y,z, 0, 0, orientacion };
            componentes.push_back(componente);
        }
     }else{ //Modificar el vector
         int posicion = tipo_edicion;
         componentes[posicion].x = x;
         componentes[posicion].y = y;
         componentes[posicion].z = z;
     }
}
