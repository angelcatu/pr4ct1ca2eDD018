#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>

#include "cliente_proveedor.h"
#include "arbolbb.h"
#include "uieliminar.h"
#include "instanciaarbole.h"
#include "arbolbinario_global.hpp"

ArbolBB bb = ARBOLBINARIO_GLOBAL_HPP::accederAlArbol();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    ui->statusBar->showMessage("Listo");
}

MainWindow::~MainWindow()
{    
    delete ui;
}

static QString nombreArchivo ;

 QString MainWindow::getNombreArchivo(){
    return nombreArchivo;
}

void MainWindow::on_actionAbrir_triggered()
{
    nombreArchivo = QFileDialog::getOpenFileName(this,"Abrir Archivos","/home","Archivos CSV (*.csv)");

        if(!nombreArchivo.isEmpty()) {

            QFile archivo(nombreArchivo);

            if(archivo.open(QFile::ReadOnly))

                ui->txtArea->setPlainText(archivo.readAll());

        }
}

void MainWindow::on_actionAcerca_de_triggered()
{
    QMessageBox msg;

    msg.setText("Bonitos y Gorditos \n Version 1.0 \n Desarrollando por Angel Elias \n FIUSAC 2018");
    msg.exec();
}

static QString tienda;


int tamanioChar(char * cadena){
    int tamanio = 0;
    while(cadena != nullptr){
        tamanio++;
        cadena = strtok(nullptr, ";");
    }
    return tamanio;
}
void insertarDatosAObjeto(int CodigoArticulo_, std::string Tienda_, std::string CLIENTE_PROVEEDOR_,
                          std::string CodigoCliente_, std::string NombreCliente_, std::string CodigoSucursal_,
                          std::string NombreSucursal_, std::string Region_, std::string Departamento_,
                          int Cantidad_, float PrecioUnitario_, float Costo_){

        Cliente_Proveedor cp = Cliente_Proveedor(CodigoArticulo_, Tienda_, CLIENTE_PROVEEDOR_,
                                                     CodigoCliente_, NombreCliente_, CodigoSucursal_,
                                                     NombreSucursal_, Region_, Departamento_,
                                                     Cantidad_, PrecioUnitario_, Costo_);

        bb.insertarArbolBB(cp);                
}


void dividirCadena(std::string cadena){

    const char *texto;
    char * aux = new char[cadena.length()+1];
    strcpy(aux, cadena.c_str());

    texto = strtok(aux, ";\n" );
    int columna = -1;

    int CodigoArticulo = 0;
    std::string Tienda;
    std::string CLIENTE_PROVEEDOR_;
    std::string CodigoCliente_;
    std::string NombreCliente_;
    std::string CodigoSucursal_;
    std::string NombreSucursal_;
    std::string Region_;
    std::string Departamento_;
    int Cantidad_ = 0;
    float PrecioUnitario_ = 0;
    float Costo_ = 0;

    while(texto != nullptr){
        columna++;

        if(texto != "\n"){

            switch (columna) {
            case 0:
                texto = bb.optimizarCodigoEntrada(texto);
                CodigoArticulo = std::atoi(texto);
                break;
            case 1:
            {
                    std::string str(texto);
                    Tienda = str;
            }
                break;
            case 2:
            {
                std::string str(texto);
                CLIENTE_PROVEEDOR_ = str;
            }
                break;
            case 3:
            {
                std::string str(texto);
                CodigoCliente_ = str;
            }
                break;
            case 4:
            {
                std::string str(texto);
                NombreCliente_ = str;
            }
                break;
            case 5:
            {
                std::string str(texto);
                CodigoSucursal_ = str;
            }
                break;
            case 6:
            {
                std::string str(texto);
                NombreSucursal_ = str;
            }
                break;
            case 7:
            {
                std::string str(texto);
                Region_ = str;
            }
                break;
            case 8:
            {
                std::string str(texto);
                Departamento_ = str;
            }
                break;
            case 9:

                Cantidad_ = std::atoi(texto);
                break;
            case 10:
                PrecioUnitario_ = std::stof(texto);
                break;
            case 11:
                Costo_ = std::stof(texto);
                if(texto[columna+1] != NULL){
                    columna = -1;
                    insertarDatosAObjeto(CodigoArticulo, Tienda, CLIENTE_PROVEEDOR_, CodigoCliente_,
                                         NombreCliente_, CodigoSucursal_, NombreSucursal_, Region_,
                                         Departamento_, Cantidad_, PrecioUnitario_, Costo_);


                }else{
                    insertarDatosAObjeto(CodigoArticulo, Tienda, CLIENTE_PROVEEDOR_, CodigoCliente_,
                                         NombreCliente_, CodigoSucursal_, NombreSucursal_, Region_,
                                         Departamento_, Cantidad_, PrecioUnitario_, Costo_);
                }
                break;
            }
            texto = strtok(nullptr, ";\n");
        }




    }
}

void MainWindow::on_btnAnalizar_clicked()
{
    // 1. Analizar el archivo de entrada
    // 2. Separar los datos y agregarlos a un nuevo objeto
    // 3. Insertar objeto en árbol bb

    if(ui->rbtnArbolBB->isChecked()){
        QString texto = ui->txtArea->toPlainText();

        if(texto != nullptr){
            std::string cadena = texto.toUtf8().constData();
            dividirCadena(cadena);
            ui->rbtnArbolBB->setEnabled(false);
            ui->boxBusqueda->setEnabled(true);
            ui->btnIniciar->setEnabled(true);
        }

    }else if(ui->rdBtnArbolAVL->isChecked()){


    }else{
        QMessageBox msg;

        msg.setText("Seleccione una estructura para continuar");
        msg.exec();
    }
}


void MainWindow::on_actionMostrar_rbol_triggered()
{
    if(ui->rbtnArbolBB->isChecked()){           
           bb.mostrarEstructuraArbolBB();
    }else if(ui->rdBtnArbolAVL->isChecked()){

    }
}

void MainWindow::on_actionEliminar_EDD_triggered()
{
    if(!ui->rbtnArbolBB->isEnabled()){
        //Eliminar arbolBB
        bb.eliminarArbolBB();
        ui->rbtnArbolBB->setEnabled(true);
    }
}

void MainWindow::on_actionEliminar_datos_triggered()
{
    uiEliminar ui;
    ui.setModal(true);
    ui.setPath(nombreArchivo);
    ui.exec();
}

void MainWindow::on_actionAnalizar_triggered()
{
    if(ui->rbtnArbolBB->isChecked()){
        QString texto = ui->txtArea->toPlainText();

        if(texto != nullptr){
            std::string cadena = texto.toUtf8().constData();
            dividirCadena(cadena);
            ui->rbtnArbolBB->setEnabled(false);
            ui->boxBusqueda->setEnabled(true);
            ui->btnIniciar->setEnabled(true);
        }

    }else if(ui->rdBtnArbolAVL->isChecked()){


    }else{
        QMessageBox msg;

        msg.setText("Seleccione una estructura para continuar");
        msg.exec();
    }
}

void MainWindow::on_actionCerrar_triggered()
{
    this->close();
}
