//A08-Sorting Algorithm
//CSC-250
//Cristian Ortiz

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void printList(int arr[],int size);
void swap(int *first, int *second);
void bubbles(int arr[], int n);

int main(int argc, char *argv[])
{
	if(argc != 2) {
		printf("ERROR: INVALID COMMAND LINE ARGUMENTS\n"
			"EXPECTING: EXECUTABLE <ARRAY-SIZE>\n");
		exit(0);
	}
	srand(time(0));
	int *arr;
	char *a = argv[1];
	int size = atoi(a);
	int i;

	arr = malloc(size*sizeof(int));
	for(i=0;i<size;i++) {
		arr[i] = rand() % 101;
	}
	printf("~*~*~*~*~*~*~*\n"
		"\n   UNSORTED\n");
	printList(arr,size);
	
	bubbles(arr,size);

	printf("\n    SORTED\n");
	printList(arr,size);


	free(arr);
	return 0;
}
void printList(int arr[],int size)
{
	int index;
	printf("     LIST\n"
		"INDEX | VALUE\n"
		"~*~*~*~*~*~*~*\n");
	for(int i=0;i<size;i++) {
		index = i;
		printf("%4d  | %4d\n",index,arr[i]);
	}
	printf("~*~*~*~*~*~*~*\n");
}
void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}
void bubbles(int arr[], int n)
{
	int i, j;
	for(i=0;i<n-1;i++) { 
		for(j=0;j<n-i-1;j++) {
			if(arr[j]>arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
			}
		}
	}	
}
