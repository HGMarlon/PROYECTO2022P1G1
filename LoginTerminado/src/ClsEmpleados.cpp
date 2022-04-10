//clase
#include "ClsEmpleados.h"

//librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

//constructor
ClsEmpleados::ClsEmpleados(int ivalorClave, string svalorNombre/*, string svalorDpi, string svalorDireccion, string svalorTelefono, string svalorCorreo*/)
{
    mestablecerClave(ivalorClave);
    mestablecerNombre(svalorNombre);
    /*mestablecerDpi(svalorDpi);
    mestablecerDireccion(svalorDireccion);
    mestablecerTelefono(svalorTelefono);
    mestablecerCorreo(svalorCorreo);*/
}

//Funciones de la clave del empleado
int ClsEmpleados::mobtenerClave() const
{
    return m_iclaveEmpleado;
}

void ClsEmpleados::mestablecerClave (int ienteroClave)
{
    m_iclaveEmpleado = ienteroClave;
}

//Funciones del nombre del empleado
string ClsEmpleados::mobtenerNombre() const
{
    return m_snombreEmpleado;
}

void ClsEmpleados::mestablecerNombre( string scadenaNombre )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombreEmpleado, svalorNombre, ilongitud );

   // anexar caracter nulo al final del nombre
   m_snombreEmpleado[ ilongitud ] = '\0';

}

//Funciones del Dpi del empleado
/*string ClsEmpleados::mobtenerDpi() const
{
    return m_sdpiEmpleado;
}

void ClsEmpleados::mestablecerDpi( string scadenaDpi )
{
    // copiar a lo más 20 caracteres de la cadena en dpi
   const char *svalorDpi = scadenaDpi.data();
   int ilongitud = strlen( svalorDpi );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sdpiEmpleado, svalorDpi, ilongitud );

   // anexar caracter nulo al final del dpi
   m_sdpiEmpleado[ ilongitud ] = '\0';
}

//Funciones de la Direccion del empleado
string ClsEmpleados::mobtenerDireccion() const
{
    return m_sdireccionEmpleado;
}

void ClsEmpleados::mestablecerDireccion ( string scadenaDireccion )
{
    // copiar a lo más 20 caracteres de la cadena de la direccion
   const char *svalorDireccion = scadenaDireccion.data();
   int ilongitud = strlen( svalorDireccion );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sdireccionEmpleado, svalorDireccion, ilongitud );

   // anexar caracter nulo al final de la cadena de la direccion
   m_sdireccionEmpleado[ ilongitud ] = '\0';
}

//Funciones del telefono del empleado
string ClsEmpleados::mobtenerTelefono() const
{
    return m_stelefonoEmpleado;
}

void ClsEmpleados::mestablecerTelefono ( string scadenaTelefono )
{
    // copiar a lo más 20 caracteres de la cadena del telefono
   const char *svalorTelefono = scadenaTelefono.data();
   int ilongitud = strlen( svalorTelefono );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_stelefonoEmpleado, svalorTelefono, ilongitud );

   // anexar caracter nulo al final de la cadena del telefono
   m_stelefonoEmpleado[ ilongitud ] = '\0';
}

//Funciones del correo electronico del empleado
string ClsEmpleados::mobtenerCorreo() const
{
    return m_scorreoEmpleado;
}

void ClsEmpleados::mestablecerCorreo ( string scadenaCorreo )
{
    // copiar a lo más 20 caracteres de la cadena del telefono
   const char *svalorCorreo = scadenaCorreo.data();
   int ilongitud = strlen( svalorCorreo );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_scorreoEmpleado, svalorCorreo, ilongitud );

   // anexar caracter nulo al final de la cadena de la direccion
   m_scorreoEmpleado[ ilongitud ] = '\0';
}*/
