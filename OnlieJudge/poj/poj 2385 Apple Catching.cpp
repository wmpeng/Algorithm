/*
* poj 2385 Apple Catching
* dp
* 注意单独处理，虽然访问越界，但是仍在dp[][]空间里，所以并不报错。dp题一定要注意边界情况，越界肯定是要单独处理的
* author: wmpeng
* time: 2017-02-01 22:39:59
*/
#include<iostream>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

//dp[i][j] 代表 前i分钟，移动恰好j次，最多能获得多少苹果
int dp[1005][35], a[1005];

int main()
{
	int t, w, ans = -1;
	cin >> t >> w;
	for (int i = 1; i <= t; i++)
		cin >> a[i];

	for (int i = 1; i <= t; i++)
	{
		//注意dp[i][0]要单独处理，因为这个并没有两个选择
		dp[i][0] = dp[i - 1][0] + ((0 % 2 + 1) == a[i]);
		for (int j = 1; j <= w; j++)
			//((j % 2 + 1) == a[i]) 计算 在移动j次后在的这棵树在第i个时间有没有掉苹果
			dp[i][j] = max(dp[i - 1][j] + ((j % 2 + 1) == a[i]), dp[i - 1][j - 1] + ((j % 2 + 1) == a[i]));
	}

	for (int i = 0; i <= w; i++)
		ans = max(ans, dp[t][i]);

	cout << ans << endl;

	return 0;
}