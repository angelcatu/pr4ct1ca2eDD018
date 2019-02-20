#include "nodoavl.h"

NodoAVL::NodoAVL()
{

}

NodoAVL::NodoAVL(Cliente_Proveedor cliente_proveedor_){
    cliente_proveedor = cliente_proveedor_;
    izq = der = nullptr;
    fe = 0;
}

NodoAVL::NodoAVL(Cliente_Proveedor cliente_proveedor_, int vfe){
    cliente_proveedor = cliente_proveedor_;
    izq = der = nullptr;
    fe = vfe;
}

NodoAVL::NodoAVL(NodoAVL* ramaIzq, Cliente_Proveedor valor, NodoAVL* ramaDer){
    cliente_proveedor = valor;
    izq = ramaIzq;
    der = ramaDer;
    fe = 0;
}

NodoAVL::NodoAVL(NodoAVL* ramaIzq, int vfe, Cliente_Proveedor valor, NodoAVL* ramaDer){
    cliente_proveedor = valor;
    izq = ramaIzq;
    der = ramaDer;
    fe = vfe;
}

//Operaciones de acceso

Cliente_Proveedor NodoAVL::valorNodo(){
    return cliente_proveedor;
}

NodoAVL * NodoAVL::subArbolIzq(){
    return izq;
}

NodoAVL * NodoAVL::subArbolDer(){
    return der;
}

void NodoAVL::nuevoValor(Cliente_Proveedor nuevo){
    cliente_proveedor = nuevo;
}

void NodoAVL::ramaIzq(NodoAVL* n){
    izq = n;
}

void NodoAVL::ramaDer(NodoAVL* n){
    der = n;
}

void NodoAVL::Pfe(int vfe){
    fe = vfe;
}

int NodoAVL::Ofe(){
    return fe;
}



