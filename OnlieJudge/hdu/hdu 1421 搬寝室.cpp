/*
* hdu 1421 搬寝室
* dp
* 思路：首先 先证明结果一定是 排序后取相邻的两个，这个显而易见，完全平方大于平方和 
*		开始想错了，错的想法：dp[i][j]代表第i个物品必须取，这样的话每次转移需要找前面的最小的，会多一层循环
*		正确的想法：dp[i][j]表示 前i件物品 取2*j件 能打到的最小的疲劳度
*		状态转移方程： dp[i][j] = min{	dp[i - 2][j - 1] + Pow(a[i]-a[i-1]) 【取第i个，即取第i和第i-1个】，
*										dp[i - 1][j] 【不取第i个】}
* author: wmpeng
* time: 2017-02-02 00:14:07
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

//dp[i][j]表示前i件物品取2*j件最小的疲劳度
int n, k,a[2005],dp[2005][1005];

int Pow(int x)
{
	return x*x;
}
void peng()
{
	int ans = 1000000000;
	memset(dp, 0, sizeof(dp));
	sort(a + 1, a + n + 1);

	dp[2][1] = Pow(a[2]-a[1]);
	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <= min(k, i / 2); j++)
			//第i件取和不取
			if (i - 1 >= j * 2)
				dp[i][j] = min(dp[i - 2][j - 1] + Pow(a[i]-a[i-1]), dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 2][j - 1] + Pow(a[i]-a[i-1]);
	}

	cout << dp[n][k] << endl;
}

int main()
{
	while(scanf("%d%d", &n, &k) != -1)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		peng();
	}

	return 0;
}
