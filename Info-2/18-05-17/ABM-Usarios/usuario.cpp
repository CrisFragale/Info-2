
#include "usuario.h"
#include <iostream>
#include <cstring>
using namespace std;

// -----------------------------------------------------------------------------
Usuario::Usuario(){
   m_apeNom = "sin nombre";
   m_fecNac   = QDate::fromString("01/01/2000","dd/mm/yyyy");
   m_dni    = 0;
   m_genero = "Femenino";

}
// -----------------------------------------------------------------------------
Usuario::Usuario(const Usuario& a){
   m_apeNom = a.m_apeNom;
   m_fecNac   = a.m_fecNac;
   m_dni    = a.m_dni;
   m_genero = a.m_genero;

}
// -----------------------------------------------------------------------------
Usuario::~Usuario(){
}
// -----------------------------------------------------------------------------
void Usuario::set_apeNom (const QString  &ape_nom){
   m_apeNom = ape_nom;
}
// -----------------------------------------------------------------------------
void Usuario::set_dni (const long dni){

   m_dni = dni;
}

// -----------------------------------------------------------------------------
void Usuario::set_fecNac(const QDate &fec_nac){

   m_fecNac = fec_nac;
}

void Usuario::set_genero(const QString &genero)
{
    m_genero = genero;
}
// -----------------------------------------------------------------------------
QString Usuario::get_apeNom (void) const {
  return m_apeNom;
}
// -----------------------------------------------------------------------------
long Usuario::get_dni (void) const {
  return m_dni;
}

// -----------------------------------------------------------------------------
QDate Usuario::get_fecNac(void) const {
  return m_fecNac;
}
// -----------------------------------------------------------------------------
QString Usuario::get_genero(void) const {
  return m_genero;
}

// -----------------------------------------------------------------------------
Usuario& Usuario::operator= (const Usuario& a){
    m_apeNom = a.m_apeNom;
    m_dni = a.m_dni;
    m_fecNac = a.m_fecNac;
    m_genero = a.m_genero;
    return *this;
}
// -----------------------------------------------------------------------------
