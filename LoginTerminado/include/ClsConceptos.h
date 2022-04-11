#ifndef CLSCONCEPTOS_H
#define CLSCONCEPTOS_H

#include<string>
#include<iostream>

using std::string;

class ClsConceptos
{
    public:
        ClsConceptos(int = 0, string = "", string = "", string = "");

        void mestablecerCodigo( int ) ;
        int mobtenerCodigo() const;

        void mestablecerNombreSueldo( string );
        string mobtenerNombreSueldo() const;

        void mestablecerSueldo( string );
        string mobtenerSueldo() const;

        void mestablecerBono( string );
        string mobtenerBono() const;
        virtual ~ClsConceptos();

    protected:

    private:
        int m_iclaveEmpleadoSueldo;
        char m_snombreEmpleadoSueldo[ 20 ];
        char m_sSueldo[ 20 ];
        char m_sBono[ 20 ];
};

#endif // CLSCONCEPTOS_H
