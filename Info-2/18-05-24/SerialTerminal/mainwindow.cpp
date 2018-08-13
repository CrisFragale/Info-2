#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QByteArray>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    port = NULL;    //indica que el objeto puerto no esta creado;
    EnumerarPuertos();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete port;
}

void MainWindow::EnumerarPuertos()
{
    ui->comboBoxPort->clear();

    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    for (int i = 0; i < ports.size(); i++)
    {
        ui->comboBoxPort->addItem(ports.at(i).portName());
    }
}

void MainWindow::on_pushButtonConectar_clicked()
{
    if(!port)
    { // configuro el puerto
        port = new QSerialPort(ui->comboBoxPort->currentText());
        port->setBaudRate(QSerialPort::Baud115200);// velocidad
        port->setFlowControl(QSerialPort::NoFlowControl);
        port->setParity(QSerialPort::NoParity);
        port->setDataBits(QSerialPort::Data8);
        port->setStopBits(QSerialPort::OneStop);
        if(!port->open(QIODevice::ReadWrite))
        {
            QMessageBox::critical(this,"Error","No se puede abrir el puerto " + port->portName());
            delete port;
            port = NULL;
        }
        else
        {
            ui->pushButtonConectar->setText("Desconectar");
            connect(port,SIGNAL(readyRead()),this,SLOT(portReadyRead()));
        }
    }
    else
    {
        delete port;
        port = NULL;
        ui->pushButtonConectar->setText("Conectar");
    }
}

void MainWindow::on_pushButtonEnviar_clicked()
{
    if(port)
    {
        QByteArray aux;
        aux.append(ui->plainTextEditTX->toPlainText());

        port->write(aux);

        ui->plainTextEditTX->clear();
    }
    else
    {
        QMessageBox::critical(this, "Error", QString::fromUtf8("No hay ningún puerto abierto"));
    }
}

void MainWindow::portReadyRead()
{
    QByteArray aux;
    aux.resize(port->bytesAvailable());
    port->read(aux.data(),aux.size());
    ui->plainTextEditRX->insertPlainText(aux);
}
