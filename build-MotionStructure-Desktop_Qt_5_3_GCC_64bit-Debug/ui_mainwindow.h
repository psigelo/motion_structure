/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMotorRotacional;
    QAction *actionMotorTranslacional;
    QAction *actionConectorRotacional;
    QAction *actionConectorTranslacional;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listadoComponentes;
    QHBoxLayout *horizontalLayout;
    QPushButton *botonEliminar;
    QPushButton *botonModificar;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *nombreText;
    QPushButton *botonFinalizar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuAgregarMotor;
    QMenu *menuAgregarConector;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(381, 470);
        actionMotorRotacional = new QAction(MainWindow);
        actionMotorRotacional->setObjectName(QStringLiteral("actionMotorRotacional"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/60px-Symbol_Hydro_motor.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMotorRotacional->setIcon(icon);
        actionMotorTranslacional = new QAction(MainWindow);
        actionMotorTranslacional->setObjectName(QStringLiteral("actionMotorTranslacional"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Engine.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMotorTranslacional->setIcon(icon1);
        actionConectorRotacional = new QAction(MainWindow);
        actionConectorRotacional->setObjectName(QStringLiteral("actionConectorRotacional"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/1404361644_stock_draw-curved-connector-with-arrows.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConectorRotacional->setIcon(icon2);
        actionConectorTranslacional = new QAction(MainWindow);
        actionConectorTranslacional->setObjectName(QStringLiteral("actionConectorTranslacional"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/1404361647_stock_draw-line-connector-with-arrows.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConectorTranslacional->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 10, 321, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        listadoComponentes = new QListWidget(verticalLayoutWidget);
        listadoComponentes->setObjectName(QStringLiteral("listadoComponentes"));

        verticalLayout->addWidget(listadoComponentes);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        botonEliminar = new QPushButton(verticalLayoutWidget);
        botonEliminar->setObjectName(QStringLiteral("botonEliminar"));

        horizontalLayout->addWidget(botonEliminar);

        botonModificar = new QPushButton(verticalLayoutWidget);
        botonModificar->setObjectName(QStringLiteral("botonModificar"));

        horizontalLayout->addWidget(botonModificar);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        nombreText = new QLineEdit(verticalLayoutWidget);
        nombreText->setObjectName(QStringLiteral("nombreText"));

        horizontalLayout_2->addWidget(nombreText);

        botonFinalizar = new QPushButton(verticalLayoutWidget);
        botonFinalizar->setObjectName(QStringLiteral("botonFinalizar"));

        horizontalLayout_2->addWidget(botonFinalizar);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 381, 21));
        menuAgregarMotor = new QMenu(menuBar);
        menuAgregarMotor->setObjectName(QStringLiteral("menuAgregarMotor"));
        menuAgregarConector = new QMenu(menuBar);
        menuAgregarConector->setObjectName(QStringLiteral("menuAgregarConector"));
        MainWindow->setMenuBar(menuBar);

        toolBar->addAction(actionMotorRotacional);
        toolBar->addSeparator();
        toolBar->addAction(actionMotorTranslacional);
        toolBar->addSeparator();
        toolBar->addAction(actionConectorRotacional);
        toolBar->addAction(actionConectorTranslacional);
        menuBar->addAction(menuAgregarMotor->menuAction());
        menuBar->addAction(menuAgregarConector->menuAction());
        menuAgregarMotor->addAction(actionMotorRotacional);
        menuAgregarMotor->addAction(actionMotorTranslacional);
        menuAgregarConector->addAction(actionConectorRotacional);
        menuAgregarConector->addAction(actionConectorTranslacional);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Motion Structure", 0));
        actionMotorRotacional->setText(QApplication::translate("MainWindow", "Rotacional", 0));
        actionMotorTranslacional->setText(QApplication::translate("MainWindow", "Translacional", 0));
        actionConectorRotacional->setText(QApplication::translate("MainWindow", "Rotacional", 0));
        actionConectorTranslacional->setText(QApplication::translate("MainWindow", "Translacional", 0));
        label->setText(QApplication::translate("MainWindow", "Componentes agregadas", 0));
        botonEliminar->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        botonModificar->setText(QApplication::translate("MainWindow", "Modificar", 0));
        label_2->setText(QApplication::translate("MainWindow", "Nombre archivo", 0));
        botonFinalizar->setText(QApplication::translate("MainWindow", "Finalizar", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        menuAgregarMotor->setTitle(QApplication::translate("MainWindow", "Agregar Motor", 0));
        menuAgregarConector->setTitle(QApplication::translate("MainWindow", "Agregar Conector", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
