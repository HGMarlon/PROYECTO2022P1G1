#include "ClsEmpleados.h"

//librerias
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>

using namespace std;

//constructor
ClsEmpleados::ClsEmpleados()
{
    //ctor
}

/*Metodos de clase proceso (menu mantemiento empleado)
    Agregar nuevo empleado*/
ClsEmpleados::mAgregarEmpleado()
{
	system("cls");
	fstream file;
	cout<<"Agregar nuevo Empleado"<<endl;
	cout<<"Ingresa el nombre completo del empleado: ";
	cin>>m_sNombreEmpleado;
	/*cout<<"Ingresa el numero de DPI del empleado: ";
	cin>>m_sDpiEmpleado;
	cout<<"Ingresa el codigo de idenficación del empleado: ";
	cin>>m_sCodigoIdentificacion;
	cout<<"Ingresa el pais de origen del empleado: ";
	cin>>m_sPaisEmpleado;
	cout<<"Ingresa el pais de residencia del empleado: ";
	cin>>m_sResidenciaEmpleado;
	cout<<"Ingresa la dirección de residencia del empleado: ";
	cin>>m_sDireccionEmpleado;
	cout<<"Ingresa el número de telefono del empleado: ";
	cin>>m_sTelefonoEmpleado;
	cout<<"Ingresa el correo electronico del empleado: ";
	cin>>m_sCorreoEmpleado;
	cout<<"Ingresa un número telefonico en caso de emergencia: ";
	cin>m_sTelefonoEmergenciaEmpleado;*/
	file.open("registroEmpleados.txt", ios::app | ios::out | ios::binary);
	file<<std::left<<std::setw(40)<< m_sNombreEmpleado
	/*<<std::left<<std::setw(15)<< m_sDpiEmpleado
	<<std::left<<std::setw(15)<< m_sCodigoIdentificacion
	<<std::setw(15)<< m_sResidenciaEmpleado
	<<std::setw(15)<< m_sResidenciaEmpleado
	<<std::setw(20)<< m_sDireccionEmpleado
	<<std::left<<std::setw(15)<< m_sTelefonoEmpleado
	<<std::left<<std::setw(20)<< m_sCorreoEmpleado
	<<std::left<<std::setw(15)<< m_sTelefonoEmergenciaEmpleado */<< "\n";
	file.close();
}
ClsEmpleados::mIngresarEmpleado()
{
    char cDecisionNuevoEmpleado;
do
    	{
    		mAgregarEmpleado();
    		cout<<"Desea agregar otra empleado?(Y,N): ";
    		cin>>cDecisionNuevoEmpleado;
		}while(cDecisionNuevoEmpleado=='y'||cDecisionNuevoEmpleado=='Y');
}
/*
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
*/
ClsEmpleados::~ClsEmpleados()
{
    //dtor
}
