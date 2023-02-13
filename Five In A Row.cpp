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

// Initialize the board with blank spaces
void initBoard() 
{
	memset(board, ' ', sizeof(board));
}

// Print the current state of the board
void printBoard()   
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

// Check if the move is valid
bool isValidMove(int row, int col)
{
	return row >= 0 && row < ROWS&& col >= 0 && col < COLS&& board[row][col] == ' ';
}

// Check if the player has won after making a move
bool hasWon(int row, int col, char player) {
    int count = 0;
    // Check horizontally
    for (int i = col; i >= 0 && board[row][i] == player; i--) {
        count++;
    }
    for (int i = col + 1; i < COLS && board[row][i] == player; i++) {
        count++;
    }
    if (count >= 5) {
        return true;
    }
    count = 0;
    // Check vertically
    for (int i = row; i >= 0 && board[i][col] == player; i--) {
        count++;
    }
    for (int i = row + 1; i < ROWS && board[i][col] == player; i++) {
        count++;
    }
    if (count >= 5) {
        return true;
    }
    count = 0;
    // Check diagonally (upper left to lower right)
    for (int i = row, j = col; i >= 0 && j >= 0 && board[i][j] == player; i--, j--) {
        count++;
    }
    for (int i = row + 1, j = col + 1; i < ROWS && j < COLS && board[i][j] == player; i++, j++) {
        count++;
    }
    if (count >= 5) {
        return true;
    }
    count = 0;
    // Check diagonally (upper right to lower left)
    for (int i = row, j = col; i >= 0 && j < COLS && board[i][j] == player; i--, j++) {
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
