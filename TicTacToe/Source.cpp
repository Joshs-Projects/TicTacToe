#include<iostream>
#include<vector>

using namespace std;

int displayBoard(vector<vector<char>> board) {
	//cout upside down to effectivly invert the y coords
	//This makes y=1 the bottom and y = 3 the top
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
		//Checks all columns
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != ' ')) {
			return true;
		}
		//Checks all rows
		else if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[0][i] != ' ')) {
			return true;
		}
		//Checks diagonal bottom-left to top-right
		else if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[1][1] != ' ')) {
			return true;
		}
		//Checks diagonal top-left to bottom-right
		else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != ' ')) {
			return true;
		}	
	}
	return false;
}

bool isMove(vector<vector<char>> board, int x_coord, int y_coord) {
	//Checks that x and y are inside the grid
	if ((x_coord < 1 || x_coord > 3) || (y_coord < 1 || y_coord > 3)) {
		return false;
	}
	//Checks that x and y isn't currently filled
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

	int turnNumber = 0;

	//While no winner and a space to go in keep playing
	while (turnNumber < 9 && isWin(board) == false) {
		displayBoard(board);

		int x_coord, y_coord;

		cout << "Please give the X-Coordinate of where you want to go" << endl;
		cin >> x_coord;
		cout << "Please give the Y-Coordinate of where you want to go" << endl;
		cin >> y_coord;

		while (!isMove(board, x_coord, y_coord)) {
			cout << "This is not a valid move please try again" << endl;
			cout << "Please give the X-Coordinate of where you want to go" << endl;
			cin >> x_coord;
			cout << "Please give the Y-Coordinate of where you want to go" << endl;
			cin >> y_coord;
		}

		board = makeMove(board, x_coord, y_coord, playerTurn);

		//Adds to the total turns as if the turns = 9 all boxes are filled and game is over
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