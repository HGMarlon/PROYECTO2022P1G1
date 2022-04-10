/* #include "ClsPuestos.h"

#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;


ClsPuestos::ClsPuestos(int valorNumero, string valorNombrePuesto, string valorDepartamento, int valorSalario, string valorNivel, string valorHoraEntrada, string valorHoraSalida)
{
    mestablecerNumero(valorNumero);
    mestablecerNombre(valorNombrePuesto);
    mestablecerDepartamento(valorDepartamento);
    mestablecerSalario(valorSalario);
    mestablecerNivAcademico(valorNivel);
    mestablecerHoraEntrada(valorHoraEntrada);
    mestablecerHoraSalida(valorHoraSalida);
}


int ClsPuestos::mobtenerNumero() const
{
    return m_iNumeroPuesto;
}

void ClsPuestos::mestablecerNumero (int valorNumero)
{
    m_iNumeroPuesto = valorNumero;
}


string ClsPuestos::mobtenerNombre() const
{
    return m_sNombrePuesto;
}


void ClsPuestos::mestablecerNombre( string nombrestring )
{

   const char *valorNombrePuesto = nombrestring.data();
   int longitud = strlen( valorNombrePuesto );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sNombrePuesto, valorNombrePuesto, longitud );


   m_sNombrePuesto[ longitud ] = '\0';

}


string ClsPuestos::mobtenerDepartamento() const
{
    return m_sNombreDepartamento;
}


void ClsPuestos::mestablecerDepartamento( string depastring )
{

   const char *valorDepartamento = depastring.data();
   int longitud = strlen( valorDepartamento );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sNombreDepartamento, valorDepartamento, longitud );


   m_sNombrePuesto[ longitud ] = '\0';
}

int ClsPuestos::mobtenerSalario() const
{
    return m_iSalario;
}

void ClsPuestos::mestablecerSalario (int valorSalario)
{
    m_iSalario = valorSalario;
}

string ClsPuestos::mobtenerNivAcademico() const
{
    return m_sNivelAcademico;
}


void ClsPuestos::mestablecerNivAcademico( string nivelstring )
{

   const char *valorNivel = nivelstring.data();
   int longitud = strlen( valorNivel );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sNivelAcademico, valorNivel, longitud );


   m_sNombrePuesto[ longitud ] = '\0';
}

string ClsPuestos::mobtenerHoraEntrada() const
{
    return m_sHoraEntrada;
}


void ClsPuestos::mestablecerHoraEntrada( string HoraEntradastring )
{

   const char *valorHoraEntrada = HoraEntradastring.data();
   int longitud = strlen( valorHoraEntrada );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sHoraEntrada, valorHoraEntrada, longitud );


   m_sNombrePuesto[ longitud ] = '\0';
}

string ClsPuestos::mobtenerHoraSalida() const
{
    return m_sHoraSalida;
}


void ClsPuestos::mestablecerHoraSalida( string HoraSalidastring )
{

   const char *valorHoraSalida = HoraSalidastring.data();
   int longitud = strlen( valorHoraSalida );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sHoraSalida, valorHoraSalida, longitud );


   m_sNombrePuesto[ longitud ] = '\0';
}

//Ingreso de datos de un nuevo empleado
ClsPuestos::mAgregarPuestos()
{
	int iespacios=0;
	system("cls");
	ofstream archivopuestos("registrospuetos.dat", ios::app | ios::out | ios::binary);
	if( !archivopuestos )
    {
        cerr << "No se pudo abrir el archivo registro empleados." << endl;
        exit( EXIT_FAILURE );
    }
	ClsPuestos puesto;
	cout<<"ingrese un numero nuevo para el puesto: (0-cancelar)";
	cin>>m_iNumeroPuesto;
    while(m_iNumeroPuesto!=0)
    {
        cout<<"Agregar un nuevo puesto"<<endl;
        cout<<"Ingresa el nombre del puesto: " << endl;
        cin>> m_sNombrePuesto;
        cout<<"Ingresa el nombre del departamento al cual pertenece el puesto: ";
        cin>>m_sNombreDepartamento;
        cout<<"Ingresa el nivel academico requerido para el puesto: ";
        cin>>m_sNivelAcademico;
        cout<<"Ingresa el monto total del salario: ";
        cin>>m_iSalario;
        cout<<"Ingresa la hora de entrada para el puesto: ";
        cin>>m_sHoraEntrada;
        cout<<"Ingresa la hora de salida para el puesto: ";
        cin>>m_sHoraSalida;

        puesto.mestablecerNumero(m_iNumeroPuesto);
        puesto.mestablecerNombre(m_sNombrePuesto);
        puesto.mestablecerDepartamento(m_sNombreDepartamento);
        puesto.mestablecerSalario(m_iSalario);
        puesto.mestablecerNivAcademico(m_sNivelAcademico);
        puesto.mestablecerHoraEntrada(m_sHoraEntrada);
        puesto.mestablecerHoraSalida(m_sHoraSalida);
        archivopuestos.seekp((puesto.mobtenerNumero() - 1 ) * sizeof(ClsPuestos));
        archivopuestos.write(reinterpret_cast<const char * > (&puesto), sizeof (ClsPuestos));
        cout<<"ingrese nuevo numero de puesto: (0-salir)";
        cin>>m_iNumeroPuesto;
    }

	/*cout<<"Ingresa el numero de DPI del empleado: ";
	cin>>m_sDpiEmpleado;
	cout<<"Ingresa la dirección de residencia del empleado: ";
	cin>>m_sDireccionEmpleado;
	cout<<"Ingresa el número de telefono del empleado: ";
	cin>>m_sTelefonoEmpleado;
	cout<<"Ingresa el correo electronico del empleado: ";
	cin>>m_sCorreoEmpleado;
	archivoEmpleados.close();
}

//Agregar un nuevo empleado
/*ClsEmpleados::mIngresarEmpleado()
{
    char cDecisionNuevoEmpleado;
do
    	{
    		mAgregarEmpleado();
    		cout<<"Desea agregar otra empleado?(Y,N): ";
    		cin>>cDecisionNuevoEmpleado;
		}while(cDecisionNuevoEmpleado=='y'||cDecisionNuevoEmpleado=='Y');
}*/

/*ClsPuestos::mDesplieguePuestos()
{
	system("cls");
	ifstream archivoPuestos("registrospuestos.dat", ios::in | ios:: binary);
	int total=0;
	cout<<"Tabla de Detalles de puestos"<<endl;
	if(!archivoPuestos)
	{
		cerr << "No se pudo abrir el archivo registro puestos." << endl;
        exit( EXIT_FAILURE );
	}
	else
	{
		ClsPuestos puesto;
		while(!archivoPuestos.eof())
		{
			total++;
			cout<<"Nombre: "<<puesto.mobtenerNombre() <<endl;
			cout<<"Numero: "<<puesto.mobtenerNumero() <<endl;
		}
		if(total==0)
		{
			cout<<"No hay informacion...";
		}
	}
	archivoPuestos.close();
}
/*Empleados::modify()
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
//Menu de gestion de los datos de empleado
/*ClsPuestos::mMenuPuestos()
{
    ClsPuestos puesto;
    int iSeleccionMenuPuestos;
	do
    {
	system("cls");

	cout<<"-------------------------------"<<endl;
	cout<<"|   SISTEMA GESTION PUESTOS   |"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"1. Ingreso Puestos"<<endl;
	cout<<"2. Despliegue Puestos"<<endl;
	cout<<"3. Modifica Puestos"<<endl;
	cout<<"4. Busca Puestos"<<endl;
	cout<<"5. Borra Puestos"<<endl;
	cout<<"0. Volver al menu superior"<<endl;

	cout<<"-------------------------------"<<endl;
	cout<<"Opcion a escoger:[1/2/3/4/5/0]"<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>iSeleccionMenuPuestos;

    switch(iSeleccionMenuPuestos)
    {
    case 1:
        puesto.mAgregarPuestos();
        break;
	case 2:
		puesto.mDesplieguePuestos();
		break;
	/*case 3:
		modificarE.modify();
		getch();
		break;
	case 4:
		buscarE.searchE();
		getch();
		break;
	case 5:
		borrarE.deletE();
		break;*/
	/*case 0:
		break;
	default:
		cout<<"Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
    }while(iSeleccionMenuPuestos!= 0);
}
ClsPuestos::~ClsPuestos()
{
    //dtor
}*/

