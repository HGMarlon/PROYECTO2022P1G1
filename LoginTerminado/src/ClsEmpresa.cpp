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

ClsEmpresa::ClsEmpresa(string svalorNombreE, string svalorCorreoE, string svalorNombreD, string svalorActividadE, string svalorNitE, string svalorDireccionE, int ivalorTelefonoE, int ivalorNumEmpleados, int ivalorNumEmpresa)
{
    mestablecerNombreE(svalorNombreE);
    mestablecerCorreoE(svalorCorreoE);
    mestablecerDirectorE(svalorNombreD);
    mestablecerActividadE(svalorActividadE);
    mestablecerNitE(svalorNitE);
    mestablecerDireccionE(svalorDireccionE);
    mestablecerTelefonoE(ivalorTelefonoE);
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
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombreE = sNombreE.data();
   int ilongitud = strlen( svalorNombreE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombreEmpresa, svalorNombreE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sNombreEmpresa[ ilongitud ] = '\0';

}


//Funciones del correo electronico de la empresa
string ClsEmpresa::mobtenerCorreoE() const
{
    return m_sCorreoEmpresa;
}

void ClsEmpresa::mestablecerCorreoE( string sCorreoE )
{
    // copiar a lo más 20 caracteres de la cadena del telefono
   const char *svalorCorreoE = sCorreoE.data();
   int ilongitud = strlen( svalorCorreoE );
   ilongitud = ( ilongitud< 20 ? ilongitud : 19 );
   strncpy( m_sCorreoEmpresa, svalorCorreoE, ilongitud );

   // anexar caracter nulo al final de la cadena de la direccion
   m_sCorreoEmpresa[ ilongitud ] = '\0';
}



//Funciones del nombre del gerente
string ClsEmpresa:: mobtenerDirectorE() const
{
    return m_sNombreDirector;
}

void ClsEmpresa::mestablecerDirectorE( string sNombreDirector )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombreD = sNombreDirector.data();
   int ilongitud = strlen( svalorNombreD );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy(m_sNombreDirector, svalorNombreD, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sNombreDirector[ ilongitud ] = '\0';

}


//Funciones actividad de la empresa
string ClsEmpresa::mobtenerActividadE() const
{
    return m_sActividadEconomica;
}

void ClsEmpresa::mestablecerActividadE( string sActividadE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorActividadE = sActividadE.data();
   int ilongitud = strlen( svalorActividadE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sActividadEconomica, svalorActividadE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sActividadEconomica[ ilongitud ] = '\0';

}


//Funciones nit de la empresa
string ClsEmpresa::mobtenerNitE() const
{
    return m_iNitEmpresa;
}

void ClsEmpresa::mestablecerNitE( string sNitE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNitE = sNitE.data();
   int ilongitud = strlen( svalorNitE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_iNitEmpresa, svalorNitE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_iNitEmpresa[ ilongitud ] = '\0';

}



//Funciones direccion de la empresa
string ClsEmpresa::mobtenerDireccionE() const
{
    return m_iDireccionEmpresa;
}

void ClsEmpresa::mestablecerDireccionE( string sDireccionE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorDireccionE = sDireccionE.data();
   int ilongitud = strlen( svalorDireccionE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_iDireccionEmpresa, svalorDireccionE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_iDireccionEmpresa[ ilongitud ] = '\0';

}


//Funciones telefono de la empresa
int ClsEmpresa::mobtenerTelefonoE() const
{
    return m_iTelefonoEmpresa;
}

void ClsEmpresa::mestablecerTelefonoE (int  ivalorTelefonoE)
{
    m_iTelefonoEmpresa =  ivalorTelefonoE;
}



//Funciones numero de empleados de la empresa
int ClsEmpresa::mobtenerNumeroEmpleadosE() const
{
    return m_iNumeroEmpleados;
}

void ClsEmpresa::mestablecerNumeroEmpleadosE (int ivalorNumEmpleados)
{
    m_iNumeroEmpleados = ivalorNumEmpleados;
}



//Funciones numero de empresa
int ClsEmpresa::mobtenerNumeroEmpresa() const
{
    return  m_iNumeroDeEmpresa;
}

void ClsEmpresa::mestablecerNumeroEmpresa(int ivalorNumEmpresa)
{
     m_iNumeroDeEmpresa = ivalorNumEmpresa;
}


/*ClsEmpresa::~ClsEmpresa()
{
    //dtor
}
*/
