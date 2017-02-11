/*
* poj 2385 Apple Catching
* dp
* ע�ⵥ��������Ȼ����Խ�磬��������dp[][]�ռ�����Բ�������dp��һ��Ҫע��߽������Խ��϶���Ҫ���������
* author: wmpeng
* time: 2017-02-01 22:39:59
*/
#include<iostream>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

//dp[i][j] ���� ǰi���ӣ��ƶ�ǡ��j�Σ�����ܻ�ö���ƻ��
int dp[1005][35], a[1005];

int main()
{
	int t, w, ans = -1;
	cin >> t >> w;
	for (int i = 1; i <= t; i++)
		cin >> a[i];

	for (int i = 1; i <= t; i++)
	{
		//ע��dp[i][0]Ҫ����������Ϊ�����û������ѡ��
		dp[i][0] = dp[i - 1][0] + ((0 % 2 + 1) == a[i]);
		for (int j = 1; j <= w; j++)
			//((j % 2 + 1) == a[i]) ���� ���ƶ�j�κ��ڵ�������ڵ�i��ʱ����û�е�ƻ��
			dp[i][j] = max(dp[i - 1][j] + ((j % 2 + 1) == a[i]), dp[i - 1][j - 1] + ((j % 2 + 1) == a[i]));
	}

	for (int i = 0; i <= w; i++)
		ans = max(ans, dp[t][i]);

	cout << ans << endl;

	return 0;
}