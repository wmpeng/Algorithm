/*
* hdu 1087 Super Jumping! Jumping! Jumping!
* dp,离散化，树状数组
* 这道题直接dp[i]表示以i结尾的最大和为多少，dp[i]=max{dp[j],a[j]<[i]}+a[i]，时间复杂度为O(n^2)
* 可以用树状数组优化，ask(i)，表示不大于i的结尾的最大的和是多少，每次更新一个dp后也更新ask(i),复杂度O(nlogn)，需要先离散化
* author: wmpeng
* time: 2017-02-02 11:07:42
*/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
//#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

struct Sort
{
	int val;
	int num;
}s[1005];
long long a[1005] = { 0 };//value数组
long long b[1005] = { 0 };//a离散化后的结果
long long dp[1005] = { 0 };
long long tree[1005];
int n;

//O(n^2)
void peng1()
{
	for (int i = 1; i <= n; i++)
	{
		long long max = 0;
		for (int j = 1; j < i; j++)
			if (a[j]<a[i] && dp[j]>max)
				max = dp[j];
		dp[i] = max + a[i];
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++)
		if (ans < dp[i])
			ans = dp[i];

	cout << ans << endl;
}

long long check(int k, long long *a)
{
	long long sum = 0;
	while (k >= 1)
	{
		//sum += a[k];
		sum = max(sum, a[k]);
		k -= k&(-k);
	}
	return sum;
}

void add(int k, long long num, long long *a)
{
	while (k <= n)
	{
		//a[k] += num;
		a[k] = max(a[k], num);
		k += k&(-k);
	}
}

bool cmp1(Sort a, Sort b)
{
	return a.val < b.val;
}
/*将a离散化*/
void liSan()
{
	int sub_a[1005];
	for (int i = 1; i <= n; i++)
		sub_a[i] = a[i];
	sort(sub_a + 1, sub_a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = lower_bound(sub_a + 1, sub_a + n + 1, a[i]) - sub_a;//k为b[i]经离散化后对应的值
	/*for (int i = 1; i <= n; i++)
		cout << b[i] << " ";
	cout << endl;*/
}

/*树状数组tree[i]维护，以不大于i的结尾的最大的和是多少
O(nlogn)*/
void peng2()
{
	liSan();
	memset(tree, 0, sizeof(tree));
	for (int i = 1; i <= n; i++)
	{
		long long max = 0;
		max = check(b[i] - 1, tree);
		dp[i] = max + a[i];
		add(b[i], dp[i], tree);
	}

	/*for (int i = 1; i <= n; i++)
		cout << dp[i] << " ";
	cout << endl;*/
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		if (ans < dp[i])
			ans = dp[i];

	cout << ans << endl;
}
int main()
{
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);

		peng2();
	}
	return 0;
}