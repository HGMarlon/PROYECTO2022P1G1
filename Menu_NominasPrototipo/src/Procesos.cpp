/*#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include "Procesos.h"
#include "ClsEmpleados.h"
using namespace std;
//Aqui estan los constructores
Procesos::Procesos()
{

}

//Metodos de la clase Menuintermedio
Menuintermedio::Menuxcategorias()
{
    ClsEmpleados mantenimiento;
    int choice2;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA DE MANTENIMIENTO |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Modificar empleados"<<endl;
	cout<<"\t\t\t 2. Modificar empresa"<<endl;
	cout<<"\t\t\t 3. Modificar puestos"<<endl;
	cout<<"\t\t\t 4. Volver al menu principal"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice2;

    switch(choice2)
    {
    case 1:
        mantenimiento.menu();
        break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
	//getch();
    }while(choice2!= 4);
}*/
