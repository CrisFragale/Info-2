
#ifndef USUARIO_H
#define USUARIO_H


    #include <QString>
    #include <QDate>
    using namespace std;

    class Usuario
    {
       protected:
          QString  m_apeNom; // Apellido y Nombre del Alumno
          long  m_dni;
          QDate   m_fecNac;
          QString m_genero;

       public:
          void set_apeNom (const QString &apeNom);   // Método para poner el nombre.
          void set_dni    (const long dni);   // Método para poner el DNI.
          void set_fecNac   (const QDate &fecNac);   // Método para poner la edad.
          void set_genero   (const QString &genero);

       public:
          Usuario ();
          Usuario (const Usuario&);
          ~Usuario ();

          Usuario& operator= (const Usuario&);

          QString get_apeNom  (void) const;
          long  get_dni     (void) const;
          QDate   get_fecNac    (void) const;
          QString get_genero(void) const;
    };

#endif /* USUARIO_H */
