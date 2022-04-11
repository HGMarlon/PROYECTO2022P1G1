//librerias
#include<string>
#include<iostream>

//C++
#ifndef CLSEMPRESA_H
#define CLSEMPRESA_H

using std::string;

class ClsEmpresa
{
    public:
         //metodos
        ClsEmpresa(string = "", string = "", string = "", string = "",string = "",string = "",int = 0,int = 0,int = 0);

        //virtual ~ClsEmpresa();

        //metodos empresa

         void mestablecerNombreE(string);
         string mobtenerNombreE()const;

         void mestablecerCorreoE(string);
         string mobtenerCorreoE()const;

         void mestablecerDirectorE(string);
         string mobtenerDirectorE()const;

         void mestablecerActividadE(string);
         string mobtenerActividadE()const;

         void mestablecerNitE(string);
         string mobtenerNitE()const;

         void mestablecerDireccionE(string);
         string mobtenerDireccionE()const;

         void mestablecerTelefonoE(int);
         int mobtenerTelefonoE()const;

         void mestablecerNumeroEmpleadosE(int);
         int mobtenerNumeroEmpleadosE()const;

         void mestablecerNumeroEmpresa(int);
         int mobtenerNumeroEmpresa()const;

    protected:

    private:
        //atributos
        char m_sNombreEmpresa[20];
        char m_sCorreoEmpresa[20];
        char m_sNombreDirector[20];
        char m_sActividadEconomica[20];
        char m_iNitEmpresa[14];
        char m_iDireccionEmpresa[20];
        int m_iTelefonoEmpresa;
        int m_iNumeroEmpleados;
        int m_iNumeroDeEmpresa;
};

#endif // CLSEMPRESA_H
