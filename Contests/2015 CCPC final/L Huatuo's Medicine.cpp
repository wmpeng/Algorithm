/*
*2015 CCPC L Huatuo's Medicine
*hud 5551 Huatuo's Medicine
*Ë®Ìâ
*author:wmpeng
*time:2016-11-21 21:55:43
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t, x,i;
	scanf("%d", &t);
	for (i = 1; i <= t;i++)
	{
		scanf("%d", &x);
		printf("Case #%d: %d\n", i,x * 2 - 1);
	}
	return 0;
}