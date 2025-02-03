// Cristian Ortiz
// CSC 250
// A02 - Strings


// DO NOT USE <string.h>
#include <stdlib.h>
#include <stdio.h>

int getUserChoice();
int getShift();
void getString(char string[]);
void stringToCaps(char string[]);
void encrypt(char string[], int shift);
void decrypt(char string[], int shift);

int main()
{

	int shift = 3;
	int choice = 0;
	char string[500];	
	while(1)
	{
		// GET USER'S CHOICE
		choice = getUserChoice();

		if( choice == 1)
		{
			// HANDLE CHANGING SHIFT VALUE
			shift = getShift();	
		}
		else if(choice == 2)
		{
			// HANDLE ENCRYPTING A MESSAGE		
			getString(string);
			stringToCaps(string);
			encrypt(string,shift);
			printf("%s\n",string);
		}
		else if(choice == 3)
		{
			// HANDLE DECRYPTING A MESSAGE
			getString(string);
			decrypt(string,shift);
			printf("%s\n",string);			
		}
		else if(choice == 4)
		{
			// HANDLES QUITTING
			printf("Quitting...\n");
			exit(1); //This line will just quit the program when it is called
		}
		else
		{
			// HANDLES INVALID INPUT
			printf("INCORRECT INPUT!!!\n");
			exit(1);
		}
	}

	return 0;
}

int getUserChoice()
{
	int choice = 0;
	char garbage;
	printf("--------------------\n");
	printf("1) Change Shift\n");
	printf("2) Encrypt a message\n");
	printf("3) Decrypt a message\n");
	printf("4) Quit\n");
	printf("--------------------\n");
	printf("Enter your choice: ");
	scanf("%d%c", &choice, &garbage);

	// GET USER'S CHOICE

	return choice;
}

int getShift()
{
	int shift = 0;
	char garbage;
	printf("Enter a new shift value:\n");
	scanf("%d%c", &shift, &garbage);
	// GET NEW SHIFT VALUE

	return shift;
}

void getString(char string[])
{
	// GET USER STRING, MESSAGE TO BE ENCRYPTED/DECRYPTED
	printf("Enter a message:\n");
	fgets(string, 500, stdin);

}

void stringToCaps(char string[])
{
	// CAPITALIZE ENTIRE STRING
	int i = 0;
	while (string[i] != '\0') {
		if (string[i] >= 'a' && string[i] <= 'z') {
			string[i] = string[i] - 32;
		}
		i++;
	}
	printf("%s\n", string);
}

void encrypt(char string[], int shift)
{
	// ENCRYPT STRING, MAKE SURE TO WRAP
	
	int i = 0;
	while (string[i] != '\0') {
		if (string[i] >= 'A' && string[i] <= 'Z') {
			int ascii = (string[i] + shift);
			if (ascii > 'Z') { 
				ascii = ascii - 'Z' + 'A' - 1;
			}
			string[i] = ascii;
		}
		i++;
	}

}

void decrypt(char string[], int shift)
{
	// DECRYPT STRING, MAKE SURE TO WRAP
	int i = 0;
	while (string[i] != '\0') {
		if (string[i] >= 'A' && string[i] <= 'Z') {
			int ascii =(string[i] - shift);
			if (ascii < 'A') {
				ascii = ascii + 'Z' - 'A' + 1;
			}
			string[i] = ascii;
		}
		i++;
	}

}
