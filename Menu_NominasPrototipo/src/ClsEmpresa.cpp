//clase
#include "ClsEmpresa.h"

//librerias
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>

using namespace std;

//constructor
ClsEmpresa::ClsEmpresa(char p_sNombreEmpresa,char p_sCorreoEmpresa,char p_sNombreRepresentante,char p_sActividadEconomica,int p_iNitEmpresa,int p_iDireccionEmpresa,int p_iTelefonoEmpresa,int p_iNumeroEmpleados,int p_iNumeroEmpresa)
{
   m_sNombreEmpresa=p_sNombreEmpresa;
   m_sCorreoEmpresa=p_sCorreoEmpresa;
   m_sNombreRepresentante=p_sNombreRepresentante;
   m_sActividadEconomica=p_sActividadEconomica;
   m_iNitEmpresa=p_iNitEmpresa;
   m_iDireccionEmpresa=p_iDireccionEmpresa;
   m_iTelefonoEmpresa=p_iTelefonoEmpresa;
   m_iNumeroEmpleados=p_iNumeroEmpleados;
   m_iNumeroDeEmpresa=p_iNumeroEmpresa;

}

//metodo obtiene nombre de la empresa










ClsEmpresa::~ClsEmpresa()
{
    //dtor
}
