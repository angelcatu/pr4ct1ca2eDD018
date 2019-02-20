#include "arbolbinario_global.hpp"
#include "arbolbb.h"

ArbolBB &accederAlArbol(){
    int i= 0;
    int a = 0;
    i++;
    if(i == 2){
        a++;
    }
    static ArbolBB bb = ArbolBB();
    return bb;
}




