#include "basedatos.h"
#include "ui_basedatos.h"
#include "dialogusuario.h"
#include <QVector>

BaseDatos::BaseDatos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BaseDatos)
{
    ui->setupUi(this);
}

BaseDatos::~BaseDatos()
{
    delete ui;
}

void BaseDatos::on_Botton_Agregar_clicked()
{
    DialogUsuario dig;

    dig exec();

    vUsuarios.append(dig.usuario);


}
