// Cristian Ortiz
// A03 - 2D Arrays (Tic Tac Toe)
// CSC 250

#include <stdlib.h>
#include <stdio.h>

void initBoard(char board[][3]);
void printBoard(char board[][3]);
void getMove(char board[][3], char turn);
int placeMove(char board[][3], char turn, int row, int col);
char getWinner(char board[][3]);
int isDraw(char board[][3]);
// Add Additional Function Prototypes Here

int main()
{
	char winner = '\0';
	char turn = 'X';
	char board[3][3];

	// Create board and initialize it

	initBoard(board);
	printBoard(board);

	// Loop until we have a winner or draw
	while(!winner && !isDraw(board))
	{
		printBoard(board);
		getMove(board, turn); 
		// Switch turns between 'X' and 'O' here
		if (turn == 'X') {
			turn = 'O';
		} else { 
			turn = 'X';
		}

		winner = getWinner(board);

	}

	printBoard(board);

	if(winner == 'X' || winner == 'O')
	{
		printf("Congrats %c! You win!\n", winner);
	}
	else
	{
		printf("Draw! No one wins!\n");
	}
	return 0;
}

void initBoard(char board[][3])
	/*
	   Initialize the tic tac toe board
	   Params:
	   char board[][3]: The tic tac toe board
	 */
{
	int i, j;
	for(i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			board[i][j] = '_';
		}
	}
}

void printBoard(char board[][3])
	/*
	   Prints the tic tac toe board
	   Params:
	   char board[][3]: The tic tac toe board
	 */
{
	// call this before printing to clear the screen before each turn
	system("clear");
	int i;
	for(i=0;i<3;i++) {
		printf("%c %c %c\n",board[i][0],board[i][1],board[i][2]);		
	}
}

void getMove(char board[][3], char turn)
	/*
	   Gets user's move
	   Params:
	   char board[][3]: The tic tac toe board
	   char turn: Char used to define whos turn it is ('X' or 'O')
	 */
{
	int i,j;
	printf("%c's Move: ",turn);
	scanf("%d %d",&i, &j);
	while (!placeMove(board,turn,i,j)) { 
		printf("Incorrect Move,%c try again: ",turn);
		scanf("%d %d",&i, &j);
	}
}

int placeMove(char board[][3], char turn, int row, int col)
	/*
	   Check if move is valid and places it if it can
	   Params:
	   char board[][3]: The tic tac toe board
	   char turn: Char used to define who's turn it is
	   int row: Row to be placed in
	   int col: Col to be placed in
	   Returns:
	   1 if move is valid and placed
	   0 if move is not valid
	 */
{
	if (row >= 0 && row <= 2 && col >= 0 && col <= 2 && board[row][col] == '_') {
		board[row][col] = turn;
		return 1;
	}
	return 0;
}

char getWinner(char board[][3])
	/*
	   Used to see if the board is in a win state
	   Params:
	   char board[][3]: The tic tac toe board
	   Returns:
	   char 'X' if X is the winner
	   char 'O' if O is the winner
	   char '\0' if there is no win state
	 */
{
	// Manually Check Diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_')
		return board[1][1];
	if (board[0][2] == board [1][1] && board [1][1] == board[2][0] && board[0][2] != '_')
		return board[0][2];

	// Loop over Rows/Columns
	for (int i=0;i<3;i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_')
			return board[i][1];
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '_')
			return board[0][i];
	}
	return '\0';
}

int isDraw(char board[][3])
	/*
	   Checks if game is in a draw state
	   Params:
	   char board[][3]: The tic tac toe board
	   Returns:
	   1 if game is in a draw state
	   0 if game is not in a draw state
	 */
{
	int i, j;
	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			if (board[i][j] == '_') {
				return 0;
			}
		}
	}
	return 1;
}

// Add Additional Function Definitions Here
