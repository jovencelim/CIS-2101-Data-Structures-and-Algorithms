#ifndef LIST_H
#define LIST_H

#define MAX 5

typedef int List;

typedef struct{
	char FName[25];
	char MI;
	char LName[25];
}NameType;

typedef struct{
	NameType data;
	int link;
}NodeType;

typedef struct{
	NodeType Nodes[MAX];
	int avail;
}VirtualHeap;

void initVirtualHeap(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index);
void initList(List *L);
void insertFirst(VirtualHeap *VH, List *L, NameType data);
void insertLast(VirtualHeap *VH, List *L, NameType data);
void displayList(VirtualHeap VH, List L);

#endif