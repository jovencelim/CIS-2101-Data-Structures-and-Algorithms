#include <stdio.h>
#include "list_v1.h"

void initialize(LIST_V1 *L){
    L->count = 0;
}

void insertPos(LIST_V1 *L, int data, int position){
    if(L->count != MAX){
        if(position >= 0 && position <= L->count){
            int i;
            for(i = L->count; i > position; i--){
                L->Elements[i] = L->Elements[i-1];
            }
            L->Elements[position] = data;
            L->count++;
        }else{
            L->Elements[position] = data;
            L->count++;
        }
    }
}

void deletePos(LIST_V1 *L, int position){
    if(L->count != 0){
        if(position >= 0 && position <= L->count){
            int i;
            for(i = position; i < L->count - 1; i++){
                L->Elements[i] = L->Elements[i+1];
            }
            L->count--;
        }
    }
}

int locate(LIST_V1 L, int data){
    int retval = -1;
    if(L.count != 0){
        int i;
        for(i = 0; i != L.count && L.Elements[i] != data; i++){}
        if(i != L.count){
            retval = i;
        }
    }
    return retval;
}

void insertSorted(LIST_V1 *L, int data){
    if(L->count != MAX){
        int i;
        for(i = 0; i != L->count && data > L->Elements[i]; i++){}
        if(i != L->count){
            insertPos(L, data, i);
        }
    }
}

void display(LIST_V1 L) {
    printf("Elements: [ ");
    if(L.count != 0){
        for(int i = 0; i < L.count; i++) {
            printf("%d", L.Elements[i]);
            if(i < L.count - 1){
                printf(", ");
            }
        }
    }else{
        printf("LIST IS EMPTY");
    }
    printf(" ]\n");
    printf("count: %d\n", L.count);
}