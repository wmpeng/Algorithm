/*
* ���㼸�Σ�Ƥ�˶�������������
* Ƥ�˶���(����ζ��㶼Ϊ����): S=a+b��2-1������a��ʾ������ڲ��ĵ�����b��ʾ����α߽��ϵĵ�����s��ʾ����ε������
* ����������������͹������
* author: wmpeng
* time: 2017-02-11 18:00:05
*/

#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

struct node
{
	int x, y;
}point[105];
int m;

int abs(int x)
{
	return (x < 0) ? (-x) : x;
}

/*�������������mΪ���������point[]Ϊ�������꣬�±��1��ʼ*/
int calDoubleA()
{
	int ans = 0;
	for (int i = 3; i <= m; i++)
		ans += (point[i].x - point[1].x)*(point[i - 1].y - point[1].y) - (point[i - 1].x - point[1].x)*(point[i].y - point[1].y);  //x1y2-x2y1  
	if (ans<0)
		ans = -ans;
	return ans;
}

int gcd(int x,int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x%y);
}

/*������������о����������㣬mΪ���������point[]Ϊ�������꣬�±��1��ʼ*/
int calE()
{
	int ret = 0;
	for (int i = 1; i <= m; i++)
		ret += gcd(abs(point[i%m + 1].x - point[i].x), abs(point[i%m + 1].y - point[i].y));
	return ret;
}

int calI(int da,int e)
{
	return (da - e + 2) / 2;
}


int main()
{
	int t;
	scanf("%d", &t);
	for(int I=1;I<=t;I++)
	{
		int x = 0, y = 0, xx, yy;
		scanf("%d", &m);
		
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &xx, &yy);
			x += xx;
			y += yy;
			point[i].x = x;
			point[i].y = y;
		}

		int da = calDoubleA();
		int e = calE();
		int i = calI(da, e);
		
		printf("Scenario #%d:\n", I);
		printf("%d %d %.1f\n\n", i, e, da / 2.0);
	}
	return 0;
}