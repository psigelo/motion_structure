#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void actualizarComponentes();

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionMotorRotacional_triggered();

    void on_actionMotorTranslacional_triggered();

    void on_actionConectorRotacional_triggered();

    void on_actionConectorTranslacional_triggered();

    void on_botonEliminar_clicked();

    void on_botonFinalizar_clicked();

    void on_botonModificar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
