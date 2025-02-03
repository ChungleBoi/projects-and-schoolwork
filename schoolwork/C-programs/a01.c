// Cristian Ortiz
// A01 - CSC 150 Review
// CSC 250


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int findMax(int arr[], int size);
int findMin(int arr[], int size);
int findSum(int arr[], int size);
float findAvg(int arr[], int size);
// Add Additional Function Prototypes Here

int main()
{
	int *arr;
	int size, i;

	printf("Enter Array Size:");
	scanf("%d", & size);
	// Dynamically Allocate Array
	arr = (int*) malloc(size * sizeof(int));
	srand(time(0));
	for(i=0; i<size; i++) {
		arr[i] = rand() % 101;
	}

	findMax(arr,size);
	findMin(arr,size);
	findSum(arr,size);
	findAvg(arr,size);

	int index;
	printf("  ARRAY\n"
		"Pos | Val\n"
		"---------\n");
	for(i=0; i<size; i++) {
		index = i;
		printf("%d   | %3d\n",index,arr[i]);
	}
	
	printf("---------\n\n");
	free(arr);

	return 0;
}

int findMax(int arr[], int size)
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
	printf("Max: %d Pos: %d\n",max,index);
	return 0;
}

int findMin(int arr[], int size)
{
	// Find Min Value in Array
	int min = arr[0];
	int index = 0;
	for(int i=0; i>size; i++) {
		if(arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}
	printf("Min: %d Pos: %d\n",min,index);
	return 0;
}

int findSum(int arr[], int size)
{
	// Find Sum of Array
	int sum = 0;
	for(int i=0; i<size; i++) {
		sum += arr[i];
	}
	printf("Sum: %d\n",sum);
	return 0;
}

float findAvg(int arr[], int size) 
{
	int sum = 0;
	for(int i=0; i<size; i++) {
		sum += arr[i];
	}
	(float) sum/size;
	printf("Avg: %d\n\n",sum/size);
	return 0;
}
// Add Additional Functions Here
