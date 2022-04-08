//librerias
#include<string>

//cpp
#ifndef CLSEMPLEADOS_H
#define CLSEMPLEADOS_H


class ClsEmpleados
{
    public:

        //metodos
        ClsEmpleados(int = 0, const std::string & = "");
        mAgregarEmpleado();
        mIngresarEmpleado();
        mMenuEmpleados();
        void mestablecerClave(int);
        int mobtenerClave() const;
        //Funciones obtener nombre
        void mestablecerNombre(const std::string &);
        std::string mobtenerNombre() const;
        mDespliegueEmpleados();
        /*modify();
        searchE();
        deletE();*/
        virtual ~ClsEmpleados();

    protected:

    private:

        //atributos
        int m_iClave;
        char m_sNombreEmpleado[ 40 ];
        char m_sDpiEmpleado[20];
        char m_sCodigoIdentificacion[20];
        char m_sPaisEmpleado[20];
        char m_sDireccionEmpleado[40];
        char m_sTelefonoEmpleado[20];
        char m_sCorreoEmpleado[20];
};

#endif // CLSEMPLEADOS_H
