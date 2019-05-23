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
    DataStack data = newDataStack();
    pushInt(&data, 59);
    pushFloat(&data, 4857.356);
    pushChar(&data, '#');
    String s = newString("Antonio");
    pushString(&data, &s);
    char* pointer = data.pointer+1;
    s = newString("Eil in di Eil");
    pushString(&data, &s);
    printf("\n\n\n%s\n\n\n", pointer);
    pushInt(&data, 301);
    pushFloat(&data, 2.343434324);
    pushFloat(&data, 2.343434324);
    pushFloat(&data, 2.343434324);
    pushFloat(&data, 2.343434324);

    void *p;
    int i;
    for(i = 0; i < 100; i++){
        p = data.start;
        p += i;
        char *c = p;
        printf("%d:\t%c\tchar->ashii\t%d\n", i, *c, *c);
    }
    printf("Dimensione memoria utilizzata: %d", getMemoryUsage(&data));
    return 0;
}

ActivationRecord newAR(void *pointer){
    ActivationRecord record;
    record.objectsPointer = pointer;
}


