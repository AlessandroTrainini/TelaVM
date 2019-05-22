#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Struttura per la gestione di array di caratteri.
* *array: puntatore al primo elemento dell'array.
*/
typedef struct
{
    char *array;
}String;

/** Costruttore di String.
* Parametri:
* *variable: puntatore ad oggetto Stringa precedentemente definito
* *str: puntatore al primo elemento di un array di caratteri
* Oggetto allocato per riferimento.
*/
void assign(String *,const char *);

String newString(const char *);

void assign(String *variable, const char *str)
{
    if(variable)
    {
        // Puntatore a blocchi di memoria (8bit) con strlen caratteri consecutivi
        // inizializzati a 0. (probabilmente si può usare malloc)
        variable->array=(char*)calloc(strlen(str),sizeof(char));
        strncpy(variable->array,str,strlen(str));
    }
}

String newString(const char *str)
{
    String s;
    assign(&s, str);
    return s;
}
