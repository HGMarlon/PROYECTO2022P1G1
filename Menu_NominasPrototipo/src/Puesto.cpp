#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include "Puesto.h"

Puesto::Puesto()
{

}

Puesto::~Puesto()
{

}

Puesto::insertP()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles del Puesto ---------------------------------------------"<<endl;
		cout<<"\t\t\tIngresa el numero de puesto  : ";
	cin>>Numero;
	cout<<"\t\t\tIngresa el cargo del puesto         : ";
	cin>>Cargo;
	cout<<"\t\t\tIngresa el departamento al cual pertenecera     : ";
	cin>>DepaPuesto;
	cout<<"\t\t\tIngresa el monto del salario correspondiente  : ";
	cin>>Salario;
	cout<<"\t\t\tIngresa el nivel academico requerido: ";
	cin>>Nivel;
	cout<<"\t\t\tIngresa hora de entrada  : ";
	cin>>HoraEntrada;
	cout<<"\t\t\tIngresa hora de salida  : ";
	cin>>HoraSalida;
	file.open("ParticipantRecordPuesto.dat", ios::app | ios::out| ios::binary);
	file<<std::left<<std::setw(15)<< Numero <<std::left<<std::setw(15)<< Cargo <<std::left<<std::setw(15)<< DepaPuesto <<std::left<<std::setw(15)<< Salario <<std::left<<std::setw(15)<< Nivel <<std::left<<std::setw(15)<< HoraEntrada <<std::left<<std::setw(15)<< HoraSalida << "\n";
	file.close();
}
Puesto::menu()
{
    Puesto mostrarP;
    Puesto modificarP;
    Puesto buscarP;
    Puesto borrarP;
    int choice3;
	do
    {
    system("cls");

    cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION PUESTOS  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Puestos"<<endl;
	cout<<"\t\t\t 2. Despliegue Puestos"<<endl;
	cout<<"\t\t\t 3. Modifica Puestos"<<endl;
	cout<<"\t\t\t 4. Busca Puestos"<<endl;
	cout<<"\t\t\t 5. Borra puestos"<<endl;
	cout<<"\t\t\t 6. Volver al menu superior"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice3;

    switch(choice3)
    {
    case 1:
        ingresarP();
        getch();
        break;
	case 2:
		mostrarP.displayP();
		getch();
		break;
	case 3:
		modificarP.modify();
		getch();
		break;
	case 4:
		buscarP.searchP();
		getch();
		break;
	case 5:
		borrarP.deletP();
		break;
	case 6:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
	//getch();
    }while(choice3!= 6);
}


Puesto::ingresarP()
{
    char z;
do
    	{
    		insertP();
    		cout<<"\n\t\t\t Agrega otra puesto(Y,N): ";
    		cin>>z;
		}while(z=='y'||z=='Y');
}

//Metodos de la clase Menuintermedio

Puesto::displayP()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de los Puestos -------------------------"<<endl;
	file.open("ParticipantRecordPuesto.dat",ios::in |ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> Numero >> Cargo >> DepaPuesto >> Salario >> Nivel >> HoraEntrada >> HoraSalida;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Numero del puesto: "<<Numero<<endl;
			cout<<"\t\t\t Nombre del cargo correspondiente al puesto: "<<Cargo<<endl;
			cout<<"\t\t\t departamento al que pertenecera: "<<DepaPuesto<<endl;
			cout<<"\t\t\t Monto del salario: "<<Salario<<endl;
			cout<<"\t\t\t Nivel academico solicitado: "<<Nivel<<endl;
			cout<<"\t\t\t Hora de entrada: "<<HoraEntrada<<endl;
			cout<<"\t\t\t Hora de salida: "<<HoraSalida<<endl;
			file >> Numero >> Cargo >> DepaPuesto >> Salario >> Nivel >> HoraEntrada >> HoraSalida;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
Puesto::modify()
{
	system("cls");
	fstream file,file1;
	string participant_Numero;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Puesto-------------------------"<<endl;
	file.open("ParticipantRecordPuesto.dat",ios::in| ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el numero de puesto que quiere modificar: ";
		cin>>participant_Numero;
		file1.open("RecordPuesto.dat",ios::app | ios::out| ios::binary);
		file >> Numero >> Cargo >> DepaPuesto >> Salario >> Nivel >> HoraEntrada >> HoraSalida;
		while(!file.eof())
		{
			if(participant_Numero!=Numero)
			{
			 file<<std::left<<std::setw(15)<< Numero <<std::left<<std::setw(15)<< Cargo <<std::left<<std::setw(15)<< DepaPuesto <<std::left<<std::setw(15)<< Salario <<std::left<<std::setw(15)<< Nivel <<std::left<<std::setw(15)<< HoraEntrada <<std::left<<std::setw(15)<< HoraSalida << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese el numero de puesto: ";
				cin>>Numero;
				cout<<"\t\t\tIngrese el cargo del puesto: ";
				cin>>Cargo;
				cout<<"\t\t\tIngrese el departamento correspondiente al puesto: ";
				cin>>DepaPuesto;
				cout<<"\t\t\tIngrese el Monto del salario : ";
				cin>>Salario;
				cout<<"\t\t\tIngrese el nivel academico necesario: ";
				cin>>Nivel;
				cout<<"\t\t\tIngrese hora de entrada: ";
				cin>>HoraEntrada;
				cout<<"\t\t\tIngrese hora de salida: ";
				cin>>HoraSalida;
				file<<std::left<<std::setw(15)<< Numero <<std::left<<std::setw(15)<< Cargo <<std::left<<std::setw(15)<< DepaPuesto <<std::left<<std::setw(15)<< Salario <<std::left<<std::setw(15)<< Nivel <<std::left<<std::setw(15)<< HoraEntrada <<std::left<<std::setw(15)<< HoraSalida << "\n";
				found++;
			}
			file >> Numero >> Cargo >> DepaPuesto >> Salario >> Nivel >> HoraEntrada >> HoraSalida;

		}
		file1.close();
		file.close();
		remove("ParticipantRecordPuesto.dat");
		rename("RecordPuesto.dat","ParticipantRecordPuesto.dat");
	}
}

Puesto::searchP()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("ParticipantRecordPuesto.dat",ios::in | ios::binary);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Puesto buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_NumeroPuesto;
		cout<<"\n-------------------------Datos del Puesto buscado------------------------"<<endl;
		cout<<"\nIngrese el numero del puesto que quiere buscar: ";
		cin>>participant_NumeroPuesto;
		file >> Numero >> Cargo >> DepaPuesto >> Salario >> Nivel >> HoraEntrada >> HoraSalida;
		while(!file.eof())
		{
			if(participant_NumeroPuesto==Numero)
			{
				cout<<"\n\n\t\t\t Numero depuesto: "<<Numero<<endl;
				cout<<"\t\t\t cargo del pueesto: "<<Cargo<<endl;
				cout<<"\t\t\t Departamento correspondiente al puesto: "<<DepaPuesto<<endl;
				cout<<"\t\t\t Monto del salario: "<<Salario<<endl;
				cout<<"\t\t\t Nivel academico requerido: "<<Nivel<<endl;
				cout<<"\t\t\t Hora de entrda: "<<HoraEntrada<<endl;
				cout<<"\t\t\t Hora de salida: "<<HoraSalida<<endl;
				found++;
			}
			file >> Numero >> Cargo >> DepaPuesto >> Salario >> Nivel >> HoraEntrada >> HoraSalida;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Puesto no encontrado...";
		}
		file.close();
	}
}
Puesto::deletP()
{
	system("cls");
	fstream file,file1;
	string participant_NumeroPuesto;
	int found=0;
	cout<<"\n-------------------------Detalles del Puesto a Borrar-------------------------"<<endl;
	file.open("ParticipantRecordPuesto.dat",ios::in|ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Numero del puesto que quiere borrar: ";
		cin>>participant_NumeroPuesto;
		file1.open("RecordPuesto.dat",ios::app |ios::out| ios::binary);
		file >> Numero >> Cargo >> DepaPuesto >> Salario >> Nivel >> HoraEntrada >> HoraSalida;
		while(!file.eof())
		{
			if(participant_NumeroPuesto!= Numero)
			{
				file<<std::left<<std::setw(15)<< Numero <<std::left<<std::setw(15)<< Cargo <<std::left<<std::setw(15)<< DepaPuesto <<std::left<<std::setw(15)<< Salario <<std::left<<std::setw(15)<< Nivel <<std::left<<std::setw(15)<< HoraEntrada <<std::left<<std::setw(15)<< HoraSalida << "\n";;
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> Numero >> Cargo >> DepaPuesto >> Salario >> Nivel >> HoraEntrada >> HoraSalida;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t DPI Empleado no encontrado...";
			getch();
		}
		file1.close();
		file.close();
		remove("ParticipantRecordPuesto.dat");
		rename("RecordPuesto.dat","ParticipantRecordPuesto.dat");
	}
}
