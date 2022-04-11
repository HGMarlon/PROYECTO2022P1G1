#include "ClsConceptos.h"

//librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

ClsConceptos::ClsConceptos(int valorCodigo, string txtNombre, string nSueldo, string nBono)
{
    mestablecerCodigo(valorCodigo);
    mestablecerNombreSueldo(txtNombre);
    mestablecerSueldo(nSueldo);
    mestablecerBono(nBono);
}

int ClsConceptos::mobtenerCodigo() const
{
    return m_iclaveEmpleadoSueldo;
}

void ClsConceptos::mestablecerCodigo (int ienteroCodigo)
{
    m_iclaveEmpleadoSueldo = ienteroCodigo;
}

//Funciones del nombre del empleado
string ClsConceptos::mobtenerNombreSueldo() const
{
    return m_snombreEmpleadoSueldo;
}

void ClsConceptos::mestablecerNombreSueldo( string scadenaNombreSueldo )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombreSueldo = scadenaNombreSueldo.data();
   int ilongitud = strlen( svalorNombreSueldo );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombreEmpleadoSueldo, svalorNombreSueldo, ilongitud );

   // anexar caracter nulo al final del nombre
   m_snombreEmpleadoSueldo[ ilongitud ] = '\0';

}

string ClsConceptos::mobtenerSueldo() const
{
    return m_sSueldo;
}

void ClsConceptos::mestablecerSueldo( string scadenaSueldo )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorSueldo = scadenaSueldo.data();
   int ilongitud = strlen( svalorSueldo );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sSueldo, svalorSueldo, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sSueldo[ ilongitud ] = '\0';

}

string ClsConceptos::mobtenerBono() const
{
    return m_sBono;
}

void ClsConceptos::mestablecerBono( string scadenaBono )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorBono = scadenaBono.data();
   int ilongitud = strlen( svalorBono );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sBono, svalorBono, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sBono[ ilongitud ] = '\0';

}

ClsConceptos::~ClsConceptos()
{
    //dtor
}
