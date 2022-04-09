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
    m_sNombreEmpresa[20]=p_sNombreEmpresa;
    m_sCorreoEmpresa[20]=p_sCorreoEmpresa;
    m_sNombreRepresentante[20]=p_sNombreRepresentante;
    m_sActividadEconomica[20]=p_sActividadEconomica;
    m_iNitEmpresa[20]=p_iNitEmpresa;
    m_iDireccionEmpresa[20]=p_iDireccionEmpresa;
    m_iTelefonoEmpresa[20]=p_iTelefonoEmpresa;
    m_iNumeroEmpleados[20]=p_iNumeroEmpleados;
    m_iNumeroDeEmpresa[20]=p_iNumeroEmpresa;
}

//metodo menu de la empresa
void ClsEmpresa::mMenuEmpresa(){

    ClsEmpresa empresa
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
		empresa.mIngresarEmpresa();
		getch();
		break;
	case 2:
		empresa.mDesplegarEmpresa();
		getch();
		break;
	case 3:
		empresa.mModificarEmpresa();
		getch();
		break;
	case 4:
		empresa.mBuscarEmpresa();
		break;
	case 5:
	    empresa.mEliminarEmpresa();
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

//metodo datos de la empresa
void ClsEmpresa::mIngresarEmpresa(){
    int iespacios=0;
    system("cls");
    ofstream archivoEmpresa("datosempresa.dat", ios::app | ios::out | ios::binary);
    if( !archivoEmpleados )
    {
        cerr << "No se pudo abrir el archivo datos empresa." << endl;
        exit( EXIT_FAILURE );
    }
    ClsEmpresa empresa;
    cout<<"----Agregar datos de una Empresa----"<<endl;
    cout<<"Ingresa Nombre de la Empresa: " << endl;
    cin>> m_sNombreEmpresa;
    cout<<"Ingresa Actividad Economica: "; << endl;
    cin>>m_sActividadEconomica;
    cout<<"Ingresa Correo Electronico de la empresa: "; << endl;
    cin>>m_sCorreoEmpresa;
    cout<<"Ingresa Nombre del Gerente o Representante legal: "; << endl;
    cin>>m_sNombreRepresentante;
    cout<<"Ingresa No.de nit: "; << endl;
    cin>>m_iNitEmpresa;
    cout<<"Ingresa No.de nit: "; << endl;
    cin>>m_iNitEmpresa;
    cout<<"Ingresa Direccion de la Empresa: "; << endl;
    cin>>m_iDireccionEmpresa;
    cout<<"Ingresa No.de trabajadores que posee la Empresa: "; << endl;
    cin>>m_iNumeroEmpleados;
    cout<<"Ingresa No.de Empresa: "; << endl;
    cin>>m_iNumeroDeEmpresa;
}



ClsEmpresa::~ClsEmpresa()
{
    //dtor
}
