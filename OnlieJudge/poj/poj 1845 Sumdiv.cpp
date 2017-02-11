/*
*poj 1845
*模的逆元
*注意：矩阵快速幂时会超过long long，注意手动mod
*author: wmpeng
*time: 2017-01-31 19:46:27
*/

#include<iostream>
#include<stdio.h>
#include<map>
#include<math.h>
#define MOD 9901ll
using namespace std;
long long a, b;
map<long long,long long> factor;

//找a的质因数分解，存放在factor中 
void resolution()
{
	long long sq = sqrt(double(a));
	long long aa = a;
	for (long long i = 2; i <= sq && aa!=1; i++)
	{
		if (aa%i == 0)
		{
			factor[i]++;
			aa /= i;
			i--;
		}
	}
	if (aa > 1)
		factor[aa]++;
}

//计算mi1*mi2%mod 
long long calMi(long long mi1,long long mi2,long long mod)
{
	long long ret = 0;
	for (int i = 60; i >= 0; i--)
	{
		ret *= 2;
		ret +=mi1 * (mi2 / (1ll << i));
		ret %= mod;
		mi2 %= (1ll << i);
	}
	return ret;
}

long long cal(long long pi, long long ai)
{
	long long mi[1000] = {1,pi};
	long long mod = MOD*(pi - 1);
	long long kk = ai*b + 1;
	long long ret = 1;
	
	for (long long i = 2; i <= 999; i++)
	{
		mi[i] = calMi(mi[i - 1], mi[i - 1], mod);//注意可能超long long
	}
	
	for (long long i=1;kk != 0;i++)
	{
		if(kk % 2==1)
			ret *= mi[i];
		ret %= mod;
		kk /= 2;
	}
	
	ret = (ret + mod - 1) % mod;
	ret /= (pi - 1);

	return ret;
}

int main()
{
	long long ans = 1;

	while (cin >> a >> b)
	{
		factor.clear();
		ans = 1;
		resolution();
		/*for (map<long long, long long>::iterator it = factor.begin(); it != factor.end(); it++)
			cout << it->first << "," << it->second << endl;*/
		for (map<long long, long long>::iterator it = factor.begin(); it != factor.end(); it++)
		{
			ans *= cal(it->first, it->second);
			ans %= MOD;
		}

		cout << ans << endl;
	}
	return 0;
}
