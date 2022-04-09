#include "clsconceptos.h"

//Librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

ClsConceptos::ClsConceptos(int nClave, string txtNombreEmpleado, string nDpi, string nSueldo, string nBono)
{
    mestablecerCodigo(nClave);
    mestablecerNombre(txtNombreEmpleado);
    mestablecerDpi(nDpi);
    mestablecerSueldo(nSueldo);
    mestablecerBono(nBono);
}

ClsConceptos::menuConceptos()
{
    ClsConceptos sueldo;

    int conceptosMenu;
	do
    {
	system("cls");

	cout<<"-------------------------------"<<endl;
	cout<<" |    SISTEMA DE CONCEPTOS   |"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"1. Ingresar Sueldos"<<endl;
	cout<<"2. Modificar Sueldos"<<endl;
	cout<<"3. Mostrar Sueldos"<<endl;
	cout<<"0. Volver al menu principal"<<endl;

	cout<<"-------------------------------"<<endl;
	cout<<"Opcion a escoger:[1/2/3/0]"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>conceptosMenu;

    switch(conceptosMenu)
    {
    case 1:
        sueldo.ingresarSueldos();
        break;
	case 2:

		break;
	case 3:
	    sueldo.mDespliegueSueldos();
	    getch();
		break;
	case 0:

		break;
	default:
		cout<<"Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
    }while(conceptosMenu!= 0);
}
///////////////////////////////////INGRESAR SUELDO////////////////////////////////////////////////
int ClsConceptos::mobtenerCodigo() const
{
    return m_iCodigoEmpleado;
}

void ClsConceptos::mestablecerCodigo (int ienteroCodigo)
{
    m_iCodigoEmpleado = ienteroCodigo;
}

string ClsConceptos::mobtenerNombre() const
{
    return m_sNombreEmpleado;
}

void ClsConceptos::mestablecerNombre( string nombrestring )
{
   // copiar a lo m�s 20 caracteres de la cadena en nombree
   const char *txtNombreEmpleado = nombrestring.data();
   int longitud = strlen( txtNombreEmpleado );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sNombreEmpleado, txtNombreEmpleado, longitud );

   // anexar caracter nulo al final del nombre
   m_sNombreEmpleado[ longitud ] = '\0';

}

string ClsConceptos::mobtenerDpi() const
{
    return m_sDpiEmpleado;
}

void ClsConceptos::mestablecerDpi( string ienteroDpi )
{
    // copiar a lo m�s 20 caracteres de la cadena en nombree
   const char *nDpi = ienteroDpi.data();
   int longitud = strlen( nDpi );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sDpiEmpleado, nDpi, longitud );

   // anexar caracter nulo al final del nombre
   m_sDpiEmpleado[ longitud ] = '\0';
}

string ClsConceptos::mobtenerSueldo() const
{
    return m_sSueldoEmpleado;
}

void ClsConceptos::mestablecerSueldo( string ienteroSueldo )
{
    // copiar a lo m�s 20 caracteres de la cadena en nombree
   const char *nSueldo = ienteroSueldo.data();
   int longitud = strlen( nSueldo );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sSueldoEmpleado, nSueldo, longitud );

   // anexar caracter nulo al final del nombre
   m_sSueldoEmpleado[ longitud ] = '\0';
}

string ClsConceptos::mobtenerBono() const
{
    return m_sBonoEmpleado;
}

void ClsConceptos::mestablecerBono( string ienteroBono )
{
    // copiar a lo m�s 20 caracteres de la cadena en nombree
   const char *nBono = ienteroBono.data();
   int longitud = strlen( nBono );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sBonoEmpleado, nBono, longitud );

   // anexar caracter nulo al final del nombre
   m_sBonoEmpleado[ longitud ] = '\0';
}

ClsConceptos::ingresarSueldos()
{
    int iespacios=0;
	system("cls");
	ofstream archivoSueldos("RegistroSueldos.dat", ios::app | ios::out | ios::binary);
	if( !archivoSueldos )
    {
        cerr << "No se pudo abrir el archivo Registro Sueldos." << endl;
        exit( EXIT_FAILURE );
    }
	ClsConceptos sueldo;
	cout<<"Ingrese una nuevo codigo para el empleado: (0-cancelar)";
	cin>>m_iCodigoEmpleado;
    while(m_iCodigoEmpleado!=0)
    {
        cout<<"Agregar nuevo Empleado"<<endl;
        cout<<"Ingresa el nombre del empleado: ";
        cin>> m_sNombreEmpleado;
        cout<<"Ingresa el DPI del empleado: ";
        cin>>m_sDpiEmpleado;
        cout<<"Ingresa el Sueldo del empleado: ";
        cin>>m_sSueldoEmpleado;
        cout<<"Ingresa el Bono del empleado: ";
        cin>>m_sBonoEmpleado;
        sueldo.mestablecerCodigo(m_iCodigoEmpleado);
        sueldo.mestablecerNombre(m_sNombreEmpleado);
        sueldo.mestablecerDpi(m_sDpiEmpleado);
        sueldo.mestablecerSueldo(m_sSueldoEmpleado);
        sueldo.mestablecerBono(m_sBonoEmpleado);
        archivoSueldos.seekp((sueldo.mobtenerCodigo() - 1 ) * sizeof(ClsConceptos));
        archivoSueldos.write(reinterpret_cast<const char * > (&sueldo), sizeof (ClsConceptos));
        cout<<"ingrese nueva clave: (0-salir)";
        cin>>m_iCodigoEmpleado;
    }
	archivoSueldos.close();
}

/////////////////////////////////////////MOSTRAR SUELDO//////////////////////////////////////////////////

ClsConceptos::mDespliegueSueldos()
{
    system("cls");
	ifstream archivoSueldo("RegistroSueldos.dat", /*ios::in |*/ ios:: binary);
	int total=0;
	cout<<"Tabla de Detalles de Sueldos"<<endl;
	if(!archivoSueldo)
	{
		cerr << "No se pudo abrir el archivo registro Sueldos." << endl;
        exit( EXIT_FAILURE );
	}
	else
	{
		ClsConceptos sueldos;
		while(!archivoSueldo.eof())
		{
			total++;
            archivoSueldo.read((char *) &sueldos.m_iCodigoEmpleado, sizeof(ClsConceptos));
			cout<<"Codigo: "<<sueldos.m_iCodigoEmpleado<<endl;
		}
		if(total==0)
		{
			cout<<"No hay informacion...";
		}
	}
	archivoSueldo.close();
}

ClsConceptos::~ClsConceptos()
{
    //dtor
}
