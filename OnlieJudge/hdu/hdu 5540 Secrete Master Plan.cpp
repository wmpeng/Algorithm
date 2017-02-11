/*
*2015 CCPC final A Secrete Master Plan
*hud 5540 Secrete Master Plan
*Ë®Ìâ£¬Ä£Äâ
*author:wmpeng
*time:2016-11-21 21:54:43
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int a[2][2], b[2][2];
bool j()
{
	for (int i = 0; i<2; i++) 
		for (int j = 0; j<2; j++) 
			if (a[i][j] != b[i][j]) return false;
	return true;
}

void zhuan()
{
	int tmp = a[0][0];
	a[0][0] = a[1][0];
	a[1][0] = a[1][1];
	a[1][1] = a[0][1];
	a[0][1] = tmp;
}
int main()
{
	int t, cnt = 0;
	scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i<2; i++)
			for (int j = 0; j<2; j++)
				scanf("%d", &a[i][j]);
		for (int i = 0; i<2; i++)
			for (int j = 0; j<2; j++)
				scanf("%d", &b[i][j]);
		
		bool f = false;
		for (int i = 0; i<4; i++) 
		{
			if (j()) f = true;
			zhuan();
		}
		if (f)
			printf("Case #%d: POSSIBLE\n", ++cnt);
		else 
			printf("Case #%d: IMPOSSIBLE\n", ++cnt);
	}
	return 0;
}