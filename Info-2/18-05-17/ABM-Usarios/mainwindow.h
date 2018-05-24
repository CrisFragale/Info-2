#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "usuario.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Agregar_clicked();

    void on_pushButton_Editar_clicked();

    void on_pushButton_Eliminar_clicked();

    void on_pushButton_Salir_clicked();

private:
    Ui::MainWindow *ui;

    QVector<Usuario> vUsuarios;
};

#endif // MAINWINDOW_H
