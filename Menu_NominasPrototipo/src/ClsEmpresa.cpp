//clase
#include "ClsEmpresa.h"

//librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;




#include "ClsEmpresa.h"

ClsEmpresa::ClsEmpresa(string svalorNombreE, string svalorCorreoE, string svalorNombreD, string svalorActividadE, string svalorNitE, string svalorDireccionE, int ivalorTelefonoE, int ivalorNumEmpleados, int ivalorNumEmpresa)
{
    mestablecerNombreE(svalorNombre);
    mestablecerCorreoE(svalorCorreo);
    mestablecerDirectorE(svalorNombreD);
    mestablecerActividadE(svalorActividad);
    mestablecerNitE(svalorNit);
    mestablecerDireccionE(svalorDireccion);
    mestablecerTelefonoE(ivalorTelefono);
    mestablecerNumeroEmpleadosE(ivalorNumEmpleados);
    mestablecerNumeroEmpresa(ivalorNumEmpresa);
}

//Funciones del nombre de la empresa
string ClsEmpresa::mobtenerNombreE() const
{
    return m_sNombreEmpresa;
}

void ClsEmpresa::mestablecerNombreE( string sNombreE )
{
   // copiar a lo m�s 20 caracteres de la cadena en nombree
   const char *svalorNombreE = sNombreE.data();
   int ilongitud = strlen( svalorNombreE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombreEmpresa, svalorNombreE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sNombreEmpresa[ ilongitud ] = '\0';

}













ClsEmpresa::~ClsEmpresa()
{
    //dtor
}
