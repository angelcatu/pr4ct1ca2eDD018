#ifndef OBJETOARBOL_H
#define OBJETOARBOL_H

#include <string>

class ObjetoArbol
{
public:
    ObjetoArbol();
    ObjetoArbol(int valor_, std::string izq_, std::string der_);

    int getValor();
    std::string getIzq();
    std::string getDer();
    void setIzq(std::string val_);
    void setDer(std::string val_);

private:
    int valor;
    std::string izq;
    std::string der;
};

#endif // OBJETOARBOL_H
