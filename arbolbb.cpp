#include <iostream>
#include <fstream>
#include "arbolbb.h"
#include <list>

std::ofstream fout("reporteArbolBB.dot");

ArbolBB::ArbolBB()
{
    raiz = nullptr;
}

static int va = -1;

const char * ArbolBB::optimizarCodigoEntrada(const char * r){

    std::string original ;
    original = r;

    std::string parte = "AB";

    if(original.length() > 0){
        std::string nueva = original.substr( 0, original.find( parte ) ) + original.substr( original.find( parte )+parte.size() );
        r = nueva.c_str();
    }

    return r;
}

void ArbolBB::insertarArbolBB(Cliente_Proveedor valor){
    raiz = insertarArbolBB(raiz, valor);
}

NodoBB * ArbolBB::insertarArbolBB(NodoBB* raizSub, Cliente_Proveedor valor){   
    if(raizSub == nullptr){
        raizSub = new NodoBB(valor);
    }else if(valor.getCodigoArticulo() < raizSub->cliente_proveedor.getCodigoArticulo()){
        NodoBB *iz;
        iz = insertarArbolBB(raizSub->subArbolIzq(), valor);
        raizSub->ramaIzq(iz);
    } else if(valor.getCodigoArticulo() > raizSub->cliente_proveedor.getCodigoArticulo()){
        NodoBB *de;
        de = insertarArbolBB(raizSub->subArbolDer(), valor);
        raizSub->ramaDer(de);
    }else{

    }
    return raizSub;
}

void ArbolBB::graficarEnlaces(){



    for(int i = 0; i < listaDeValores.size(); i++){

        if(listaDeValores[i].getIzq() == "izq" && listaDeValores[i].getDer() == "der"){
            fout<<"\n\n\""<<listaDeValores[i].getValor()<<"\":f0->\""<<listaDeValores[i+1].getValor()<<"\";"<<std::endl;
            listaDeValores[i].setIzq("null");
        }else if(listaDeValores[i].getIzq() == "izq" && listaDeValores[i].getDer() == "null"){
            fout<<"\n\n\""<<listaDeValores[i].getValor()<<"\":f0->\""<<listaDeValores[i+1].getValor()<<"\";"  <<std::endl;
            listaDeValores[i].setIzq("null");
        }else if(listaDeValores[i].getIzq() == "null" && listaDeValores[i].getDer() == "der"){
            fout<<"\n\n\""<<listaDeValores[i].getValor()<<"\":f1->\""<<listaDeValores[i+1].getValor()<<"\";"<<std::endl;
            listaDeValores[i].setDer("null");
        }else if(listaDeValores[i].getIzq() == "null" && listaDeValores[i].getDer() == "null"){
            if(listaDeValores[i].getDer() == "null" && listaDeValores[i].getIzq() == "null" && listaDeValores.size() != 2){
                //fout<<"\n\n\""<<listaDeValores[i-1].getValor()<<"\":f1->\""<<listaDeValores[i].getValor()<<"\";"  <<std::endl;
                listaDeValores.erase(listaDeValores.begin()+(i));
                i--;
                i--;
            }else if(listaDeValores.size() != 1){
                i--;
                i--;
            }

        }
    }

}

void ArbolBB::insertarEnListaArbolBB(int valor, std::string izq, std::string der){
    listaDeValores.push_back(ObjetoArbol(valor, izq, der));
}

int i = 0;
void ArbolBB::graficarArbolBB(NodoBB *r){

    if(i == 2){
        i++;
    }

        if(r != nullptr){           
            //Comenzar gráfica
            fout<<"\n\n\""<<r->cliente_proveedor.getCodigoArticulo()<<"\" [\nlabel = \"<f0>|  "<<r->cliente_proveedor.getCodigoArticulo()<<"   |<f1>\"\n shape = \"record\" \n];    "<<std::endl;

            if(r->subArbolIzq() != nullptr){

                if(r->subArbolDer() != nullptr){
                    insertarEnListaArbolBB(r->cliente_proveedor.getCodigoArticulo(),
                                           "izq", "der");
                }else{
                    insertarEnListaArbolBB(r->cliente_proveedor.getCodigoArticulo(),
                                           "izq", "null");
                }
            }else if(r->subArbolDer() != nullptr){

                if(r->subArbolIzq() != nullptr){
                    insertarEnListaArbolBB(r->cliente_proveedor.getCodigoArticulo(),
                                           "izq", "der");
                }else{
                    insertarEnListaArbolBB(r->cliente_proveedor.getCodigoArticulo(),
                                           "null", "der");
                }
            }else{
                    insertarEnListaArbolBB(r->cliente_proveedor.getCodigoArticulo(),
                                          "null", "null");
            }

            graficarArbolBB(r->subArbolIzq());
            graficarArbolBB(r->subArbolDer());
        }

}

void ArbolBB::mostrarEstructuraArbolBB(){

    i++;
    listaDeValores.clear();
    if(i == 2){
        i++;
    }


        fout<<"digraph G{\n graph[rankdir = \"TB\"\n]; \n\nnode[fontsize = \"16\"\n shape = \"elipse\"\n];"<<std::endl;

        graficarArbolBB(raiz);
        graficarEnlaces();

        fout<<"\n}"<<std::endl;
        fout.close();

        system("dot -Tpng reporteArbolBB.dot -o reporteArbolBB.png");
                system("nohup display /home/angel/Documentos/USAC/EDD/Practica2/build-Practica2-Desktop_Qt_5_11_2_GCC_64bit-Debug/reporteArbolBB.png &" );

}

void ArbolBB::recorridoPostOrden(NodoBB *r){
    if(r != nullptr){
        recorridoPostOrden(r->subArbolIzq());
        recorridoPostOrden(r->subArbolDer());
        r = nullptr;
        free(r);
    }
}

NodoBB * ArbolBB::reemplazar(NodoBB* act){
    NodoBB *a, *b;
    b = act;
    a = act->subArbolIzq();
    while(a->subArbolDer() != nullptr){
        b = a;
        a = a->subArbolDer();
    }
    //Copia en act el valor del nodo apuntado por a
    act->nuevoValor(a->cliente_proveedor);

    if(b == act){
        b->ramaIzq(a->subArbolIzq()); //Enlaza subarbol izquierdo
    }else{
        b->ramaDer(a->subArbolIzq()); //Enlaza subarbol derecho
    }

    return a;

}

NodoBB * ArbolBB::eliminar(NodoBB *raizSub, int valor){
    if(raizSub == nullptr){

    }else if(valor < raizSub->cliente_proveedor.getCodigoArticulo()){
        NodoBB* iz;
        iz = eliminar(raizSub->subArbolIzq(), valor);
        raizSub->ramaIzq(iz);
    }else if(valor > raizSub->cliente_proveedor.getCodigoArticulo()){
        NodoBB* de;
        de = eliminar(raizSub->subArbolDer(), valor);
        raizSub->ramaDer(de);
    }else{
        //Nodo encontrado
        NodoBB *q;
        q = raizSub;

        if(q->subArbolIzq()== nullptr){
            raizSub = q->subArbolDer();
        }else if(q->subArbolDer() == nullptr){
            raizSub = q->subArbolIzq();
        }else{
            q = reemplazar(q);
        }
        q = nullptr;
    }

    return raizSub;
}


void ArbolBB::eliminar(std::string valor){

        int val = std::stoi(valor);
        raiz = eliminar(raiz, val);        
}

void ArbolBB::eliminarDato(std::string dato){
    std::string original = dato;
    std::string parte = "AB";

    if(original.length() > 0){
        std::string nueva = original.substr( 0, original.find( parte ) ) + original.substr( original.find( parte )+parte.size() );
        dato = nueva;
    }

    eliminar(dato);

}





void ArbolBB::eliminarArbolBB(){
        recorridoPostOrden(raiz);
}
