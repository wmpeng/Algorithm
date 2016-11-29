/*
*2015 CCPC final D Pick The Sticks
*hdu 5543 D Pick The Sticks
*dp
*auther:wmpeng
*time:2016-11-22 16:13:41
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n, l;
struct Stick
{
	long long l;
	long long v;
}sticks[1005];
long long dp[4005][3];//最后一个维度代表有几个机会折半

void peng()
{
	int i, j;
	long long ans = 0;
	memset(dp, 0, sizeof(dp));
	//考虑只放一个的情况
	for (j = 1; j <= n; j++)
		if (sticks[j].v > ans)
			ans = sticks[j].v;

	for (i = 1; i <= n; i++)
		for (j = l; j >= sticks[i].l/2; j--)
		{
			if (j - sticks[i].l>=0 && dp[j][0] < dp[j - sticks[i].l][0] + sticks[i].v)
				dp[j][0] = dp[j - sticks[i].l][0] + sticks[i].v;
			if (j - sticks[i].l >= 0 && dp[j][1] < dp[j - sticks[i].l][1] + sticks[i].v)//每个分两种情况，当前（j）取一半还是不取一半
				dp[j][1] = dp[j - sticks[i].l][1] + sticks[i].v;
			if (dp[j][1] < dp[j - sticks[i].l / 2][0] + sticks[i].v)
				dp[j][1] = dp[j - sticks[i].l / 2][0] + sticks[i].v;
			if (j - sticks[i].l >= 0 && dp[j][2] < dp[j - sticks[i].l][2] + sticks[i].v)
				dp[j][2] = dp[j - sticks[i].l][2] + sticks[i].v;
			if (dp[j][2] < dp[j - sticks[i].l / 2][1] + sticks[i].v)
				dp[j][2] = dp[j - sticks[i].l / 2][1] + sticks[i].v;
		}
	ans = (ans>dp[l][2]?ans: dp[l][2]);
	cout << ans << endl;
}

int main()
{
	int t, i, j;
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		scanf("%d%d", &n, &l);
		l *= 2;
		for (j = 1; j <= n; j++) 
		{
			scanf("%I64d%I64d", &sticks[j].l, &sticks[j].v);
			sticks[j].l *= 2;
		}
		printf("Case #%d: ", i);
		peng();
	}
	return 0;
}