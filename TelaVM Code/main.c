#include <stdio.h>
#include <stdlib.h>
#include "DataString.h"
#include "DataStack.h"

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
}
