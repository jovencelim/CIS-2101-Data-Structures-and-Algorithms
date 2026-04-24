#ifndef LIST_V1_H
#define LIST_V1_H

#define MAX 5

typedef struct{
    int Elements[MAX];
    int count;
}LIST_V1;

void initialize(LIST_V1 *L);
void insertPos(LIST_V1 *L, int data, int position);
void deletePos(LIST_V1 *L, int position);
int locate(LIST_V1 L, int data);
void insertSorted(LIST_V1 *L, int data);
void display(LIST_V1 L);

#endif