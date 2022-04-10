#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>

using namespace std;

int main(){
//char Usuario[15];
//char Contra[15];
int contador=0;
//string contra1;
string Usuario, Contra;
    bool ingresa=false;
    do{
        system("cls");
        cout<<"---------------------------"<<endl;
        cout<<" AUTENTICACION DE USUARIOS "<<endl;
        cout<<"---------------------------"<<endl;
       cout<<"Ingrese su usuario  :";
       getline(cin,Usuario);
//cin>>Usuario;
cout<<"Ingrese su contraseña  :";
//cin>>Contra;

fstream archivoUsuario("Usuario.dat",ios::app| ios::out |ios::binary);
archivoUsuario.write((char*)&Usuario, sizeof(Usuario));
archivoUsuario.close();

fstream archivoContra("Contraseña.dat",ios::app| ios::out |ios::binary);
archivoContra.write((char*)&Contra, sizeof(Contra));
archivoContra.close();
        char caracter;
        caracter = getch();
        Contra="";
        while (caracter != 13) //ASCII TECLA ENTER
        {
            if (caracter != 8) //ASCII TECLA RETROCESO
            {
                Contra.push_back(caracter);
                cout<<"*";
            } else
            {
                if (Contra.length() > 0)
                {
                    cout<<"\b \b"; //Efecto caracter borrado en pantalla
                    Contra = Contra.substr(0,Contra.length()-1); //Toma todos los caracteres menos el ultimo
                }
            }
            caracter = getch();
        }
        //instancia de clase USUARIOS, para consultar: primero se consulta el usuario, si existe, se consulta la contraseña
        if (Usuario==Usuario && Contra==Contra){
            ingresa=true;
            //bitacora.setRegistro(usuario, "Login correcto");
        } else {
            cout<<"\nEl usuario y/o contrasena son incorrectos"<<endl;
            cin.get();
            contador++;
            //bitacora.setRegistro(usuario, "Login incorrecto");
        }
    } while (ingresa==false && contador<3);
    if (ingresa==false){
        cout<<"\nLo siento, no puede ingresar al sistema, sus contrasenas son invalidas o agoto intentos"<<endl;
        cin.get();
    } else {
        cout<<"\n=== Bienvenido al Sistema ==="<<endl;
        cin.get();
    }
    return ingresa;


return 0;
}
