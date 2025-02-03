// Cristian Ortiz
// A04 - Pointers & Dynamic Memory(Recommit & Push) 
// CSC 250


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void findMax(int arr[], int size, FILE *outfile);
void findMin(int arr[], int size, FILE *outfile);
void findSum(int arr[], int size, FILE *outfile);
void findAvg(int arr[], int size, FILE *outfile);
void printArray(int arr[], int size, FILE *outfile);

// Add Additional Function Prototypes Here

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("ERROR: INVALID COMMAND LINE ARGUMENTS\n"
				"EXPECTING: EXECUTABLE <ARRAY-SIZE> <OUTPUT-FILE>\n");
		exit(0);
	}
	FILE *outfile = fopen(argv[2], "w");
	int *arr;

	if (outfile != NULL) {
		printf("\nFILE %s WAS SUCCESSFULLY OPENED.\n\n", argv[2]);
	}

	char *a = argv[1];
	int size = atoi(a);
	int i;

	// Dynamically Allocate Array
	arr = (int*) malloc(size * sizeof(int));
	srand(time(0));

	for(i=0; i<size; i++) {
		arr[i] = rand() % 101;
	}

	findMax(arr,size,outfile);
	findMin(arr,size,outfile);
	findSum(arr,size,outfile);
	findAvg(arr,size,outfile);

	printArray(arr,size,outfile);

	fclose(outfile);

	//Array doubled & memory reallocated
	size *= 2;
	outfile = fopen(argv[2], "a"); // Appending with "a" option instead of writing.

	arr = (int*) realloc(arr, size * sizeof(int));
	fprintf(outfile,"REALLOCATED MEMORY\n");

	for(i=0;i<size;i++) {
		arr[i] = rand() % 101;
	}

	findMax(arr,size,outfile);
	findMin(arr,size,outfile);
	findSum(arr,size,outfile);
	findAvg(arr,size,outfile);

	printArray(arr,size,outfile);

	free(arr);
	fclose(outfile);
	return 0;
}
void printArray(int arr[], int size, FILE *outfile)
{	
	int index;
	fprintf(outfile,"  ARRAY\n"
			"IND | VAL\n"
			"---------\n");
	for(int i=0; i<size; i++) {
		index = i;
		fprintf(outfile,"%d   | %3d\n",index,arr[i]);
	}	
	fprintf(outfile,"---------\n\n");
}
void findMax(int arr[], int size, FILE *outfile)
{
	// Find Max Value in Array
	int max = arr[0];
	int index = 0;
	for(int i=0; i<size; i++) {
		if(arr[i] > max) {
			max = arr[i];
			index = i;
		}
	}
	fprintf(outfile,"MAX: %d IND: %d\n",max,index);
}

void findMin(int arr[], int size, FILE *outfile)
{
	// Find Min Value in Array
	int min = arr[0];
	int index = 0;
	for(int i=0; i<size; i++) {
		if(arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}
	fprintf(outfile,"MIN: %d IND: %d\n",min,index);
}

void findSum(int arr[], int size, FILE *outfile)
{
	// Find Sum of Array
	int sum = 0;
	for(int i=0; i<size; i++) {
		sum += arr[i];
	}
	fprintf(outfile,"SUM: %d\n",sum);
}

void findAvg(int arr[], int size, FILE *outfile) 
{
	int sum = 0;
	for(int i=0; i<size; i++) {
		sum += arr[i];
	}
	(float) sum/size;
	fprintf(outfile,"AVG: %d\n\n",sum/size);	
}
// Add Additional Functions Here
