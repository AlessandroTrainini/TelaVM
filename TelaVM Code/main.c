#include <stdio.h>
#include <stdlib.h>
#include "DataString.h"
#include "DataStack.h"

typedef struct{
    String name;
    char type;
}VarRecord;

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
/**

VarStor
Funzione che costruisce il record di attivazione, passandogli l'indirizzo del suo spazio delle
variabili
*/
ActivationRecord newAR(void *);

int main()
{

}

ActivationRecord newAR(void *pointer){
    ActivationRecord record;
    record.objectsPointer = pointer;
}


