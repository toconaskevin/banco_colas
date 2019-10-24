#include "banco_colas.h"

int main() {

    STR_COLA colaComun;
    STR_COLA colaPremium;

    crearCola(&colaComun);
    crearCola(&colaPremium);

    while(totemTurnos(&colaPremium, &colaComun));

    //debug
    if(!isEmpty(&colaPremium)){
        mostrarCola(&colaPremium);
    }
    if(!isEmpty(&colaComun)){
        mostrarCola(&colaComun);
    }
    //enddebug
    return 0;
}
