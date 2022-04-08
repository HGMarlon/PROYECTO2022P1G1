#include<cstring>
#include<string>
#ifndef CLSEMPLEADOS_H
#define CLSEMPLEADOS_H
using namespace std;

class ClsEmpleados
{
    public:
        //metodos
        ClsEmpleados();
        mAgregarEmpleado();
        mIngresarEmpleado();
        /*display();
        menu();
        modify();
        searchE();
        deletE();*/
        virtual ~ClsEmpleados();

    protected:

    private:
        //atributos
        string m_sNombreEmpleado/*, m_sCodigoIdentificacion, m_sResidenciaEmpleado, m_sResidenciaEmpleado, m_sDireccionEmpleado, m_sTelefonoEmpleado, m_sCorreoEmpleado, m_sTelefonoEmergenciaEmpleado*/;
};

#endif // CLSEMPLEADOS_H
