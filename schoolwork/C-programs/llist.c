// Cristian Ortiz
// CSC 250
// A07 - Linked Lists

#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int getOption();
void getValue(int *value);

int main()
{
	int length = 0;
	llist *list = NULL;
	list = malloc(sizeof(llist));
	list->head = NULL;
	list->tail = NULL;
	int option = 0;
	int value = 0;
	int x = 0;
	char garbage;
	while(1) 
	{
		option = getOption();

		if(option == 0) {
			free(list);
			exit(1); //exits program

		} else if(option == 1) {
			//Inserts at the front of list
			getValue(&value);
			insertFront(list,value);

		} else if(option == 2) {
			//Deletes at the front of list
			deleteFront(list);

		} else if(option == 3) {
			//Inserts at the back of list
			getValue(&value);
			insertBack(list,value);

		} else if(option == 4) {
			//Deletes at the back of list
			deleteBack(list);

		} else if(option == 5) { 
			//Find Value in list and print a message
			//confirming if there exists such value Y/N
			getValue(&value);
			findValue(list, value);

		} else if(option == 6) {
			//Find Value in list and insert new node 
			//after first occurence
			getValue(&value);
			scanf("%d%c", &x, &garbage);
			findAddAfter(list,value,x);

		} else if(option == 7) {
			//Find Value in list and delete first node
			//the searched value
			getValue(&value);
			findAndDelete(list, value);

		} else if(option == 8) {
			//Print List Length
			length = listLength(list);
			printf("%d item(s) are in the list\n",length); 

		} else if(option == 9) {
			//Print List
			printList(list);

		} else {  
			printf("INCORRECT SELECTION!!\n");
			exit(1);
		}
	}
	return 0;
}
int getOption()
{
	int option = 0;
	char garbage;
	scanf("%d%c", &option, &garbage);

	return option;
}
void getValue(int *value)
{
	char garbage;
	scanf("%d%c", value, &garbage);
}

