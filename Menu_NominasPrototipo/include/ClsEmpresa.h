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
         mMenuEmpresa();
         mIngresarEmpresa();
         mDesplegarEmpresa();
         mModificarEmpresa();
         mBuscarEmpresa();
         mEliminarEmpresa();


        virtual ~ClsEmpresa();

    protected:

    private:
        //atributos
        char m_sNombreEmpresa[20];
        char m_sCorreoEmpresa[20];
        char m_sNombreRepresentante[20];
        char m_sActividadEconomica[20];
        int m_iNitEmpresa;
        int m_iDireccionEmpresa;
        int m_iTelefonoEmpresa;
        int m_iNumeroEmpleados;
        int m_iNumeroDeEmpresa;

};

#endif // CLSEMPRESA_H
