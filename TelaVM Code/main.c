#include <stdio.h>
#include <stdlib.h>
#include "DataString.h"
#include "DataStack.h"

typedef struct{
    String name;
    char type;
}VarRecord;

// Guida void pointer
//https://italiancoders.it/allocazione-dinamica-della-memoria-usi-e-costumi-del-puntatore-void/
typedef struct record{
    VarRecord *variables;
    void* objectsPointer;
    struct record* caller;
    struct record* father;
    char returnType;
}ActivationRecord;

/**
Funzione che costruisce il VarStorage.
capire quante sono in base al codice
*/

/**
VarStor
Funzione che costruisce il record di attivazione, passandogli l'indirizzo del suo spazio delle
variabili
*/
ActivationRecord newAR(void *);

int main()
{
    return 0;
}

ActivationRecord newAR(void *pointer){
    ActivationRecord record;
    record.objectsPointer = pointer;
}


