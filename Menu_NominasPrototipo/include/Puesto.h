#ifndef PUESTO_H
#define PUESTO_H
using namespace std;

class Puesto
{
    public:
    displayP();
    insertP();
    ingresarP();
    menu();
    modify();
    searchP();
    deletP();
        Puesto();

        virtual ~Puesto();

    protected:

    private:
        string Numero, Cargo, DepaPuesto, Salario, Nivel, HoraEntrada, HoraSalida;

};
class Menuintermedio
{
public:
    Menuxcategorias();
private:

};


#endif // PUESTO_H
