/********************************************************************************
** Form generated from reading UI file 'translacionaldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLACIONALDIALOG_H
#define UI_TRANSLACIONALDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TranslacionalDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *xText;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *yText;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *zText;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *orientacion_pos;
    QRadioButton *orientacion_neg;

    void setupUi(QDialog *TranslacionalDialog)
    {
        if (TranslacionalDialog->objectName().isEmpty())
            TranslacionalDialog->setObjectName(QStringLiteral("TranslacionalDialog"));
        TranslacionalDialog->resize(243, 143);
        buttonBox = new QDialogButtonBox(TranslacionalDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-140, 110, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(TranslacionalDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 91, 99));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        xText = new QLineEdit(verticalLayoutWidget);
        xText->setObjectName(QStringLiteral("xText"));

        horizontalLayout_3->addWidget(xText);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        yText = new QLineEdit(verticalLayoutWidget);
        yText->setObjectName(QStringLiteral("yText"));

        horizontalLayout_2->addWidget(yText);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        zText = new QLineEdit(verticalLayoutWidget);
        zText->setObjectName(QStringLiteral("zText"));

        horizontalLayout->addWidget(zText);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(TranslacionalDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(110, 10, 111, 91));
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 84, 71));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        orientacion_pos = new QRadioButton(verticalLayoutWidget_2);
        orientacion_pos->setObjectName(QStringLiteral("orientacion_pos"));

        verticalLayout_2->addWidget(orientacion_pos);

        orientacion_neg = new QRadioButton(verticalLayoutWidget_2);
        orientacion_neg->setObjectName(QStringLiteral("orientacion_neg"));

        verticalLayout_2->addWidget(orientacion_neg);


        retranslateUi(TranslacionalDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TranslacionalDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TranslacionalDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TranslacionalDialog);
    } // setupUi

    void retranslateUi(QDialog *TranslacionalDialog)
    {
        TranslacionalDialog->setWindowTitle(QApplication::translate("TranslacionalDialog", "Agregando translacional", 0));
        label_4->setText(QApplication::translate("TranslacionalDialog", "Ingresar longitud", 0));
        label_3->setText(QApplication::translate("TranslacionalDialog", "x", 0));
        label_2->setText(QApplication::translate("TranslacionalDialog", "y", 0));
        label->setText(QApplication::translate("TranslacionalDialog", "z", 0));
        groupBox->setTitle(QApplication::translate("TranslacionalDialog", "Orientaci\303\263n", 0));
        orientacion_pos->setText(QApplication::translate("TranslacionalDialog", "Positiva", 0));
        orientacion_neg->setText(QApplication::translate("TranslacionalDialog", "Negativa", 0));
    } // retranslateUi

};

namespace Ui {
    class TranslacionalDialog: public Ui_TranslacionalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLACIONALDIALOG_H
