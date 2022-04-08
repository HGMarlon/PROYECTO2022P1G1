//librerias
#include<string>

//cpp
#ifndef CLSEMPLEADOS_H
#define CLSEMPLEADOS_H

using std::string;


class ClsEmpleados
{
    public:

        //metodos
        ClsEmpleados( int = 0, string = "", string = "");
        mAgregarEmpleado();
        mIngresarEmpleado();
        mMenuEmpleados();

        //establecer clave
        void mestablecerClave( int) ;
        int mobtenerClave() const;

        //Funciones obtener nombre
        void mestablecerNombre( string );
        string mobtenerNombre() const;

        //establecer dpi
        void mestablecerDpi ( string );
        string mobtenerDpi() const;

        mDespliegueEmpleados();
        /*modify();
        searchE();
        deletE();*/
        virtual ~ClsEmpleados();

    protected:

    private:

        //atributos
        int m_iClaveEmpleado;
        char m_sNombreEmpleado[ 20 ];
        char m_sDpiEmpleado[ 20 ];
        /*char m_sCodigoIdentificacion[20];
        char m_sPaisEmpleado[20];
        char m_sDireccionEmpleado[ 20 ];
        char m_sTelefonoEmpleado[20];
        char m_sCorreoEmpleado[20];*/
};

#endif // CLSEMPLEADOS_H
