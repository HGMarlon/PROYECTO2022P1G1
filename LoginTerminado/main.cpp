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
#include "ClsEmpresa.h"
#include "ClsConceptos.h"

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

//empresa
int obtenerCuentaEmpresa( const char * const );
void nuevaEmpresa( fstream& );
void crearArchivoCreditoEmpresa();
void consultarRegistroEmpresa(fstream&);
void mostrarLineaPantallaE(const ClsEmpresa &);
void actualizarRegistroEmpresa(fstream&);
void mostrarLineaE( ostream&, const ClsEmpresa & );
void imprimirRegistroE( fstream& );
void eliminarRegistroE( fstream& );
void buscarEmpresa( fstream& );
void escribirBitacoraEmpresa(int, string);

///////////////////////////SUELDOS//////////////////
int obtenerSueldo( const char * const );
void nuevoEmpleadoSueldo( fstream& );
void crearArchivoSueldo();
void consultarRegistroSueldo(fstream&);
void mostrarLineaPantallaSueldo(const ClsConceptos &);
void actualizarRegistroSueldo(fstream&);
void mostrarLineaSueldo( ostream&, const ClsConceptos & );
void imprimirRegistroSueldo( fstream& );
void eliminarRegistroSueldo( fstream& );
void buscarEmpleadoSueldo( fstream& );
void escribirBitacora(int, string);

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

        //Variables Sueldo
    int m_iclaveEmpleadoSueldo=0;
    char m_snombreEmpleadoSueldo[0];
    char m_sSueldo[0];
    char m_sBono[0];


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

                            cout<<"-------------------------------"<<endl;
                            cout<<" |   SISTEMA GESTION EMPRESA |"<<endl;
                            cout<<"-------------------------------"<<endl;
                            cout<<"1. Ingreso Empresa"<<endl;
                            cout<<"2. Despliegue Empresa"<<endl;
                            cout<<"3. Modifica Empresa"<<endl;
                            cout<<"4. Imprimir Registro de Empresa"<<endl;
                            cout<<"5. Borra Empresa"<<endl;
                            cout<<"6. Buscar Empresa"<<endl;
                            cout<<"0. Volver al menu superior"<<endl;

                            cout<<"-------------------------------"<<endl;
                            cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
                            cout<<"------------------------------"<<endl;
                            cout<<"Ingresa tu Opcion: ";
                            cin>>iSeleccionMenuEmpresa;

                            switch(iSeleccionMenuEmpresa)
                            {
                                case 1:
                                    {
                                        //agregando empresa
                                        system("cls");
                                        nuevaEmpresa(archivoEmpresa);
                                        accion="Empresa Creado";
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
                                        //Consultar empresa
                                        system("cls");
                                        consultarRegistroEmpresa(archivoEmpresa);
                                        getch();
                                        accion="Consulta empresa";
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
                                        actualizarRegistroEmpresa(archivoEmpresa);
                                        getch();
                                        accion="Modificacion Empresa";
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

                                        imprimirRegistroE(archivoEmpresa);
                                        accion="Imprimir Empresa";
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

                                        eliminarRegistroE(archivoEmpresa);
                                        accion="Eliminar Empresa";
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

                                        buscarEmpresa(archivoEmpresa);
                                        accion="Buscar Empresa";
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
                        }while(iSeleccionMenuEmpresa!=0);
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
                        int iseleccionMenuSueldos;
                        do
                        {
                            system("cls");
                            //archivoempleados
                            // abrir el archivo en modo de lectura y escritura
                            fstream archivoSueldos("RegistroSueldos.dat", ios::in | ios::out | ios::binary);

                            // salir del programa si fstream no puede abrir el archivo
                            if ( !archivoSueldos ) {
                                cerr << "No se pudo abrir el archivo." << endl;
                                crearArchivoSueldo();
                                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                exit ( 1 );
                                exit( EXIT_FAILURE );

                               } // fin de instrucción if
                            //Menu tercer nivel
                            cout<<"-------------------------------"<<endl;
                            cout<<"|   SISTEMA GESTION SUELDOS  |"<<endl;
                            cout<<"-------------------------------"<<endl;
                            cout<<"1. Ingreso Sueldos"<<endl;
                            cout<<"2. Modificar Sueldos"<<endl;
                            cout<<"3. Mostrar Sueldos"<<endl;
                            cout<<"4. Eliminar Sueldos"<<endl;
                            cout<<"5. Buscar Sueldos"<<endl;
                            cout<<"6. Imprimir Registro Sueldos"<<endl;
                            cout<<"0. Volver al menu superior"<<endl;

                            cout<<"-------------------------------"<<endl;
                            cout<<"Opcion a escoger:[1/2/3/0]"<<endl;
                            cout<<"------------------------------"<<endl;
                            cout<<"Ingresa tu Opcion: ";
                            cin>>iseleccionMenuSueldos;
                            //menu tercer nivel
                            switch(iseleccionMenuSueldos)
                            {
                            case 1:
                                {
                                    system("cls");
                                    nuevoEmpleadoSueldo(archivoSueldos);
                                    accion="Sueldo Creado";
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
                                    system("cls");
                                    actualizarRegistroSueldo(archivoSueldos);
                                    accion="Sueldo Actualizada";
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
                                    consultarRegistroSueldo(archivoSueldos);
                                    accion="Sueldo Consultado";
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
                                    getch();
                                }
                                break;
                            case 4:
                                {
                                    system("cls");
                                    eliminarRegistroSueldo(archivoSueldos);
                                    accion="Sueldo Eliminado";
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
                                    buscarEmpleadoSueldo(archivoSueldos);
                                    accion="Sueldo Buscado";
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
                                    imprimirRegistroSueldo(archivoSueldos);
                                    accion="Sueldo Impreso";
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
                        }while(iseleccionMenuSueldos!= 0);
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


// crear e insertar registro empresa
void nuevaEmpresa( fstream &insertarEnArchivoEmpresa)
{
   // obtener nombre de empresa a crear
   int m_iNumeroDeEmpresa= obtenerCuentaEmpresa( "Escriba el nombre de la empresa");

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivoEmpresa.seekg(
      ( m_iNumeroDeEmpresa- 1 ) * sizeof( ClsEmpresa) );

   // leer el registro del archivo
   ClsEmpresa empresa;
   insertarEnArchivoEmpresa.read( reinterpret_cast< char * >( &empresa),
      sizeof( ClsEmpresa) );

   // crear el registro, si éste no existe ya
   if ( empresa.mobtenerNumeroEmpresa() == 0 ) {
///////////////////////////////////////////////////////////////////////
        char m_sNombreEmpresa[20];
        char m_sCorreoEmpresa[20];
        char m_sNombreDirector[20];
        char m_sActividadEconomica[20];
        char m_iNitEmpresa[14];
        char m_iDireccionEmpresa[20];
        int m_iTelefonoEmpresa;
        int m_iNumeroEmpleados;
        int m_iNumeroDeEmpresa;

      // el usuario introduce
      cout << "Escriba el nombre de la empresa:" << endl;
      cin >> setw( 20 ) >> m_sNombreEmpresa;
      cout << "Escriba el correo electronico de la empresa:" << endl;
      cin >> setw( 20 ) >> m_sCorreoEmpresa;
      cout << "Escriba el nombre del director de la empresa:" << endl;
      cin >> setw( 20 ) >> m_sNombreDirector;
      cout << "Escriba actividad economica de la empresa:" << endl;
      cin >> setw( 20 ) >>m_sActividadEconomica ;
      cout << "Escriba el nit de la empresa:" << endl;
      cin >> setw( 14 ) >>m_iNitEmpresa;
      cout << "Escriba la direccion de la empresa:" << endl;
      cin >> setw( 20 ) >>m_iDireccionEmpresa;
      cout << "Escriba el telefono de la empresa:" << endl;
      cin >> setw( 9 ) >>m_iTelefonoEmpresa;
      cout << "Escriba el numero de empleados:" << endl;
      cin >> setw( 7 ) >>m_iNumeroEmpleados;
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
      insertarEnArchivoEmpresa.seekp( ( m_iNumeroDeEmpresa - 1 ) *
         sizeof( ClsEmpresa) );

      // insertar el registro en el archivo
      insertarEnArchivoEmpresa.write(
         reinterpret_cast< const char * >( &empresa ),
         sizeof( ClsEmpresa) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "el numero#" << m_iNumeroDeEmpresa
           << " ya contiene informacion." << endl;

} // fin de la función nuevoRegistro
int obtenerCuentaEmpresa( const char * const indicadorEmpresa )
{
   int m_iNumeroDeEmpresa;

   // obtener el valor del número de cuenta
   do {
      cout << indicadorEmpresa << " (1 - 100): ";
      cin >> m_iNumeroDeEmpresa;

   } while ( m_iNumeroDeEmpresa < 1 || m_iNumeroDeEmpresa > 100 );

   return m_iNumeroDeEmpresa;

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


//MOSTRAR EMPRESA
void consultarRegistroEmpresa( fstream &leerDeArchivoEmpresa )
{
   cout << left << setw( 20 ) << "Nombre" << setw( 20 ) << "Correo"<< setw( 20 )<< "Director" << setw( 20 )<< "Actividad Economica "<< setw( 14 )<< "Nit "<< setw( 20 )<< "Direccion"<< setw( 9 )<< "Telefono "<< setw( 7 )<< "Empleados "<< setw( 20 )<< "Numero de Empresa "<< setw( 14 )<< endl;


   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivoEmpresa.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsEmpresa empresa;
   leerDeArchivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
      sizeof( ClsEmpresa ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivoEmpresa.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empresa.mobtenerNumeroEmpresa() != 0 )
         mostrarLineaPantallaE(empresa);

      // leer siguiente registro del archivo de registros
      leerDeArchivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
         sizeof( ClsEmpresa ) );

   } // fin de instrucción while

} // fin de la función consultarRegistro

void mostrarLineaPantallaE( const ClsEmpresa &registroEmpresa )
{
   cout << left << setw( 20 ) << registroEmpresa.mobtenerNombreE().data()
          << setw( 20 ) << registroEmpresa.mobtenerCorreoE().data()
          << setw( 20 ) << registroEmpresa.mobtenerDirectorE().data()
          << setw( 20 ) << registroEmpresa. mobtenerActividadE().data()
          << setw( 14 ) << registroEmpresa.mobtenerNitE().data()
          << setw( 20 ) << registroEmpresa.mobtenerDireccionE().data()
          << setw( 9 ) << registroEmpresa.mobtenerTelefonoE()
          << setw( 7 ) << registroEmpresa.mobtenerNumeroEmpleadosE()
          << setw( 20 ) << registroEmpresa.mobtenerNumeroEmpresa()
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

//ACTUALIZAR EMPRESA
void actualizarRegistroEmpresa( fstream &actualizarArchivoEmpresa )
{
   // obtener el número de empresa a actualizar
   int numeroEmpresa = obtenerCuentaEmpresa( "Escriba la empresa que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivoEmpresa.seekg(
      ( numeroEmpresa - 1 ) * sizeof( ClsEmpresa ) );

   // leer el primer registro del archivo
   ClsEmpresa empresa;
   actualizarArchivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
      sizeof( ClsEmpresa ) );

   // actualizar el registro
   if ( empresa.mobtenerNumeroEmpresa() != 0 ) {
      mostrarLineaE( cout , empresa);

      // solicitar al usuario que especifique la transacción
      cout << "\nEscriba el nombre: ";
      char m_snombreEmpresa [ 20 ];
      cin >> m_snombreEmpresa;

      // actualizar el saldo del registro
      empresa.mestablecerNombreE( m_snombreEmpresa );
      mostrarLineaE( cout, empresa );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivoEmpresa.seekp(
         ( numeroEmpresa - 1 ) * sizeof( ClsEmpresa ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivoEmpresa.write(
         reinterpret_cast< const char * >( &empresa ),
         sizeof( ClsEmpresa ) );

   } // fin de instrucción if

   // mostrar error si la empresa no existe
   else
      cerr << "La empresa #" << numeroEmpresa
         << " no tiene informacion." << endl;

} // fin de la función actualizarRegistro

// mostrar registro individual
void mostrarLineaE( ostream &salida, const ClsEmpresa &registroEmpresa )
{
   salida << left << setw( 20 ) << registroEmpresa.mobtenerNombreE().data()
          << setw( 20 ) << registroEmpresa.mobtenerCorreoE().data()
          << setw( 20 ) << registroEmpresa.mobtenerDirectorE().data()
          << setw( 20 ) << registroEmpresa.mobtenerActividadE().data()
          << setw( 14 ) << registroEmpresa.mobtenerNitE().data()
          << setw( 20 ) << registroEmpresa.mobtenerDireccionE().data()
          << setw( 9 ) << registroEmpresa.mobtenerTelefonoE()
          << setw( 7 ) << registroEmpresa.mobtenerNumeroEmpleadosE()
          << setw( 20 ) << registroEmpresa.mobtenerNumeroEmpresa()
          << endl;


} // fin de la función mostrarLinea

void imprimirRegistroE( fstream &leerDeArchivoEmpresa )
{
   // crear archivo de texto
   ofstream archivoImprimirSalidaE( "imprimirE.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalidaE ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   archivoImprimirSalidaE << left << left << setw( 20 ) << "Nombre" << setw( 20 )<< "Correo"<< setw( 20 )<< "Director" << setw( 20 )<< "Actividad Economica "<< setw( 14 )<< "Nit "<< setw( 20 )<< "Direccion"<< setw( 9 )<< "Telefono "<< setw( 7 )<< "Empleados "<< setw( 20 )<< "Numero de Empresa "<< setw( 14 )<< endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivoEmpresa.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsEmpresa empresa;
   leerDeArchivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
      sizeof( ClsEmpresa ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivoEmpresa.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empresa.mobtenerNumeroEmpresa() != 0 )
         mostrarLineaE( archivoImprimirSalidaE , empresa );

      // leer siguiente registro del archivo de registros
      leerDeArchivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
         sizeof( ClsEmpresa ) );

   } // fin de instrucción while

} // fin de la función imprimirRegistro

void eliminarRegistroE( fstream &eliminarDeArchivoEmpresa)
{
   // obtener número de cuenta a eliminar
   int numeroEmpresa= obtenerCuentaEmpresa( "Escriba la empresa a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivoEmpresa.seekg(
      ( numeroEmpresa- 1 ) * sizeof( ClsEmpresa) );

   // leer el registro del archivo
   ClsEmpresa empresa;
   eliminarDeArchivoEmpresa.read( reinterpret_cast< char * >( &empresa),
      sizeof(  ClsEmpresa ) );

   // eliminar el registro, si es que existe en el archivo
   if ( empresa.mobtenerNumeroEmpresa() != 0 ) {
      ClsEmpresa empresaEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivoEmpresa.seekp( ( numeroEmpresa- 1 ) *
         sizeof( ClsEmpresa ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivoEmpresa.write(
         reinterpret_cast< const char * >( &empresaEnBlanco ),
         sizeof( ClsEmpresa ) );

      cout << "Empresa #" << numeroEmpresa<< " eliminado correctamente.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
   {
       cerr << "Empresa #" << numeroEmpresa << " esta vacia.\n";
   }
   getch();

} // fin de eliminarRegistro

void buscarEmpresa( fstream &leerDeArchivoEmpresa)
{

   // obtener el número de cuenta a buscar
   int numeroEmpresa= obtenerCuentaEmpresa( "Escriba la empresa que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   leerDeArchivoEmpresa.seekg(
      ( numeroEmpresa - 1 ) * sizeof( ClsEmpresa) );

   // leer el primer registro del archivo
   ClsEmpresa empresa;
   leerDeArchivoEmpresa.read( reinterpret_cast< char * >( &empresa ),
      sizeof( ClsEmpresa ) );
    //cout<<empleado.mobtenerClave();

   // actualizar el registro
   if ( empresa.mobtenerNumeroEmpresa() != 0 ) {
      mostrarLineaE( cout, empresa );
   }

   // mostrar error si la cuenta no existe
   else
   {
       cerr << "La empresa #" << numeroEmpresa
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


////////////////////////////////////////////////////SUELDOS////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////crear e insertar registro
void nuevoEmpleadoSueldo( fstream &insertarEnArchivoSueldo )
{
   // obtener el número de cuenta a crear
   int m_iclaveEmpleadoSueldo = obtenerCuenta( "Escriba el nuevo numero de cuenta" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivoSueldo.seekg(
      ( m_iclaveEmpleadoSueldo - 1 ) * sizeof( ClsConceptos ) );

   // leer el registro del archivo
   ClsConceptos sueldo;
   insertarEnArchivoSueldo.read( reinterpret_cast< char * >( &sueldo ),
      sizeof( ClsConceptos ) );

   // crear el registro, si éste no existe ya
   if ( sueldo.mobtenerCodigo() == 0 ) {

      char m_snombreEmpleadoSueldo[ 20 ];
      char m_sSueldo[20];
      char m_sBono[20];

      // el usuario introduce el apellido, primer nombre y saldo
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 20 ) >> m_snombreEmpleadoSueldo;
      cout << "Escriba el Sueldo: " << endl;
      cin >> setw( 20 ) >> m_sSueldo;
      cout << "Escriba el Bono: " << endl;
      cin >> setw( 20 ) >> m_sBono;

      // usar valores para llenar los valores de la cuenta
      sueldo.mestablecerNombreSueldo( m_snombreEmpleadoSueldo );
      sueldo.mestablecerCodigo( m_iclaveEmpleadoSueldo );
      sueldo.mestablecerSueldo( m_sSueldo );
      sueldo.mestablecerBono( m_sBono );


      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivoSueldo.seekp( ( m_iclaveEmpleadoSueldo - 1 ) *
         sizeof( ClsConceptos ) );

      // insertar el registro en el archivo
      insertarEnArchivoSueldo.write(
         reinterpret_cast< const char * >( &sueldo ),
         sizeof( ClsConceptos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "La cuenta #" << m_iclaveEmpleadoSueldo
           << " ya contiene informacion." << endl;

} // fin de la función nuevoRegistro
int obtenerSueldo( const char * const indicadorSueldo )
{
   int m_iclaveEmpleadoSueldo;

   // obtener el valor del número de cuenta
   do {
      cout << indicadorSueldo << " (1 - 100): ";
      cin >> m_iclaveEmpleadoSueldo;

   } while ( m_iclaveEmpleadoSueldo < 1 || m_iclaveEmpleadoSueldo > 100 );

   return m_iclaveEmpleadoSueldo;

} // fin de la función obtenerCuenta

///////////////////////////////////////////////////////////////CREACION ARCHIVO SUELDOS
void crearArchivoSueldo()
{
    ofstream archivoSueldos("RegistroSueldos.dat", ios::out | ios::binary);
    if(!archivoSueldos)
    {
        cerr<<"No se habrio el archivo"<<endl;
        exit(1);
    }
    ClsConceptos sueldoEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoSueldos.write(reinterpret_cast<const char * > (&sueldoEnBlanco), sizeof(ClsConceptos));
    }
}
/////////////////////////////////////////////////////////////////MOSTRAR DATOS SUELDOS
////////////////////////////////////////////////////////MOSTRAR
void consultarRegistroSueldo( fstream &leerDeArchivoSueldos )
{

   cout << left << setw( 9 ) << "Codigo" << setw( 20 )
       << "Nombre" << setw( 20 ) << "Sueldo"
       << setw( 20 ) << "Bono" << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivoSueldos.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsConceptos sueldo;
   leerDeArchivoSueldos.read( reinterpret_cast< char * >( &sueldo ),
      sizeof( ClsConceptos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivoSueldos.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( sueldo.mobtenerCodigo() != 0 )
         mostrarLineaPantallaSueldo(sueldo);

      // leer siguiente registro del archivo de registros
      leerDeArchivoSueldos.read( reinterpret_cast< char * >( &sueldo ),
         sizeof( ClsConceptos ) );

   } // fin de instrucción while

} // fin de la función consultarRegistro

void mostrarLineaPantallaSueldo( const ClsConceptos &registroSueldo )
{
   cout << left << setw( 10 ) << registroSueldo.mobtenerCodigo()
          << setw( 20 ) << registroSueldo.mobtenerNombreSueldo().data()
          << setw( 20 ) << registroSueldo.mobtenerSueldo().data()
          << setw( 20 ) << registroSueldo.mobtenerBono().data() << endl;

} // fin de la función mostrarLineaPantalla

///////////////////////////////////////////////////////////////////////////////////////////ACTUALIZAR
void actualizarRegistroSueldo( fstream &actualizarArchivoSueldo )
{
   // obtener el número de cuenta a actualizar
   int numeroCodigo = obtenerSueldo( "Escriba la cuenta que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivoSueldo.seekg(
      ( numeroCodigo - 1 ) * sizeof( ClsConceptos ) );

   // leer el primer registro del archivo
   ClsConceptos sueldo;
   actualizarArchivoSueldo.read( reinterpret_cast< char * >( &sueldo ),
      sizeof( ClsConceptos ) );

   // actualizar el registro
   if ( sueldo.mobtenerCodigo() != 0 ) {
      mostrarLineaSueldo( cout, sueldo );

      // solicitar al usuario que especifique la transacción
      cout << "\nEscriba el nombre: ";
      char m_snombreEmpleadoSueldo [ 20 ];
      cin >> m_snombreEmpleadoSueldo;

      cout << "\nEscriba el sueldo: ";
      char m_sSueldo [ 20 ];
      cin >> m_sSueldo;

      cout << "\nEscriba el bono: ";
      char m_sBono [ 20 ];
      cin >> m_sBono;

      // actualizar el saldo del registro
      sueldo.mestablecerNombreSueldo( m_snombreEmpleadoSueldo );
      mostrarLineaSueldo( cout, sueldo );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivoSueldo.seekp(
         ( numeroCodigo - 1 ) * sizeof( ClsConceptos ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivoSueldo.write(
         reinterpret_cast< const char * >( &sueldo ),
         sizeof( ClsConceptos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "La cuenta #" << numeroCodigo
         << " no tiene informacion." << endl;

} // fin de la función actualizarRegistro

void mostrarLineaSueldo( ostream &salidaSueldo, const ClsConceptos &registroSueldo )
{
   salidaSueldo << left << setw( 9 ) << registroSueldo.mobtenerCodigo()
          << setw( 20 ) << registroSueldo.mobtenerNombreSueldo().data()
          << setw( 20 ) << registroSueldo.mobtenerSueldo().data()
          << setw( 20 ) << registroSueldo.mobtenerBono().data()
          << endl;

} // fin de la función mostrarLinea

void imprimirRegistroSueldo( fstream &leerDeArchivoSueldo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalidaSueldo( "ImprimirRegistroSueldo.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalidaSueldo ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   archivoImprimirSalidaSueldo << left << setw( 9 ) << "Codigo" << setw( 20 )
       << "Nombre: " << setw( 20 ) << "Sueldo" << setw( 20 ) << "Bono" << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivoSueldo.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsConceptos sueldo;
   leerDeArchivoSueldo.read( reinterpret_cast< char * >( &sueldo ),
      sizeof( ClsConceptos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivoSueldo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( sueldo.mobtenerCodigo() != 0 )
         mostrarLineaSueldo( archivoImprimirSalidaSueldo, sueldo );

      // leer siguiente registro del archivo de registros
      leerDeArchivoSueldo.read( reinterpret_cast< char * >( &sueldo ),
         sizeof( ClsConceptos ) );

   } // fin de instrucción while

} // fin de la función imprimirRegistro

void eliminarRegistroSueldo( fstream &eliminarDeArchivoSueldo )
{
   // obtener número de cuenta a eliminar
   int numeroCodigo= obtenerSueldo( "Escriba la cuenta a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivoSueldo.seekg(
      ( numeroCodigo - 1 ) * sizeof( ClsConceptos ) );

   // leer el registro del archivo
   ClsConceptos sueldo;
   eliminarDeArchivoSueldo.read( reinterpret_cast< char * >( &sueldo ),
      sizeof( ClsConceptos ) );

   // eliminar el registro, si es que existe en el archivo
   if ( sueldo.mobtenerCodigo() != 0 ) {
      ClsConceptos empleadoEnBlancoSueldo;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivoSueldo.seekp( ( numeroCodigo - 1 ) *
         sizeof( ClsConceptos ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivoSueldo.write(
         reinterpret_cast< const char * >( &empleadoEnBlancoSueldo ),
         sizeof( ClsConceptos ) );

      cout << "Empleado clave #" << numeroCodigo << " eliminado correctamente.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
   {
       cerr << "Empleado clave #" << numeroCodigo << " esta vacia.\n";
   }
   getch();

} // fin de eliminarRegistro

void buscarEmpleadoSueldo( fstream &leerDeArchivoSueldo)
{

   // obtener el número de cuenta a buscar
   int numeroCodigo = obtenerSueldo( "Escriba la cuenta que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   leerDeArchivoSueldo.seekg(
      ( numeroCodigo - 1 ) * sizeof( ClsConceptos ) );

   // leer el primer registro del archivo
   ClsConceptos sueldo;
   leerDeArchivoSueldo.read( reinterpret_cast< char * >( &sueldo ),
      sizeof( ClsConceptos ) );
    //cout<<empleado.mobtenerClave();

   // actualizar el registro
   if ( sueldo.mobtenerCodigo() != 0 ) {
      mostrarLineaSueldo( cout, sueldo );
   }

   // mostrar error si la cuenta no existe
   else
   {
       cerr << "La cuenta #" << numeroCodigo
         << " no tiene informacion." << endl;
   }
   getch();

} // fin de la función consultarRegistro
