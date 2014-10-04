//Group88
//Member: Yanjun Wu, Zhenbao Yang

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(3, vector<int>(3));
int row, column;

void initialize();
bool draw(int p);
bool checkMate(int row, int column, int p);
bool isFull();
void input(int p);

int main()
{
	bool flag = false;
	bool isf = false;
	int p1 = 1;
	int p2 = 2;
	// player 1 = "O", player 2 = "X"
	char *winner;
	initialize();
	do
	{
		flag = draw(p1);
		if (flag == true)
		{
			winner = "O";
			break;
		}
		isf = isFull();
		if (isf == true)
			break;
		flag = draw(p2);
		if (flag == true)
		{
			winner = "X";
			break;
		}
		isf = isFull();
	} while (flag == false && isf == false);
	if (flag == false && isf == true)
	{
		cout << "Board is full. No one wins." << endl;
	}
	else
		cout << "Winner is Player " << winner << ". Congratulations!" << endl;
	return 0;
}

void initialize()
{
	cout << "  1   2   3" << endl;
	cout << "1   |   |" << endl;
	cout << "----+---+---" << endl;
	cout << "2   |   |" << endl;
	cout << "----+---+---" << endl;
	cout << "3   |   |" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			v[i][j] = 0;
		}
	}
}

bool draw(int p)
{
	bool flag = false;
	cout << "Player " << p << " :" << endl;
	cout << "Please enter two positive integer numbers as  row and column: " << endl;
	input(p);
	cout << "  1   2   3" << endl;
	cout << "1";
	for (int c = 0; c < 2; c++)
	{
		if (v[0][c] == 1)
			cout << " " << "O" << " |";
		else if (v[0][c] == 2)
			cout << " " << "X" << " |";
		else
			cout << "   |";
	}
	if (v[0][2] == 1)
		cout << " O ";
	else if (v[0][2] == 2)
		cout << " X ";
	else
		cout << "   ";
	cout << endl;
	cout << "----+---+---" << endl;
	cout << "2";
	for (int c = 0; c < 2; c++)
	{
		if (v[1][c] == 1)
			cout << " " << "O" << " |";
		else if (v[1][c] == 2)
			cout << " " << "X" << " |";
		else
			cout << "   |";
	}
	if (v[1][2] == 1)
		cout << " O ";
	else if (v[1][2] == 2)
		cout << " X ";
	else
		cout << "   ";
	cout << endl;
	cout << "----+---+---" << endl;
	cout << "3";
	for (int c = 0; c < 2; c++)
	{
		if (v[2][c] == 1)
			cout << " " << "O" << " |";
		else if (v[2][c] == 2)
			cout << " " << "X" << " |";
		else
			cout << "   |";
	}
	if (v[2][2] == 1)
		cout << " O ";
	else if (v[2][2] == 2)
		cout << " X ";
	else
		cout << "   ";
	cout << endl;
	flag = checkMate(row, column, p);
	return flag;
}

bool checkMate(int row, int column, int p)
{
	bool flag = false;
	if (row == 1 && column == 1)
	{
		if ((v[0][0] == p && v[1][1] == p && v[2][2] == p) || (v[0][1] == p && v[1][1] == p && v[2][1] == p)
			|| (v[0][2] == p && v[1][1] == p && v[2][0] == p) || (v[1][0] == p && v[1][1] == p && v[1][2] == p))
			flag = true;
	}
	else if (row == 1 && column != 1)
	{
		if ((v[0][column] == p && v[1][column] == p && v[2][column] == p) || (v[1][0] == p && v[1][1] == p && v[1][2] == p))
			flag = true;
	}
	else if (row != 1 && column == 1)
	{
		if ((v[row][0] == p && v[row][1] == p && v[row][2] == p) || (v[0][1] == p && v[1][1] == p && v[2][1] == p))
			flag = true;
	}
	else
	{
		if (row == 0 && column == 0)
		{
			if ((v[0][0] == p && v[0][1] == p && v[0][2] == p) || (v[0][0] == p && v[1][0] == p && v[2][0] == p)
				|| (v[0][0] == p && v[1][1] == p && v[2][2] == p))
				flag = true;
		}
		if (row == 0 && column == 2)
		{
			if ((v[0][0] == p && v[0][1] == p && v[0][2] == p) || (v[0][2] == p && v[1][2] == p && v[2][2] == p)
				|| v[0][2] == p && v[1][1] == p && v[2][0] == p)
				flag = true;
		}
		if (row == 2 && column == 0)
		{
			if ((v[0][0] == p && v[1][0] == p && v[2][0] == p) || (v[2][0] == p && v[1][1] == p && v[0][2] == p)
				|| v[2][0] == p && v[2][1] == p && v[2][2] == p)
				flag = true;
		}
		if (row == 2 && column == 2)
		{
			if ((v[2][0] == p && v[2][1] == p && v[2][2] == p) || (v[0][2] == p && v[1][2] == p && v[2][2] == p)
				|| v[0][0] == p && v[1][1] == p && v[2][2] == p)
				flag = true;
		}
	}
	return flag;
}

bool isFull()
{
	bool flag = true;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (v[i][j] == 0)
			{
				flag = false;
			}
		}
	}
	return flag;
}

void input(int p)
{
	int r, c;
	int fn = 0;
	//fn = 0, initialize
	//fn = 1, correct
	//fn = 2, out of range
	//fn = 3, existed
	//fn = 4, not integer
	while (fn != 1)
	{
		cin.sync();
		cin.clear();
		cin >> r >> c;
		if (cin.bad() || cin.fail())
		{
			fn = 4;
			cout << "ILLEGAL INPUT!" << endl;
		}
		else if (r > 3 || r <= 0 || c > 3 || c <= 0)
		{
			fn = 2;
			cout << "OUT OF RANGE!" << endl;
		}
		else if (v[r - 1][c - 1] == 1 || v[r - 1][c - 1] == 2)
		{
			fn = 3;
			cout << "EXISTED!" << endl;
		}
		else
		{
			fn = 1;
			break;
		}
		cout << "Reinput:" << endl;
	}
	row = r - 1;
	column = c - 1;
	v[row][column] = p;
}