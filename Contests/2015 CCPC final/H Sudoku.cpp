/*
*2015 CCPC H Sudoku 
*hud 5547 Sudoku 
*Ë®Ìâ
*author:wmpeng
*time:2016-11-21 21:55:43
*/

#include<iostream>
#include<stdio.h>
using namespace std;

int mart[4][4],ans[4][4];
int tt;
int getans;
//void prt()
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//			cout << mart[i][j];
//		cout << endl;
//	}
//	cout << endl;
//}
void peng(int n)
{
	int x = n / 4, y = n % 4;
	//cout << endl << "(" << x << "," << y << ")" << endl;
	//prt();
	if (n == 16)
	{
		for (int i = 0; i < 16; i++)
			*(ans[0] + i) = *(mart[0] + i);
		getans = 1;
		return;
	}
	else if (mart[x][y] != 0)
		peng(n + 1);
	else
	{
		for (int i = 1; i <= 4; i++)
		{
			int flag = 0;
			for (int j = 0; j < 4; j++)
				if (mart[x][j] == i || mart[j][y] == i)
				{
					flag = 1;
					break;
				}
			if (x < 2 && y < 2 && (mart[0][0] == i || mart[1][0] == i || mart[0][1] == i || mart[1][1] == i))
				flag = 1;
			if (x < 2 && y >= 2 && (mart[0][2] == i || mart[1][2] == i || mart[0][3] == i || mart[1][3] == i))
				flag = 1;
			if (x >= 2 && y < 2 && (mart[2][0] == i || mart[3][0] == i || mart[2][1] == i || mart[3][1] == i))
				flag = 1;
			if (x >= 2 && y >= 2 && (mart[2][2] == i || mart[2][3] == i || mart[3][2] == i || mart[3][3] == i))
				flag = 1;
			if (flag == 0)
			{
				mart[x][y] = i;
				if (getans == 0)
					peng(n + 1);
			}
		}
		mart[x][y] = 0;
	}
}
int main()
{
	int t, i, j;
	char s[5];
	scanf("%d", &t);
	for (tt = 1; tt <= t;tt++)
	{
		getans = 0;
		for (i = 0; i < 4; i++)
		{
			scanf("%s", s);
			for (j = 0; j < 4; j++)
				if (s[j] == '*')
					mart[i][j] = 0;
				else
					mart[i][j] = s[j] - '0';
		}
		peng(0);
		printf("Case #%d:\n", tt);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				printf("%d", ans[i][j]);
			printf("\n");
		}
	}
}