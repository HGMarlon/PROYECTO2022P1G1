#include "Clsbitacora.h"

Clsbitacora::Clsbitacora(int valorCodigo)
{
    mestablecerCodigo(valorCodigo);
}

//Funciones de la clave del empleado
int Clsbitacora::mobtenerCodigo() const
{
    return m_icodigo;
}

void Clsbitacora::mestablecerCodigo (int icodigo)
{
    m_icodigo = icodigo;
}

Clsbitacora::~Clsbitacora()
{
    //dtor
}
