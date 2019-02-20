#ifndef NODOBB_H
#define NODOBB_H

#include "cliente_proveedor.h"

class NodoBB
{
public:
    NodoBB();
    NodoBB(Cliente_Proveedor valor);
    NodoBB(Cliente_Proveedor valor, NodoBB* ramaIzq, NodoBB* ramaDer);

    //Operaciones de acceso
    NodoBB* subArbolIzq();
    NodoBB* subArbolDer();

    //Operaciones de modificación
    void nuevoValor(Cliente_Proveedor nuevo);
    void ramaIzq(NodoBB* n);
    void ramaDer(NodoBB* n);

    Cliente_Proveedor cliente_proveedor;
protected:
    NodoBB *izq, *der;
};

#endif // NODOBB_H
