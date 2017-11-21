#include <iostream>
#include <sstream>
using namespace std;
char win;int vyhod;int x;
void tablica(char *mass) {
	cout << "   1   2   3" << endl;
	cout << " +---+---+---+" << endl;
	cout << "a| " << mass[0] << " | " << mass[1] << " | " << mass[2] << " |" << endl;
	cout << " +---+---+---+" << endl;
	cout << "b| " << mass[3] << " | " << mass[4] << " | " << mass[5] << " |" << endl;
	cout << " +---+---+---+" << endl;
	cout << "c| " << mass[6] << " | " << mass[7] << " | " << mass[8] << " |" << endl;
	cout << " +---+---+---+" << endl;
}
void vozmhody(char op, char *mass) {
	int k = 0;
	for (int i = 0; i < 9; i++) {
		if (!(mass[i] == 'X' || mass[i] == 'O')) {
			if (i < 3) {
				cout << ++k << ".mark cell a" << i + 1 << " as " << op << endl;
			}
			if (i>2 && i<6) {
				cout << ++k << ".mark cell b" << i - 2 << " as " << op << endl;
			}
			if (i>5) {
				cout << ++k << ".mark cell c" << i - 5 << " as " << op << endl;
			}
		}
	}
	cout << ++k << ". quit" << endl;
	vyhod = k;
}
int hod(int move, char op, char *mass) {
	int cell;
	string string;
	getline(cin, string);
	istringstream stream(string);
	stream >> cell;
	while (cell < 1 || cell >(11 - move)) {
		cout << endl << "You can not use this move. Enter another move" << endl;
		getline(cin, string);
		istringstream stream(string);
		stream >> cell;
	}
	int k = 0;
	for (int i = 0; i < 10; i++){
		if (mass[i] == ' ') {
			k++;
		}
		if (k == cell) {
			mass[i] = op;
			tablica(mass);
			return 0;
			}
	}
	if (cell == vyhod) {
		cout << "game over((" << endl;
		x = vyhod;
		return -1;
	}
	return 0;
}
char proverka(char *mass) {
	for (int i = 0; i < 3; i++) {
		if ((mass[i * 3] == mass[i * 3 + 1] && mass[i * 3 + 1] == mass[i * 3 + 2]) && mass[i * 3] != ' ') {
			return mass[i];;
		}
		if ((mass[i] == mass[i + 3] && mass[i + 3] == mass[i + 6]) && mass[i] != ' ') {
			return mass[i];
		}
		if (((mass[2] == mass[4] && mass[4] == mass[6]) && mass[2] != ' ') || ((mass[0] == mass[4] && mass[4] == mass[8]) && mass[0] != ' ')) {
			return mass[i];
		}
	}
	return ' ';
}
int main() {
	char mass[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char op;
	tablica(mass);
	for (int move = 1; move <= 9; move++) {
		if (move % 2) {
			op = 'X';
			vozmhody(op, mass);
			hod(move, op, mass);
		}
		else {
			op = 'O';
			vozmhody(op, mass);
			hod(move, op, mass);
		}
		if (vyhod == x) {
			return -1;
		}
		if (move >= 5) {
			proverka(mass);
			char  win = proverka(mass);
				cout << win<<" win" << endl;
				return -1;
			}
			if (move == 9 && win != 'X' && win != 'O') {
				cout << "nichya" << endl;
				return -1;
			}
	}
	if (vyhod ==x) {
		return -1;
	}
}
