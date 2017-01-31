/*
*UVA 227 Puzzle
*Ä£Äâ
*author: wmpeng
*time: 2017-01-31 12:05:58
*/
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
char mart[10][10];
string cmd;

bool peng()
{
	int x, y;
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			if (mart[i][j] == ' ')
			{
				x = i;
				y = j;
				break;
			}
	
	int len = cmd.length();
	for (int i = 0; i < len; i++)
	{
		switch (cmd[i])
		{
		case 'A':
			if (x == 1) return false;
			mart[x - 1][y] ^= mart[x][y] ^= mart[x - 1][y] ^= mart[x][y];
			x--;
			break;
		case 'B':
			if (x == 5) return false;
			mart[x + 1][y] ^= mart[x][y] ^= mart[x + 1][y] ^= mart[x][y];
			x++;
			break;
		case 'L':
			if (y == 1) return false;
			mart[x][y - 1] ^= mart[x][y] ^= mart[x][y - 1] ^= mart[x][y];
			y--;
			break;
		case 'R':
			if (y == 5) return false;
			mart[x][y + 1] ^= mart[x][y] ^= mart[x][y + 1] ^= mart[x][y];
			y++;
			break;
		default:
			;
		}
	}
	return true;
}

int main()
{
	char ctemp;
	for (int I = 1; true; I++)
	{
		memset(mart, 0, sizeof(mart));
		cmd = *new string();
		string temp;
		for (int i = 1; i <= 5; i++)
			for (int j = 1; j <= 6; j++)
			{
				scanf("%c", &mart[i][j]);
				if (i == 1 && j == 1 & mart[i][j] == 'Z')
					return 0;
			}
		while (1)
		{
			cin >> temp;
			cmd += temp;
			if (temp[temp.length() - 1] == '0')
				break;
		}
		scanf("%c", &ctemp);
		
		if (I != 1)
			cout << endl;
		if (peng())
		{
			cout << "Puzzle #" << I << ":" << endl;
			for (int i = 1; i <= 5; i++)
			{
				for (int j = 1; j <= 4; j++)
					cout << mart[i][j]<<" ";
				cout << mart[i][5] << endl;
			}
		}
		else
		{
			cout << "Puzzle #" << I << ":" << endl;
			cout << "This puzzle has no final configuration." << endl;
		}
	}
	return 0;
}