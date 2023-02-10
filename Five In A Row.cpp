 /*
  File: Five In A Row.cpp 
  Author: Yanyan Zhou
  Date: January 2023
  Description: 
    The text describes a program that plays the Five In A Row game. 
    It involves two players who alternate turns to place their markers ('O' for the first player and 'X' for the second player) 
    on a 15x15 grid that starts with empty spaces. 
    The players input the row and column of their move, but it will only be accepted if it falls within the grid's boundaries and the cell is unoccupied. 
    The "hasWon" function determines if a player has won the game 
    by counting the consecutive pieces in all four directions (horizontally, vertically, and diagonally). 
    If the count reaches 5, the player wins, and the game concludes.
*/

#include <iostream>
#include <cstring>
using namespace std;

const int ROWS = 15;
const int COLS = 15;
const char P1 = 'O';
const char P2 = 'X';

char board[ROWS][COLS];

void initBoard() //Initialize the character array board
{
	memset(board, ' ', sizeof(board));
}

void printBoard()   //output the board 
{
	cout << "  ";
	for (int i = 0; i < COLS; i++) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < ROWS; i++) {
		cout << i << " ";
		for (int j = 0; j < COLS; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool isValidMove(int row, int col)
{
	return row >= 0 && row < ROWS&& col >= 0 && col < COLS&& board[row][col] == ' ';
}

bool hasWon(int row, int col, char player) //Determine if a player has met the win condition by traversing the board array
{
	int count = 0;
	for (int i = row, j = col; i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j] == player; i--, j--) {
		count++;
	}
	for (int i = row + 1, j = col + 1; i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j] == player; i++, j++) {
		count++;
	}
	if (count >= 5) {
		return true;
	}
	count = 0;
	for (int i = row, j = col; i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j] == player; i--, j++) {
		count++;
	}
	for (int i = row + 1, j = col - 1; i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j] == player; i++, j--) {
		count++;
	}
	if (count >= 5) {
		return true;
	}
	count = 0;
	for (int i = row, j = col; i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j] == player; i--) {
		count++;
	}
	for (int i = row + 1; i >= 0 && i < ROWS && board[i][col] == player; i++) {
		count++;
	}
	if (count >= 5) {
		return true;
	}
	count = 0;
	for (int j = col; j >= 0 && j < COLS && board[row][j] == player; j--) {
		count++;
	}
	for (int j = col + 1; j >= 0 && j < COLS && board[row][j] == player; j--)
	{
		count++;
	}
	if (count >= 5) {
		return true;
	}
	return false;
}

int main() {
	initBoard();
	char player = P1;
	while (true) {
		printBoard(); //output the board before and after player moves 
		int row, col;
		cout << "Player " << player << ", enter your move (row column): ";
		cin >> row >> col;
		cout << endl;

		while (!isValidMove(row, col)) //If the move is invalid, re-enter the move
		{
			cout << "Invalid move, try again: ";
			cin >> row >> col;
		}
		board[row][col] = player;
		if (hasWon(row, col, player)) //If a player achieves the winning conditions, the game ends.
		{
			cout << "Player " << player << " has won!" << endl;
			break;
		}
		player = (player == P1) ? P2 : P1; //the player switches one by one
	}
	return 0;
}
