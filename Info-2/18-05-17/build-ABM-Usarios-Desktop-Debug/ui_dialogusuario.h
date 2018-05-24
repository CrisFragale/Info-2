/********************************************************************************
** Form generated from reading UI file 'dialogusuario.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUSUARIO_H
#define UI_DIALOGUSUARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_dialogUsuario
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_Apellido;
    QLabel *label_7;
    QComboBox *comboBox_Genero;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_Nombre;
    QLabel *label_6;
    QLineEdit *lineEdit_Dni;
    QLineEdit *lineEdit_NomApe;
    QLabel *label_5;
    QLabel *label_2;
    QDateEdit *dateEdit;

    void setupUi(QDialog *dialogUsuario)
    {
        if (dialogUsuario->objectName().isEmpty())
            dialogUsuario->setObjectName(QStringLiteral("dialogUsuario"));
        dialogUsuario->resize(318, 214);
        gridLayout = new QGridLayout(dialogUsuario);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(dialogUsuario);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 2);

        label_4 = new QLabel(dialogUsuario);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 2);

        lineEdit_Apellido = new QLineEdit(dialogUsuario);
        lineEdit_Apellido->setObjectName(QStringLiteral("lineEdit_Apellido"));

        gridLayout->addWidget(lineEdit_Apellido, 1, 2, 1, 1);

        label_7 = new QLabel(dialogUsuario);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 2);

        comboBox_Genero = new QComboBox(dialogUsuario);
        comboBox_Genero->setObjectName(QStringLiteral("comboBox_Genero"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_Genero->sizePolicy().hasHeightForWidth());
        comboBox_Genero->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBox_Genero, 6, 2, 1, 1);

        buttonBox = new QDialogButtonBox(dialogUsuario);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 7, 1, 1, 2);

        lineEdit_Nombre = new QLineEdit(dialogUsuario);
        lineEdit_Nombre->setObjectName(QStringLiteral("lineEdit_Nombre"));

        gridLayout->addWidget(lineEdit_Nombre, 0, 2, 1, 1);

        label_6 = new QLabel(dialogUsuario);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        lineEdit_Dni = new QLineEdit(dialogUsuario);
        lineEdit_Dni->setObjectName(QStringLiteral("lineEdit_Dni"));

        gridLayout->addWidget(lineEdit_Dni, 3, 2, 1, 1);

        lineEdit_NomApe = new QLineEdit(dialogUsuario);
        lineEdit_NomApe->setObjectName(QStringLiteral("lineEdit_NomApe"));
        lineEdit_NomApe->setReadOnly(true);

        gridLayout->addWidget(lineEdit_NomApe, 2, 2, 1, 1);

        label_5 = new QLabel(dialogUsuario);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 2);

        label_2 = new QLabel(dialogUsuario);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        dateEdit = new QDateEdit(dialogUsuario);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy1);
        dateEdit->setMinimumSize(QSize(0, 0));
        dateEdit->setAcceptDrops(false);

        gridLayout->addWidget(dateEdit, 4, 2, 1, 1);


        retranslateUi(dialogUsuario);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogUsuario, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogUsuario, SLOT(reject()));

        comboBox_Genero->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(dialogUsuario);
    } // setupUi

    void retranslateUi(QDialog *dialogUsuario)
    {
        dialogUsuario->setWindowTitle(QApplication::translate("dialogUsuario", "Dialog", 0));
        label_3->setText(QApplication::translate("dialogUsuario", "Nombre", 0));
        label_4->setText(QApplication::translate("dialogUsuario", "Apellido", 0));
        label_7->setText(QApplication::translate("dialogUsuario", "Genero", 0));
        comboBox_Genero->clear();
        comboBox_Genero->insertItems(0, QStringList()
         << QApplication::translate("dialogUsuario", "Femenino", 0)
         << QApplication::translate("dialogUsuario", "Masculino", 0)
         << QApplication::translate("dialogUsuario", "Otro", 0)
        );
        label_6->setText(QApplication::translate("dialogUsuario", "DNI", 0));
        lineEdit_Dni->setInputMask(QApplication::translate("dialogUsuario", "99999999", 0));
        label_5->setText(QApplication::translate("dialogUsuario", "Nombre Completo", 0));
        label_2->setText(QApplication::translate("dialogUsuario", "Fecha De Nacimiento", 0));
    } // retranslateUi

};

namespace Ui {
    class dialogUsuario: public Ui_dialogUsuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUSUARIO_H
