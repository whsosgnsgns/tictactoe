#include <iostream>
#include "time.h"

using namespace std;


int wincheck(char tictactoe[])
{
	int win = 0;
	if (tictactoe[0] == tictactoe[1] && tictactoe[0] == tictactoe[2])
		win = 1;
	else if (tictactoe[3] == tictactoe[4] && tictactoe[3] == tictactoe[5])
		win = 1;
	else if (tictactoe[6] == tictactoe[7] && tictactoe[6] == tictactoe[8])
		win = 1;
	else if (tictactoe[0] == tictactoe[3] && tictactoe[0] == tictactoe[6])
		win = 1;
	else if (tictactoe[1] == tictactoe[4] && tictactoe[1] == tictactoe[7])
		win = 1;
	else if (tictactoe[2] == tictactoe[5] && tictactoe[2] == tictactoe[8])
		win = 1;
	else if (tictactoe[0] == tictactoe[4] && tictactoe[0] == tictactoe[8])
		win = 1;
	else if (tictactoe[2] == tictactoe[4] && tictactoe[2] == tictactoe[6])
		win = 1;
	else
		win = 0;
	return win;
}


void Draw(char tictactoe[])
{
	int j = 0;
	for (unsigned int i = 0; i < 9; i++)
	{
		if (j == 3)
		{
			cout << endl;
			j = 0;
		}
		cout << tictactoe[i] << " ";
		j++;
	}
	cout << endl;
}


int main()
{
	srand(time(0));
	int win = 0;
	int num = 0;
	int turn = 0;
	char tictactoe[9] = {'1', '2', '3','4', '5', '6','7', '8', '9'};
	Draw(tictactoe);


	while (win != 1 || turn < 9)
	{
		cout << "Player X Turn (Type 1~9): ";
		cin >> num;

		while (num > 9 || num < 1)
		{
			cout << "Out of gameboard; Player X type 1-9 again: ";
			cin >> num;
		}

		while (tictactoe[num-1] == 'X' || tictactoe[num-1] == 'O')
		{
			cout << "Already placed; Player X type 1-9 again: ";
			cin >> num;
		}
		tictactoe[num-1] = 'X';
		Draw(tictactoe);
		cout << "Player X placed at " << num << endl;
		turn++;
		win = wincheck(tictactoe);
		if (win == 1)
		{
			cout << "Player X win!" << endl;
			break;
		}
		if (turn >= 9)
		{
			cout << "Draw!" << endl;
			break;
		}
		// cout << "Player O Turn (Type 1~9): ";
		num = rand()%9 + 1;
		// cin >> num;

		while (num > 9 || num < 1)
		{
			num = rand()%9 + 1;
			// cout << "Out of gameboard; Player O type 1-9 again: ";
			// cin >> num;
		}

		while (tictactoe[num-1] == 'X' || tictactoe[num-1] == 'O')
		{
			num = rand()%9 + 1;
			// cout << "Already placed; Player O type 1-9 again: ";
			// cin >> num;
		}
		tictactoe[num-1] = 'O';
		Draw(tictactoe);
		cout << "Computer places at " << num << endl;
		win = wincheck(tictactoe);
		turn++;
		if (win == 1)
		{
			cout << "Player O win!" << endl;
			break;
		}
	}

	return 0;
}
