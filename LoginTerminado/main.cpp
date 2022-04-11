//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
//Clases
#include "ClsEmpleados.h"
#include "ClsPuestos.h"
#include "ClsBancos.h"
#include "Clslogin.h"
#include "Clsbitacora.h"

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
string obtenerNombreUsuario();
void escribirBitacora(int, string);

//puestos
int obtenerCuentaPuesto( const char * const );
void nuevoPuesto( fstream& );
void crearArchivoCreditoPuestos();
void consultarRegistroPuestos(fstream&);
void mostrarLineaPantallaP(const ClsPuestos &);
void actualizarRegistroP(fstream&);
void mostrarLineaP( ostream&, const ClsPuestos & );
void imprimirRegistroP( fstream& );
void eliminarRegistroP( fstream& );
void buscarPuesto( fstream& );
void escribirBitacoraPuestos(int, string);

//Bancos
int obtenerCuentaBanco( const char * const );
void nuevoBanco( fstream& );
void crearArchivoCreditoBanco();
void consultarRegistroBanco(fstream&);
void mostrarLineaPantallaB(const ClsBancos &);
void actualizarRegistroB(fstream&);
void mostrarLineaB( ostream&, const ClsBancos & );
void imprimirRegistroB( fstream& );
void eliminarRegistroB( fstream& );
void buscarBanco( fstream& );
void escribirBitacoraBancos(int, string);

main(){
    //Creando objeto
    Clsbitacora bitacora;

    //Variables
    int imenuPrincipal;
    int m_iclaveEmpleado=0;
    char m_snombreEmpleado[0];
    int iingresoUsuario;
    char snombreUsuario[ 20 ];
    int isesion = 0;
    int a=1;
    int codigo;
    int codigoa=0;
    string accion="";
    string ingresoUsuario;

    //variables puesto
    int m_iNumeroPuesto=0;
    char m_sNombrePuesto[ 0 ];
    char m_sNombreDepartamento[ 0 ];
    char m_sNivelAcademico[ 0 ];
    int  m_iSalario=0;
    char m_sHoraEntrada[ 0 ];
    char m_sHoraSalida[ 0 ];

     //variables banco
    char m_sNombreBanco[20];
    int m_iNumeroCuenta;
    char m_sNombreUsuario[20];
    int m_iSaldoCuenta;
    char m_sTipoCuenta[20];


    //tiempo
    time_t t;
    t = time(NULL);
    struct tm *fecha;
    fecha = localtime(&t);

    /*Login
       abrir el archivo en modo de lectura y escritura*/
    fstream archivoUsuarios("registrousuarios.dat", ios::in | ios::out | ios::binary);

    // salir del programa si fstream no puede abrir el archivo
    if ( !archivoUsuarios ){
            cerr << "No se pudo abrir el archivo." << endl;
            crearArchivoUsuarios();
            cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
            exit ( 0 );
        } // fin de instrucción if

    cout<<"1. Iniciar sesion "<<endl;
    cout<<"2. Registrarse "<<endl;
    cin>>isesion;
    if(isesion==2)
    {
        nuevoUsuario(archivoUsuarios);
    }

   system("cls");
   cout<<"Ingrese su nombre de usuario :";
   cin>>snombreUsuario;
   string nombreUsuario;
   // obtener el número de cuenta a buscar
   int numeroUsuario = obtenerUsuario("Escriba su codigo : ");

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   archivoUsuarios.seekg(
      ( numeroUsuario - 1 ) * sizeof( Clslogin ) );

   // leer el primer registro del archivo
   Clslogin usuario;
   archivoUsuarios.read( reinterpret_cast< char * >( &usuario ),
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
        a=0;
    }
    else
    {
        cout <<"Acceso denegado";
        getch();
    }

    if(a==0){

        getch();

    //Bitacora
    codigo = numeroUsuario;
    accion = "Ingreso al sistema";
    //escribirBitacora(codigo, accion);

    ofstream bitacora("bitacora.txt", ios::app | ios::out);
    if (!bitacora)
    {
        cerr << "No se pudo abrir el archivo." << endl;
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
        exit ( 3 );
    }

	bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
	<<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
	<<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
	<<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
	bitacora.close();

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
                                    accion="Empleado Creado";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                }
                                break;
                            case 2:
                                {
                                    //Consultar
                                    system("cls");
                                    consultarRegistro(archivoEmpleados);
                                    getch();
                                    accion="Consulta empleados";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                }
                                break;
                            case 3:
                                {
                                    actualizarRegistro(archivoEmpleados);
                                    accion="Modificacion Empleados";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                }
                                break;
                            case 4:
                                {
                                    imprimirRegistro(archivoEmpleados);
                                    accion="Imprimir Empleados";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                }
                                break;
                            case 5:
                                {
                                    eliminarRegistro(archivoEmpleados);
                                    accion="Eliminar Empleados";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                }
                                break;
                            case 6:
                                {
                                    buscarEmpleado(archivoEmpleados);
                                    accion="Buscar Empleados";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
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
                    {

                    }
                    break;
                case 3:
                    {
                        int choice3;
                        do
                        {
                            system("cls");
                            //archivopuestos
                            // abrir el archivo en modo de lectura y escritura
                            fstream archivoPuestos("registrospuestos.dat", ios::in | ios::out | ios::binary);

                            // salir del programa si fstream no puede abrir el archivo
                            if ( !archivoPuestos ) {
                                cerr << "No se pudo abrir el archivo." << endl;
                                crearArchivoCreditoPuestos();
                                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                exit ( 1 );
                                exit( EXIT_FAILURE );
                            }

                            cout<<"-------------------------------"<<endl;
                            cout<<"|   SISTEMA GESTION PUESTOS   |"<<endl;
                            cout<<"-------------------------------"<<endl;
                            cout<<"1. Ingreso Puestos"<<endl;
                            cout<<"2. Despliegue Puestos"<<endl;
                            cout<<"3. Modifica Puestos"<<endl;
                            cout<<"4. Imprimir Regisro de Puestos"<<endl;
                            cout<<"5. Borra Puestos"<<endl;
                            cout<<"6. Buscar Puestos"<<endl;
                            cout<<"0. Volver al menu superior"<<endl;

                            cout<<"-------------------------------"<<endl;
                            cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
                            cout<<"------------------------------"<<endl;
                            cin>>choice3;

                            switch(choice3)
                            {
                                case 1:
                                   {
                                        //agregando puestos
                                        system("cls");
                                        nuevoPuesto(archivoPuestos);
                                        getch();
                                        accion="Puesto Creado";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();

                                   }
                                    break;
                                case 2:
                                    {
                                        //Consultar puestos
                                        system("cls");
                                        consultarRegistroPuestos(archivoPuestos);
                                        getch();
                                        accion="Consulta puestos";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();

                                    }
                                    break;
                                case 3:
                                     {
                                        system("cls");
                                        actualizarRegistroP(archivoPuestos);
                                        getch();
                                        accion="Modificacion Puestos";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                     }

                                    break;
                                case 4:
                                    {
                                        system("cls");
                                        imprimirRegistroP(archivoPuestos);
                                        cout<<"sus archivos han sido guardados correctamente"<<endl;
                                        getch();
                                        accion="Imprimir Puestos";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                    }

                                    break;
                                case 5:
                                    {
                                         system("cls");
                                         eliminarRegistroP(archivoPuestos);
                                         getch();
                                         accion="Eliminar Puestos";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                    }

                                    break;
                                case 6:
                                    {
                                         system("cls");
                                         buscarPuesto(archivoPuestos);
                                         getch();
                                         accion="Buscar Puestos";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                    }
                                    break;
                                case 0:
                                    break;
                                default:
                                    cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                                    getch();
                            }
                        //getch();
                        }while(choice3!= 0);
                    }

                    break;
                case 4:
                    {

                    }
                    break;
                case 5:
                    {

                    }
                    break;
                case 6:
                    {
                        int choice6;
                        do
                        {
                            system("cls");
                            //archivopuestos
                            // abrir el archivo en modo de lectura y escritura
                            fstream archivoBancos("registrosbancos.dat", ios::in | ios::out | ios::binary);

                            // salir del programa si fstream no puede abrir el archivo
                            if ( !archivoBancos ) {
                                cerr << "No se pudo abrir el archivo." << endl;
                                crearArchivoCreditoBanco();
                                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                exit ( 1 );
                                exit( EXIT_FAILURE );
                            }

                            cout<<"-------------------------------"<<endl;
                            cout<<"|   SISTEMA GESTION BANCOS    |"<<endl;
                            cout<<"-------------------------------"<<endl;
                            cout<<"1. Ingreso Bancos"<<endl;
                            cout<<"2. Despliegue Bancos"<<endl;
                            cout<<"3. Modifica Bancos"<<endl;
                            cout<<"4. Imprimir Regisro de Bancos"<<endl;
                            cout<<"5. Borra Bancos"<<endl;
                            cout<<"6. Buscar Bancos"<<endl;
                            cout<<"0. Volver al menu superior"<<endl;

                            cout<<"-------------------------------"<<endl;
                            cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
                            cout<<"------------------------------"<<endl;
                            cin>>choice6;

                            switch(choice6)
                            {
                                case 1:
                                   {
                                        //agregando puestos
                                        system("cls");
                                        nuevoBanco(archivoBancos);
                                        getch();
                                        accion="Banco Creado";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();

                                   }
                                    break;
                                case 2:
                                    {
                                        //Consultar puestos
                                        system("cls");
                                        consultarRegistroBanco(archivoBancos);
                                        getch();
                                        accion="Consulta Bancos";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();

                                    }
                                    break;
                                case 3:
                                     {
                                        system("cls");
                                        actualizarRegistroB(archivoBancos);
                                        getch();
                                        accion="Modificacion Bancos";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                     }

                                    break;
                                case 4:
                                    {
                                        system("cls");
                                        imprimirRegistroB(archivoBancos);
                                        cout<<"sus archivos han sido guardados correctamente"<<endl;
                                        getch();
                                        accion="Imprimir Bancos";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                    }

                                    break;
                                case 5:
                                    {
                                         system("cls");
                                         eliminarRegistroB(archivoBancos);
                                         getch();
                                         accion="Eliminar Bancos";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                    }

                                    break;
                                case 6:
                                    {
                                         system("cls");
                                         buscarBanco(archivoBancos);
                                         getch();
                                         accion="Buscar Bancos";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                    }
                                    break;
                                case 0:
                                    break;
                                default:
                                    cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                                    getch();
                            }
                        //getch();
                        }while(choice6!= 0);

                    }
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

void nuevoPuesto( fstream &insertarEnArchivoPuesto )
{
   // obtener el número de puesto a crear
   int m_iNumeroPuesto = obtenerCuentaPuesto( "Escriba el nuevo numero de cuenta" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivoPuesto.seekg(
      ( m_iNumeroPuesto - 1 ) * sizeof( ClsPuestos ) );

   // leer el registro del archivo puesto
   ClsPuestos puesto;
   insertarEnArchivoPuesto.read( reinterpret_cast< char * >( &puesto ),
      sizeof( ClsPuestos ) );

   // crear el registro, si éste no existe ya
   if ( puesto.mobtenerNumero() == 0 ) {
///////////////////////////////////////////////////////////////////////
      char m_sNombrePuesto[ 20 ];
      char m_sNombreDepartamento[ 20 ];
      char m_sNivelAcademico[ 20 ];
      int  m_iSalario;
      char m_sHoraEntrada[20];
      char m_sHoraSalida[ 20 ];

      // el usuario introducela información
      cout << "Escriba el nombre del puesto: " << endl;
      cin >> setw( 20 ) >> m_sNombrePuesto;
      cout << "Escriba el nombre del departamento correspondiente: " << endl;
      cin >> setw( 20 ) >> m_sNombreDepartamento;
      cout << "Escriba el nivel academico requerido: " << endl;
      cin >> setw( 20 ) >> m_sNivelAcademico;
      cout << "Escriba el total de salario: " << endl;
      cin >> setw( 9 ) >>m_iSalario ;
      cout << "Escriba la hora de entrada: " << endl;
      cin >> setw( 20 ) >> m_sHoraEntrada;
      cout << "Escriba la hora de salida: " << endl;
      cin >> setw( 20 ) >> m_sHoraSalida;

      // usar valores para llenar los valores de la cuenta
      puesto.mestablecerNumero( m_iNumeroPuesto );
      puesto.mestablecerNombreP( m_sNombrePuesto );
      puesto.mestablecerDepartamento(m_sNombreDepartamento);
      puesto.mestablecerNivelAcademico(m_sNivelAcademico);
      puesto.mestablecerSalario(m_iSalario);
      puesto.mestablecerHoraEntrada(m_sHoraEntrada);
      puesto.mestablecerHoraSalida(m_sHoraSalida);

      //seguir agragando

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivoPuesto.seekp( ( m_iNumeroPuesto - 1 ) *
         sizeof( ClsPuestos ) );

      // insertar el registro en el archivo
      insertarEnArchivoPuesto.write(
         reinterpret_cast< const char * >( &puesto ),
         sizeof( ClsPuestos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "el numero#" << m_iNumeroPuesto
           << " ya contiene informacion." << endl;

} // fin de la función nuevoRegistro
int obtenerCuentaPuesto( const char * const indicadorPuesto )
{
   int m_iNumeroPuesto;

   // obtener el valor del número de cuenta
   do {
      cout << indicadorPuesto << " (1 - 100): ";
      cin >> m_iNumeroPuesto;

   } while ( m_iNumeroPuesto < 1 || m_iNumeroPuesto > 100 );

   return m_iNumeroPuesto;

} // fin de la función obtenerCuenta

void crearArchivoCreditoPuestos()
{
    ofstream archivoPuestos("registrospuestos.dat", ios::out | ios::binary);
    if(!archivoPuestos)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    ClsPuestos PuestoEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoPuestos.write(reinterpret_cast<const char * > (&PuestoEnBlanco), sizeof(ClsPuestos));
    }
}


void nuevoBanco( fstream &insertarEnArchivoBanco )
{
   // obtener el número de puesto a crear
   int m_iNumeroCuenta = obtenerCuentaBanco( "Escriba el nuevo numero de cuenta" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivoBanco.seekg(
      ( m_iNumeroCuenta - 1 ) * sizeof( ClsBancos ) );

   // leer el registro del archivo puesto
   ClsBancos banco;
   insertarEnArchivoBanco.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );

   // crear el registro, si éste no existe ya
   if ( banco.mobtenerNumeroB() == 0 ) {
      char m_sNombreBanco[20];
      char m_sNombreUsuario[20];
      int m_iSaldoCuenta;
      char m_sTipoCuenta[20];

      // el usuario introducela información
      cout << "Escriba el nombre del Banco: " << endl;
      cin >> setw( 20 ) >> m_sNombreBanco;
      cout << "Escriba el nombre del propietario de la cuenta: " << endl;
      cin >> setw( 20 ) >> m_sNombreUsuario;
      cout << "Escriba el total de saldo en la cuenta: " << endl;
      cin >> setw( 9 ) >>m_iSaldoCuenta ;
      cout << "Escriba el tipo de cuenta: " << endl;
      cin >> setw( 20 ) >> m_sTipoCuenta;


      // usar valores para llenar los valores de la cuenta
      banco.mestablecerNombreBanco(m_sNombreBanco);
      banco.mestablecerNumeroCuenta(m_iNumeroCuenta);
      banco.mestablecerNombreUsuario(m_sNombreUsuario);
      banco.mestablecerSaldoCuenta(m_iSaldoCuenta);
      banco.mestablecerTipoCuenta(m_sTipoCuenta);


      //seguir agragando

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivoBanco.seekp( ( m_iNumeroCuenta - 1 ) *
         sizeof( ClsBancos ) );

      // insertar el registro en el archivo
      insertarEnArchivoBanco.write(
         reinterpret_cast< const char * >( &banco ),
         sizeof( ClsBancos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "el numero#" << m_iNumeroCuenta
           << " ya contiene informacion." << endl;

} // fin de la función nuevoRegistro
int obtenerCuentaBanco( const char * const indicadorBanco )
{
   int m_iNumeroCuenta;

   // obtener el valor del número de cuenta
   do {
      cout << indicadorBanco << " (1 - 100): ";
      cin >> m_iNumeroCuenta;

   } while ( m_iNumeroCuenta < 1 || m_iNumeroCuenta > 100 );

   return m_iNumeroCuenta;

} // fin de la función obtenerCuenta

void crearArchivoCreditoBanco()
{
    ofstream archivoBancos("registrosbancos.dat", ios::out | ios::binary);
    if(!archivoBancos)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    ClsBancos BancoEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoBancos.write(reinterpret_cast<const char * > (&BancoEnBlanco), sizeof(ClsBancos));
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

//MOSTRAR PUESTOS
void consultarRegistroPuestos( fstream &leerDeArchivoPuesto )
{

   cout << left << setw( 9 ) << "Numero" << setw( 20 )<< "Nombre"<< setw( 20 )<< "Departamento" << setw( 20 )<< "NivelAcademico"<< setw( 9 )<< "Salario"<< setw( 20 )<< "HoraEntrada"<< setw( 20 )<< "HoraSalida" << setw( 14 )<< endl;


   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivoPuesto.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsPuestos puesto;
   leerDeArchivoPuesto.read( reinterpret_cast< char * >( &puesto ),
      sizeof( ClsPuestos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivoPuesto.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( puesto.mobtenerNumero() != 0 )
         mostrarLineaPantallaP(puesto);

      // leer siguiente registro del archivo de registros
      leerDeArchivoPuesto.read( reinterpret_cast< char * >( &puesto ),
         sizeof( ClsPuestos ) );

   } // fin de instrucción while

} // fin de la función consultarRegistro

void mostrarLineaPantallaP( const ClsPuestos &registroPuesto )
{
   cout << left << setw( 9 ) << registroPuesto.mobtenerNumero()
          << setw( 20 ) << registroPuesto.mobtenerNombreP().data()
          << setw( 20 ) << registroPuesto.mobtenerDepartamento().data()
          << setw( 20 ) << registroPuesto.mobtenerNivAcademico().data()
          << setw( 9 ) << registroPuesto.mobtenerSalario()
          << setw( 20 ) << registroPuesto.mobtenerHoraEntrada().data()
          << setw( 20 ) << registroPuesto.mobtenerHoraSalida().data()
          /*<< setw( 14 ) << registro.obtenerPrimerNombre().data() //.data string sin .data int
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSaldo() <<*/ <<endl;

} // fin de la función mostrarLineaPantalla


//MOSTRAR BANCOS
void consultarRegistroBanco( fstream &leerDeArchivoBanco )
{

   cout << left << setw( 9 ) << "NumeroCuenta" << setw( 20 )<< "NombreBanco"<< setw( 20 )<< "NombreUsuario" << setw( 9 )<< "Saldo"<< setw( 20 )<< "TipoCuenta"<<  endl;


   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivoBanco.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsBancos banco;
   leerDeArchivoBanco.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivoBanco.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( banco.mobtenerNumeroB() != 0 )
        mostrarLineaPantallaB(banco);

      // leer siguiente registro del archivo de registros
      leerDeArchivoBanco.read( reinterpret_cast< char * >( &banco ),
         sizeof( ClsBancos ) );

   } // fin de instrucción while

} // fin de la función consultarRegistro

void mostrarLineaPantallaB( const ClsBancos &registroBanco )
{
   cout << left << setw( 9 ) << registroBanco.mobtenerNumeroB()
          << setw( 20 ) << registroBanco.mobtenerNombreB().data()
          << setw( 20 ) << registroBanco.mobtenerUsuarioB().data()
          << setw( 9  ) << registroBanco.mobtenerSaldoB()
          << setw( 20 ) << registroBanco.mobtenerTipoB().data()

          /*<< setw( 14 ) << registro.obtenerPrimerNombre().data() //.data string sin .data int
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSaldo() <<*/ <<endl;

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

//ACTUALIZAR PUESTOS
void actualizarRegistroP( fstream &actualizarArchivoPuesto )
{
   // obtener el número de cuenta a actualizar
   int NumeroPuesto = obtenerCuentaPuesto( "Escriba la cuenta que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivoPuesto.seekg(
      ( NumeroPuesto - 1 ) * sizeof( ClsPuestos ) );

   // leer el primer registro del archivo
   ClsPuestos puesto;
   actualizarArchivoPuesto.read( reinterpret_cast< char * >( &puesto ),
      sizeof( ClsPuestos ) );

   // actualizar el registro
   if (puesto.mobtenerNumero() != 0 ) {
      mostrarLineaP( cout, puesto );

      // solicitar al usuario que especifique la transacción
      cout << "\nEscriba el nombre del puesto: ";
      char m_sNombrePuesto [ 20 ];
      cin >> m_sNombrePuesto;

      // actualizar el saldo del registro
      puesto.mestablecerNombreP( m_sNombrePuesto );
      mostrarLineaP( cout, puesto );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivoPuesto.seekp(
         ( NumeroPuesto - 1 ) * sizeof( ClsPuestos ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivoPuesto.write(
         reinterpret_cast< const char * >( &puesto ),
         sizeof( ClsPuestos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "El puesto #" << NumeroPuesto
         << " no tiene informacion." << endl;

} // fin de la función actualizarRegistro


//ACTUALIZAR BANCOS
void actualizarRegistroB( fstream &actualizarArchivoBanco )
{
   // obtener el número de cuenta a actualizar
   int NumeroCuenta = obtenerCuentaBanco( "Escriba la cuenta que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivoBanco.seekg(
      ( NumeroCuenta - 1 ) * sizeof( ClsBancos ) );

   // leer el primer registro del archivo
   ClsBancos banco;
   actualizarArchivoBanco.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );

   // actualizar el registro
   if (banco.mobtenerNumeroB() != 0 ) {
      mostrarLineaB( cout, banco );

      // solicitar al usuario que especifique la transacción
      cout << "\nEscriba el nombre del Banco ";
      char m_sNombreBanco [ 20 ];
      cin >> m_sNombreBanco;

      // actualizar el saldo del registro
      banco.mestablecerNombreBanco( m_sNombreBanco );
      mostrarLineaB( cout, banco );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivoBanco.seekp(
         ( NumeroCuenta - 1 ) * sizeof( ClsBancos ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivoBanco.write(
         reinterpret_cast< const char * >( &banco ),
         sizeof( ClsBancos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "La cuenta #" << NumeroCuenta
         << " no tiene informacion." << endl;

} // fin de la función actualizarRegistro


// mostrar registro individual
void mostrarLinea( ostream &salida, const ClsEmpleados &registro )
{
   salida << left << setw( 10 ) << registro.mobtenerClave()
          << setw( 20 ) << registro.mobtenerNombre().data()
          << endl;

} // fin de la función mostrarLinea
// mostrar registro puestos individual
void mostrarLineaP( ostream &salida, const ClsPuestos &registroPuesto )
{
   salida << left << setw( 9 ) <<registroPuesto.mobtenerNumero()
          << setw( 20 ) << registroPuesto.mobtenerNombreP().data()
          << setw( 20 ) << registroPuesto.mobtenerDepartamento().data()
          << setw( 20 ) << registroPuesto.mobtenerNivAcademico().data()
          << setw( 9 ) << registroPuesto.mobtenerSalario()
          << setw( 20 ) << registroPuesto.mobtenerHoraEntrada().data()
          << setw( 20 ) << registroPuesto.mobtenerHoraSalida().data()
          << endl;

} // fin de la función mostrarLinea


// mostrar registro Bancos individual
void mostrarLineaB( ostream &salida, const ClsBancos &registroBanco )
{
   salida << left << setw( 9 ) <<registroBanco.mobtenerNumeroB()
          << setw( 20 ) << registroBanco.mobtenerNombreB().data()
          << setw( 20 ) << registroBanco.mobtenerUsuarioB().data()
          << setw( 9 ) << registroBanco.mobtenerSaldoB()
          << setw( 20 ) << registroBanco.mobtenerTipoB().data()
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
void imprimirRegistroP( fstream &leerDeArchivoPuesto )
{
   // crear archivo de texto
   ofstream archivoImprimirSalidaP( "imprimir.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalidaP ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   archivoImprimirSalidaP << left << setw( 9 ) << "Numero" << setw( 20 )<< "Nombre"<< setw( 20 )<< "Departamento" << setw( 20 )<< "NivelAcademico"<< setw( 9 )<< "Salario"<< setw( 20 )<< "HoraEntrada"<< setw( 20 )<< "HoraSalida" << setw( 14 )<< endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivoPuesto.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsPuestos puesto;
   leerDeArchivoPuesto.read( reinterpret_cast< char * >( &puesto ),
      sizeof( ClsPuestos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivoPuesto.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( puesto.mobtenerNumero() != 0 )
         mostrarLineaP( archivoImprimirSalidaP, puesto );

      // leer siguiente registro del archivo de registros
      leerDeArchivoPuesto.read( reinterpret_cast< char * >( &puesto ),
         sizeof( ClsPuestos ) );
      getch();
   } // fin de instrucción while

} // fin de la función imprimirRegistro


void imprimirRegistroB( fstream &leerDeArchivoBanco )
{
   // crear archivo de texto
   ofstream archivoImprimirSalidaB( "imprimir.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalidaB ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   archivoImprimirSalidaB << left << setw( 9 ) << "NumeroCuenta" << setw( 20 )<< "NombreBanco"<< setw( 20 )<< "NombreUsuario" << setw( 9 )<< "Saldo"<< setw( 20 )<< "TipoCuenta"<<  endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivoBanco.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsBancos banco;
   leerDeArchivoBanco.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivoBanco.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( banco.mobtenerNumeroB() != 0 )
         mostrarLineaB( archivoImprimirSalidaB, banco );

      // leer siguiente registro del archivo de registros
      leerDeArchivoBanco.read( reinterpret_cast< char * >( &banco ),
         sizeof( ClsBancos ) );
      getch();
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
void eliminarRegistroP (fstream &eliminarDeArchivoPuestos )
{
   // obtener número de cuenta a eliminar
   int numeroPuesto= obtenerCuentaPuesto( "Escriba el puesto a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivoPuestos.seekg(
      ( numeroPuesto - 1 ) * sizeof( ClsPuestos ) );

   // leer el registro del archivo
   ClsPuestos puesto;
   eliminarDeArchivoPuestos.read( reinterpret_cast< char * >( &puesto ),
      sizeof( ClsPuestos ) );

   // eliminar el registro, si es que existe en el archivo
   if ( puesto.mobtenerNumero() != 0 ) {
      ClsPuestos puestosEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivoPuestos.seekp( ( numeroPuesto - 1 ) *
         sizeof( ClsPuestos ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivoPuestos.write(
         reinterpret_cast< const char * >( &puestosEnBlanco ),
         sizeof( ClsPuestos ) );

      cout << "El puesto #" << numeroPuesto << " eliminado correctamente.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
   {
       cerr << "El puesto #" << numeroPuesto << " esta vacia.\n";
   }
   getch();

} // fin de eliminarRegistro


void eliminarRegistroB (fstream &eliminarDeArchivoBancos )
{
   // obtener número de cuenta a eliminar
   int numeroCuenta= obtenerCuentaBanco( "Escriba el cuenta a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivoBancos.seekg(
      ( numeroCuenta - 1 ) * sizeof( ClsBancos ) );

   // leer el registro del archivo
   ClsBancos banco;
   eliminarDeArchivoBancos.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );

   // eliminar el registro, si es que existe en el archivo
   if ( banco.mobtenerNumeroB() != 0 ) {
      ClsBancos BancoEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivoBancos.seekp( ( numeroCuenta - 1 ) *
         sizeof( ClsBancos ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivoBancos.write(
         reinterpret_cast< const char * >( &BancoEnBlanco ),
         sizeof( ClsBancos ) );

      cout << "La cuenta #" << numeroCuenta << " eliminado correctamente.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
   {
       cerr << "La cuenta #" << numeroCuenta << " esta vacia.\n";
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
void buscarPuesto( fstream &leerDeArchivoPuesto )
{

   // obtener el número de cuenta a buscar
   int numeroPuesto = obtenerCuentaPuesto( "Escriba el puesto que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   leerDeArchivoPuesto.seekg(
      ( numeroPuesto - 1 ) * sizeof( ClsPuestos ) );

   // leer el primer registro del archivo
   ClsPuestos puesto;
   leerDeArchivoPuesto.read( reinterpret_cast< char * >( &puesto ),
      sizeof( ClsPuestos ) );
    //cout<<empleado.mobtenerClave();

   // actualizar el registro
   if ( puesto.mobtenerNumero() != 0 ) {
      mostrarLineaP( cout, puesto );
   }

   // mostrar error si la cuenta no existe
   else
   {
       cerr << "El puesto #" << numeroPuesto
         << " no tiene informacion." << endl;
   }
   getch();

} // fin de la función consultarRegistro


void buscarBanco( fstream &leerDeArchivoBanco )
{

   // obtener el número de cuenta a buscar
   int numeroCuenta = obtenerCuentaBanco( "Escriba el banco que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   leerDeArchivoBanco.seekg(
      ( numeroCuenta - 1 ) * sizeof( ClsBancos ) );

   // leer el primer registro del archivo
   ClsBancos banco;
   leerDeArchivoBanco.read( reinterpret_cast< char * >( &banco ),
      sizeof( ClsBancos ) );
    //cout<<empleado.mobtenerClave();

   // actualizar el registro
   if ( banco.mobtenerNumeroB() != 0 ) {
      mostrarLineaB( cout, banco );
   }

   // mostrar error si la cuenta no existe
   else
   {
       cerr << "la cuenta  #" << numeroCuenta
         << " no tiene informacion." << endl;
   }
   getch();

} // fin de la función consultarRegistro
// crear e insertar registro

void nuevoUsuario( fstream &insertarEnArchivo )
{
//Clslogin usuario;
   // obtener el número de cuenta a crear
   int aingresoUsuario = obtenerUsuario( "Escriba el codigo de ingreso " );

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
      cout << "Escriba el nombre : " << endl;
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
    ofstream archivoUsuarios("registrousuarios.dat", ios::out | ios::binary);
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
