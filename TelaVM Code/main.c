#include <stdio.h>
#include <stdlib.h>
#include "DataStack.h"
#include "ExeStack.h"


// Guida void pointer
//https://italiancoders.it/allocazione-dinamica-della-memoria-usi-e-costumi-del-puntatore-void/
typedef struct record{
    char* name;
    char* varNames;
    int parameters;
    void* objectsPointer;
    struct record* caller;
    struct record* father;
    char returnType;
    void* returnPointer;
}ActivationRecord;

/**
* Funzione che costruisce il record di attivazione, passandogli l'indirizzo del suo spazio delle
* variabili
*/
ActivationRecord newAR(char* arName, int localsVariables, int params){
    ActivationRecord record;
    record.objectsPointer = malloc(100);
    assignString(record.name, arName);
    record.varNames = malloc(100);
    *record.varNames = '\0';
    record.parameters = params;
    return record;
}

void addVariable(ActivationRecord* ar, DataStack* data, char* name, char* type)
{
    //aggiungo il tipo della variabile, è il primo carattere presente nella stringa
    strcat(ar->varNames, type);
    //dopo il tipo che è il primo carattere inserisco il nome
    strcat(ar->varNames, name);
    //inserisco il separatore, il carattere /1 perchè /0 da problemi col il concat
    strcat(ar->varNames, "\1");
    switch (type[0])
    {
        case 'i': pushDataInt(data, 0); break;
        case 'f': pushDataFloat(data, 0); break;
        case 'c': pushDataChar(data, '\0'); break;
        case 's': pushDataString(data); break;
    }
}

void assignString(char* dest, char* str)
{
    dest=(char*)calloc(strlen(str),sizeof(char));
    strncpy(dest,str,strlen(str));
}
//ci passano il nome della variabile e la distanza dall'attuale record di attivazione

int main()
{
    DataStack data = newDataStack();
    ActivationRecord AR = newAR("Nome", 3, 3);
    addVariable(&AR, &data, "m1","i");
    addVariable(&AR,&data, "p2","s");
    addVariable(&AR,&data, "f3","c");
    addVariable(&AR,&data, "p4","i");
    addVariable(&AR,&data, "p5","f");
    printf("\n\n\n%s\n%d\n\n", AR.varNames, strlen(AR.varNames));
    debug(&data);
}
