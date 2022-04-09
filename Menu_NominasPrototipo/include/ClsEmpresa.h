//librerias
#include<string>

//cpp
#ifndef CLSEMPRESA_H
#define CLSEMPRESA_H

using namespace std;

class ClsEmpresa
{
    public:
        ClsEmpresa(char,char,char,char,int,int,int,int,int);//constructor
       //metodos
        void mMenuEmpresa();
        void mIngresarEmpresa();
        void mDesplegarEmpresa();
        void mModificarEmpresa();
        void mBuscarEmpresa();
        void mEliminarEmpresa();


        virtual ~ClsEmpresa();

    protected:

    private:
        //atributos
        char m_sNombreEmpresa[20];
        char m_sCorreoEmpresa[20];
        char m_sNombreRepresentante[20];
        char m_sActividadEconomica[20];
        int m_iNitEmpresa[20];
        int m_iDireccionEmpresa[20];
        int m_iTelefonoEmpresa[20];
        int m_iNumeroEmpleados[20];
        int m_iNumeroDeEmpresa[20];

};

#endif // CLSEMPRESA_H
