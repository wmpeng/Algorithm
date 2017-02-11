/*
* hdu 4828 Girds
* ������������Ԫ
* ���������õ��ƹ�ʽ�������� Catalan(n+1) = Catalan(n)*(4*n+2)/(n+2)����Ϊ�����ҪMOD���������г�����
*		����������Ԫ��ת��Ϊ Catalan(n+1) = Catalan(n)*(4*n+2) * Niyuan(n+2) % MOD��
*		����MOD�ܴ�������������չŷ������㷨����Ԫ��
* ע�⣺ʹ��long long�������м�ʱmod��ֹ���
* author: wmpeng
* time: 2017-01-31 22:06:26
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#define MOD 1000000007ll
using namespace std;
long long catalan[1000005];
long long x, y;

/*
* ���� (a / b) MOD p == a MOD (p * b) / b 
* !���� ��ΪMODӦ�������ȡ��
**/
void init1()
{
	catalan[0] = 1;
	catalan[1] = 1;
	for (long long i = 1; i <= 1000000; i++)
	{
		catalan[i + 1] = (  (catalan[i] * (4 * i + 2)) % (MOD*(i + 2))  ) / (i + 2);
	}
	for (int i = 1; i <= 100; i++)
		cout <<i<<":"<< catalan[i]%MOD << endl;
}

/*��չŷ������㷨*/
void gcd(long long a, long long b)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	//cout << a << " " << b << endl;
	gcd(b, a%b);
	long long tmp;
	tmp = x;
	x = y;
	y = tmp - a / b * y;
}

/*������չŷ������㷨����Ԫx
*ax+py=1��xΪb����p����Ԫ��yΪp����b����Ԫ*/
long long niyuan(long long n)
{
	gcd(n, MOD);
	return (x%MOD + MOD) % MOD;
}

/*���� (a / b) MOD p == (a * k) MOD p ������kΪb����p����Ԫ*/
void init2()
{
	catalan[1] = 1;
	for (int i = 1; i <= 1000000; i++)
		catalan[i + 1] = (catalan[i] * (4 * i + 2) % MOD * niyuan(i+2)) % MOD;//ע�����
}

int main()
{
	init2();
	int t, n;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		printf("Case #%d:\n%lld\n",i, catalan[n]);
	}

	return 0;
}
