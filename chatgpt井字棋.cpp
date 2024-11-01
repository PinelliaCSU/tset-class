#include <iostream>
#include <vector>

using namespace std;

// 游戏板大小
const int SIZE = 3;

// 初始化游戏板
void initializeBoard(vector<vector<char>>& board) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			board[i][j] = ' ';
		}
	}
}

// 打印游戏板
void printBoard(const vector<vector<char>>& board) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cout << board[i][j];
			if (j < SIZE - 1) cout << " | ";
		}
		cout << endl;
		if (i < SIZE - 1) {
			for (int j = 0; j < SIZE - 1; ++j) cout << "--+";
			cout << "--" << endl;
		}
	}
}

// 检查玩家是否赢了
bool checkWin(const vector<vector<char>>& board, char player) {
	// 检查行
	for (int i = 0; i < SIZE; ++i) {
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
	}
	
	// 检查列
	for (int j = 0; j < SIZE; ++j) {
		if (board[0][j] == player && board[1][j] == player && board[2][j] == player) return true;
	}
	
	// 检查对角线
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
	
	return false;
}

// 检查是否平局
bool checkDraw(const vector<vector<char>>& board) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] == ' ') return false;
		}
	}
	return true;
}

// 检查位置是否合法
bool isValidMove(const vector<vector<char>>& board, int row, int col) {
	return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

int main() {
	vector<vector<char>> board(SIZE, vector<char>(SIZE));
	initializeBoard(board);
	
	char currentPlayer = 'X';
	bool gameOver = false;
	
	while (!gameOver) {
		printBoard(board);
		
		int row, col;
		cout << "Player " << currentPlayer << ", enter row and column (0, 1, or 2): ";
		cin >> row >> col;
		
		if (isValidMove(board, row, col)) {
			board[row][col] = currentPlayer;
			
			if (checkWin(board, currentPlayer)) {
				printBoard(board);
				cout << "Player " << currentPlayer << " wins!" << endl;
				gameOver = true;
			} else if (checkDraw(board)) {
				printBoard(board);
				cout << "The game is a draw!" << endl;
				gameOver = true;
			} else {
				currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
			}
		} else {
			cout << "Invalid move. Try again." << endl;
		}
	}
	
	return 0;
}

