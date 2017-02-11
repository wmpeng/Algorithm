/*
* hdu 4828 Girds
* 卡特兰数，逆元
* 描述：利用递推公式求卡特兰数 Catalan(n+1) = Catalan(n)*(4*n+2)/(n+2)，因为结果需要MOD而其中又有除法，
*		所以利用逆元，转换为 Catalan(n+1) = Catalan(n)*(4*n+2) * Niyuan(n+2) % MOD，
*		由于MOD很大，所以利用了扩展欧几里得算法求逆元。
* 注意：使用long long，过程中及时mod防止溢出
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
* 利用 (a / b) MOD p == a MOD (p * b) / b 
* !不对 因为MOD应该在最后取余
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

/*扩展欧几里得算法*/
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

/*利用扩展欧几里得算法求逆元x
*ax+py=1，x为b关于p的逆元，y为p关于b的逆元*/
long long niyuan(long long n)
{
	gcd(n, MOD);
	return (x%MOD + MOD) % MOD;
}

/*利用 (a / b) MOD p == (a * k) MOD p ，其中k为b关于p的逆元*/
void init2()
{
	catalan[1] = 1;
	for (int i = 1; i <= 1000000; i++)
		catalan[i + 1] = (catalan[i] * (4 * i + 2) % MOD * niyuan(i+2)) % MOD;//注意溢出
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
