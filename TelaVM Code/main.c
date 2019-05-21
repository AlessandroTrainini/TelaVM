#include <stdio.h>
#include <stdlib.h>
typedef struct{
    void *start;
    void *pointer;
}DataStack;

DataStack newDataStack()
{
    DataStack data;
    data.start = malloc(1000);
    data.pointer = data.start;
    return data;

}

void pushInt(DataStack *data, int value)
{
    char *c;
    c = data->pointer;
    *c = 'i';
    data->pointer++;
    int *integer;
    integer = data->pointer;
    *integer = value;
    data->pointer += sizeof(int);
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
    data->pointer += sizeof(char);
}

typedef struct
{
    char *array;
}String;



void assign(String *,const char *);

void assign(String *variable, const char *str)
{
    if(variable)
    {
        variable->array=(char*)calloc(strlen(str),sizeof(char));
        strncpy(variable->array,str,strlen(str));
    }
}

void main()
{
    DataStack data = newDataStack();
    printf("pointer: %p\n", data.pointer);
    pushInt(&data, 59);
    printf("pointer: %p\n", data.pointer);
    pushInt(&data, 485738);
    printf("pointer: %p\n", data.pointer);
    pushChar(&data, '#');
    printf("pointer: %p\n\n\n", data.pointer);

    void *p;
    p = data.start;
    p+=11;
    char *c = p;
    printf("%c", *c);

}
