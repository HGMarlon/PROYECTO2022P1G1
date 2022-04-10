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
#include "Clslogin.h"

using namespace std;

int obtenerCuenta( const char * const );
int obtenerUsuario( const char * const );
void nuevoEmpleado( fstream& );
void crearArchivoCredito();
void crearArchivoUsuarios();
void consultarRegistro(fstream&);
void mostrarLineaPantalla(const ClsEmpleados &);
void actualizarRegistro(fstream&);
void mostrarLinea( ostream&, const ClsEmpleados & );
void imprimirRegistro( fstream& );
void eliminarRegistro( fstream& );
void buscarEmpleado( fstream& );
void nuevoUsuario( fstream& );
void buscarUsuario( fstream& );
string obtenerNombreUsuario();

main(){
    //Variables
    int imenuPrincipal;
    int m_iclaveEmpleado=0;
    char m_snombreEmpleado[0];
    int iingresoUsuario;
    char snombreUsuario[ 20 ];
    int isesion = 0;
    string ingresoUsuario;
    /*Login
       abrir el archivo en modo de lectura y escritura*/
    fstream archivoUsuarios("registroUsuaios.dat", ios::in | ios::out | ios::binary);

    // salir del programa si fstream no puede abrir el archivo
    if ( !archivoUsuarios )
        {
            cerr << "No se pudo abrir el archivo." << endl;
            crearArchivoUsuarios();
            cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
            exit ( 1 );
        } // fin de instrucción if

    cout<<"1. Iniciar sesion ";
    cout<<"2. Registrarse ";
    cin>>isesion;
    if(isesion==2)
    {
        nuevoUsuario(archivoUsuarios);
    }

    buscarUsuario(archivoUsuarios);

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
                            cout<<"4. Imprimir Regisro de Empleados"<<endl;
                            cout<<"5. Borra Empleados"<<endl;
                            cout<<"6. Buscar Empleados"<<endl;
                            cout<<"0. Volver al menu superior"<<endl;

                            cout<<"-------------------------------"<<endl;
                            cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
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
                                {
                                    actualizarRegistro(archivoEmpleados);
                                }
                                break;
                            case 4:
                                {
                                    imprimirRegistro(archivoEmpleados);
                                }
                                break;
                            case 5:
                                {
                                    eliminarRegistro(archivoEmpleados);
                                }
                                break;
                            case 6:
                                {
                                    buscarEmpleado(archivoEmpleados);
                                }
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

                    break;
                case 3:

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

      // el usuario introduce el nombre
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 20 ) >> m_snombreEmpleado;

      // usar valores para llenar los valores de la clave
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
//MOSTRAR
void consultarRegistro( fstream &leerDeArchivo )
{

   cout << left << setw( 10 ) << "Clave" << setw( 20 )
       << "Nombre" << endl;

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
          << endl;

} // fin de la función mostrarLineaPantalla

//ACTUALIZAR
void actualizarRegistro( fstream &actualizarArchivo )
{
   // obtener el número de cuenta a actualizar
   int numeroClave = obtenerCuenta( "Escriba la cuenta que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroClave - 1 ) * sizeof( ClsEmpleados ) );

   // leer el primer registro del archivo
   ClsEmpleados empleado;
   actualizarArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( ClsEmpleados ) );

   // actualizar el registro
   if ( empleado.mobtenerClave() != 0 ) {
      mostrarLinea( cout, empleado );

      // solicitar al usuario que especifique la transacción
      cout << "\nEscriba el nombre: ";
      char m_snombreEmpleado [ 20 ];
      cin >> m_snombreEmpleado;

      // actualizar el saldo del registro
      empleado.mestablecerNombre( m_snombreEmpleado );
      mostrarLinea( cout, empleado );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroClave - 1 ) * sizeof( ClsEmpleados ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivo.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( ClsEmpleados ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "La cuenta #" << numeroClave
         << " no tiene informacion." << endl;

} // fin de la función actualizarRegistro

// mostrar registro individual
void mostrarLinea( ostream &salida, const ClsEmpleados &registro )
{
   salida << left << setw( 10 ) << registro.mobtenerClave()
          << setw( 20 ) << registro.mobtenerNombre().data()
          << endl;

} // fin de la función mostrarLinea

void imprimirRegistro( fstream &leerDeArchivo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalida( "imprimir.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalida ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   archivoImprimirSalida << left << setw( 10 ) << "Clave" << setw( 20 )
       << "nombre: "<< endl;

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
         mostrarLinea( archivoImprimirSalida, empleado );

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
         sizeof( ClsEmpleados ) );

   } // fin de instrucción while

} // fin de la función imprimirRegistro

void eliminarRegistro( fstream &eliminarDeArchivo )
{
   // obtener número de cuenta a eliminar
   int numeroClave= obtenerCuenta( "Escriba la cuenta a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivo.seekg(
      ( numeroClave - 1 ) * sizeof( ClsEmpleados ) );

   // leer el registro del archivo
   ClsEmpleados empleado;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( ClsEmpleados ) );

   // eliminar el registro, si es que existe en el archivo
   if ( empleado.mobtenerClave() != 0 ) {
      ClsEmpleados empleadoEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivo.seekp( ( numeroClave - 1 ) *
         sizeof( ClsEmpleados ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &empleadoEnBlanco ),
         sizeof( ClsEmpleados ) );

      cout << "Empleado clave #" << numeroClave << " eliminado correctamente.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
   {
       cerr << "Empleado clave #" << numeroClave << " esta vacia.\n";
   }
   getch();

} // fin de eliminarRegistro

void buscarEmpleado( fstream &leerDeArchivo )
{

   // obtener el número de cuenta a buscar
   int numeroClave = obtenerCuenta( "Escriba la cuenta que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   leerDeArchivo.seekg(
      ( numeroClave - 1 ) * sizeof( ClsEmpleados ) );

   // leer el primer registro del archivo
   ClsEmpleados empleado;
   leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( ClsEmpleados ) );
    //cout<<empleado.mobtenerClave();

   // actualizar el registro
   if ( empleado.mobtenerClave() != 0 ) {
      mostrarLinea( cout, empleado );
   }

   // mostrar error si la cuenta no existe
   else
   {
       cerr << "La cuenta #" << numeroClave
         << " no tiene informacion." << endl;
   }
   getch();

} // fin de la función consultarRegistro

// crear e insertar registro
void nuevoUsuario( fstream &insertarEnArchivo )
{
//Clslogin usuario;
   // obtener el número de cuenta a crear
   int aingresoUsuario = obtenerUsuario( "Escriba el nuevo numero de cuenta" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( aingresoUsuario - 1 ) * sizeof( Clslogin ) );

   // leer el registro del archivo
   Clslogin usuario;
   insertarEnArchivo.read( reinterpret_cast< char * >( &usuario ),
      sizeof( Clslogin ) );

   // crear el registro, si éste no existe ya
   if ( usuario.mobtenerIngreso() == 0 ) {

      char m_snombreUsuario[ 20 ];

      // el usuario introduce el nombre
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 20 ) >> m_snombreUsuario;

      // usar valores para llenar los valores de la clave
      usuario.mestablecernombreUsuario( m_snombreUsuario );
      usuario.mestablecerIngreso( aingresoUsuario );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( aingresoUsuario - 1 ) *
         sizeof( Clslogin ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &usuario ),
         sizeof( Clslogin ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "La cuenta #" << aingresoUsuario
           << " ya contiene informacion." << endl;

} // fin de la función nuevoRegistro

void crearArchivoUsuarios()
{
    ofstream archivoUsuarios("registroUsuarios.dat", ios::out | ios::binary);
    if(!archivoUsuarios)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    Clslogin usuarioEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoUsuarios.write(reinterpret_cast<const char * > (&usuarioEnBlanco), sizeof(Clslogin));
    }
}

int obtenerUsuario( const char * const indicador )
{
   int m_iingresoUsuario;

   // obtener el valor del número de cuenta
   do {
      cout << indicador << " (1 - 100): ";
      cin >> m_iingresoUsuario;

   } while ( m_iingresoUsuario < 1 || m_iingresoUsuario > 100 );

   return m_iingresoUsuario;

} // fin de la función obtenerCuenta

void buscarUsuario( fstream &leerDeArchivo )
{
   char snombreUsuario[ 20 ];
   cout<<"Ingrese su nombre de usuario";
   cin>>snombreUsuario;
   string nombreUsuario;
   // obtener el número de cuenta a buscar
   int numeroUsuario = obtenerUsuario("Escriba su contraseña : ");

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   leerDeArchivo.seekg(
      ( numeroUsuario - 1 ) * sizeof( Clslogin ) );

   // leer el primer registro del archivo
   Clslogin usuario;
   leerDeArchivo.read( reinterpret_cast< char * >( &usuario ),
      sizeof( Clslogin ) );

   if ( usuario.mobtenerIngreso() != 0 )
    {
        nombreUsuario=usuario.mobtenernombreUsuario();
    }

   // mostrar error si la cuenta no existe
   else
   {
       cerr <<"No esta registrado." << endl;
   }
   if (nombreUsuario==snombreUsuario)
    {
        cout<<"Acceso concedido";
    }
    else
    {
        cout <<"Acceso denegado";
    }
   getch();

} // fin de la función consultarRegistro
