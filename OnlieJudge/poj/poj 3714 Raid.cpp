/*Poj 3714 Raid 
*kd-tree
*author:wmpeng
*time:2016-11-17 17:59:53
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

const long long K = 2;
long long ans;
struct kdNode
{
	long long x[K];
	long long div;
}p[100005];
struct Coord
{
	long long x[K];
}q;

long long cmpk;
bool cmp(kdNode a, kdNode b)
{
	return a.x[cmpk] < b.x[cmpk];
}

void buildKd(long long l, long long r, long long k)
{
	if (l > r)
		return;
	long long m = (r + l) / 2;
	cmpk = k;
	sort(p + l, p + r + 1, cmp);
	p[m].div = k;
	buildKd(l, m - 1, (k + 1) % K);//可以不放在叶节点吗
	buildKd(m + 1, r, (k + 1) % K);
}

long long dis2(kdNode &a, Coord &b)
{
	long long res = 0;
	for (long long i = 0; i < K; ++i)
		res += (a.x[i] - b.x[i])*(a.x[i] - b.x[i]);
	return res;
}
void findKd(long long l, long long r, Coord tar, long long cnt)
{
	if (l > r)
		return;
	long long m = (l + r) / 2;
	long long dist = dis2(p[m], tar);
	ans = min(dist, ans);

	long long t = tar.x[p[m].div] - p[m].x[p[m].div];//坐标差
	if (t <= 0)
	{
		findKd(l, m - 1, tar, cnt);
		if (ans>t*t)
			findKd(m + 1, r, tar, cnt);//回溯的感觉
	}
	else
	{
		findKd(m + 1, r, tar, cnt);
		if (ans > t*t)
			findKd(l, m - 1, tar, cnt);
	}
}

int main()
{
	int t, n, i, j, x, y;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			p[i].x[0] = x;
			p[i].x[1] = y;
		}
		buildKd(0, n - 1, 0);
		ans = 9000000000000000000LL;
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			q.x[0] = x;
			q.x[1] = y;
			findKd(0, n - 1, q, 1);
		}
		printf("%.3f\n", sqrt(double(ans)));
	}
	return 0;
}