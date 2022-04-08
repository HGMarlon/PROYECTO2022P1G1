//Clases
#include "ClsMenus.h"
#include "ClsEmpleados.h"

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
    int choice2;
	do
    {
	system("cls");

	cout<<"-------------------------------"<<endl;
	cout<<" |   SISTEMA DE MANTENIMIENTO |"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"1. Modificar empleados"<<endl;
	cout<<"2. Modificar empresa"<<endl;
	cout<<"3. Modificar puestos"<<endl;
	cout<<"4. Volver al menu principal"<<endl;

	cout<<"-------------------------------"<<endl;
	cout<<"Opcion a escoger:[1/2/3/4]"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice2;

    switch(choice2)
    {
    case 1:
        mantenimentoEmpleado.mMenuEmpleados();
        break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	default:
		cout<<"Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
    }while(choice2!= 4);
}


ClsMenus::~ClsMenus()
{
    //dtor
}
