#include <stdio.h>
typedef enum{false, true}bool;
typedef unsigned char SET;

void initialize(SET *S);
void insert(SET *S, int element);
void delete(SET *S, int element);
bool find(SET S, int element);
void displayBits(SET S);

int main(){
    SET s;
    initialize(&s);
    insert(&s, 5);
    insert(&s, 6);
    insert(&s, 7);
    displayBits(s);
    return 0;
}

void initialize(SET *S){
    *S = 0;
}

void insert(SET *S, int element){
    if(element >= 0 && element <= 7){
        SET bitmask = 1 << element;
        *S = *S | bitmask;
    }
}

void delete(SET *S, int element){
    if(element >= 0 && element <= 7){
        SET bitmask = 1 << element;
        *S = *S & ~bitmask;
    }
}

bool find(SET S, int element){
    SET bitmask = 1 << element;
    return (S & bitmask)? true:false;
}

void displayBits(SET S){
    for(int i = 7; i >= 0; i--){
        SET bitmask = 1 << i;
        printf("%d", (S & bitmask) ? 1 : 0);
    }
    printf("\n");
}
