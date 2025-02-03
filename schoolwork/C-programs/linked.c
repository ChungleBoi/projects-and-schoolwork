#include <stdlib.h>
#include <stdio.h>
#include "linked.h"

void printList(llist *list)
{
	node *temp;
	temp = list->head;
	printf("List:");
	while(temp != NULL) {
		printf("%4d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int listLength(llist *list)
{
	node *temp;
	temp = list->head;
	int count = 0;
	while(temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}
void insertFront(llist *list,int x)
{
	node *new;
	new = malloc(sizeof(node));
	new->data = x;

	new->next = list->head;
	list->head = new;
	
}
void insertBack(llist *list, int x)
{
	node *new;
	new = malloc(sizeof(node));
	new->data = x;
	new->next = NULL;

	node *temp = list->head;

	if(list->head == NULL) {
		new->prev = NULL;
		list->head = new;
	} else {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		new->prev = temp;
		temp->next = new;
	}
}
void deleteFront(llist *list)
{
	node *temp = NULL;
	if(list->head != NULL) {
		temp = list->head->next;
		free(list->head);
		}
	list->head = temp;

}
void deleteBack(llist *list)
{
	if(list->head != NULL ) { 
		node *temp;
		temp = list->head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		node *prev;
		prev = list->head;
		if(prev == temp) {
			free(temp);
			list->head = NULL;
		} else {
			while(prev->next != temp) {
			prev = prev->next;
			}
			prev->next = NULL;
			free(temp);
		}
	}
}
void findValue(llist *list ,int value)
{
	node *temp;
	temp = list->head;
	int i = 0;
	while(temp != NULL) {
		if(temp->data == value) {
			i++;
		}
		temp = temp->next;
	}
	if(i==0) {
		printf("%d is not in the list at all\n",value);
	} else {
		printf("%d is in the list %d time(s)\n",value,i);
	}
}
void findAddAfter(llist *list, int value, int x)
{
	node *NNode = malloc(sizeof(node));
	NNode->data = x;
	NNode->next = NULL;
	NNode->prev = NULL;
	node *temp1 = list->head;
	node *temp2 = NULL;
	int found = 0; // to track if value was found

	while(temp1 != NULL) {
		if(temp1->data == value) {
			temp2 = temp1->next;
			if(temp2 != NULL) {
				temp2->prev = NNode;
			}
			temp1->next = NNode;
			NNode->prev = temp1; 
			NNode->next = temp2;
			if(temp2 == NULL) {
				list->tail = NNode;
			}
			found = 1; //if found, this should equal 1
			break;
		} 
		temp1 = temp1->next;
	}
	if(found == 0) { //if value is not found
		free(NNode); // unused created node is released from duty
	}
}
void findAndDelete(llist *list, int value)
{
	node *temp = list->head;
	node *prev = NULL;
	node *next = NULL;

	while(temp != NULL) {
		if(temp->data == value) {
			next = temp->next;
			if(prev != NULL) {
				prev->next = next;
			} else {
				list->head = next;
			} 
			if(next != NULL) {
				next->prev = prev;
			} else { 
				list->tail = prev;
			}
			free(temp);
			break;
			temp = next;
		} else {
			prev = temp;	
			temp = temp->next;
		}
	}
}


