#include "usuarioRFID.h"
#include <Arduino.h>

void UsuarioRFID::setPreferencias(String _intensidad){
        this->intensidad = _intensidad;
}

String UsuarioRFID::getInfo() {
        return "ID: " + uid + ", Animal: " + nombreAnimal + ", Bebida: " +
               ", Intensidad: " + intensidad + ", Cantidad de Bebidas: " + String(cantidadBebidas);
}