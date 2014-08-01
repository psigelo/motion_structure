/********************************************************************************
** Form generated from reading UI file 'rotacionaldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTACIONALDIALOG_H
#define UI_ROTACIONALDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RotacionalDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *rot_x;
    QRadioButton *rot_y;
    QRadioButton *rot_z;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QLineEdit *anguloText;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *orientacion_pos;
    QRadioButton *orientacion_neg;

    void setupUi(QDialog *RotacionalDialog)
    {
        if (RotacionalDialog->objectName().isEmpty())
            RotacionalDialog->setObjectName(QStringLiteral("RotacionalDialog"));
        RotacionalDialog->resize(226, 194);
        buttonBox = new QDialogButtonBox(RotacionalDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-150, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(RotacionalDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 61, 121));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 41, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rot_x = new QRadioButton(verticalLayoutWidget);
        rot_x->setObjectName(QStringLiteral("rot_x"));

        verticalLayout->addWidget(rot_x);

        rot_y = new QRadioButton(verticalLayoutWidget);
        rot_y->setObjectName(QStringLiteral("rot_y"));

        verticalLayout->addWidget(rot_y);

        rot_z = new QRadioButton(verticalLayoutWidget);
        rot_z->setObjectName(QStringLiteral("rot_z"));

        verticalLayout->addWidget(rot_z);

        verticalLayoutWidget_5 = new QWidget(RotacionalDialog);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(90, 20, 111, 41));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_5);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_6->addWidget(label);

        anguloText = new QLineEdit(verticalLayoutWidget_5);
        anguloText->setObjectName(QStringLiteral("anguloText"));

        verticalLayout_6->addWidget(anguloText);

        groupBox_2 = new QGroupBox(RotacionalDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(90, 70, 111, 71));
        verticalLayoutWidget_3 = new QWidget(groupBox_2);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 91, 42));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        orientacion_pos = new QRadioButton(verticalLayoutWidget_3);
        orientacion_pos->setObjectName(QStringLiteral("orientacion_pos"));

        verticalLayout_3->addWidget(orientacion_pos);

        orientacion_neg = new QRadioButton(verticalLayoutWidget_3);
        orientacion_neg->setObjectName(QStringLiteral("orientacion_neg"));

        verticalLayout_3->addWidget(orientacion_neg);

        verticalLayoutWidget_3->raise();

        retranslateUi(RotacionalDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RotacionalDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RotacionalDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RotacionalDialog);
    } // setupUi

    void retranslateUi(QDialog *RotacionalDialog)
    {
        RotacionalDialog->setWindowTitle(QApplication::translate("RotacionalDialog", "Agregando rotacional", 0));
        groupBox->setTitle(QApplication::translate("RotacionalDialog", "Eje", 0));
        rot_x->setText(QApplication::translate("RotacionalDialog", "x", 0));
        rot_y->setText(QApplication::translate("RotacionalDialog", "y", 0));
        rot_z->setText(QApplication::translate("RotacionalDialog", "z", 0));
        label->setText(QApplication::translate("RotacionalDialog", "\303\201ngulo elemento", 0));
        groupBox_2->setTitle(QApplication::translate("RotacionalDialog", "Orientaci\303\263n", 0));
        orientacion_pos->setText(QApplication::translate("RotacionalDialog", "Positiva", 0));
        orientacion_neg->setText(QApplication::translate("RotacionalDialog", "Negativa", 0));
    } // retranslateUi

};

namespace Ui {
    class RotacionalDialog: public Ui_RotacionalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTACIONALDIALOG_H
