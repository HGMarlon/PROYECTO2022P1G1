//librerias
#include<string>
#include<iostream>

//C++
#ifndef CLSEMPLEADOS_H
#define CLSEMPLEADOS_H

using std::string;


class ClsEmpleados
{
    public:

        //metodos
        ClsEmpleados( int = 0, string = ""/*, string = "", string = "", string = "", string = ""*/);

        /*Funciones de los atibutos
            Fuciones de la clave del empleado*/
        void mestablecerClave( int ) ;
        int mobtenerClave() const;

        //Funciones del nombre del empleado
        void mestablecerNombre( string );
        string mobtenerNombre() const;

        //Funciones del dpi del empleado
        /*void mestablecerDpi ( string );
        string mobtenerDpi() const;

        //Funciones de la direccion del empleado
        void mestablecerDireccion ( string );
        string mobtenerDireccion() const;

        //Funciones del telefono del empleado
        void mestablecerTelefono ( string );
        string mobtenerTelefono() const;

        //Funciones del correo electronico del empleado
        void mestablecerCorreo ( string );
        string mobtenerCorreo() const;*/


    protected:

    private:

        //Atributos
        int m_iclaveEmpleado;
        char m_snombreEmpleado[ 20 ];
        /*char m_sdpiEmpleado[ 20 ];
        char m_sdireccionEmpleado[ 20 ];
        char m_stelefonoEmpleado[ 20 ];
        char m_scorreoEmpleado[ 20 ];*/
};

#endif // CLSEMPLEADOS_H
