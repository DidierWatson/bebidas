#include <SPI.h>
#include "controladorRFID.h"
#include "usuarioRFID.h"

#define SS_PIN 10
#define RST_PIN 9

ControladorRFID controladorRFID(SS_PIN, RST_PIN);

void setup() {
    Serial.begin(9600);
    controladorRFID.iniciar();
}

void loop() {
    String uid = controladorRFID.leerUID();
    if (uid != "") {
        Serial.println("Tarjeta detectada. UID: " + uid);

        UsuarioRFID* usuario = controladorRFID.verificarUsuario(uid);

        if (usuario == nullptr) {
          
            Serial.println("Usuario nuevo. Asignando animal...");
            controladorRFID.registrarUsuario(uid, "Tigre"); 
            Serial.println("Usuario registrado con animal Tigre.");
        } else {
          
            Serial.println("Usuario existente. Información: ");
            Serial.println(usuario->getInfo());
        }
    }
    delay(1000); 
}
