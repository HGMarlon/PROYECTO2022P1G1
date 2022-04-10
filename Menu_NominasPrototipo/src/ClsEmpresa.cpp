//clase
#include "ClsEmpresa.h"

//librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;




#include "ClsEmpresa.h"

ClsEmpresa::ClsEmpresa(string svalorNombreE, string svalorCorreoE, string svalorNombreD, string svalorActividadE, string svalorNitE, string svalorDireccionE, int ivalorTelefonoE, int ivalorNumEmpleados, int ivalorNumEmpresa)
{
    mestablecerNombreE(svalorNombreE);
    mestablecerCorreoE(svalorCorreoE);
    mestablecerDirectorE(svalorNombreD);
    mestablecerActividadE(svalorActividadE);
    mestablecerNitE(svalorNitE);
    mestablecerDireccionE(svalorDireccionE);
    mestablecerTelefonoE(ivalorTelefonoE);
    mestablecerNumeroEmpleadosE(ivalorNumEmpleados);
    mestablecerNumeroEmpresa(ivalorNumEmpresa);
}

//Funciones del nombre de la empresa
string ClsEmpresa::mobtenerNombreE() const
{
    return m_sNombreEmpresa;
}

void ClsEmpresa::mestablecerNombreE( string sNombreE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombreE = sNombreE.data();
   int ilongitud = strlen( svalorNombreE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombreEmpresa, svalorNombreE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sNombreEmpresa[ ilongitud ] = '\0';

}


//Funciones del correo electronico de la empresa
string ClsEmpresa::mobtenerCorreoE() const
{
    return m_sCorreoEmpresa;
}

void ClsEmpresa::mestablecerCorreoE( string sCorreoE )
{
    // copiar a lo más 20 caracteres de la cadena del telefono
   const char *svalorCorreoE = sCorreoE.data();
   int ilongitud = strlen( svalorCorreoE );
   ilongitud = ( ilongitud< 20 ? ilongitud : 19 );
   strncpy( m_sCorreoEmpresa, svalorCorreoE, ilongitud );

   // anexar caracter nulo al final de la cadena de la direccion
   m_sCorreoEmpresa[ ilongitud ] = '\0';
}



//Funciones del nombre del gerente
string ClsEmpresa:: mobtenerDirectorE() const
{
    return m_sNombreDirector;
}

void ClsEmpresa::mestablecerDirectorE( string sNombreDirector )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombreD = sNombreDirector.data();
   int ilongitud = strlen( svalorNombreD );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy(m_sNombreDirector, svalorNombreD, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sNombreDirector[ ilongitud ] = '\0';

}


//Funciones actividad de la empresa
string ClsEmpresa::mobtenerActividadE() const
{
    return m_sActividadEconomica;
}

void ClsEmpresa::mestablecerActividadE( string sActividadE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorActividadE = sActividadE.data();
   int ilongitud = strlen( svalorActividadE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sActividadEconomica, svalorActividadE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sActividadEconomica[ ilongitud ] = '\0';

}


//Funciones nit de la empresa
string ClsEmpresa::mobtenerNitE() const
{
    return m_iNitEmpresa;
}

void ClsEmpresa::mestablecerNitE( string sNitE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNitE = sNitE.data();
   int ilongitud = strlen( svalorNitE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_iNitEmpresa, svalorNitE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_iNitEmpresa[ ilongitud ] = '\0';

}



//Funciones direccion de la empresa
string ClsEmpresa::mobtenerDireccionE() const
{
    return m_iDireccionEmpresa;
}

void ClsEmpresa::mestablecerDireccionE( string sDireccionE )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorDireccionE = sDireccionE.data();
   int ilongitud = strlen( svalorDireccionE );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_iDireccionEmpresa, svalorDireccionE, ilongitud );

   // anexar caracter nulo al final del nombre
   m_iDireccionEmpresa[ ilongitud ] = '\0';

}


//Funciones telefono de la empresa
int ClsEmpresa::mobtenerTelefonoE() const
{
    return m_iTelefonoEmpresa;
}

void ClsEmpresa::mestablecerTelefonoE (int  ivalorTelefonoE)
{
    m_iTelefonoEmpresa =  ivalorTelefonoE;
}



//Funciones numero de empleados de la empresa
int ClsEmpresa::mobtenerNumeroEmpleadosE() const
{
    return m_iNumeroEmpleados;
}

void ClsEmpresa::mestablecerNumeroEmpleadosE (int ivalorNumEmpleados)
{
    m_iNumeroEmpleados = ivalorNumEmpleados;
}



//Funciones numero de empresa
int ClsEmpresa::mobtenerNumeroEmpresa() const
{
    return  m_iNumeroDeEmpresa;
}

void ClsEmpresa::mestablecerNumeroEmpresa(int ivalorNumEmpresa)
{
     m_iNumeroDeEmpresa = ivalorNumEmpresa;
}


/*
//Ingreso de datos nueva empresa
ClsEmpresa::magregarEmpresa()
{
	system("cls");
	ofstream archivoEmpresa("registrosempresa.dat", ios::app | ios::out | ios::binary);
	if( !archivoEmpresa )
    {
        cerr << "No se pudo abrir el archivo de datos empresa." << endl;
        exit( EXIT_FAILURE );
    }
	ClsEmpresa empresa;
	cout<<"ingrese nuevo nombre para la empresa: (0-cancelar)";
	cin>>m_sNombreEmpresa;
    while(m_sNombreEmpresa!=0)
    {
        cout<<"Editar Empresa"<<endl;
        cout<<"Ingresa el nombre de la empresa: " << endl;
        cin>> m_sNombreEmpresa;
        cout<<"Ingresa el correo electronico de la empresa: ";
        cin>> m_sCorreoEmpresa;
        cout<<"Ingresa nombre del director/encargado de la empresa: ";
        cin>>m_sNombreDirector;
        cout<<"Ingresa actividad economica de la empresa: ";
        cin>>m_sActividadEconomica;
        cout<<"Ingresa el nit de la empresa: ";
        cin>>m_iNitEmpresa;
        cout<<"Ingresa direccion de la empresa: ";
        cin>>m_iDireccionEmpresa;
        cout<<"Ingresa telefono de la empresa: ";
        cin>>m_iTelefonoEmpresa;
        cout<<"Ingresa numero de empleados de la empresa: ";
        cin>>m_iNumeroEmpleados;
        cout<<"Ingresa numero de empresa: ";
        cin>>m_iNumeroDeEmpresa;
        empresa.mestablecerNombreE(svalorNombre);
        empresa.mestablecerCorreoE(svalorCorreo);
        empresa.mestablecerDirectorE(svalorNombreD);
        empresa.mestablecerActividadE(svalorActividad);
        empresa.mestablecerNitE(svalorNit);
        empresa.mestablecerDireccionE(svalorDireccion);
        empresa.mestablecerTelefonoE(ivalorTelefono);
        empresa.mestablecerNumeroEmpleadosE(ivalorNumEmpleados);
        archivoEmpresa.seekp((empresa.mobtenerNombreE - 1 ) * sizeof(ClsEmpresa));
        archivoEmpresa.write(reinterpret_cast<const char * > (&empresa), sizeof (ClsEmpresa));
        cout<<"Datos almacenados con éxito";
        cout<<"ingrese nuevo nombre de empresa: (0-salir)";
        cin>>m_sNombreEmpresa;
    }
	archivoEmpresa.close();
}



/Agregar un nueva empresa
ClsEmpresa::mIngresarEmpresa()
{
    char cDecisionNuevoEmpresa;
do
    	{
    		magregarEmpresa();
    		cout<<"Desea agregar otra empresa?(Y,N): ";
    		cin>>cDecisionNuevoEmpresa;
		}while(cDecisionNuevoEmpresa=='y'||cDecisionNuevoEmpresa=='Y');
}



ClsEmpresa::mdespliegueEmpresa()
{
	system("cls");
	ifstream archivoEmpresa("registrosempresa.dat", ios::in | ios:: binary);
	int iinformacionE=0;
	cout<<"Tabla de Detalles de Empresa:"<<endl;
	if(!archivoEmpresa)
	{
		cerr << "No se pudo abrir el archivo detalles empresa." << endl;
        exit( EXIT_FAILURE );
	}
	else
	{
		ClsEmpresa empresa;
		while(!archivoEmpresa.eof())
		{
			iinformacionE++;
			cout<<"Nombre:"<<empresa.mobtenerNombreE()<<endl;
			cout<<"Correo:"<<empresa.mobtenerCorreoE()<<endl;
			cout<<"Director:"<<empresa.mobtenerDirectorE()<<endl;
			cout<<"Actividad Economica:"<<mobtenerActividadE()<<endl;
			cout<<"Nit:"<<empresa.mobtenerNitE()<<endl;
			cout<<"Direccion:"<<empresa.mobtenerDireccionE()<<endl;
			cout<<"Telefono:"<<empresa.mobtenerTelefonoE()<<endl;
			cout<<"Numero de empleados:"<<empresa.mobtenerNumeroEmpleadosE()<<endl;
			cout<<"Numero de empresa:"<<empresa.mobtenerNumeroEmpresa()<<endl;

		}
		if(iinformacionE==0)
		{
			cout<<"No hay informacion...";
		}
		cout<<"Fin del archivo.";
	}
	archivoEmpresa.close();
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


ClsEmpresa::mMenuEmpresa()
{
    ClsEmpresa empresa;
    int iseleccionMenuEmpresa;
	do
    {
	system("cls");

	cout<<"-------------------------------"<<endl;
    cout<<"|   SISTEMA GESTION EMPRESA   |"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"1. Ingreso Empresa"<<endl;
    cout<<"2. Despliegue Empresa"<<endl;
    cout<<"3. Modifica Empresa"<<endl;
    cout<<"4. Busca Empresa"<<endl;
    cout<<"5. Borra Empresa"<<endl;
    cout<<"0. Volver al menu superior"<<endl;

    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/0]"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"Ingresa tu Opcion: ";
    cin>>iSeleccionMenuEmpresa;

    switch(iseleccionMenuEmpresa)
    {
    case 1:
        empresa.magregarEmpresa();
        break;
	case 2:
		empresa.mdespliegueEmpresa();
		break;
	case 3:
		empresa.mmodificarEmpresa();
		break;
	case 4:
		empresa.mbuscarEmpresa();
		break;
	case 5:
		empresa.meliminarEmpresa();
		break;
	case 0:
		break;
	default:
		cout<<"Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
    }while(iseleccionMenuEmpresa!= 0);
}*/


/*ClsEmpresa::~ClsEmpresa()
{
    //dtor
}*/

