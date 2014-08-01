#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QString>
#include <QListWidgetItem>
#include <iostream>
#include <fstream>

#include "rotacionaldialog.h" //Para menú
#include "translacionaldialog.h" //Para menú

#include "globals.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->nombreText->setText("salida.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 \brief Llamado cuando se clcikea el botón "motor rotacional". Cambia las variables de editando a motor y llama al dialog rotacional.
 */
void MainWindow::on_actionMotorRotacional_triggered()
{
    //Llamar a menú rotacional
    editando = MOTOR;
    tipo_edicion = CREANDO;
    RotacionalDialog motor_rot;
    motor_rot.exec();
    actualizarComponentes();
}
/**
 \brief Llamado cuando se clickea el botón "motor translacional". Cambia las variables de editando a motor y llama al dialog translacional.
 */

void MainWindow::on_actionMotorTranslacional_triggered()
{
    editando = MOTOR;
    tipo_edicion = CREANDO;
    TranslacionalDialog motor_trans;
    motor_trans.exec();
    actualizarComponentes();
}

/**
 \brief Llamado cuando se clickea el botón "conector rotacional". Cambia las variables de editando a conector y llama al dialog respectivo.
 */
void MainWindow::on_actionConectorRotacional_triggered()
{
    editando = CONECTOR;
    tipo_edicion = CREANDO;
    RotacionalDialog conector_motor;
    conector_motor.exec();
    actualizarComponentes();
}

/**
 \brief Llamado cuando se clickea el botón "conector rotacional". Cambia las variables de editando a conector y llama al dialog respectivo.
 */
void MainWindow::on_actionConectorTranslacional_triggered()
{
    editando = CONECTOR;
    tipo_edicion = CREANDO;
    TranslacionalDialog conector_trans;
    conector_trans.exec();
    actualizarComponentes();
}

/**
 \brief Elimina una componente agregada en específico.
 \brief La componente que es borrada es la que está seleccionada en el widget listadoComponentes.
 */
void MainWindow::on_botonEliminar_clicked()
{
    int item = ui->listadoComponentes->currentRow();
    ui->listadoComponentes->takeItem(item);

    componentes.erase(componentes.begin() + item);
    printComponentes(componentes);

    actualizarComponentes();
}

/**
 \brief  Método a ser llamado cada vez que se haga una modificación en la cantidad de componentes.
 */
void MainWindow::actualizarComponentes()
{
    ui->listadoComponentes->clear();
    for(int count = 0;  count < (int) componentes.size(); count++){
        string salida = returnComponentes(componentes, count);
        QString qstr = QString::fromStdString(salida);
        ui->listadoComponentes->addItem(new QListWidgetItem(qstr));
    }
}


/**
 \brief  Llama a la ventana de edición de componente (sea esta translacional o rotacional)
 */
void MainWindow::on_botonModificar_clicked()
{
    int item = ui->listadoComponentes->currentRow();
    tipo_edicion = item;
    if((componentes[item].tipo == MOTOR_ROT)||(componentes[item].tipo == CONECTO_ROT)){
        RotacionalDialog rot;
        rot.exec();
    }else{
        TranslacionalDialog trans;
        trans.exec();
    }
    actualizarComponentes();
}

/**
 \brief Método que es llamado al finalizar el proceso. Genera el archivo de salida con la configuración guardada.
  Guarda toda la información guardada en el vector de estructuras y además lee el input para el nombre del archivo a generar.
 */
using namespace std;
void MainWindow::on_botonFinalizar_clicked()
{
    ofstream myfile;
    QString qs = ui->nombreText->text();
    myfile.open (qs.toUtf8().constData()); //Este es el nombre del archivo entregado por argumento
    myfile << returnStringArchivo(componentes);
    myfile.close();

    QMessageBox msgBox;
    msgBox.setText("Generado archvivo de salida");
    msgBox.exec();
}
