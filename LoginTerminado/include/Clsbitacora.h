#ifndef CLSBITACORA_H
#define CLSBITACORA_H


class Clsbitacora
{
    public:
        Clsbitacora( int = 0);

        void mestablecerCodigo( int ) ;
        int mobtenerCodigo() const;

        virtual ~Clsbitacora();

    protected:

    private:
        int m_icodigo;
};

#endif // CLSBITACORA_H
