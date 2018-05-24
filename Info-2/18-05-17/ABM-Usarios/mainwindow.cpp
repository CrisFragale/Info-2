#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include "dialogusuario.h"


QTreeWidgetItem* ConvertirUsuarioATreeItem(const Usuario& usuario, int nIndex); // mi treewidget item guarda el tree wirget parada vez que quiero mostrar infprmacion en mi tree widget.

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->treeWidget->setColumnWidth(0, 150);
    //ui->treeWidget->setColumnWidth(1, 150);
    //ui->treeWidget->setColumnWidth(2, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Agregar_clicked() //1 ejecuta dialogo
{   dialogUsuario dlg;

    if (dlg.exec() == QDialog::Accepted)
    {
            vUsuarios.append(dlg.usuario); // 3 levanto los datos de la var usuaruio

            int nIndex = vUsuarios.size()-1;
            ui->treeWidget->addTopLevelItem(ConvertirUsuarioATreeItem(dlg.usuario, nIndex)); // 4  lo cargo en el arbol y llamo a la fun

            ui->treeWidget->resizeColumnToContents(0);

            QMessageBox::information(this, "Prueba", "Usuario agregado satisfactoriamente!");
    }
}

QTreeWidgetItem* ConvertirUsuarioATreeItem(const Usuario& usuario, int nIndex) // 5 convierto a qtree.... item
{
        return new QTreeWidgetItem( // creo el Qtre.... y luego creeo un at top lavel (guarda el dato dentro del widget)
                QStringList()
                        << usuario.get_apeNom()
                        << QString::number(usuario.get_dni()) // recibe unnnumero number, y me devuelve un QSTRING.
                        << usuario.get_fecNac().toString("dd/MM/yyyy")
                        << QString::number(nIndex)


        );
}

void MainWindow::on_pushButton_Editar_clicked() // E1   clikeo en editar
{
    QTreeWidgetItem* item_old = ui->treeWidget->currentItem(); // agarro el usuario seleccionado

    if (item_old)
    {
            int nIndex = item_old->data(3, QVariant::Int).toInt();

            Usuario old = vUsuarios[nIndex];

            dialogUsuario dlg;
            dlg.usuario = old; // a usu le cargo el viejo

            if (dlg.exec() == QDialog::Accepted)//
            {
                    vUsuarios[nIndex] = dlg.usuario;

                    QTreeWidgetItem* item_new = ConvertirUsuarioATreeItem(dlg.usuario, nIndex);
                    *item_old = *item_new;
                    delete item_new;

                    ui->treeWidget->resizeColumnToContents(0);
            }
    }

}

void MainWindow::on_pushButton_Eliminar_clicked()
{
    QTreeWidgetItem* item_old = ui->treeWidget->currentItem();
    int resp;
    resp = QMessageBox::question(this, "Eliminar", "¿Está seguro?", QMessageBox::Yes | QMessageBox::No);
    if (item_old && resp == QMessageBox::Yes)
    {
            int nIndex = item_old->data(3, QVariant::Int).toInt();

            vUsuarios.remove(nIndex);

            delete ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item_old));

            ui->treeWidget->resizeColumnToContents(0);
    }

}

void MainWindow::on_pushButton_Salir_clicked()
{

}
