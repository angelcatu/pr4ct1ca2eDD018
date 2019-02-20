    #include "cliente_proveedor.h"

Cliente_Proveedor::Cliente_Proveedor()
{

}

Cliente_Proveedor::Cliente_Proveedor(int CodigoArticulo_, std::string Tienda_, std::string CLIENTE_PROVEEDOR_,
                                     std::string CodigoCliente_, std::string NombreCliente_, std::string CodigoSucursal_,
                                     std::string NombreSucursal_, std::string Region_, std::string Departamento_,
                                     int Cantidad_, float PrecioUnitario_, float Costo_){
    CodigoArticulo = CodigoArticulo_;
    Tienda = Tienda_;
    CLIENTE_PROVEEDOR = CLIENTE_PROVEEDOR_;
    CodigoCliente = CodigoCliente_;
    NombreCliente = NombreCliente_;
    CodigoSucursal = CodigoSucursal_;
    NombreSucursal = NombreSucursal_;
    Region = Region_;
    Departamento = Departamento_;
    Cantidad = Cantidad_;
    PrecioUnitario = PrecioUnitario_;
    Costo = Costo_;
}

//Métodos Get
int Cliente_Proveedor::getCodigoArticulo(){
    return CodigoArticulo;
}

std::string Cliente_Proveedor::getTienda()    {
    return Tienda;
}

std::string Cliente_Proveedor::getCLIENTE_PROVEEDOR(){
    return CLIENTE_PROVEEDOR;
}

std::string Cliente_Proveedor::getCodigoCliente(){
    return CodigoCliente;
}

std::string Cliente_Proveedor::getNombreCliente(){
    return NombreCliente;
}

std::string Cliente_Proveedor::getCodigoSucursal(){
    return CodigoSucursal;
}

std::string Cliente_Proveedor::getNombreSucursal(){
    return  NombreSucursal;
}

std::string Cliente_Proveedor::getRegion(){
    return Region;
}

std::string Cliente_Proveedor::getDepartamento(){
    return Departamento;
}

int Cliente_Proveedor::getCantidad(){
    return Cantidad;
}

float Cliente_Proveedor::getPrecioUnitario(){
    return PrecioUnitario;
}

float Cliente_Proveedor::getCosto(){
    return Costo;
}

//****************************


//Métodos Set
void Cliente_Proveedor::setCodigoArticulo(int CodigoArticulo_){
    CodigoArticulo = CodigoArticulo_;
}

void Cliente_Proveedor::setTienda(std::string Tienda_){
    Tienda = Tienda_;
}

void Cliente_Proveedor::setCLIENTE_PROVEEDOR(std::string CLIENTE_PROVEEDOR_){
    CLIENTE_PROVEEDOR = CLIENTE_PROVEEDOR_;
}

void Cliente_Proveedor::setCodigoCliente(std::string CodigoCliente_){
    CodigoCliente = CodigoCliente_;
}

void Cliente_Proveedor::setNombreCliente(std::string NombreCliente_){
    NombreCliente = NombreCliente_;
}

void Cliente_Proveedor::setCodigoSucursal(std::string CodigoSucursal_){
    CodigoSucursal = CodigoSucursal_;
}

void Cliente_Proveedor::setNombreSucursal(std::string NombreSucursal_){
    NombreSucursal = NombreSucursal_;
}

void Cliente_Proveedor::setRegion(std::string Region_){
    Region = Region_;
}

void Cliente_Proveedor::setDepartamento(std::string Departamento_){
    Departamento = Departamento_;
}

void Cliente_Proveedor::setCantidad(int Cantidad_){
    Cantidad = Cantidad_;
}

void Cliente_Proveedor::setPrecioUnitario(float PrecioUnitario_){
    PrecioUnitario = PrecioUnitario_;
}

void Cliente_Proveedor::setCosto(float Costo_){
    Costo = Costo_;
}
