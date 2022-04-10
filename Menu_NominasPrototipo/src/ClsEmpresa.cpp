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
    mestablecerNombreE(svalorNombre);
    mestablecerCorreoE(svalorCorreo);
    mestablecerDirectorE(svalorNombreD);
    mestablecerActividadE(svalorActividad);
    mestablecerNitE(svalorNit);
    mestablecerDireccionE(svalorDireccion);
    mestablecerTelefonoE(ivalorTelefono);
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

void ClsEmpresa::mestablecerNombreE( string sActividadE )
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

void ClsEmpleados::mestablecerTelefonoE (int  ivalorTelefonoE)
{
    m_iTelefonoEmpresa =  ivalorTelefonoE;
}



//Funciones numero de empleados de la empresa
int ClsEmpresa::mobtenerNumeroEmpleadosE() const
{
    return m_iNumeroEmpleados;
}

void ClsEmpleados::mestablecerNumeroEmpleadosE (int ivalorNumEmpleados)
{
    m_iNumeroEmpleados = ivalorNumEmpleados;
}



//Funciones numero de empresa
int ClsEmpresa::mobtenerNumeroEmpresa() const
{
    return  m_iNumeroDeEmpresa;
}

void ClsEmpleados::mestablecerNumeroEmpresa(int ivalorNumEmpresa)
{
     m_iNumeroDeEmpresa = ivalorNumEmpresa;
}



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
}*/



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






ClsEmpresa::~ClsEmpresa()
{
    //dtor
}
