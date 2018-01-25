/*
* hdu 1421 ������
* dp
* ˼·������ ��֤�����һ���� �����ȡ���ڵ�����������Զ��׼�����ȫƽ������ƽ���� 
*		��ʼ����ˣ�����뷨��dp[i][j]�����i����Ʒ����ȡ�������Ļ�ÿ��ת����Ҫ��ǰ�����С�ģ����һ��ѭ��
*		��ȷ���뷨��dp[i][j]��ʾ ǰi����Ʒ ȡ2*j�� �ܴ򵽵���С��ƣ�Ͷ�
*		״̬ת�Ʒ��̣� dp[i][j] = min{	dp[i - 2][j - 1] + Pow(a[i]-a[i-1]) ��ȡ��i������ȡ��i�͵�i-1������
*										dp[i - 1][j] ����ȡ��i����}
* author: wmpeng
* time: 2017-02-02 00:14:07
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

//dp[i][j]��ʾǰi����Ʒȡ2*j����С��ƣ�Ͷ�
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
			//��i��ȡ�Ͳ�ȡ
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
