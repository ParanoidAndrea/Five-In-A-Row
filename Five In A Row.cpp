// Five In A Row.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
This code implements a basic Five In A Row game where two players take turns placing their pieces
('O' for player 1 and 'X' for player 2) on a 15x15 grid.
The board is initialized with blank spaces, and the players take turns entering the rowand column of their move.
The move is considered valid only if the chosen cell is within the boundaries of the gridand is unoccupied.
The function `hasWon` checks if the player has won the game
after making a move by counting the number of consecutive pieces in all four directions
(horizontally, vertically, and diagonally).
If the count reaches 5, the player has won and the game ends.
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