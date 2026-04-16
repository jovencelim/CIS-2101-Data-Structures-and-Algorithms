#include <stdio.h>
#include "list.h"

void initVirtualHeap(VirtualHeap *VH){
	int i;
	for(i = 0; i < MAX-1; i++){
		VH->Nodes[i].link = i+1;
	}
	VH->Nodes[MAX-1].link = -1;
	VH->avail = 0;
}

int allocSpace(VirtualHeap *VH){
	int retval = -1;
	if(VH->avail != -1){
		retval = VH->avail;
		VH->avail = VH->Nodes[retval].link;
	}
	return retval;
}

void deallocSpace(VirtualHeap *VH, int index){
	if(index > -1 && index <= MAX-1){
		VH->Nodes[index].link = VH->avail;
		VH->avail = index;
	}
}

void initList(List *L){
	*L = -1;
}

void insertFirst(VirtualHeap *VH, List *L, NameType data){
	List newNode = allocSpace(VH);
	if(newNode != -1){
		VH->Nodes[newNode].data = data;
		VH->Nodes[newNode].link = *L;
		*L = newNode;
	}else{
		printf("\nMemory Allocation Unsuccessful\n");
	}
}

void insertLast(VirtualHeap *VH, List *L, NameType data){
	List newNode = allocSpace(VH);
	if(newNode != -1){
		VH->Nodes[newNode].data = data;
		if(*L != -1){
			List trav = *L;
			while(VH->Nodes[trav].link != -1){
				trav = VH->Nodes[trav].link;
			}
			VH->Nodes[trav].link = newNode;
			VH->Nodes[newNode].link = -1;
		}else{
			VH->Nodes[newNode].link = *L;
			*L = newNode;
		}
	}else{
		printf("\nMemory Allocation Unsuccessful\n");
	}
}

void displayList(VirtualHeap VH, List L){
    List trav;
    printf("\n%-25s %-5s %-25s\n", "-------------------------", "---", "-------------------------");
    printf("%-25s %-5s %-25s\n", "First Name", "MI", "Last Name");
    printf("%-25s %-5s %-25s\n", "-------------------------", "---", "-------------------------");
    for (trav = L; trav != -1; trav = VH.Nodes[trav].link) {
        printf("%-25s %-5c %-25s\n", 
            VH.Nodes[trav].data.FName, 
            VH.Nodes[trav].data.MI, 
            VH.Nodes[trav].data.LName);
    }
}