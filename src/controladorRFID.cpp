#include <Arduino.h>
#include <MFRC522.h>
#include <controladorRFID.h>


void ControladorRFID::iniciar(){
        SPI.begin();
        rfid.PCD_Init();
}

String ControladorRFID::leerUID(){
        if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()){
                return "";
        }
        String uid = "";
        for (byte i = 0; i < rfid.uid.size; i++) {
                uid += String(rfid.uid.uidByte[i], HEX);
        }
        rfid.PICC_HaltA();
        return uid;
}

UsuarioRFID *ControladorRFID::verificarUsuario(String uid) {
        for (int i = 0; i < contadorUsuarios; i++) {
            if (usuariosRegistrados[i]->uid == uid) {
                return usuariosRegistrados[i];
            }
        }
        return nullptr;
}

void ControladorRFID::registrarUsuario(String uid, String nombreAnimal) {
        if (contadorUsuarios < MAX_USUARIOS) {
            usuariosRegistrados[contadorUsuarios] = new UsuarioRFID(uid, nombreAnimal);
            contadorUsuarios++;
            Serial.println("Usuario registrado exitosamente.");
        } else {
            Serial.println("Error: Capacidad máxima de usuarios alcanzada.");
        }     
}