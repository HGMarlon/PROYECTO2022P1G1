#include<string>
#include<iostream>

#ifndef CLSBANCOS_H
#define CLSBANCOS_H

using std::string;

class ClsBancos
{
    public:
         ClsBancos( string = "", int = 0, string = "", int = 0,  string = "");


        void mestablecerNombreBanco( string) ;
        string mobtenerNombreB() const;


        void mestablecerNumeroCuenta( int );
        int mobtenerNumeroB() const;


        void mestablecerNombreUsuario ( string );
        string mobtenerUsuarioB() const;

        void mestablecerSaldoCuenta( int );
        int mobtenerSaldoB() const;

        void mestablecerTipoCuenta ( string );
        string mobtenerTipoB() const;

    protected:

    private:
        char m_sNombreBanco[20];
        int m_iNumeroCuenta;
        char m_sNombreUsuario[20];
        int m_iSaldoCuenta;
        char m_sTipoCuenta[20];
};

#endif // CLSBANCOS_H
