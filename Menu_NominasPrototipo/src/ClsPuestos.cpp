#include "ClsPuestos.h"

#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;


ClsPuestos::ClsPuestos(int ivalorNumero, string svalorNombrePuesto, string svalorDepartamento, int ivalorSalario, string svalorNivel, string svalorHoraEntrada, string svalorHoraSalida)
{
    mestablecerNumero(ivalorNumero);
    mestablecerNombreP(svalorNombrePuesto);
    mestablecerDepartamento(svalorDepartamento);
    mestablecerSalario(ivalorSalario);
    mestablecerNivelAcademico(svalorNivel);
    mestablecerHoraEntrada(svalorHoraEntrada);
    mestablecerHoraSalida(svalorHoraSalida);
}


int ClsPuestos::mobtenerNumero() const
{
    return m_iNumeroPuesto;
}

void ClsPuestos::mestablecerNumero (int ivalorNumero)
{
    m_iNumeroPuesto = ivalorNumero;
}


string ClsPuestos::mobtenerNombreP() const
{
    return m_sNombrePuesto;
}


void ClsPuestos::mestablecerNombreP( string scadenaNombreP )
{

   const char *svalorNombrePuesto = scadenaNombreP.data();
   int ilongitud = strlen( svalorNombrePuesto );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombrePuesto, svalorNombrePuesto, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';

}


string ClsPuestos::mobtenerDepartamento() const
{
    return m_sNombreDepartamento;
}


void ClsPuestos::mestablecerDepartamento( string sdepa )
{

   const char *svalorDepartamento = sdepa.data();
   int ilongitud = strlen( svalorDepartamento );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombreDepartamento, svalorDepartamento, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';
}

int ClsPuestos::mobtenerSalario() const
{
    return m_iSalario;
}

void ClsPuestos::mestablecerSalario (int ivalorSalario)
{
    m_iSalario = ivalorSalario;
}

string ClsPuestos::mobtenerNivAcademico() const
{
    return m_sNivelAcademico;
}


void ClsPuestos::mestablecerNivelAcademico( string snivel )
{

   const char *svalorNivel = snivel.data();
   int ilongitud = strlen( svalorNivel );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNivelAcademico, svalorNivel, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';
}

string ClsPuestos::mobtenerHoraEntrada() const
{
    return m_sHoraEntrada;
}


void ClsPuestos::mestablecerHoraEntrada( string sHoraEntrada )
{

   const char *svalorHoraEntrada = sHoraEntrada.data();
   int ilongitud = strlen( svalorHoraEntrada );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sHoraEntrada, svalorHoraEntrada, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';
}

string ClsPuestos::mobtenerHoraSalida() const
{
    return m_sHoraSalida;
}


void ClsPuestos::mestablecerHoraSalida( string sHoraSalida )
{

   const char *svalorHoraSalida = sHoraSalida.data();
   int ilongitud = strlen( svalorHoraSalida );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sHoraSalida, svalorHoraSalida, ilongitud );


   m_sNombrePuesto[ ilongitud ] = '\0';
}
