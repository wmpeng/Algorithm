/*
*2015 CCPC C The Battle of Chibi
*hdu 5542 The Battle of Chibi
*dp,Ê÷×´Êý×é
*author:wmpeng
*time:2016-11-23 14:28:30
*/

#include <iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
int n,m;
int a[1005],b[10005];
long long dp[1005][1005];
long long sum[1005][1005];

void add(int kk,int k, int num)
{
	while (k <= n)
	{
		sum[kk][k] += num;
		k += k&(-k);
	}
}

long long check(int kk,int k)
{
	long long s = 0;
	while (k >= 1)
	{
		s += sum[kk][k];
		k -= k&(-k);
	}
	return s;
}



void peng()
{
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	int i,j,k,ans=0;
	for(i=1;i<=n;i++)
		dp[i][1]=1;
	for(i=1;i<=n;i++)
	{
		for(k=2;k<=m;k++)
		{
			dp[i][k]+=check(k-1,a[i]-1);
			dp[i][k]%=1000000007;
		}
		for(k=1;k<=m;k++)
		{
			add(k,a[i],dp[i][k]);
		}
	}
    for(i=1;i<=n;i++)
	{
		ans+=dp[i][m];
		ans%=1000000007;
	}
	cout<<ans<<endl;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&m);
        for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			b[j]=a[j];
		}
		sort(b+1,b+n+1);
		map<int,int> mmap;
        for(int j=1;j<=n;j++)
			mmap[b[j]]=j;
		for(int j=1;j<=n;j++)
			a[j]=mmap[a[j]];

		printf("Case #%d: ",i);
		peng();
	}
    return 0;
}

