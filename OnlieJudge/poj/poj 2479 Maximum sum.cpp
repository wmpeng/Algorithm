/*
* poj 2479 Maximun sum
* 水题,dp
* 两次dp即可，不要裸用cin，直接卡超时
* author: wmpeng
* time: 2017-02-01 22:11:24
*/
#include<iostream>
#include<string.h>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int a[50005], dp1[50005], dp2[50005], ans1[50005], ans2[50005];

/*两个dp，一个从前往后一个从后向前*/
void peng()
{
	int n,ans=-1000000000;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	dp1[1] = a[1];
	for (int i = 2; i <= n; i++)
		dp1[i] = max(a[i], dp1[i - 1] + a[i]);
	
	dp2[n] = a[n];
	for (int i = n-1; i >=1 ; i--)
		dp2[i] = max(a[i], dp2[i + 1] + a[i]);

	ans1[1] = dp1[1];
	for (int i = 2; i <= n; i++)
		ans1[i] = max(ans1[i - 1], dp1[i]);

	ans2[n] = dp2[n];
	for (int i = n-1; i >=1 ; i--)
		ans2[i] = max(ans2[i + 1], dp2[i]);


	for (int i = 2; i <= n; i++)
		ans = max(ans, ans1[i - 1] + ans2[i]);

	printf("%d\n", ans);
}
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		peng();
	return 0;
}