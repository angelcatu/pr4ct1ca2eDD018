#include "objetoarbol.h"
#include <string>

ObjetoArbol::ObjetoArbol()
{

}

ObjetoArbol::ObjetoArbol(int valor_, std::string izq_, std::string der_){
    valor = valor_;
    izq = izq_;
    der = der_;
}

int ObjetoArbol::getValor(){
    return valor;
}

std::string ObjetoArbol::getIzq(){
    return izq;
}

std::string ObjetoArbol::getDer(){
    return der;
}

void ObjetoArbol::setIzq(std::string val_){
    izq = val_;
}

void ObjetoArbol::setDer(std::string val_){
    der = val_;
}

