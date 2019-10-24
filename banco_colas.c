//
// Created by k on 24/10/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio_ext.h>
#include "banco_colas.h"

void crearCola(STR_COLA *cola) {
    cola->frente = NULL;
    cola->fin = NULL;
}

STR_CLIENTE getDatosCliente() {
    STR_CLIENTE cliente;
    char nombre[35];

    printf("Ingrese su nombre y apellido: ");
    __fpurge(stdin);
    fgets(cliente.nombre, 35, stdin);

    printf("Usted es cliente premium?\n0. No\n1. Si\n--> ");
    scanf("%d", &cliente.premium);

    printf("Usted esta embarazada?\n0. No\n1. Si\n--> ");
    scanf("%d", &cliente.embarazada);

    printf("Ingrese la operacion a realizar:\n");
    printf("1. Extraccion\n2. Prestamos\n3. Pagos\n4. Otros\n--> ");
    scanf("%d", &cliente.operacion);

    return cliente;
}

void agregarNodo(STR_COLA *cola, STR_CLIENTE cliente) {
    STR_NODO *nodo = (STR_NODO)(malloc(sizeof(STR_NODO)));
    if(nodo == NULL){
        exit(EXIT_FAILURE);
    }
    nodo->cliente = cliente;
    nodo->sgte = NULL;
    if(cola->frente == NULL){
        cola->frente = nodo;
    }
    else {
        cola->fin->sgte = nodo;
    }
    cola->fin = nodo;
    return;
}

STR_CLIENTE delete(STR_COLA *cola) {
    STR_NODO *aux = cola->frente;
    STR_CLIENTE cliente = aux->cliente;
    cola->frente = aux->sgte;
    if(cola->frente == NULL){
        cola->fin = NULL;
    }
    free(aux);
    return cliente;
}

bool isEmpty(STR_COLA *cola){
    return cola->frente == NULL && cola->fin == NULL;
}

void copiarNodo(STR_COLA *cola, STR_COLA *colaPrioridad) {
    agregarNodo(colaPrioridad, delete(cola));
}

void setColaPrioridad(STR_COLA *cola, STR_CLIENTE cliente) {
    STR_NODO *nodo = (STR_NODO)(malloc(sizeof(STR_NODO)));
    if(nodo == NULL){
        exit(EXIT_FAILURE);
    }
    STR_COLA *aux = cola;
    crearCola(cola);
    nodo->cliente = cliente;
    nodo->sgte = NULL;
    cola->frente = nodo;
    cola->fin = nodo;
    while(!isEmpty(aux)) {
        copiarNodo(aux, cola);
    }
}

bool totemTurnos(STR_COLA *colaPremium, STR_COLA *colaNormal) {
    STR_CLIENTE cliente = getDatosCliente();
    if (cliente.operacion == -1){
        return false;
    }
    if(cliente.premium){
        if(cliente.embarazada){
            setColaPrioridad(colaPremium, cliente);
        } else {
            agregarNodo(colaPremium, cliente);
        }
    } else {
        if(cliente.embarazada){
            setColaPrioridad(colaNormal, cliente);
        } else {
            agregarNodo(colaNormal, cliente);
        }
    }

    return true;
}

void mostrarCola(STR_COLA *cola) {
    STR_CLIENTE cliente;
    if(cola->frente->cliente.premium)  {
        printf("COLA PREMIUM\n////////////\n");
    } else {
        printf("COLA COMUN\n////////////\n");
    }
    while(!isEmpty(cola)) {
        cliente = delete(cola);
        printf("Nombre del cliente: %s", cliente.nombre);
        printf("Operacion realizada: %d\n\n", cliente.operacion);
    }
}