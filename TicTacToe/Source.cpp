#include<iostream>
#include<vector>

using namespace std;

int displayBoard(vector<vector<char>> board) {
	for (int i = 2; i >= 0; i--) {
		cout << board[i][0] << '|' << board[i][1] << '|' << board[i][2] << endl;
		if (i == 0) {
			cout << endl;
		}
		else {
			cout << "-+-+-" << endl;
		}
	}

	return 0;
}

//check for a winner
bool isWin(vector<vector<char>> board) {

	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != ' ')) {
			return true;
		}
		else if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[0][i] != ' ')) {
			return true;
		}
		else if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[1][1] != ' ')) {
			return true;
		}
		else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != ' ')) {
			return true;
		}	
	}
	return false;
}

bool isMove(vector<vector<char>> board, int x_coord, int y_coord) {
	if ((x_coord < 1 || x_coord > 3) || (y_coord < 1 || y_coord > 3)) {
		return false;
	}
	if ((board[y_coord - 1][x_coord - 1] == 'x') || (board[y_coord - 1][x_coord - 1] == 'o')) {
		return false;
	}
	else {
		return true;
	}
}

vector<vector<char>> makeMove(vector<vector<char>> board, int x_coord, int y_coord, char player) {
	board[y_coord-1][x_coord-1] = player;

	return board;
}

int main() {
	char playerTurn = 'x';
	vector<vector<char>> board = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

	isWin(board);

	displayBoard(board);

	int turnNumber = 0;

	//while no winner and a space to go in
	while (turnNumber < 9 && isWin(board) == false) {
		displayBoard(board);

		int x_coord, y_coord;

		cout << "Please give the X-Coordinate of where you want to go" << endl;
		cin >> x_coord;
		cout << "Please give the Y-Coordinate of where you want to go" << endl;
		cin >> y_coord;

		//Do this to invert the y_coord so y_coord of 1 is at the bottom and y_coord of 3 is at the top
		//y_coord = 3 - y_coord;

		while (!isMove(board, x_coord, y_coord)) {
			cout << "This is not a valid move please try again" << endl;
			cout << "Please give the X-Coordinate of where you want to go" << endl;
			cin >> x_coord;
			cout << "Please give the Y-Coordinate of where you want to go" << endl;
			cin >> y_coord;

			//Do this to invert the y_coord so y_coord of 1 is at the bottom and y_coord of 3 is at the top
			//y_coord = 3 - y_coord;
		}
		board = makeMove(board, x_coord, y_coord, playerTurn);

		turnNumber = turnNumber + 1;
		if (playerTurn == 'x') {
			playerTurn = 'o';
		}
		else if (playerTurn == 'o') {
			playerTurn = 'x';
		}
	}

	if (isWin(board) == true) {
		if (playerTurn == 'x') {
			playerTurn = 'o';
		}
		else if (playerTurn == 'o') {
			playerTurn = 'x';
		}

		cout << "Player " << playerTurn << " won. Better luck next time." << endl;
	}
	else {
		cout << "It's a draw." << endl;
	}

	string end;
	cin >> end;

	return 0;

}