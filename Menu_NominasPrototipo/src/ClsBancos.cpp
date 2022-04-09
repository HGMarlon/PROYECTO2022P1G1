#include "ClsBancos.h"

#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

ClsBancos::ClsBancos(string valorNombre, int valorNumero, string valorUsuario, int valorSaldo, string valorTipo)
{
    mestablecerNombreBanco(valorNombre);
    mestablecerNumeroCuenta(valorNumero);
    mestablecerNombreUsuario(valorUsuario);
    mestablecerSaldoCuenta(valorSaldo);
    mestablecerTipoCuenta(valorTipo);
}

string ClsBancos::mobtenerNombre() const
{
    return m_sNombreBanco;
}


void ClsBancos::mestablecerNombreBanco( string nombrestring )
{

   const char *valorNombre = nombrestring.data();
   int longitud = strlen( valorNombre );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sNombreBanco, valorNombre, longitud );


   m_sNombreBanco[ longitud ] = '\0';

}

int ClsBancos::mobtenerNumero() const
{
    return m_iNumeroCuenta;
}

void ClsBancos::mestablecerNumeroCuenta (int valorNumero)
{
    m_iNumeroCuenta = valorNumero;
}

string ClsBancos::mobtenerUsuario() const
{
    return m_sNombreUsuario;
}


void ClsBancos::mestablecerNombreUsuario( string usuariostring )
{

   const char *valorUsuario = usuariostring.data();
   int longitud = strlen( valorUsuario );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sNombreUsuario, valorUsuario, longitud );


   m_sNombreUsuario[ longitud ] = '\0';

}

int ClsBancos::mobtenerSaldo() const
{
    return m_iSaldoCuenta;
}

void ClsBancos::mestablecerSaldoCuenta (int valorSaldo)
{
    m_iSaldoCuenta = valorSaldo;
}


string ClsBancos::mobtenerTipo() const
{
    return m_sTipoCuenta;
}


void ClsBancos::mestablecerTipoCuenta( string tipocuentastring )
{

   const char *valorTipo = tipocuentastring.data();
   int longitud = strlen( valorTipo );
   longitud = ( longitud < 20 ? longitud : 19 );
   strncpy( m_sTipoCuenta, valorTipo, longitud );


   m_sTipoCuenta[ longitud ] = '\0';

}

ClsBancos::mAgregarBanco()
{
	int iespacios=0;
	system("cls");
	ofstream archivoBancos("registrosbancos.dat", ios::app | ios::out | ios::binary);
	if( !archivoBancos )
    {
        cerr << "No se pudo abrir el archivo registro bancos." << endl;
        exit( EXIT_FAILURE );
    }
	ClsBancos banco;
	cout<<"ingrese una nuevo numero de cuenta: (0-cancelar)";
	cin>>m_iNumeroCuenta;
    while(m_iNumeroCuenta!=0)
    {
        cout<<"Agregar nuevo Banco"<<endl;
        cout<<"Ingresa el nombre del banco: " << endl;
        cin>> m_sNombreBanco;
        cout<<"Ingresa el nombre del usuario : ";
        cin>>m_sNombreUsuario;
        cout<<"Ingresa el numero del saldo de la cuenta : ";
        cin>>m_iSaldoCuenta;
        cout<<"Ingresa el tipo de cuenta : ";
        cin>>m_sTipoCuenta;

        banco.mestablecerNombreBanco(m_sNombreBanco);
        banco.mestablecerNumeroCuenta(m_iNumeroCuenta);
        banco.mestablecerNombreUsuario(m_sNombreUsuario);
        banco.mestablecerSaldoCuenta(m_iSaldoCuenta);
        banco.mestablecerTipoCuenta(m_sTipoCuenta);
        archivoBancos.seekp((banco.mobtenerNumero() - 1 ) * sizeof(ClsBancos));
        archivoBancos.write(reinterpret_cast<const char * > (&banco), sizeof (ClsBancos));
        cout<<"ingrese nuevo numero de cuenta: (0-salir)";
        cin>>m_iNumeroCuenta;
    }

	/*cout<<"Ingresa el numero de DPI del empleado: ";
	cin>>m_sDpiEmpleado;
	cout<<"Ingresa la dirección de residencia del empleado: ";
	cin>>m_sDireccionEmpleado;
	cout<<"Ingresa el número de telefono del empleado: ";
	cin>>m_sTelefonoEmpleado;
	cout<<"Ingresa el correo electronico del empleado: ";
	cin>>m_sCorreoEmpleado;
	archivoEmpleados.close();*/
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

ClsBancos::mDespliegueBanco()
{
	system("cls");
	ifstream archivoBancos("registrosebanco.dat", ios::in | ios:: binary);
	int total=0;
	cout<<"Tabla de Detalles de Bancos"<<endl;
	if(!archivoBancos)
	{
		cerr << "No se pudo abrir el archivo registro bancos." << endl;
        exit( EXIT_FAILURE );
	}
	else
	{
		ClsBancos banco;
		while(!archivoBancos.eof())
		{
			total++;
			cout<<"Nombre: "<<banco.mobtenerNombre() <<endl;
			cout<<"Cuenta: "<<banco.mobtenerNumero() <<endl;
		}
		if(total==0)
		{
			cout<<"No hay informacion...";
		}
	}
	archivoBancos.close();
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
ClsBancos::mMenuBancos()
{
    ClsBancos banco;
    int iSeleccionMenuBanco;
	do
    {
	system("cls");

	cout<<"-------------------------------"<<endl;
	cout<<"|   SISTEMA GESTION BANCOS    |"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"1. Ingreso Bancos"<<endl;
	cout<<"2. Despliegue Bancos"<<endl;
	cout<<"3. Modifica Bancos"<<endl;
	cout<<"4. Busca Bancos"<<endl;
	cout<<"5. Borra Bancos"<<endl;
	cout<<"0. Volver al menu superior"<<endl;

	cout<<"-------------------------------"<<endl;
	cout<<"Opcion a escoger:[1/2/3/4/5/0]"<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>iSeleccionMenuBanco;

    switch(iSeleccionMenuBanco)
    {
    case 1:
        banco.mAgregarBanco();
        break;
	case 2:
		banco.mDespliegueBanco();
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
	case 0:
		break;
	default:
		cout<<"Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
    }while(iSeleccionMenuBanco!= 0);
}


ClsBancos::~ClsBancos()
{
    //dtor
}
