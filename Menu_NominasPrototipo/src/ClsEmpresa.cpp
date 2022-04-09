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
ClsEmpresa::ClsEmpresa(char p_sNombreEmpresa,char p_sActividadEconomica,char p_sCorreoEmpresa,char p_sNombreRepresentante,int p_iNitEmpresa,int p_iDireccionEmpresa,int p_iTelefonoEmpresa,int p_iNumeroEmpleados,int p_iNumeroEmpresa)
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
    ofstream archivoEmpresa("datosempresa.dat", ios::app | ios::out | ios::out | ios::binary);
    if( !archivoEmpresa )
    {
        cerr << "No se pudo abrir el archivo datos empresa." << endl;
        exit( EXIT_FAILURE );
    }
    ClsEmpresa empresa;
    cout<<"----Agregar datos de una Empresa----"<<endl;
    cout<<"Ingresa Nombre de la Empresa: " << endl;
    cin>>m_sNombreEmpresa;
    cout<<"Ingresa Actividad Economica: "; << endl;
    cin>>m_sActividadEconomica;
    cout<<"Ingresa Correo Electronico de la empresa: "; << endl;
    cin>>m_sCorreoEmpresa;
    cout<<"Ingresa Nombre del Gerente o Representante legal: "; << endl;
    cin>>m_sNombreRepresentante;
    cout<<"Ingresa No.de nit: "; << endl;
    cin>>m_iNitEmpresa;
    cout<<"Ingresa Direccion de la Empresa: "; << endl;
    cin>>m_iDireccionEmpresa;
    cout<<"Ingresa telefono de la Empresa: "; << endl;
    cin>>m_iTelefonoEmpresa;
    cout<<"Ingresa No.de trabajadores que posee la Empresa: "; << endl;
    cin>>m_iNumeroEmpleados;
    cout<<"Ingresa No.de Empresa: "; << endl;
    cin>>m_iNumeroDeEmpresa;
}

ClsEmpresa::mDesplegarEmpresa(){
    system("cls");
	ifstream archivoEmpresa("datosempresa.dat", ios::in | ios::out | ios:: binary);
	int total=0;
	cout<<"----Tabla de datos de Empresa----"<<endl;
	if(!archivoEmpresa)
	{
		cerr << "No se pudo abrir el archivo datos empresa." << endl;
        exit( EXIT_FAILURE );
	}
	else
	{
		ClsEmpresa empresa;
		while(!archivoEmpresa.eof())
		{
			total++;
			cout<<"Nombre: "<< m_sNombreEmpresa <<endl;
			cout<<"Actividad: "<< m_sActividadEconomica <<endl;
			cout<<"Correo: "<< m_sCorreoEmpresa <<endl;
			cout<<"Representante: "<< m_sNombreRepresentante <<endl;
			cout<<"Nit: "<< m_iNitEmpresa <<endl;
			cout<<"Direccion: "<< m_iDireccionEmpresa <<endl;
			cout<<"Telefono: "<< m_iTelefonoEmpresa <<endl;
			cout<<"Empleados: "<< m_iNumeroEmpleados <<endl;
			cout<<"Empresa: "<< m_iNumeroDeEmpresa <<endl;
		}
		if(total==0)
		{
			cout<<"No hay informacion...";
		}
	}
	archivoEmpleados.close();
}

ClsEmpresa::mModificarEmpresa(){
    system("cls");
	fstream file,file1;
	int numero_Empresa;
	cout<<"\n-------------------------Modificacion Datos de Empresa-------------------------"<<endl;
	file.open("datosEmpresa.dat",ios::in | ios::out | ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el numero de empresa que desea modificar: ";
		cin>>numero_Empresa;
		file1.open("RegistroDatosEmpresa.dat",ios::app | ios::out | ios::in | ios::binary);
		file >> m_sNombreEmpresa >> m_sActividadEconomica >> m_sCorreoEmpresa >> m_sNombreRepresentante >> m_iNitEmpresa >> m_iDireccionEmpresa >> m_iTelefonoEmpresa >> m_iNumeroEmpleados >>  m_iNumeroDeEmpresa ;
		while(!file.eof())
		{
			if(numero_Empresa!=m_iNumeroDeEmpresa
            file1<<std::left<<std::setw(20)<< m_sNombreEmpresa <<std::left<<std::setw(20)<< m_sActividadEconomica <<std::left<<std::setw(20)<< m_sCorreoEmpresa <<std::left<<std::setw(20)<< m_sNombreRepresentante <<std::left<<std::setw(20)<< m_iNitEmpresa <<std::left<<std::setw(20)<< m_iDireccionEmpresa  <<std::left<<std::setw(20)<< m_iTelefonoEmpresa << std::left<<std::setw(20)<< m_iNumeroEmpleados <<std::left<<std::setw(20)<< m_iNumeroDeEmpresa <<std::left<<std::setw(20) <<"\n";
			}
			else
			{
                cout<<"----Agregar datos de una Empresa----"<<endl;
                cout<<"Ingresa Nombre de la Empresa: " << endl;
                cin>>m_sNombreEmpresa;
                cout<<"Ingresa Actividad Economica: "; << endl;
                cin>>m_sActividadEconomica;
                cout<<"Ingresa Correo Electronico de la empresa: "; << endl;
                cin>>m_sCorreoEmpresa;
                cout<<"Ingresa Nombre del Gerente o Representante legal: "; << endl;
                cin>>m_sNombreRepresentante;
                cout<<"Ingresa No.de nit: "; << endl;
                cin>>m_iNitEmpresa;
                cout<<"Ingresa Direccion de la Empresa: "; << endl;
                cin>>m_iDireccionEmpresa;
                cout<<"Ingresa telefono de la Empresa: "; << endl;
                cin>>m_iTelefonoEmpresa;
                cout<<"Ingresa No.de trabajadores que posee la Empresa: "; << endl;
                cin>>m_iNumeroEmpleados;
                cout<<"Ingresa No.de Empresa: "; << endl;
                cin>>m_iNumeroDeEmpresa;
                file1<<std::left<<std::setw(20)<< m_sNombreEmpresa <<std::left<<std::setw(20)<< m_sActividadEconomica <<std::left<<std::setw(20)<< m_sCorreoEmpresa <<std::left<<std::setw(20)<< m_sNombreRepresentante <<std::left<<std::setw(20)<< m_iNitEmpresa <<std::left<<std::setw(20)<< m_iDireccionEmpresa  <<std::left<<std::setw(20)<< m_iTelefonoEmpresa << std::left<<std::setw(20)<< m_iNumeroEmpleados <<std::left<<std::setw(20)<< m_iNumeroDeEmpresa <<std::left<<std::setw(20) <<"\n";
				found++;
			}
			file >> m_sNombreEmpresa >> m_sActividadEconomica >> m_sCorreoEmpresa >> m_sNombreRepresentante >> m_iNitEmpresa >> m_iDireccionEmpresa >> m_iTelefonoEmpresa >> m_iNumeroEmpleados >>  m_iNumeroDeEmpresa ;

		}
		file1.close();
		file.close();
		remove("datosEmpresa.dat");
		rename("RegistroDatosEmpresa.dat","datosEmpresa.dat");
	}
}

ClsEmpresa::mBuscarEmpresa(){

	system("cls");
	fstream file;
	int found=0;
	file.open("datosEmpresa.dat",ios::in | ios::out | ios::binary);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Empresa buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		int numero_EmpresaN;
		cout<<"\n-------------------------Datos de la Empresa buscada------------------------"<<endl;
		cout<<"\nIngrese el numero de empresa que desea modificar: ";
		cin>>numero_EmpresaN;
		file >> m_sNombreEmpresa >> m_sActividadEconomica >> m_sCorreoEmpresa >> m_sNombreRepresentante >> m_iNitEmpresa >> m_iDireccionEmpresa >> m_iTelefonoEmpresa >> m_iNumeroEmpleados >>  m_iNumeroDeEmpresa ;
		while(!file.eof())
		{
			if(numero_EmpresaN==m_iNumeroDeEmpresa)
			{
				cout<<"Nombre: "<< m_sNombreEmpresa <<endl;
                cout<<"Actividad: "<< m_sActividadEconomica <<endl;
                cout<<"Correo: "<< m_sCorreoEmpresa <<endl;
                cout<<"Representante: "<< m_sNombreRepresentante <<endl;
                cout<<"Nit: "<< m_iNitEmpresa <<endl;
                cout<<"Direccion: "<< m_iDireccionEmpresa <<endl;
                cout<<"Telefono: "<< m_iTelefonoEmpresa <<endl;
                cout<<"Empleados: "<< m_iNumeroEmpleados <<endl;
                cout<<"Empresa: "<< m_iNumeroDeEmpresa <<endl;
				found++;
			}
			file >> m_sNombreEmpresa >> m_sActividadEconomica >> m_sCorreoEmpresa >> m_sNombreRepresentante >> m_iNitEmpresa >> m_iDireccionEmpresa >> m_iTelefonoEmpresa >> m_iNumeroEmpleados >>  m_iNumeroDeEmpresa ;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empresa no encontrada...";
		}
		file.close();
	}
}





ClsEmpresa::~ClsEmpresa()
{
    //dtor
}
