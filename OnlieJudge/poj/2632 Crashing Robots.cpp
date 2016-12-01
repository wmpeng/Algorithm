/*
*poj 2632
*水题，模拟，枚举
*author: wmpeng
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int a, b, n, m;
map<char,char> L,R;
int flag = 1;
struct
{
	int x, y;
	char dir;
}robot[105];

void ini()
{
	L['N'] = 'W';
	L['W'] = 'S';
	L['S'] = 'E';
	L['E'] = 'N';
	R['N'] = 'E';
	R['E'] = 'S';
	R['S'] = 'W';
	R['W'] = 'N';
}
bool pd(int x)
{
	if (robot[x].x == 0 || robot[x].x == a + 1 || robot[x].y == 0 || robot[x].y == b + 1)
	{
		printf("Robot %d crashes into the wall\n", x);
		return true;
	}
	for (int i = 1; i <= n; i++)
		if (i != x && robot[x].x == robot[i].x && robot[x].y == robot[i].y)
		{
			printf("Robot %d crashes into robot %d\n", x, i);
			return true;
		}
	/*cout << "[";
	for (int i = 1; i <= n; i++)
		cout << robot[i].x << "," << robot[i].y << "," << robot[i].dir << " ; ";
	cout << "]";*/
	return false;
}

void peng()
{
	int robotn, repeat;
	char action;
	cin >> robotn >> action >> repeat;
	if (flag == 0)
		return;
	if (action == 'L')
		for (int ii = 1; ii <= repeat; ii++)
			robot[robotn].dir = L[robot[robotn].dir];
	else if (action == 'R')
		for (int ii = 1; ii <= repeat; ii++)
			robot[robotn].dir = R[robot[robotn].dir];
	else if (action == 'F')
	{
		if (robot[robotn].dir == 'N')
			for (int ii = 1; ii <= repeat; ii++)
			{
				robot[robotn].y++;
				if (pd(robotn))
				{
					flag = 0;
					break;
				}
			}
		else if (robot[robotn].dir == 'E')
			for (int ii = 1; ii <= repeat; ii++)
			{
				robot[robotn].x++;
				if (pd(robotn))
				{
					flag = 0;
					break;
				}
			}
		else if (robot[robotn].dir == 'W')
			for (int ii = 1; ii <= repeat; ii++)
			{
				robot[robotn].x--;
				if (pd(robotn))
				{
					flag = 0;
					break;
				}
			}
		else if (robot[robotn].dir == 'S')
			for (int ii = 1; ii <= repeat; ii++)
			{
				robot[robotn].y--;
				if (pd(robotn))
				{
					flag = 0;
					break;
				}
			}
	}
}

int main()
{
	ini();
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		flag = 1;
		cin >> a >> b >> n >> m;
		for (int j = 1; j <= n; j++)
			cin >> robot[j].x >> robot[j].y >> robot[j].dir;
		for (int j = 1; j <= m; j++)
			peng();

		if (flag == 1)
			cout << "OK" << endl;
	}
	return 0;
}