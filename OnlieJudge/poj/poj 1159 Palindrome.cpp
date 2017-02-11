/*
* poj 1159 Palindrome
* dp
* 经典又巧妙的dp, dp[i][j] 表示 i~j构成回文串最少需要添加多少字符
* author: wmpeng
* time: 2017-02-01 22:45:37
*/
#include<iostream>
using namespace std;
char s[5005];
short n, dp[5005][5005];
int min(int a, int b)
{
	return a > b ? b : a;
}
int main()
{
	int i, j;
	cin >> n >> s+1;
	for (i = n - 1; i >= 1; i--)
		for (j = i + 1; j <= n; j++)
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
	cout << dp[1][n]<<endl;
	return 0;
}