#ifndef DIALOGUSUARIO_H
#define DIALOGUSUARIO_H

#include <QDialog>
#include "usuario.h"

namespace Ui {
class dialogUsuario;
}

class dialogUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit dialogUsuario(QWidget *parent = 0);
    ~dialogUsuario();
     int exec();

    Usuario usuario;

public slots:
    void nombreChanged(QString s);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::dialogUsuario *ui;
};

#endif // DIALOGUSUARIO_H
