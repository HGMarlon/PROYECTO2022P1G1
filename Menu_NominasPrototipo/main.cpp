//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
//Clases
#include "ClsEmpleados.h"
#include "ClsPuestos.h"
#include "ClsEmpresa.h"

using namespace std;

int obtenerCuenta( const char * const );
void nuevoEmpleado( fstream& );
void crearArchivoCredito();
void consultarRegistro(fstream&);
void mostrarLineaPantalla(const ClsEmpleados &);

//empresa
int obtenerCuentaEmpresa( const char * const );
void nuevaEmpresa( fstream& );
void crearArchivoCreditoEmpresa();
void consultarRegistroEmpresa(fstream&);
void mostrarLineaPantallaE(const ClsEmpresa &);

main(){
    //Variables
    int imenuPrincipal;
    int m_iclaveEmpleado=0;
    char m_snombreEmpleado[0];

    //variables empresa
    char m_sNombreEmpresa[0];
    char m_sCorreoEmpresa[0];
    char m_sNombreDirector[0];
    char m_sActividadEconomica[0];
    char m_iNitEmpresa[0];
    char m_iDireccionEmpresa[0];
    int m_iTelefonoEmpresa=0;
    int m_iNumeroEmpleados=0;
    int m_iNumeroDeEmpresa=0;

	//Menu principal
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
	cout<<"0. EXIT"<<endl;

	cout<<"-------------------------------"<<endl;
	cout<<"OPCIONES A ESCOGER :     [1/2/3/4/5/6/0]"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"INGRESA TU OPCION : ";
    cin>>imenuPrincipal;

    switch(imenuPrincipal)
    {
    case 1:
        {
            int choice2;
            do
            {
                system("cls");
                //Menu segundo nivel
                cout<<"-------------------------------"<<endl;
                cout<<" |   SISTEMA DE MANTENIMIENTO |"<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"1. CRUD empleados"<<endl;
                cout<<"2. CRUD empresa"<<endl;
                cout<<"3. CRUD puestos"<<endl;
                cout<<"4. CRUD conceptos"<<endl;
                cout<<"5. CRUD departamentos"<<endl;
                cout<<"6. CRUD bancos"<<endl;
                cout<<"0. Volver al menu principal"<<endl;

                cout<<"-------------------------------"<<endl;
                cout<<"Opcion a escoger:[1/2/3/0]"<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"Ingresa tu Opcion: ";
                cin>>choice2;
                //Menu segundo nivel
                switch(choice2)
                {
                case 1:
                    {
                        int iseleccionMenuEmpleados;
                        do
                        {
                            system("cls");
                            //archivoempleados
                            // abrir el archivo en modo de lectura y escritura
                            fstream archivoEmpleados("registrosempleados.dat", ios::in | ios::out | ios::binary);

                            // salir del programa si fstream no puede abrir el archivo
                            if ( !archivoEmpleados ) {
                                cerr << "No se pudo abrir el archivo." << endl;
                                crearArchivoCredito();
                                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                exit ( 1 );
                                exit( EXIT_FAILURE );

                               } // fin de instrucción if
                            //Menu tercer nivel
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
                            //menu tercer nivel
                            switch(iseleccionMenuEmpleados)
                            {
                            case 1:
                                {
                                    //agregando empleados
                                    system("cls");
                                    nuevoEmpleado(archivoEmpleados);
                                }
                                break;
                            case 2:
                                {
                                    //Consultar
                                    system("cls");
                                    consultarRegistro(archivoEmpleados);
                                    getch();
                                }
                                break;
                            case 3:
                                //empleado.mmodificarEmpleado();
                                break;
                            case 4:
                                //empleado.mbuscarEmpleado();
                                break;
                            case 5:
                                //empleado.meliminarEmpleado();
                                break;
                            case 0:
                                break;
                            default:
                                cout<<"Opcion invalida...Por favor prueba otra vez..";
                                getch();
                            }
                        }while(iseleccionMenuEmpleados!= 0);
                    }
                    break;
                case 2:
                    {
                        int iSeleccionMenuEmpresa;
                        do
                        {
                            system("cls");
                            //archivoempresa
                            // abrir el archivo en modo de lectura y escritura
                            fstream archivoEmpresa("registrosempresa.dat", ios::in | ios::out | ios::binary);

                            // salir del programa si fstream no puede abrir el archivo
                            if ( !archivoEmpresa ) {
                                cerr << "No se pudo abrir el archivo." << endl;
                                crearArchivoCreditoEmpresa();
                                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                exit ( 1 );
                                exit( EXIT_FAILURE );
                            }

                            cout<<"\t\t\t-------------------------------"<<endl;
                            cout<<"\t\t\t |   SISTEMA GESTION EMPRESA |"<<endl;
                            cout<<"\t\t\t-------------------------------"<<endl;
                            cout<<"\t\t\t 1. Ingreso Empresa"<<endl;
                            cout<<"\t\t\t 2. Despliegue Empresa"<<endl;
                            cout<<"\t\t\t 3. Modifica Empresa"<<endl;
                            cout<<"\t\t\t 4. Busca Empresa"<<endl;
                            cout<<"\t\t\t 5. Borra Empresa"<<endl;
                            cout<<"\t\t\t 0. Volver al menu superior"<<endl;

                            cout<<"\t\t\t-------------------------------"<<endl;
                            cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/0]"<<endl;
                            cout<<"\t\t\t-------------------------------"<<endl;
                            cout<<"Ingresa tu Opcion: ";
                            cin>>iSeleccionMenuEmpresa;

                            switch(iSeleccionMenuEmpresa)
                            {
                                case 1:
                                    //agregando empresa
                                    system("cls");
                                    nuevaEmpresa(archivoEmpresa);

                                    break;
                                case 2:
                                    //Consultar empresa
                                    system("cls");
                                    consultarRegistroEmpresa(archivoEmpresa);
                                    getch();

                                    break;
                                case 3:

                                    break;
                                case 4:

                                    break;
                                case 5:

                                    break;
                                case 0:
                                    break;
                                default:
                                    cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                                    getch();
                            }
                        //getch();
                        }while(iSeleccionMenuEmpresa!=0);
                    }

                    break;
                case 3:
                    //mantenimientoPuesto.mMenuPuestos();
                    break;
                case 0:

                    break;
                default:
                    cout<<"Opcion invalida...Por favor prueba otra vez..";
                    getch();
                }
            }while(choice2!= 0);
        }
        break;
	case 2:
		cout<<"USTED ESTA EN EL APARTADO GENERACION NOMINA";
		getch();
		break;
	case 3:
	    cout<<"USTED ESTA EN EL APARTADO INFORMES NOMINA";
	    getch();
		break;
	case 4:
	    cout<<"USTED ESTA EN EL APARTADO TRANSFERENCIA BANCARIA";
	    getch();
		break;
	case 5:
	    cout<<"USTED ESTA EN EL APARTADO GENERACION POLIZA";
	    getch();
		break;
	case 6:
	    cout<<"USTED ESTA EN EL APARTADO IMPUESTOS";
	    getch();
	    break;
    case 0:
        exit(0);
        break;
	default:
		cout<<"CARACTER NO VALIDO, INGRESE OTRA OPCION";
		getch();
        break;
	}
	}while(imenuPrincipal!= 0);
}

// crear e insertar registro
void nuevoEmpleado( fstream &insertarEnArchivo )
{
   // obtener el número de cuenta a crear
   int m_iclaveEmpleado = obtenerCuenta( "Escriba el nuevo numero de cuenta" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( m_iclaveEmpleado - 1 ) * sizeof( ClsEmpleados ) );

   // leer el registro del archivo
   ClsEmpleados empleado;
   insertarEnArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( ClsEmpleados ) );

   // crear el registro, si éste no existe ya
   if ( empleado.mobtenerClave() == 0 ) {

      char m_snombreEmpleado[ 20 ];

      // el usuario introduce el apellido, primer nombre y saldo
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 20 ) >> m_snombreEmpleado;

      // usar valores para llenar los valores de la cuenta
      empleado.mestablecerNombre( m_snombreEmpleado );
      empleado.mestablecerClave( m_iclaveEmpleado );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( m_iclaveEmpleado - 1 ) *
         sizeof( ClsEmpleados ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( ClsEmpleados ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "La cuenta #" << m_iclaveEmpleado
           << " ya contiene informacion." << endl;

} // fin de la función nuevoRegistro
int obtenerCuenta( const char * const indicador )
{
   int m_iclaveEmpleado;

   // obtener el valor del número de cuenta
   do {
      cout << indicador << " (1 - 100): ";
      cin >> m_iclaveEmpleado;

   } while ( m_iclaveEmpleado < 1 || m_iclaveEmpleado > 100 );

   return m_iclaveEmpleado;

} // fin de la función obtenerCuenta

void crearArchivoCredito()
{
    ofstream archivoEmpleados("registrosempleados.dat", ios::out | ios::binary);
    if(!archivoEmpleados)
    {
        cerr<<"No se habrio el archivo"<<endl;
        exit(1);
    }
    ClsEmpleados empleadoEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoEmpleados.write(reinterpret_cast<const char * > (&empleadoEnBlanco), sizeof(ClsEmpleados));
    }
}


// crear e insertar registro empresa
void nuevaEmpresa( fstream &insertarEnArchivoEmpresa)
{
   // obtener nombre de empresa a crear
   int m_sNombreEmpresa= obtenerCuentaEmpresa( "Escriba el nuevo nombre de la empresa");

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivoEmpresa.seekg(
      ( m_sNombreEmpresa- 1 ) * sizeof( ClsEmpresa) );

   // leer el registro del archivo
   ClsEmpresa empresa;
   insertarEnArchivoEmpresa.read( reinterpret_cast< char * >( &empresa),
      sizeof( ClsEmpresa) );

   // crear el registro, si éste no existe ya
   if ( empresa.mobtenerNombre() == 0 ) {
///////////////////////////////////////////////////////////////////////
        char m_sNombreEmpresa[20];
        char m_sCorreoEmpresa[20];
        char m_sNombreDirector[20];
        char m_sActividadEconomica[20];
        char m_iNitEmpresa[13];
        char m_iDireccionEmpresa[20];
        int m_iTelefonoEmpresa;
        int m_iNumeroEmpleados;
        int m_iNumeroDeEmpresa;

      // el usuario introduce
      cout << "Escriba el nombre de la empresa:" << endl;
      cin >> setw( 20 ) >> m_sNombreEmpresa;
      cout << "Escriba el nombre del correo de la empresa:" << endl;
      cin >> setw( 20 ) >> m_sCorreoEmpresa;
      cout << "Escriba el nombre del director de la emprsa:" << endl;
      cin >> setw( 20 ) >> m_sNombreDirector;
      cout << "Escriba actividad economica de la empresa:" << endl;
      cin >> setw( 20 ) >>m_sActividadEconomica ;
      cout << "Escriba el nit de la empresa:" << endl;
      cin >> setw( 13 ) >>m_iNitEmpresa;
      cout << "Escriba la direccion de la empresa:" << endl;
      cin >> setw( 20 ) >>m_iDireccionEmpresa;
      cout << "Escriba el telefono de la empresa:" << endl;
      cin >> setw( 8 ) >>m_iTelefonoEmpresa;
      cout << "Escriba el numero de empleados:" << endl;
      cin >> setw( 6 ) >>m_iNumeroEmpleados;
      cout << "Escriba el numero de empresa:" << endl;
      cin >> setw( 20 ) >>m_iNumeroDeEmpresa;


      empresa.mestablecerNombreE(m_sNombreEmpresa);
      empresa.mestablecerCorreoE(m_sCorreoEmpresa);
      empresa.mestablecerDirectorE(m_sNombreDirector);
      empresa.mestablecerActividadE(m_sActividadEconomica);
      empresa.mestablecerNitE(m_iNitEmpresa);
      empresa.mestablecerDireccionE(m_iDireccionEmpresa);
      empresa.mestablecerTelefonoE(m_iTelefonoEmpresa);
      empresa.mestablecerNumeroEmpleadosE(m_iNumeroEmpleados);
      empresa.mestablecerNumeroEmpresa(m_iNumeroDeEmpresa);


      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivoEmpresa.seekp( ( m_iNumeroPuesto - 1 ) *
         sizeof( ClsEmpresa) );

      // insertar el registro en el archivo
      insertarEnArchivoEmpresa.write(
         reinterpret_cast< const char * >( &empresa ),
         sizeof( ClsEmpresa) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "el numero#" << m_sNombreEmpresa
           << " ya contiene informacion." << endl;

} // fin de la función nuevoRegistro
int obtenerCuentaEmpresa( const char * const indicadorEmpresa )
{
   int m_sNombreEmpresa;

   // obtener el valor del número de cuenta
   do {
      cout << indicadorEmpresa << " (1 - 100): ";
      cin >> m_sNombreEmpresa;

   } while ( m_sNombreEmpresa < 1 || m_sNombreEmpresa > 100 );

   return m_sNombreEmpresa;

} // fin de la función obtenerCuenta

void crearArchivoCreditoEmpresa()
{
    ofstream archivoEmpresa("registrosempresa.dat", ios::out | ios::binary);
    if(!archivoEmpresa)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    ClsEmpresa EmpresaEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoEmpresa.write(reinterpret_cast<const char * > (&EmpresaEnBlanco), sizeof(ClsEmpresa));
    }
}


//MOSTRAR
void consultarRegistro( fstream &leerDeArchivo )
{

   cout << left << setw( 10 ) << "Clave" << setw( 20 )
       << "Nombre" /*<< setw( 14 ) << "Primer nombre" << right
       << setw( 10 ) << "Saldo"*/ << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsEmpleados empleado;
   leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( ClsEmpleados ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.mobtenerClave() != 0 )
         mostrarLineaPantalla(empleado);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
         sizeof( ClsEmpleados ) );

   } // fin de instrucción while

} // fin de la función consultarRegistro

void mostrarLineaPantalla( const ClsEmpleados &registro )
{
   cout << left << setw( 10 ) << registro.mobtenerClave()
          << setw( 20 ) << registro.mobtenerNombre().data()
          /*<< setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSaldo() */<< endl;

} // fin de la función mostrarLineaPantalla
