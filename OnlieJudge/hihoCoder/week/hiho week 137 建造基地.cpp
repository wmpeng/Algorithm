/*
* hiho week 137 建造基地
* dp,完全背包的变化
* author: wmpeng
* time: 2017-02-11 22:14:10
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#define inf 1000000000000000000ll
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n, m, k, t;
int a[105], b[105];
long long dp[10005];

long long DP()
{
	for (int i = 0; i <= 10000; i++)
		dp[i] = inf;


	dp[0] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= k; j++)
			if (j <= b[i])
				dp[j] = min(dp[j], a[i]);
			else
				dp[j] = min(dp[j], a[i] + dp[j - b[i]]);

	return dp[k];
}

void peng()
{
	//N、M、K和T
	scanf("%d%d%d%d", &n, &m, &k, &t);
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	int maxb = -1;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &b[i]);
		if (b[i] > maxb)
			maxb = b[i];
	}

	//如果没有答案
	long long tt = 1;
	for (int i = 1; i < n; i++)
	{
		tt *= t;
		if (tt > maxb)
		{
			cout << "No Answer" << endl;
			return;
		}
	}

	//如果有答案
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i != 1)
			for (int j = 1; j <= m; j++)
				b[j] /= t;
		ans += DP();
	}

	cout << ans << endl;
}

int main()
{
	int q;
	cin >> q;
	for (int I = 1; I <= q; I++)
	{
		peng();
	}

	return 0;
}