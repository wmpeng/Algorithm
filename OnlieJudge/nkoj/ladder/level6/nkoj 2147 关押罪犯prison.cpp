/**
*nkoj 2147 关押罪犯prison
*并查集
*author:wmpeng
*time:2016-12-15 11:14:37
*
*descirption:
*	set[i](i<=n)表示i的祖先，set[i](i>n)表示i-n的对立的祖先。
*	先对边排序（降序），按顺序处理，如果两个端点已经属于同一个集合，那么这个边的权值就是答案。
*	如果两个不属于同一个集合，那么分别放在与另一个点对立的集合里。
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
		if (fathera == fatherb)///两个属于一个集合
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