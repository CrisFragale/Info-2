#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_pushButtonEnviar_clicked();
    void on_pushButtonConectar_clicked();
    void portReadyRead();

private:
    QSerialPort *port;
    void EnumerarPuertos();
};

#endif // MAINWINDOW_H
