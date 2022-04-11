#include<string>
#include<iostream>

#ifndef PUESTO_H
#define PUESTO_H

using std::string;

class ClsPuestos
{
    public:
        ClsPuestos( int = 0, string = "", string = "", int = 0, string = "", string = "", string = "");
         /* mIngresarPuestos();
        mAgregarPuestos();
        mMenuPuestos();*/

        void mestablecerNumero( int) ;
        int mobtenerNumero() const;

        void mestablecerNombreP( string );
        string mobtenerNombreP() const;

        void mestablecerDepartamento ( string );
        string mobtenerDepartamento() const;

        void mestablecerSalario( int );
        int mobtenerSalario() const;

        void mestablecerNivelAcademico( string );
        string mobtenerNivAcademico() const;

        void mestablecerHoraEntrada ( string );
        string mobtenerHoraEntrada() const;

        void mestablecerHoraSalida( string ) ;
        string mobtenerHoraSalida() const;


        /* mDesplieguePuestos();
        modify();
        searchP();
        deletP();*/


        /*virtual ~ClsPuestos();*/

    protected:

    private:
        int m_iNumeroPuesto;
        char m_sNombrePuesto[ 20 ];
        char m_sNombreDepartamento[ 20 ];
        char m_sNivelAcademico[ 20 ];
        int  m_iSalario;
        char m_sHoraEntrada[20];
        char m_sHoraSalida[ 20 ];


};



#endif // PUESTO_H
