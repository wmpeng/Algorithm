/*
* poj 1157 LITTLE SHOP OF FLOWERS
* 水题，dp
* 变形的01背包
* author: wmpeng
* time: 2017-02-01 21:45:39
*/
#include<iostream>
using namespace std;
int dp[105][105],a[105][105];
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int f, v;
	cin >> f >> v;
	for (int i = 1; i <= f; i++)
		for (int j = 1; j <= v; j++)
			cin >> a[i][j];
	for (int i = 1; i <= f; i++)
		dp[i][i] = dp[i - 1][i - 1] + a[i][i];
	for(int i=1;i<=f;i++)
		for (int j = i + 1; j <= v; j++)
			dp[i][j] = max(dp[i - 1][j - 1] + a[i][j], dp[i][j - 1]);

	cout << dp[f][v] << endl;

	return 0;
}