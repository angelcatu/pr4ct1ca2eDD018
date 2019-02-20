#ifndef ARBOLBB_H
#define ARBOLBB_H

#include <list>
#include <array>
#include <vector>
#include "cliente_proveedor.h"
#include "objetoarbol.h"
#include "nodobb.h"
class ArbolBB
{
public:

    ArbolBB();           
    void insertarArbolBB(Cliente_Proveedor valor);
    void mostrarEstructuraArbolBB();
    void eliminarArbolBB();
    const char* optimizarCodigoEntrada(const char *r);

    void eliminarDato(std::string dato);


protected:
    NodoBB *raiz;
    NodoBB* insertarArbolBB(NodoBB* raizSub, Cliente_Proveedor valor);   

private:
    std::vector<ObjetoArbol> listaDeValores ;
    void insertarEnListaArbolBB(int valor, std::string izq, std::string der);
    void graficarArbolBB(NodoBB *r);
    void graficarEnlaces();
    void recorridoPostOrden(NodoBB *r);

    void eliminar(std::string valor);
    NodoBB* eliminar(NodoBB *raizSub, int valor);
    NodoBB* reemplazar(NodoBB* act);
};

#endif // ARBOLBB_H
