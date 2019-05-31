#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM_STACK 1000


/** Struttura di contenimento di costanti e variabili dei record di attivazione.
* *start: puntatore alla PRIMA area di memoria dello stack.
* *pointer: puntatore alla prima area di memoria non occupata.
* Nei record di attivazione verr� salvato il puntatore all'area di memoria
* corrispondente alla prima variabile che viene inizializzata nel modulo
*/
typedef struct
{
    void *start;
    void *pointer;
}DataStack;

/** Costruttore di DataStack.
* Allocati DIM blocchi di memoria con *p = malloc(n) (funzione che ritorna un
* puntatore *p ad n caratteri consecutivi).
* Salva il primo indirizzo di memoria e inizializza il puntatore.
* Ritorna un oggetto Datastack.
*/
DataStack newDataStack();

/** Funzione di DataStack.
* Aggiunge una variabile di tipo carattere a DataStack: tipo 'c' e valore passato.
*/
void pushChar(DataStack *data, char value);

/** Funzione di DataStack.
* Aggiunge una variabile di tipo intero a DataStack: tipo 'i' e valore passato.
*/
void pushInt(DataStack *data, int value);

/** Funzione di DataStack
* Aggiunge una variabile di tipo stringa a DataStack: tipo 's' e valore passato.
*/
void pushString(DataStack *data, String *value);

/** Funzione di DataStack
* Aggiunge una variabile di tipo float a DataStack: tipo 'f' e valore passato
*/
void pushFloat(DataStack *data, float value);

/** Funzione di DataStack
* Ritorna la dimensione attuale della memoria utilizzata, facendo
* la differenza tra i puntatori "pointer" e "start"
*/
int getMemoryUsage(DataStack* data);

/** Funzione di Datastack
* Ritorna il puntatore alla prima posizione libera nella memoria
*/
void* getPointer(DataStack* data);

/* solo in caso di debug
int main()
{
    DataStack data = newDataStack();
    pushInt(&data, 59);
    pushFloat(&data, 4857.356);
    pushChar(&data, '#');
    String s = newString("Antonio");
    pushString(&data, &s);
    s = newString("Eil in di Eil");
    pushString(&data, &s);
    pushInt(&data, 301);
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
}*/



DataStack newDataStack()
{
    DataStack data;
    data.start = malloc(DIM_STACK);
    data.pointer = data.start;
    return data;

}

void pushChar(DataStack *data, char value)
{
    char *c;
    c = data->pointer;
    *c = 'c';
    data->pointer++;
    char *charac;
    charac = data->pointer;
    *charac = value;
    // Operazione equivalente: *data.pointer++;
    data->pointer += sizeof(char);
}

void pushInt(DataStack *data, int value)
{
    char *c;
    // -> perch� data � un puntatore
    // operazione equivalente: c=*data.pointer;
    c = data->pointer;
    // Salvo il carattere nella prima posizione disponibile
    *c = 'i';
    // Dato che ho scritto solamente 8bit incremento il puntatore (dafault: 8bit)
    data->pointer++;
    int *integer;
    integer = data->pointer;
    *integer = value;
    // Dopo aver salvato il tipo e il valore incremento il puntatore alla prossima
    // area libera di 4Byte
    data->pointer += sizeof(int);
}

void pushString(DataStack *data, String *value)
{
    // Scrivo il tipo nella prima posizione disponibile
    char *c;
    c = data->pointer;
    *c = 's';
    //Incremento di 8bit
    data->pointer++;

    // Punto alla prossima memoria libera
    c = data->pointer;
    // Alloco una stringa
    strncpy(c, value->array, strlen(value->array));
    data->pointer = data->pointer + strlen(value->array);
    //aggiungo il terminatore per dire che � finita la stringa
    char* terminator = data->pointer;
    *terminator = '\0';
    data->pointer++;

    /*
    c = data->pointer;
    char *stringa;
    stringa = s->array;
    int len = strlen(stringa);
    int i;
    for(i = 0; i < len; i++) {
        *c = *stringa;
        stringa++;
        data->pointer++;
        c = data->pointer;
    }
    *c='\0';
    data->pointer++;*/
}

void pushFloat(DataStack *data, float value)
{
    char *c;
    // -> perch� data � un puntatore
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

int getMemoryUsage(DataStack* data)
{
    return (int) data->pointer - (int) data->start;
}

void* getPointer(DataStack* data)
{
    return data->pointer;
}
