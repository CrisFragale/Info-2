/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Salir;
    QPushButton *pushButton_Agregar;
    QPushButton *pushButton_Eliminar;
    QPushButton *pushButton_Editar;
    QTreeWidget *treeWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_Salir = new QPushButton(centralWidget);
        pushButton_Salir->setObjectName(QStringLiteral("pushButton_Salir"));

        gridLayout->addWidget(pushButton_Salir, 1, 3, 1, 1);

        pushButton_Agregar = new QPushButton(centralWidget);
        pushButton_Agregar->setObjectName(QStringLiteral("pushButton_Agregar"));

        gridLayout->addWidget(pushButton_Agregar, 1, 0, 1, 1);

        pushButton_Eliminar = new QPushButton(centralWidget);
        pushButton_Eliminar->setObjectName(QStringLiteral("pushButton_Eliminar"));

        gridLayout->addWidget(pushButton_Eliminar, 1, 2, 1, 1);

        pushButton_Editar = new QPushButton(centralWidget);
        pushButton_Editar->setObjectName(QStringLiteral("pushButton_Editar"));

        gridLayout->addWidget(pushButton_Editar, 1, 1, 1, 1);

        treeWidget = new QTreeWidget(centralWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        gridLayout->addWidget(treeWidget, 0, 0, 1, 4);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_Salir->setText(QApplication::translate("MainWindow", "Salir", 0));
        pushButton_Agregar->setText(QApplication::translate("MainWindow", "Agregar", 0));
        pushButton_Eliminar->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        pushButton_Editar->setText(QApplication::translate("MainWindow", "Editar", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Fecha Nacimiento", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Dni", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Nombre Y Apellido", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
