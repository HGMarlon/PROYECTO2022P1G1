#include "menuNominas.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
persona::persona()
{
    //ctor
}

void persona::menuM()
{
    int choice;
	char z;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION PERSONAS  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Personas"<<endl;
	cout<<"\t\t\t 2. Despliegue Personas"<<endl;
	cout<<"\t\t\t 3. Modifica Personas"<<endl;
	cout<<"\t\t\t 4. Busca Personas"<<endl;
	cout<<"\t\t\t 5. Borra Personas"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertA();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>z;
		}while(z=='y'||z=='Y');
		break;
	case 2:
		//display();
		break;
	case 3:
		//modify();
		break;
	case 4:
		//searchA();
		break;
	case 5:
		//delet();
		break;
	case 6:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}
void persona::insertA()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Persona ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa DPI Empleado         : ";
	cin>>dpi;
	cout<<"\t\t\tIngresa Nombre Empleado     : ";
	cin>>name;
	cout<<"\t\t\tIngresa Telefono Empleado   : ";
	cin>>phone;
	cout<<"\t\t\tIngresa Direccion Persona  : ";
	cin>>address;
	cout<<"\t\t\tIngresa Numero de Afiliación Empleado  : ";
	cin>>noAfiliacion;
	file.open("ParticipantRecord.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< dpi <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
	file.close();
}
