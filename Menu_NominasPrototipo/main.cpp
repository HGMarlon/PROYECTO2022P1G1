//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
//Clases
#include "ClsEmpleados.h"
#include "ClsPuestos.h"

using namespace std;

main(){
    //Variables
    int imenuPrincipal;
    int m_iclaveEmpleado=0;
    char m_snombreEmpleado[0];

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
                                    /*ofstream archivoEmpleados("registrosempleados.txt", ios::app | ios::out | ios::binary);
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
                                        archivoEmpleados << left << setw( 9 ) << "Clave" << setw( 20 )
                                        << "Nombre" << endl;
                                        cout<<"Datos almacenados con éxito";
                                        cout<<"ingrese nueva clave: (0-salir)";
                                        cin>>m_iclaveEmpleado;
                                    }
                                    archivoEmpleados.close();*/
                                }
                                break;
                            case 2:
                                //empleado.mdespliegueEmpleado();
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
