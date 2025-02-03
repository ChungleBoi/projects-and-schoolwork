#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	int id;
	char name[25];
	int age;
	char title[25];
	float salary;
} employee;

void PrintAllInfo(employee e[], int size);
void removeNewLines(employee *e);
void printEmployeeInfo(employee e[],int num);

int main(int argc, char *argv[])
{
	// Verify correct number of command line arguments were given
	if(argc != 2) {
		printf("ERROR: Invalid command line arguments\n"
				"EXPECTING: <INPUT-FILE>\n");
		exit(0);
	}
	// Open input file, verify it was opened properly
	FILE *input = NULL;
	input = fopen(argv[1], "r");

	if(input != NULL) {
		printf("\nFILE %s WAS SUCCESSFULLY OPENED.\n\n",argv[1]);
	}
	else {
		exit(0);
	}

	char line[25];
	int employeeNum;
	// Read in first line of the file
	if (fgets(line,sizeof(line),input)!= NULL) {
		employeeNum = atoi (&line[0]);	
	}

	// This will tell us the size of the employee array
	// Dynamically allocate a strucutre array of that size
	employee *database = NULL;
	database = malloc(employeeNum * sizeof(employee));


	// Read in every employee
	for(int i=0;i<employeeNum;i++) {

		database[i].id = i;

		fgets(database[i].name,sizeof(database[i].name),input);

		fgets(line,sizeof(line),input);
		database[i].age = atoi(line);

		fgets(database[i].title,sizeof(database[i].title),input);

		fgets(line,sizeof(line),input);
		database[i].salary = atof(line);

		removeNewLines(&database[i]);
	}


	// Prepare the operations loop
	char operation;
	char garbage;
	// Read in first operation
	fscanf(input, "%c%c", &operation, &garbage);

	// Loop until we run into the exit operation
	while(operation != '0')
	{
		// Update Employee Name
		if(operation == '1')
		{
			char line[25];
			int i;

			fgets(line,sizeof(line),input);
			i = atoi(line);

			fgets(database[i].name,sizeof(database[i].name),input);

			removeNewLines(&database[i]);

		}

		// Update Employee Salary
		if(operation == '2')
		{
			char line[10];
			int i;

			fgets(line,sizeof(line),input);
			i = atoi(line);

			fgets(line,sizeof(line),input);
			database[i].salary = atof(line);

			fgets(line,sizeof(line),input);	//I don't know where I went wrong
		}

		// Increase Employee Salary by Percentage
		if(operation == '3')
		{
			char line[10];
			double ratio;
			int i;

			fgets(line,sizeof(line),input); //employee index
			i = atoi(line);

			fgets(line,sizeof(line),input); //ratio by which to increase employee salary
			ratio = atof(line);

			database[i].salary *= ratio; //employee salary increased and saved in structure

		}

		// Increase All Employee Salaries by Percentage
		if(operation == '4')
		{
			char line[10];
			double ratio;
			int i;

			fgets(line,sizeof(line),input);
			ratio = atof(line);

			for (i=0;i<employeeNum;i++) {
				database[i].salary *= ratio;
			}		
		}

		// Update Employee Title
		if(operation == '5')
		{
			char line[25];
			int i;

			fgets(line,sizeof(line),input);
			i = atoi(line);

			fgets(database[i].title,sizeof(database[i].title),input);

			removeNewLines(&database[i]);
		}

		// Employee Birthday
		if(operation == '6')
		{
			char line[3];
			int i;

			fgets(line,sizeof(line),input);
			i = atoi(line);

			database[i].age += 1;

		}

		// Print Employee Info
		if(operation == '7')
		{
			char line[3];
			int i;

			fgets(line,sizeof(line),input);
			i = atoi(line);

			printEmployeeInfo(database,i);
		}

		// Print All Employee Info
		if(operation == '8')
		{
			PrintAllInfo(database, employeeNum);
		}

		// Read in next operation
		fscanf(input, "%c%c", &operation, &garbage);
	}
	free(database);
	fclose(input);
	return 0;
}

void PrintAllInfo(employee e[], int size)
{
	int i = 0;
	printf("+-EMPLOYEE NAME-------------+-AGE-+-TITLE---------------------+-SALARY------+\n");
	for(i=0; i<size; i++)
		printf("| %-25s | %3d | %-25s | $ %9.2f |\n", e[i].name, e[i].age, e[i].title, e[i].salary);
}
void printEmployeeInfo(employee e[],int num)
{
	int i = num;
	printf("+-EMPLOYEE NAME-------------+-AGE-+-TITLE---------------------+-SALARY------+\n");
	printf("| %-25s | %3d | %-25s | $ %9.2f |\n", e[i].name, e[i].age, e[i].title, e[i].salary);
}

void removeNewLines(employee *e)
{
	int length;
	length = strlen(e->name);
	if(e->name[length-1] =='\n')
		e->name[length-1] = '\0';

	length = strlen(e->title);
	if(e->title[length-1] == '\n')
		e->title[length-1] = '\0';
}
