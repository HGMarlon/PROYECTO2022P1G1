#include "ClsBancos.h"

#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

ClsBancos::ClsBancos(string svalorNombreBanc, int ivalorNumeroBanc, string svalorUsuario, int ivalorSaldoBanc, string svalorTipoBanc)
{
    mestablecerNombreBanco(svalorNombreBanc);
    mestablecerNumeroCuenta(ivalorNumeroBanc);
    mestablecerNombreUsuario(svalorUsuario);
    mestablecerSaldoCuenta(ivalorSaldoBanc);
    mestablecerTipoCuenta(svalorTipoBanc);
}

string ClsBancos::mobtenerNombreB() const
{
    return m_sNombreBanco;
}


void ClsBancos::mestablecerNombreBanco( string snombrebanco )
{

   const char *valorNombre = snombrebanco.data();
   int longitud = strlen( valorNombre );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sNombreBanco, valorNombre, longitud );


   m_sNombreBanco[ longitud ] = '\0';

}

int ClsBancos::mobtenerNumeroB() const
{
    return m_iNumeroCuenta;
}

void ClsBancos::mestablecerNumeroCuenta (int valorNumero)
{
    m_iNumeroCuenta = valorNumero;
}

string ClsBancos::mobtenerUsuarioB() const
{
    return m_sNombreUsuario;
}


void ClsBancos::mestablecerNombreUsuario( string usuariostring )
{

   const char *valorUsuario = usuariostring.data();
   int longitud = strlen( valorUsuario );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sNombreUsuario, valorUsuario, longitud );


   m_sNombreUsuario[ longitud ] = '\0';

}

int ClsBancos::mobtenerSaldoB() const
{
    return m_iSaldoCuenta;
}

void ClsBancos::mestablecerSaldoCuenta (int valorSaldo)
{
    m_iSaldoCuenta = valorSaldo;
}


string ClsBancos::mobtenerTipoB() const
{
    return m_sTipoCuenta;
}


void ClsBancos::mestablecerTipoCuenta( string tipocuentastring )
{

   const char *valorTipo = tipocuentastring.data();
   int longitud = strlen( valorTipo );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sTipoCuenta, valorTipo, longitud );


   m_sTipoCuenta[ longitud ] = '\0';
}
