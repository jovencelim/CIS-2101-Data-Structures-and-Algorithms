#include <stdio.h>
#include "list_v1.h"

int main(){
    printf("\nArray Implementation of List (V1)\n");
    LIST_V1 list;
    initialize(&list);
    insertPos(&list, 5, 0); // insert first initially
    display(list);
    return 0;
}