/*
* poj 1384 Piggy-Bank
* 完全背包
* author: wmpeng
* time: 2017-02-11 22:04:45
*/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
#define min(a,b) (a<b?a:b)
#define inf 1000000000
using namespace std;

int n, m;
int p[505],w[505];
int dp[10005];

//n是硬币的种类，m是容量，p是硬币的价值，w是硬币的重量
void DP()
{
	for (int i = 1; i <= m; i++)
		dp[i] = inf;
	dp[0] = 0;

	/*注意完全背包在循环容量时是顺着的，而普通背包是逆着的*/
	for (int j = 1; j <= n; j++)//物品
		for (int k = 0; k <= m; k++)//容量
			if (k >= w[j])
				dp[k] = min(dp[k], dp[k - w[j]] + p[j]);
	if (dp[m] == inf)
		printf("This is impossible.\n");
	else
		printf("The minimum amount of money in the piggy-bank is %d.\n", dp[m]);
}

int main()
{
	int t;
	cin >> t;
	for (int I = 1; I <= t; I++)
	{
		int a, b;
		cin >> a >> b;
		m = b - a;

		cin >> n;
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &p[i], &w[i]);
		DP();
	}
	return 0;
}