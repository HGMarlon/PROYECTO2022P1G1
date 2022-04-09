#include <fstream>
#include <iostream>

#include "ClsPrueba.h"

using namespace std;
int main()
{
    ClsPrueba a1,a2,a3;

    a1.pedirAlumno();
    a2.pedirAlumno();

    ofstream archivo("prueba.dat", ios::binary | ios::out | ios::app);
    archivo.write((char *) &a1, sizeof(ClsPrueba));
    archivo.write((char *) &a2, sizeof(ClsPrueba));
    archivo.close();


    ifstream leerarchivo("prueba.dat", ios::binary);
    leerarchivo.seekg(sizeof(0));
    leerarchivo.read((char *) &a3, sizeof(ClsPrueba));

    ////////////////////////////////////////////////////////////////////////////////////////
    /*int e=10;
    float f=12.5;

    fstream archivo("prueba.dat", ios::binary | ios::out | ios::app);
    archivo.write((char *) &e, sizeof(int));
    archivo.write((char *) &f, sizeof(float));
    cout<<"El entero: "<<e<<endl;
    cout<<"El float: "<<f<<endl;
    archivo.close();*/

    return 0;
}
