#include "dialogusuario.h"
#include "ui_dialogusuario.h"

dialogUsuario::dialogUsuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogUsuario)
{
    ui->setupUi(this);
}

dialogUsuario::~dialogUsuario()
{
    delete ui;
}


int dialogUsuario::exec() // E2 aca muestro
{


        ui->lineEdit_NomApe->setText(usuario.get_apeNom());
        QString ape_nom = usuario.get_apeNom();
        int coma = usuario.get_apeNom().indexOf("'");
        ui->lineEdit_Nombre->setText(ape_nom.mid(coma + 1));
        ui->lineEdit_Apellido->setText(ape_nom.mid(0, coma));
        ui->lineEdit_Dni->setText(QString::number(usuario.get_dni(),'d',8));
        ui->dateEdit->setDate(usuario.get_fecNac());
        ui->comboBox_Genero->setCurrentText(usuario.get_genero());

        //Hago las conexiones despues de inicializar
        connect(ui->lineEdit_Apellido, SIGNAL(textChanged(QString)), this,SLOT(nombreChanged(QString)));
        connect(ui->lineEdit_Nombre, SIGNAL(textChanged(QString)), this,SLOT(nombreChanged(QString)));

        return QDialog::exec();
}


void dialogUsuario::on_buttonBox_accepted() // 2 capto datos y guardo en usuario
{
    usuario.set_apeNom(ui->lineEdit_NomApe->text());
    usuario.set_fecNac(ui->dateEdit->date());
    usuario.set_dni(ui->lineEdit_Dni->text().toLong());
    usuario.set_genero(ui->comboBox_Genero->currentText());
}

void dialogUsuario::nombreChanged(QString s)
{
        ui->lineEdit_NomApe->setText(ui->lineEdit_Apellido->text().length()?ui->lineEdit_Apellido->text() + ", " + ui->lineEdit_Nombre->text():ui->lineEdit_Nombre->text());
}
