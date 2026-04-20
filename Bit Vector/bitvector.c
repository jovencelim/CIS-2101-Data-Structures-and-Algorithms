#include <stdio.h>
typedef enum{false, true}bool;
typedef unsigned char SET;

void initialize(SET *S);
void insert(SET *S, int element);
void delete(SET *S, int element);
bool find(SET S, int element);
void display(SET S);

int main(){
    SET s;
    initialize(&s);
    insert(&s, 5);
    insert(&s, 6);
    insert(&s, 7);
    find(s, 5);
    display(s);
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

void display(SET S){
    printf("SET: { ");
    for(int i = 0; i <= sizeof(SET)-1; i++){
        if(find(S, i)){
            printf("%d ", i);
        }
    }
    printf("}\n");
}
