#ifndef MENUNOMINAS_H
#define MENUNOMINAS_H
#include <string>
#include <iostream>
using namespace std;
using std::string;

class menuNominas
{
    public:


        menuNominas();
        virtual ~menuNominas();

    protected:

    private:

};

class persona
{
    public:
        persona();
        void menuM();
		void insertA();
		void display();
    protected:

    private:
        string dpi,name,phone,college,noAfiliacion,address;

};

#endif // MENUNOMINAS_H
