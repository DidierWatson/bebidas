#ifndef CONTROLADORRFID_H
#define CONTROLADORRFID_H

#include <Arduino.h>
#include <MFRC522.h>
#include "usuarioRFID.h"

#define MAX_USUARIOS 30


class ControladorRFID {
private:
    MFRC522 rfid;
    MFRC522::MIFARE_Key key;
    UsuarioRFID* usuariosRegistrados[MAX_USUARIOS];
    int contadorUsuarios;

public:
    ControladorRFID(byte ssPin, byte rstPin) : rfid(ssPin, rstPin) {}
    void iniciar();
    String leerUID();
    UsuarioRFID* verificarUsuario(String uid);
    void registrarUsuario(String uid, String nombreAnimal);
};

#endif