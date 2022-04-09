//clase
#include "ClsEmpleados.h"

//librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

//constructor
ClsEmpleados::ClsEmpleados(int ivalorClave, string svalorNombre, string svalorDpi, string svalorDireccion, string svalorTelefono, string svalorCorreo)
{
    mestablecerClave(ivalorClave);
    mestablecerNombre(svalorNombre);
    mestablecerDpi(svalorDpi);
    mestablecerDireccion(svalorDireccion);
    mestablecerTelefono(svalorTelefono);
    mestablecerCorreo(svalorCorreo);
}

//Funciones de la clave del empleado
int ClsEmpleados::mobtenerClave() const
{
    return m_iclaveEmpleado;
}

void ClsEmpleados::mestablecerClave (int ienteroClave)
{
    m_iclaveEmpleado = ienteroClave;
}

//Funciones del nombre del empleado
string ClsEmpleados::mobtenerNombre() const
{
    return m_snombreEmpleado;
}

void ClsEmpleados::mestablecerNombre( string scadenaNombre )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombreEmpleado, svalorNombre, ilongitud );

   // anexar caracter nulo al final del nombre
   m_snombreEmpleado[ ilongitud ] = '\0';

}

//Funciones del Dpi del empleado
string ClsEmpleados::mobtenerDpi() const
{
    return m_sdpiEmpleado;
}

void ClsEmpleados::mestablecerDpi( string scadenaDpi )
{
    // copiar a lo más 20 caracteres de la cadena en dpi
   const char *svalorDpi = scadenaDpi.data();
   int ilongitud = strlen( svalorDpi );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sdpiEmpleado, svalorDpi, ilongitud );

   // anexar caracter nulo al final del dpi
   m_sdpiEmpleado[ ilongitud ] = '\0';
}

//Funciones de la Direccion del empleado
string ClsEmpleados::mobtenerDireccion() const
{
    return m_sdireccionEmpleado;
}

void ClsEmpleados::mestablecerDireccion ( string scadenaDireccion )
{
    // copiar a lo más 20 caracteres de la cadena de la direccion
   const char *svalorDireccion = scadenaDireccion.data();
   int ilongitud = strlen( svalorDireccion );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sdireccionEmpleado, svalorDireccion, ilongitud );

   // anexar caracter nulo al final de la cadena de la direccion
   m_sdireccionEmpleado[ ilongitud ] = '\0';
}

//Funciones del telefono del empleado
string ClsEmpleados::mobtenerTelefono() const
{
    return m_stelefonoEmpleado;
}

void ClsEmpleados::mestablecerTelefono ( string scadenaTelefono )
{
    // copiar a lo más 20 caracteres de la cadena del telefono
   const char *svalorTelefono = scadenaTelefono.data();
   int ilongitud = strlen( svalorTelefono );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_stelefonoEmpleado, svalorTelefono, ilongitud );

   // anexar caracter nulo al final de la cadena del telefono
   m_stelefonoEmpleado[ ilongitud ] = '\0';
}

//Funciones del correo electronico del empleado
string ClsEmpleados::mobtenerCorreo() const
{
    return m_scorreoEmpleado;
}

void ClsEmpleados::mestablecerCorreo ( string scadenaCorreo )
{
    // copiar a lo más 20 caracteres de la cadena del telefono
   const char *svalorCorreo = scadenaCorreo.data();
   int ilongitud = strlen( svalorCorreo );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_scorreoEmpleado, svalorCorreo, ilongitud );

   // anexar caracter nulo al final de la cadena de la direccion
   m_scorreoEmpleado[ ilongitud ] = '\0';
}


//Ingreso de datos de un nuevo empleado
ClsEmpleados::magregarEmpleado()
{
	system("cls");
	ofstream archivoEmpleados("registrosempleados.dat", ios::app | ios::out | ios::binary);
	if( !archivoEmpleados )
    {
        cerr << "No se pudo abrir el archivo registro empleados." << endl;
        exit( EXIT_FAILURE );
    }
	ClsEmpleados empleado;
	cout<<"ingrese una clave del empleado: (0-cancelar)";
	cin>>m_iclaveEmpleado;
    while(m_iclaveEmpleado!=0)
    {
        cout<<"Editar Empleado"<<endl;
        cout<<"Ingresa el nombre del empleado: " << endl;
        cin>> m_snombreEmpleado;
        cout<<"Ingresa el numero de DPI del empleado: ";
        cin>>m_sdpiEmpleado;
        cout<<"Ingresa la dirección de residencia del empleado: ";
        cin>>m_sdireccionEmpleado;
        cout<<"Ingresa el número de telefono del empleado: ";
        cin>>m_stelefonoEmpleado;
        cout<<"Ingresa el correo electronico del empleado: ";
        cin>>m_scorreoEmpleado;
        empleado.mestablecerClave(m_iclaveEmpleado);
        empleado.mestablecerNombre(m_snombreEmpleado);
        empleado.mestablecerDpi(m_sdpiEmpleado);
        empleado.mestablecerDireccion(m_sdireccionEmpleado);
        empleado.mestablecerTelefono(m_stelefonoEmpleado);
        empleado.mestablecerCorreo(m_scorreoEmpleado);
        archivoEmpleados.seekp((empleado.mobtenerClave() - 1 ) * sizeof(ClsEmpleados));
        archivoEmpleados.write(reinterpret_cast<const char * > (&empleado), sizeof (ClsEmpleados));
        cout<<"Datos almacenados con éxito";
        cout<<"ingrese nueva clave: (0-salir)";
        cin>>m_iclaveEmpleado;
    }
	archivoEmpleados.close();
}

ClsEmpleados::mdespliegueEmpleado()
{
	system("cls");
	ifstream archivoEmpleados("registrosempleados.dat", ios::in | ios:: binary);
	int iinformacion=0;
	cout<<"Tabla de Detalles de Personas:"<<endl;
	if(!archivoEmpleados)
	{
		cerr << "No se pudo abrir el archivo registro empleados." << endl;
        exit( EXIT_FAILURE );
	}
	else
	{
		ClsEmpleados empleado;
		while(!archivoEmpleados.eof())
		{
			iinformacion++;
			cout<<"Clave: "<<empleado.mobtenerClave() <<endl;
			cout<<"Nombre: "<<empleado.mobtenerNombre() <<endl;
			cout<<"DPI: "<<empleado.mobtenerDpi() <<endl;
			cout<<"Direccion: "<<empleado.mobtenerDireccion() <<endl;
			cout<<"Telefono: "<<empleado.mobtenerTelefono() <<endl;
			cout<<"Correo: "<<empleado.mobtenerCorreo() <<endl;
		}
		if(iinformacion==0)
		{
			cout<<"No hay informacion...";
		}
		cout<<"Fin del archivo.";
	}
	archivoEmpleados.close();
}
ClsEmpleados::mmodificarEmpleado()
{
	system("cls");
	ofstream archivoEmpleados("registrosempleados.dat", ios::app | ios::out | ios::binary);
	if( !archivoEmpleados )
    {
        cerr << "No se pudo abrir el archivo registro empleados." << endl;
        exit( EXIT_FAILURE );
    }
	ClsEmpleados empleado;
	cout<<"Ingrese la clave del empleado a modificar(0-Salir): ";
    cin>>m_iclaveEmpleado;
	while(m_iclaveEmpleado!=0)
    {
        empleado.mbuscarEmpleado(m_iclaveEmpleado);
        cout<<"Editar Empleado"<<endl;
        cout<<"Ingresa el nombre del empleado: " << endl;
        cin>> m_snombreEmpleado;
        cout<<"Ingresa el numero de DPI del empleado: ";
        cin>>m_sdpiEmpleado;
        cout<<"Ingresa la dirección de residencia del empleado: ";
        cin>>m_sdireccionEmpleado;
        cout<<"Ingresa el número de telefono del empleado: ";
        cin>>m_stelefonoEmpleado;
        cout<<"Ingresa el correo electronico del empleado: ";
        cin>>m_scorreoEmpleado;
        empleado.mestablecerClave(m_iclaveEmpleado);
        empleado.mestablecerNombre(m_snombreEmpleado);
        empleado.mestablecerDpi(m_sdpiEmpleado);
        empleado.mestablecerDireccion(m_sdireccionEmpleado);
        empleado.mestablecerTelefono(m_stelefonoEmpleado);
        empleado.mestablecerCorreo(m_scorreoEmpleado);
        archivoEmpleados.seekp((empleado.mobtenerClave() - 1 ) * sizeof(ClsEmpleados));
        archivoEmpleados.write(reinterpret_cast<const char * > (&empleado), sizeof (ClsEmpleados));
        cout<<"Datos almacenados con éxito";
        cout<<"Para editar otro empleado ingrese otra clave: (0-salir)";
        cin>>m_iclaveEmpleado;
    }
}

ClsEmpleados::mbuscarEmpleado( int ivalorClave )
{
	system("cls");
	/*fstream file;
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
	}*/
}
ClsEmpleados::meliminarEmpleado()
{
	/*system("cls");
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
	}*/
}
//Menu de gestion de los datos de empleado

ClsEmpleados::mmenuEmpleado()
{
    ClsEmpleados empleado;
    int iseleccionMenuEmpleados;
	do
    {
	system("cls");

	cout<<"-------------------------------"<<endl;
	cout<<"|   SISTEMA GESTION EMPLEADOS  |"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"1. Ingreso Empleados"<<endl;
	cout<<"2. Despliegue Empleados"<<endl;
	cout<<"3. Modifica Empleados"<<endl;
	cout<<"4. Busca Empleados"<<endl;
	cout<<"5. Borra Empleados"<<endl;
	cout<<"0. Volver al menu superior"<<endl;

	cout<<"-------------------------------"<<endl;
	cout<<"Opcion a escoger:[1/2/3/4/5/0]"<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>iseleccionMenuEmpleados;

    switch(iseleccionMenuEmpleados)
    {
    case 1:
        empleado.magregarEmpleado();
        break;
	case 2:
		empleado.mdespliegueEmpleado();
		break;
	case 3:
		empleado.mmodificarEmpleado();
		break;
	case 4:
		empleado.mbuscarEmpleado();
		break;
	case 5:
		empleado.meliminarEmpleado();
		break;
	case 0:
		break;
	default:
		cout<<"Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
    }while(iseleccionMenuEmpleados!= 0);
}
ClsEmpleados::~ClsEmpleados()
{
    //dtor
}
