#ifndef NODOAVL_H
#define NODOAVL_H

#include "cliente_proveedor.h"

class NodoAVL
{
public:
    NodoAVL();
    NodoAVL(Cliente_Proveedor cliente_proveedor_);
    NodoAVL(Cliente_Proveedor cliente_proveedor_, int vfe);
    NodoAVL(NodoAVL* ramaIzq, Cliente_Proveedor valor, NodoAVL* ramaDer);
    NodoAVL(NodoAVL* ramaIzq, int vfe, Cliente_Proveedor valor, NodoAVL* ramaDer);


    //Operaciones de acceso
    Cliente_Proveedor valorNodo();
    NodoAVL* subArbolIzq();
    NodoAVL* subArbolDer();
    void nuevoValor(Cliente_Proveedor nuevo);
    void ramaIzq(NodoAVL* n);
    void ramaDer(NodoAVL* n);
    void Pfe(int vfe);
    int Ofe();

protected:
    Cliente_Proveedor cliente_proveedor;
    NodoAVL *izq;
    NodoAVL *der;
    int fe;
};

#endif // NODOAVL_H
