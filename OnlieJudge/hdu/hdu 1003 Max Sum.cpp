/*
* hdu 1003 Max Sum
* ˮ�⣬dp
* ע�������Ҫȡ�ǰ��һ��
* author�� wmpeng
* time: 2017-02-01 23:03:21
*/
#include<iostream>
using namespace std;

struct Node
{
	int val, beg;
};
int a[100005];
//dp[i] �����Ե�i����β�����ĺ�Ϊ����
Node dp[100005];
void peng()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	dp[1].val = a[1];
	dp[1].beg = 1;
	for (int i = 2; i <= n; i++)
	{
		if (dp[i - 1].val < 0)
		{
			dp[i].val = a[i];
			dp[i].beg = i;
		}
		else
		{
			dp[i].val = dp[i - 1].val + a[i];
			dp[i].beg = dp[i - 1].beg;
		}
	}

	int ans = 1;
	for (int i = 1; i <= n; i++)
		if (dp[i].val > dp[ans].val)
			ans = i;

	printf("%d %d %d\n", dp[ans].val, dp[ans].beg, ans);
}
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		if (i != 1)
			cout << endl;
		cout << "Case " << i << ":" << endl;//û��"#"���ӵ���
		peng();
	}
	return 0;
}