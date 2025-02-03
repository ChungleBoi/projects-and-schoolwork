#ifndef LINKED_H
#define LINKED_H

//Structure Definition
struct node_def {
	int data;
	struct node_def *next;
	struct node_def *prev;
};
typedef struct node_def node;
struct linked_list_def {
	struct node_def *head;
	struct node_def *tail;
};
typedef struct linked_list_def llist;
//Function Declarations
void printList(llist *list);
int listLength(llist *list);
void insertFront(llist *list,int x);
void insertBack(llist *list, int x);
void deleteFront(llist *list);
void deleteBack(llist *list);
void findValue(llist *list ,int value);
void findAddAfter(llist *list, int value, int x);
void findAndDelete(llist *list, int value);

#endif
