/*
* poj 1384 Piggy-Bank
* ��ȫ����
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

//n��Ӳ�ҵ����࣬m��������p��Ӳ�ҵļ�ֵ��w��Ӳ�ҵ�����
void DP()
{
	for (int i = 1; i <= m; i++)
		dp[i] = inf;
	dp[0] = 0;

	/*ע����ȫ������ѭ������ʱ��˳�ŵģ�����ͨ���������ŵ�*/
	for (int j = 1; j <= n; j++)//��Ʒ
		for (int k = 0; k <= m; k++)//����
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