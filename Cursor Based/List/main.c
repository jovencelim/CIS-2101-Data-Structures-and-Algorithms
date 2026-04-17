#include <stdio.h>
#include "list.h"

int main(){
	VirtualHeap vh;
	initVirtualHeap(&vh);
	List l;
	initList(&l);

//	INSERT FIRST FUNCTION
//	insertFirst(&vh, &l, (NameType){"Jovence", '1', "Lim"});
//	insertFirst(&vh, &l, (NameType){"John", '2', "Doe"});
//	insertFirst(&vh, &l, (NameType){"Jane", '3', "Doe"});
//	insertFirst(&vh, &l, (NameType){"Sam", '4', "Smith"});
//	insertFirst(&vh, &l, (NameType){"John", '5', "Lennon"});
//	insertFirst(&vh, &l, (NameType){"Jane", '6', "Smith"});

//	INSERT LAST FUNCTION
	insertLast(&vh, &l, (NameType){"Jovence", '1', "Lim"});
	insertLast(&vh, &l, (NameType){"John", '2', "Doe"});
	insertLast(&vh, &l, (NameType){"Jane", '3', "Doe"});
	insertLast(&vh, &l, (NameType){"Sam", '4', "Smith"});
	insertLast(&vh, &l, (NameType){"John", '5', "Lennon"});
	insertLast(&vh, &l, (NameType){"Jane", '6', "Smith"});
	displayList(vh, l);
	return 0;
}