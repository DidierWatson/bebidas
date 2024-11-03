#ifndef USUARIORFID_H
#define USUARIORFID_H

#include <Arduino.h>

class UsuarioRFID {
public:
    String uid;
    String nombreAnimal;
    String intensidad;
    int cantidadBebidas; 

    UsuarioRFID(String _uid, String _nombreAnimal) 
        : uid(_uid), nombreAnimal(_nombreAnimal), cantidadBebidas(0) {}

    void setPreferencias(String _intensidad);

    void incrementarBebidas() {
        cantidadBebidas++;
    }
    
    String getInfo();
};

#endif