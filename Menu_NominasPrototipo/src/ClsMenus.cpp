//Clases
#include "ClsMenus.h"
#include "ClsEmpleados.h"
#include "ClsEmpresa.h"

//Librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//Aqui estan los constructores
ClsMenus::ClsMenus()
{
    //ctor
}

//Metodos de la clase Menu intermedio
ClsMenus::Menuxcategorias()
{
    ClsEmpleados mantenimentoEmpleado;
    ClsEmpleados mantenimientoEmpresa;

    int choice2;
	do
    {
	system("cls");

	cout<<"-------------------------------"<<endl;
	cout<<" |   SISTEMA DE MANTENIMIENTO |"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"1. CRUD empleados"<<endl;
	cout<<"2. CRUD empresa"<<endl;
	cout<<"3. CRUD puestos"<<endl;
	cout<<"4. CRUD conceptos"<<endl;
	cout<<"5. CRUD departamentos"<<endl;
	cout<<"6. CRUD bancos"<<endl;
	cout<<"0. Volver al menu principal"<<endl;

	cout<<"-------------------------------"<<endl;
	cout<<"Opcion a escoger:[1/2/3/0]"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice2;

    switch(choice2)
    {
    case 1:
        mantenimentoEmpleado.mMenuEmpleados();
        break;
	case 2:
        mantenimientoEmpresa.mMenuEmpresa();
		break;
	case 3:

		break;
	case 0:

		break;
	default:
		cout<<"Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
    }while(choice2!= 0);
}


ClsMenus::~ClsMenus()
{
    //dtor
}
