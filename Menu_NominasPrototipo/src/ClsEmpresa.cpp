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
void ClsEmpresa::mMenuEmpresa(){
    int iSeleccionMenuEmpresa;
    do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION EMPRESA |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Empresa"<<endl;
	cout<<"\t\t\t 2. Despliegue Empresa"<<endl;
	cout<<"\t\t\t 3. Modifica Empresa"<<endl;
	cout<<"\t\t\t 4. Busca Empresa"<<endl;
	cout<<"\t\t\t 5. Borra Empresa"<<endl;
	cout<<"\t\t\t 0. Volver al menu superior"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/0]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>iSeleccionMenuEmpresa;

    switch(iSeleccionMenuEmpresa)
    {
	case 1:
		mostrarE.mIngresarEmpresa();
		getch();
		break;
	case 2:
		desplegarE.mDesplegarEmpresa();
		getch();
		break;
	case 3:
		modificarE.mModificarEmpresa();
		getch();
		break;
	case 4:
		buscarE.mBuscarEmpresa();
		break;
	case 5:
	    borrarE.mEliminarEmpresa();
		break;
    case 0:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
	//getch();
    }while(iSeleccionMenuEmpresa!=0);
}


ClsEmpresa::~ClsEmpresa()
{
    //dtor
}
