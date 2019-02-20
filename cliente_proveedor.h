#ifndef CLIENTE_PROVEEDOR_H
#define CLIENTE_PROVEEDOR_H

#include <string.h>

#include <QObject>

class Cliente_Proveedor
{
public:
    Cliente_Proveedor();

        Cliente_Proveedor(int CodigoArticulo_, std::string Tienda_, std::string CLIENTE_PROVEEDOR_,
        std::string CodigoCliente_, std::string NombreCliente_, std::string CodigoSucursal_,
        std::string NombreSucursal_, std::string Region_, std::string Departamento_,
        int Cantidad_, float PrecioUnitario_, float Costo_);

     //Métodos Get
    int getCodigoArticulo();
    std::string getTienda();
    std::string getCLIENTE_PROVEEDOR();
    std::string getCodigoCliente();
    std::string getNombreCliente();
    std::string getCodigoSucursal();
    std::string getNombreSucursal();
    std::string getRegion();
    std::string getDepartamento();
    int getCantidad();
    float getPrecioUnitario();
    float getCosto();

    //Métodos Set
    void setCodigoArticulo(int CodigoArticulo_);
    void setTienda(std::string Tienda_);
    void setCLIENTE_PROVEEDOR(std::string CLIENTE_PROVEEDOR_);
    void setCodigoCliente(std::string CodigoCliente_);
    void setNombreCliente(std::string NombreCliente_);
    void setCodigoSucursal(std::string CodigoSucursal_);
    void setNombreSucursal(std::string NombreSucursal_);
    void setRegion(std::string Region_);
    void setDepartamento(std::string Departamento_);
    void setCantidad(int Cantidad_);
    void setPrecioUnitario(float PrecioUnitario_);
    void setCosto(float Costo_);

private:

    //Variables
    int CodigoArticulo;
    std::string Tienda;
    std::string CLIENTE_PROVEEDOR;
    std::string CodigoCliente;
    std::string NombreCliente;
    std::string CodigoSucursal;
    std::string NombreSucursal;
    std::string Region;
    std::string Departamento;
    int Cantidad;
    float PrecioUnitario;
    float Costo;

};

#endif // CLIENTE_PROVEEDOR_H
