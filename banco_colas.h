//
// Created by k on 24/10/19.
//

#ifndef BANCO_COLAS_BANCO_COLAS_H
#define BANCO_COLAS_BANCO_COLAS_H

typedef struct {
    char nombre[35];
    int operacion;
    int embarazada;
    int premium;
}STR_CLIENTE;

typedef struct nodo {
    STR_CLIENTE cliente;
    struct nodo *sgte;
}STR_NODO;

typedef struct {
    STR_NODO *frente;
    STR_NODO *fin;
}STR_COLA;

void crearCola(STR_COLA *cola);

STR_CLIENTE getDatosCliente();

void agregarNodo(STR_COLA *cola, STR_CLIENTE cliente);

STR_CLIENTE delete(STR_COLA *cola);

bool isEmpty(STR_COLA *cola);

void copiarNodo(STR_COLA *cola, STR_COLA *colaPrioridad);

void setColaPrioridad(STR_COLA *cola, STR_CLIENTE cliente);

bool totemTurnos(STR_COLA *colaPremium, STR_COLA *colaNormal);

void mostrarCola(STR_COLA *cola);

#endif //BANCO_COLAS_BANCO_COLAS_H
