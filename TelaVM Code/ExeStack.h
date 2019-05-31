#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM_STACK 1000


/** Struttura di contenimento di costanti e variabili dei record di attivazione.
* *start: puntatore alla PRIMA area di memoria dello stack.
* *pointer: puntatore alla prima area di memoria non occupata.
* Nei record di attivazione verrà salvato il puntatore all'area di memoria
* corrispondente alla prima variabile che viene inizializzata nel modulo
*/
typedef struct
{
    int dimension;
    void *start;
    void *pointer;
}ExeStack;

/** Costruttore di ExeStack.
* Allocati DIM blocchi di memoria con *p = malloc(n) (funzione che ritorna un
* puntatore *p ad n caratteri consecutivi).
* Salva il primo indirizzo di memoria e inizializza il puntatore.
* Ritorna un oggetto ExeStack.
*/
ExeStack newExeStack();

/** Funzione di ExeStack.
* Aggiunge una variabile di tipo carattere a ExeStack: tipo 'c' e valore passato.
*/
void pushExeChar(ExeStack *data, char value);

/** Funzione di ExeStack.
* Aggiunge una variabile di tipo intero a ExeStack: tipo 'i' e valore passato.
*/
void pushExeInt(ExeStack *data, int value);

/** Funzione di ExeStack
* Aggiunge una variabile di tipo stringa a ExeStack: tipo 's' e valore passato.
*/
void pushExeString(ExeStack *, char *c);

/** Funzione di ExeStack
* Aggiunge una variabile di tipo float a ExeStack: tipo 'f' e valore passato
*/
void pushExeFloat(ExeStack *data, float value);

/** Funzione di ExeStack
* Ritorna la dimensione attuale della memoria utilizzata, facendo
* la differenza tra i puntatori "pointer" e "start"
*/
int getMemoryExeUsage(ExeStack* data);

/** Funzione di ExeStack
* Ritorna il puntatore alla prima posizione libera nella memoria
*/
void* getExePointer(ExeStack* data);



/* solo in caso di debug
int main()
{
    ExeStack data = newExeStack();
    pushExeInt(&data, 59);
    pushExeFloat(&data, 4857.356);
    pushExeChar(&data, '#');
    String s = newString("Antonio");
    pushExeString(&data, &s);
    s = newString("Eil in di Eil");
    pushExeString(&data, &s);
    pushExeInt(&data, 301);
    pushExeFloat(&data, 2.343434324);

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
}*/



ExeStack newExeStack()
{
    ExeStack data;
    data.start = malloc(DIM_STACK);
    data.pointer = data.start;
    return data;

}

void pushExeChar(ExeStack *data, char value)
{
    char *charac;
    charac = data->pointer;
    *charac = value;
    // Operazione equivalente: *data.pointer++;
    data->pointer += sizeof(char);
}

char pullExeChar(ExeStack *data) {
    data->pointer -= sizeof(char);
    char* value = data->pointer;
    return *value;
}

void pushExeInt(ExeStack *data, int value)
{
    int *integer;
    integer = data->pointer;
    *integer = value;
    // Dopo aver salvato il tipo e il valore incremento il puntatore alla prossima
    // area libera di 4Byte
    data->pointer += sizeof(int);
}

int pullExeInt(ExeStack *data) {

    data->pointer -= sizeof(int);
    int* value = data->pointer;
    return *value;
}

void pushExeString(ExeStack *data, char* value)
{
    char *c = data->pointer;
    c = value;
    data->pointer++;
}

char* pullExeString(ExeStack *data) {

}

void pushExeFloat(ExeStack *data, float value)
{
    char *c;
    // -> perché data è un puntatore
    // operazione equivalente: c=*data.pointer;
    c = data->pointer;
    // Salvo il carattere nella prima posizione disponibile
    *c = 'f';
    // Dato che ho scritto solamente 8bit incremento il puntatore (dafault: 8bit)
    data->pointer++;
    float *real;
    real = data->pointer;
    *real = value;
    // Dopo aver salvato il tipo e il valore incremento il puntatore alla prossima
    // area libera di 4Byte
    data->pointer += sizeof(float);
}

int getMemoryExeUsage(ExeStack* data)
{
    return (int) data->pointer - (int) data->start;
}

void* getExePointer(ExeStack* data)
{
    return data->pointer;
}

void debugExe(ExeStack* data)
{
    void* p;
    int i;
    for(i = 0; i < 100; i++){
        p = data->start;
        p += i;
        char *c = p;
        printf("%d:\t%c\tchar->ashii\t%d\n", i, *c, *c);
    }
    printf("Dimensione memoria utilizzata: %d", getMemoryUsage(data));
}

void addI() {

}

/**
void* get(ExeStack* data, int index, void* startPoint)
{
    if (index == 0)
        return startPoint++;
    char* startChar = startPoint;
    switch (*startChar)
    {
        case 'i': startPoint+=sizeof(int)+1; get(data, index--, startPoint);break;
        case 'f': startPoint+=sizeof(float)+1; get(data, index--, startPoint);break;
        case 'c': startPoint+=sizeof(char)+1; get(data, index--, startPoint);break;
        case 'b': startPoint+=sizeof(int)+1; get(data, index--, startPoint);break;
        case 's': jumpString()
    }
}*/
