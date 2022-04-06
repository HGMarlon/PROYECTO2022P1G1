#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include "Procesos.h"2
using namespace std;
//Aqui estan los constructores
Procesos::Procesos()
{

}

//Metodos de clase proceso (menu mantemiento empleado)
Empleados::insertE()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Empleado ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa DPI Empleado         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre y Apellido Empleado     : ";
	cin>>name;
	cout<<"\t\t\tIngresa Telefono Empleado  : ";
	cin>>phone;
	cout<<"\t\t\tIngresa Correo Empleado: ";
	cin>>mail;
	cout<<"\t\t\tIngresa No.Afiliación Empleado  : ";
	cin>>affiliation;
	file.open("ParticipantRecordEmpleados.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< mail <<std::left<<std::setw(15)<< affiliation << "\n";
	file.close();
}
Empleados::ingresarE()
{
    char z;
do
    	{
    		insertE();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>z;
		}while(z=='y'||z=='Y');
}

Empleados::menu()
{
    Empleados mostrarE;
    Empleados modificarE;
    Empleados buscarE;
    Empleados borrarE;
   int choice1;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION EMPLEADOS  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Empleados"<<endl;
	cout<<"\t\t\t 2. Despliegue Empleados"<<endl;
	cout<<"\t\t\t 3. Modifica Empleados"<<endl;
	cout<<"\t\t\t 4. Busca Empleados"<<endl;
	cout<<"\t\t\t 5. Borra Empleados"<<endl;
	cout<<"\t\t\t 6. Volver al menu superior"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice1;

    switch(choice1)
    {
    case 1:
        ingresarE();
        getch();
        break;
	case 2:
		mostrarE.display();
		getch();
		break;
	case 3:
		modificarE.modify();
		getch();
		break;
	case 4:
		buscarE.searchE();
		getch();
		break;
	case 5:
		borrarE.deletE();
		break;
	case 6:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
	//getch();
    }while(choice1!= 6);
}
//Metodos de la clase Menuintermedio
Menuintermedio::Menuxcategorias()
{
    Empleados mantenimiento;
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
}
Empleados::display()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
	file.open("ParticipantRecordEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> name >> phone >> mail >> affiliation;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t DPI Empleado: "<<id<<endl;
			cout<<"\t\t\t Nombre y Apellido Empleado: "<<name<<endl;
			cout<<"\t\t\t Telefono Empleado: "<<phone<<endl;
			cout<<"\t\t\t Correo Empleado: "<<mail<<endl;
			cout<<"\t\t\t No.Afiliacion Empleado: "<<affiliation<<endl;
			file >> id >> name >> phone >> mail >> affiliation;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
Empleados::modify()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<endl;
	file.open("ParticipantRecordEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la personas que quiere modificar: ";
		cin>>participant_id;
		file1.open("RecordEmpleados.txt",ios::app | ios::out);
		file >> id >> name >> phone >> mail >> affiliation;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< mail <<std::left<<std::setw(15)<< affiliation << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese DPI Empleado: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre y Apellido Empleado: ";
				cin>>name;
				cout<<"\t\t\tIngrese Telefono Empleado: ";
				cin>>phone;
				cout<<"\t\t\tIngrese Correo Empleado: ";
				cin>>mail;
				cout<<"\t\t\tIngrese No.Afiliacion Persona: ";
				cin>>affiliation;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< mail <<std::left<<std::setw(15)<< affiliation << "\n";
				found++;
			}
			file >> id >> name >> phone >> mail >> affiliation;

		}
		file1.close();
		file.close();
		remove("ParticipantRecordEmpleados.txt");
		rename("RecordEmpleados.txt","ParticipantRecordEmpleados.txt");
	}
}

Empleados::searchE()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("ParticipantRecordEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Empleado buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_idEmpleado;
		cout<<"\n-------------------------Datos del Empleado buscado------------------------"<<endl;
		cout<<"\nIngrese DPI del Empleado que quiere buscar: ";
		cin>>participant_idEmpleado;
		file >> id >> name >> phone >> mail >> affiliation;
		while(!file.eof())
		{
			if(participant_idEmpleado==id)
			{
				cout<<"\n\n\t\t\t DPI Empleado: "<<id<<endl;
				cout<<"\t\t\t Nombre y Apellido Empleado: "<<name<<endl;
				cout<<"\t\t\t Telefono Empleado: "<<phone<<endl;
				cout<<"\t\t\t Correo Empleado: "<<mail<<endl;
				cout<<"\t\t\t No.Afiliacion Empleado: "<<affiliation<<endl;
				found++;
			}
			file >> id >> name >> phone >> mail >> affiliation;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empleado no encontrado...";
		}
		file.close();
	}
}
Empleados::deletE()
{
	system("cls");
	fstream file,file1;
	string participant_idEmpleado;
	int found=0;
	cout<<"\n-------------------------Detalles Empleado a Borrar-------------------------"<<endl;
	file.open("ParticipantRecordEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el DPI del Empleado que quiere borrar: ";
		cin>>participant_idEmpleado;
		file1.open("RecordEmpleados.txt",ios::app | ios::out);
		file >> id >> name >> phone >> mail >> affiliation;
		while(!file.eof())
		{
			if(participant_idEmpleado!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< mail <<std::left<<std::setw(15)<< affiliation << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> name >> phone >> mail >> affiliation;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t DPI Empleado no encontrado...";
			getch();
		}
		file1.close();
		file.close();
		remove("ParticipantRecordEmpleados.txt");
		rename("RecordEmpleados.txt","ParticipantRecordEmpleados.txt");
	}
}
