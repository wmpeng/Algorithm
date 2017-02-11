/*
* hdu 1087 Super Jumping! Jumping! Jumping!
* dp,��ɢ������״����
* �����ֱ��dp[i]��ʾ��i��β������Ϊ���٣�dp[i]=max{dp[j],a[j]<[i]}+a[i]��ʱ�临�Ӷ�ΪO(n^2)
* ��������״�����Ż���ask(i)����ʾ������i�Ľ�β�����ĺ��Ƕ��٣�ÿ�θ���һ��dp��Ҳ����ask(i),���Ӷ�O(nlogn)����Ҫ����ɢ��
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
long long a[1005] = { 0 };//value����
long long b[1005] = { 0 };//a��ɢ����Ľ��
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
/*��a��ɢ��*/
void liSan()
{
	int sub_a[1005];
	for (int i = 1; i <= n; i++)
		sub_a[i] = a[i];
	sort(sub_a + 1, sub_a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = lower_bound(sub_a + 1, sub_a + n + 1, a[i]) - sub_a;//kΪb[i]����ɢ�����Ӧ��ֵ
	/*for (int i = 1; i <= n; i++)
		cout << b[i] << " ";
	cout << endl;*/
}

/*��״����tree[i]ά�����Բ�����i�Ľ�β�����ĺ��Ƕ���
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