#include <stdio.h>
#include <stdlib.h>
#include "DataStack.h"


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
Funzione che costruisce il record di attivazione, passandogli l'indirizzo del suo spazio delle
variabili
*/
ActivationRecord newAR(char*, void*, int, int);

/**

*/



int main()
{
    DataStack data = newDataStack();
    ActivationRecord AR = newAR("Nome", data.pointer, 3, 3);
    addVariable(&AR,"m1");
    addVariable(&AR, "p2");
    addVariable(&AR, "f3");
    addVariable(&AR, "p4");
    addVariable(&AR, "p5");
    printf("\n\n\n%s", AR.varNames);
}

ActivationRecord newAR(char* arName, void *pointer, int localsVariables, int params){
    ActivationRecord record;
    record.objectsPointer = pointer;
    assign(record.name, arName);
    record.varNames = malloc(100);
    *record.varNames = '\0';
    record.parameters = params;
    return record;
}

void addVariable(ActivationRecord* ar, char* name)
{
    strcat(ar->varNames, name);
    strcat(ar->varNames, "\1");
}

void assign(char* dest, char* str)
{
    dest=(char*)calloc(strlen(str),sizeof(char));
    strncpy(dest,str,strlen(str));
}


