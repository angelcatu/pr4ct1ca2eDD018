#include "uieliminar.h"
#include "ui_uieliminar.h"
#include <QFile>
#include <string>

#include <arbolbb.h>

#include <vector>
#include <list>
#include <QMessageBox>
#include "mainwindow.h"
#include "instanciaarbole.h"
#include "arbolbinario_global.hpp"

static  QString datos1[1000];
static  QString datos2[1000];
static  QString datos3[1000];
static  QString datos4[1000];
static  QString datos5[1000];
static  QString datos6[1000];
static  QString datos7[1000];
static  QString datos8[1000];
static  QString datos9[1000];
static  QString datos10[1000];
static  QString datos11[1000];
static  QString datos12[1000];

#define GetSize(datos1) (sizeof(datos1)/sizeof(*(datos1)))

ArbolBB bb1 = ARBOLBINARIO_GLOBAL_HPP::accederAlArbol();

void uiEliminar::setPath(QString path_){
    path = path_;    
}

QString uiEliminar::getPath(){
    return path;
}

void uiEliminar::cargarDatos(){

    MainWindow archivo ;
    QString ruta;
    ruta = archivo.getNombreArchivo();

    QFile file(ruta);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){

    }else{        
        QString txtFichero;
        txtFichero.append(file.readAll());

        QStringList ficha = txtFichero.split("\n");

        for(int i = 0; i<ficha.size()-1; i++){
            QString datosFich;
            datosFich.append(ficha.at(i));

            QStringList listaDatos = datosFich.split(";");

            for(int j = 0; j < listaDatos.size(); j++){
                if(j == 0){
                    datos1[i].append(listaDatos.at(j));
                }
                if(j == 1){
                    datos2[i].append(listaDatos.at(j));
                }
                if(j == 2){
                    datos3[i].append(listaDatos.at(j));
                }
                if(j == 3){
                    datos4[i].append(listaDatos.at(j));
                }
                if(j == 4){
                    datos5[i].append(listaDatos.at(j));
                }
                if(j == 5){
                    datos6[i].append(listaDatos.at(j));
                }
                if(j == 6){
                    datos7[i].append(listaDatos.at(j));
                }
                if(j == 7){
                    datos8[i].append(listaDatos.at(j));
                }
                if(j == 8){
                    datos9[i].append(listaDatos.at(j));
                }
                if(j == 9){
                    datos10[i].append(listaDatos.at(j));
                }
                if(j == 10){
                    datos11[i].append(listaDatos.at(j));
                }
                if(j == 11){
                    datos12[i].append(listaDatos.at(j));
                }
            }
        }


    }

    QFile close;
}
int uiEliminar::longitudVector(){
    int l = 0;
    int menos = 0;
    int iterador = 0 ;
    while(datos1[iterador] != ""){
        menos++;
        iterador++;
    }
    return l = menos;
}

uiEliminar::uiEliminar(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::uiEliminar)    
{    
    ui->setupUi(this);

    cargarDatos();

    ui->table->setHidden(false);

    ui->table->setColumnCount(12);
    QStringList l;
    l <<"Codigo"<<"Tienda"<<"Cliente_Proveedor"<<"CodigoCliente"<<"Cliente"<<"CodigoSucursal"<<"NombreSucursal"<<"Region"<<"Departamento"<<"Cantidad"<<"PrecioUnitario"<<"Costo";
    ui->table->setHorizontalHeaderLabels(l);

    ui->table->setRowCount(0);

    for(int i = 0; i < longitudVector(); i++){

        ui->table->insertRow(ui->table->rowCount());

        ui->table->setItem(ui->table->rowCount()-1, 0, new QTableWidgetItem(datos1[i]));
        ui->table->setItem(ui->table->rowCount()-1, 1, new QTableWidgetItem(datos2[i]));
        ui->table->setItem(ui->table->rowCount()-1, 2, new QTableWidgetItem(datos3[i]));
        ui->table->setItem(ui->table->rowCount()-1, 3, new QTableWidgetItem(datos4[i]));
        ui->table->setItem(ui->table->rowCount()-1, 4, new QTableWidgetItem(datos5[i]));
        ui->table->setItem(ui->table->rowCount()-1, 5, new QTableWidgetItem(datos6[i]));
        ui->table->setItem(ui->table->rowCount()-1, 6, new QTableWidgetItem(datos7[i]));
        ui->table->setItem(ui->table->rowCount()-1, 7, new QTableWidgetItem(datos8[i]));
        ui->table->setItem(ui->table->rowCount()-1, 8, new QTableWidgetItem(datos9[i]));
        ui->table->setItem(ui->table->rowCount()-1, 9, new QTableWidgetItem(datos10[i]));
        ui->table->setItem(ui->table->rowCount()-1, 10, new QTableWidgetItem(datos11[i]));
        ui->table->setItem(ui->table->rowCount()-1, 11, new QTableWidgetItem(datos12[i]));

    }
}
uiEliminar::~uiEliminar()
{
    delete ui;
}
static std::string dato = "";
void uiEliminar::on_table_cellClicked(int row, int column)
{

    QTableWidgetItem *valor = ui->table->item(row, column);
    QString item = valor->text();
    dato = item.toUtf8().constData();


}

void uiEliminar::on_btn_Eliminar_clicked()
{
    //bb1.eliminarDato(dato);
    bb.eliminarDato(dato);
    this->close();
}
