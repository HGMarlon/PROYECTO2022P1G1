#include "menuNominas.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
class menuNomina
{
	private:

	public:
		void menu();
};
void menuNomina::menu()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"----------------------------------------"<<endl;
	cout<<"|---BIENVENIDO AL SISTEMA DE NOMINAS---|"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"1. MANTENIMIENTOS"<<endl;
	cout<<"2. GENERACION NOMINA"<<endl;
	cout<<"3. INFORMES NOMINAS"<<endl;
	cout<<"4. TRANSFERENCIA BANCARIA"<<endl;
	cout<<"5. GENERACION POLIZA"<<endl;
    cout<<"6. IMPUESTOS"<<endl;
	cout<<"7. EXIT"<<endl;

	cout<<"-------------------------------"<<endl;
	cout<<"OPCIONES A ESCOGER :     [1/2/3/4/5/6/7]"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"INGRESA TU OPCION : ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	cout<<"USTED ESTA EN EL APARTADO MANTENIMIENTOS";
		break;
	case 2:
		cout<<"USTED ESTA EN EL APARTADO GENERACION NOMINA";
		break;
	case 3:
	    cout<<"USTED ESTA EN EL APARTADO INFORMES NOMINA";
		break;
	case 4:
	    cout<<"USTED ESTA EN EL APARTADO TRANSFERENCIA BANCARIA";
		break;
	case 5:
	    cout<<"USTED ESTA EN EL APARTADO GENERACION POLIZA";
		break;
	case 6:
	    cout<<"USTED ESTA EN EL APARTADO IMPUESTOS";
	    break;
    case 7:
        exit(0);
	default:
		cout<<"CARACTER NO VALIDO, INGRESE OTRA OPCION";
	}
	getch();
    }while(choice!= 7);
}
main()
{
	menuNomina menuPrincipal;
	menuPrincipal.menu();
	return 0;
}

