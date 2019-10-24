#include "banco_colas.h"

int main() {

    STR_COLA colaComun;
    STR_COLA colaPremium;

    crearCola(&colaComun);
    crearCola(&colaPremium);

    while(totemTurnos(&colaPremium, &colaComun));

    if(!isEmpty(&colaPremium)){
        mostrarCola(&colaPremium);
    }
    if(!isEmpty(&colaComun)){
        mostrarCola(&colaComun);
    }
    return 0;
}
