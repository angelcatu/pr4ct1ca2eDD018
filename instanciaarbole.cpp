#include "instanciaarbole.h"
#include "arbolbb.h"



InstanciaArbole::InstanciaArbole()
{
}
ArbolBB  InstanciaArbole::getArbol(){

    static ArbolBB bb = ArbolBB{};
    return bb;
}




