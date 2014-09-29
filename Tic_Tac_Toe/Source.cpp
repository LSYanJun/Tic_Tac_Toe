//Group88
//Member: Yanjun Wu, Zhenbao Yang

#include <iostream>
#include "Header.h"
using namespace std;

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