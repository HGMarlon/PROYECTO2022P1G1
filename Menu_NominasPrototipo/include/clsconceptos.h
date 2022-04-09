#include<string>
#include<fstream>

#ifndef CLSCONCEPTOS_H
#define CLSCONCEPTOS_H

using std::string;

class ClsConceptos
{
    public:

        ClsConceptos( int = 0, string = "", string = "", string = "", string = "");

        menuConceptos();
        ingresarSueldos();

        //establecer clave
        void mestablecerCodigo( int) ;
        int mobtenerCodigo() const;

        //Funciones obtener nombre
        void mestablecerNombre( string );
        string mobtenerNombre() const;

        //establecer DPI
        void mestablecerDpi( string) ;
        string mobtenerDpi() const;

        //establecer Sueldo
        void mestablecerSueldo( string) ;
        string mobtenerSueldo() const;

        //establecer Bono
        void mestablecerBono( string) ;
        string mobtenerBono() const;

        mDespliegueSueldos();

        /*void imprimirLinea(oestream, const);*/

        virtual ~ClsConceptos();

    protected:

    private:
        int m_iCodigoEmpleado;
        char m_sNombreEmpleado[ 20 ];
        char m_sDpiEmpleado[20];
        char m_sSueldoEmpleado[20];
        char m_sBonoEmpleado[20];
};

#endif // CLSCONCEPTOS_H
