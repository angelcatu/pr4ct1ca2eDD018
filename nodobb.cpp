#include "nodobb.h"

NodoBB::NodoBB()
{

}

NodoBB::NodoBB(Cliente_Proveedor valor){
    cliente_proveedor = valor;
    izq = der = nullptr;
}

NodoBB::NodoBB(Cliente_Proveedor valor, NodoBB* ramaIzq, NodoBB* ramaDer){
    cliente_proveedor = valor;
    izq = ramaIzq;
    der = ramaDer;
}

void NodoBB::nuevoValor(Cliente_Proveedor nuevo){
    cliente_proveedor = nuevo;
}

NodoBB * NodoBB::subArbolIzq(){
    return izq;
}

NodoBB * NodoBB::subArbolDer(){
    return der;
}

void NodoBB::ramaIzq(NodoBB* n){
    izq = n;
}

void NodoBB::ramaDer(NodoBB* n){
    der = n;
}
