/**
*nkoj 2147 ��Ѻ�ﷸprison
*���鼯
*author:wmpeng
*time:2016-12-15 11:14:37
*
*descirption:
*	set[i](i<=n)��ʾi�����ȣ�set[i](i>n)��ʾi-n�Ķ��������ȡ�
*	�ȶԱ����򣨽��򣩣���˳������������˵��Ѿ�����ͬһ�����ϣ���ô����ߵ�Ȩֵ���Ǵ𰸡�
*	�������������ͬһ�����ϣ���ô�ֱ��������һ��������ļ����
*/

#include<iostream>
#include<stdio.h>
#include<algorithm>
#
using namespace std;
struct Pair
{
	int a, b, c;
}p[100005];

int n, m;
int set[40005];

bool cmp(Pair a, Pair b)
{
	return a.c > b.c;
}

int find(int x)
{
	return set[x] == x ? x : find(set[x]);
}

int main()
{
	int i;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i].a >> p[i].b >> p[i].c;
		if (p[i].a>p[i].b)
			p[i].a ^= p[i].b ^= p[i].a ^= p[i].b;
	}
	sort(p + 1, p + m + 1, cmp);

	for (int i = 1; i <= n; i++)///init
	{
		set[i] = i;
		set[i + n] = i + n;
	}

	for (int i = 1; i <= m; i++)
	{
		int fathera = find(p[i].a);
		int fatherb = find(p[i].b);
		if (fathera == fatherb)///��������һ������
		{
			cout << p[i].c << endl;
			return 0;
		}
		set[fathera] = find(p[i].b + n);
		set[fatherb] = find(p[i].a + n);
	}
	cout << 0 << endl;
	return 0;
}